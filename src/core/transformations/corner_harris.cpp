#include "corner_harris.h"

#include "blur_gaussian.h"
#include "conversion_grayscale.h"
#include "edge_sobel.h"

CornerHarris::CornerHarris(PNM* img) :
	Convolution(img)
{
}

CornerHarris::CornerHarris(PNM* img, ImageViewer* iv) :
	Convolution(img, iv)
{
}

PNM* CornerHarris::transform()
{
	int    threshold    = getParameter("threshold").toInt();
	double sigma        = getParameter("sigma").toDouble(),
		sigma_weight = getParameter("sigma_weight").toDouble(),
		k_param      = getParameter("k").toDouble();

	int width  = image->width(),
		height = image->height();

	PNM* newImage = new PNM(width, height, QImage::Format_Indexed8);

	math::matrix<double> I_x2(width,height);
	math::matrix<double> I_y2(width,height);
	math::matrix<double> I_xy(width,height);
	math::matrix<double> corners_candidates(width,height);
	math::matrix<double> corners_nonmax_suppress(width,height);
	PNM* tempImage = new PNM(width, height, QImage::Format_Indexed8);

	tempImage = ConversionGrayscale::ConversionGrayscale(image).transform();
	BlurGaussian blurGaussian(tempImage);
	blurGaussian.setParameter("size", 3);
	blurGaussian.setParameter("sigma", 3.6);
	tempImage = blurGaussian.transform();
	EdgeSobel sobel(tempImage);
	math::matrix<double>* x_gradient = sobel.rawHorizontalDetection();
	math::matrix<double>* y_gradient = sobel.rawVerticalDetection();

	for (int i=0; i<width; i++)
	{        
		for (int j=0; j<height; j++)
		{
			double gx_pix=(*x_gradient)(i,j);
			double gy_pix=(*y_gradient)(i,j);
			I_x2(i,j)=gx_pix*gx_pix;
			I_y2(i,j)=gy_pix*gy_pix;
			I_xy(i,j)=gx_pix*gy_pix;
		}
	}
	for (int i=0; i<width; i++)
	{        
		for (int j=0; j<height; j++)
		{
			if(i==0 || j==0 || i==width-1 || j==height-1)
			{
				corners_candidates(i,j)=0;
				corners_nonmax_suppress(i,j)=0;
			}
			else
			{
				double	S_x2=0;
				double S_y2 = 0;
				double S_xy=0;
				for(int k=-1;k<2;k++)
				{
					for (int l=-1;l<2;l++)
					{
						double g_val=BlurGaussian::getGauss(k,l,sigma);
						S_x2+=I_x2(i+k,j+l)*g_val;
						S_y2+=I_y2(i+k,j+l)*g_val;
						S_xy+=I_xy(i+k,j+l)*g_val;
					}
				}
				S_x2=S_x2/sigma_weight;
				S_y2=S_y2/sigma_weight;
				S_xy=S_xy/sigma_weight;
				math::matrix<double> H(2,2);
				H(0,0)=S_x2;
				H(1,1)=S_y2;
				H(1,0)=S_xy;
				H(0,1)=S_xy;
				double r=H(0,0)*H(1,1)-H(0,1)*H(1,0)-k_param*pow(H(0,0) + H(1,1), 2);
				if (r>threshold)
				{
					corners_candidates(i,j)=r;
				}
				else
				{
					corners_candidates(i,j)=0;
				}
			}
		}
	}

	bool make_nonmax_suppression=true;
	while(make_nonmax_suppression==true)
	{
		make_nonmax_suppression=false;
		for (int i=1;i<width-1;i++)
		{
			for (int j=1;j<height-1;j++)
			{
				double val=corners_candidates(i,j);
				if (val>corners_candidates(i-1,j-1) &&val>corners_candidates(i-1,j) && val>corners_candidates(i-1,j+1) && val>corners_candidates(i,j-1) && val>corners_candidates(i,j+1) && val>corners_candidates(i+1,j-1) &&val>corners_candidates(i+1,j) && val>corners_candidates(i+1,j+1))
				{
					corners_nonmax_suppress(i,j)=val;
				}
				else
				{
					if (val>0)
					{
						make_nonmax_suppression=true;
					}
					corners_nonmax_suppress(i,j)=0;
				}

			}
		}
		corners_candidates=corners_nonmax_suppress;
	}
	for (int i=0;i<width;i++)
	{
		for (int j=0;j<height;j++)
		{
			if (corners_candidates(i,j)==0)
			{

				newImage->setPixel(i,j,PIXEL_VAL_MAX);

			}
			else
			{
				newImage->setPixel(i,j,PIXEL_VAL_MIN);
			}
		}
	}

	return newImage;
}