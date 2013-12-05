#include "edge_laplacian_of_gauss.h"

#include "blur_gaussian.h"

EdgeLaplaceOfGauss::EdgeLaplaceOfGauss(PNM* img) :
    Convolution(img)
{
}

EdgeLaplaceOfGauss::EdgeLaplaceOfGauss(PNM* img, ImageViewer* iv) :
    Convolution(img, iv)
{
}

math::matrix<double> EdgeLaplaceOfGauss::getMask(int, Mode)
{
    size = getParameter("size").toInt();
    double sigma = getParameter("sigma").toDouble();

    math::matrix<double> mask(size, size);

    for (int x=0; x<size; x++)
	{	
		for (int y=0; y<size; y++)
		{
			mask(x,y) = getLoG(x, y, sigma);
		}
	}
	//Proszê pamiêtaæ, ¿e œrodek maski to inaczej wspó³rzêdne (0,0) dla getLoG(...).
	mask((int) size/2, (int) size/2) = getLoG(0, 0, sigma);

    return mask;
}

double EdgeLaplaceOfGauss::getLoG(int x, int y, double s)
{
    double a = ((pow(x,2)+pow(y,2))/pow(s,2) - 2/pow(s,2));
	double b = BlurGaussian::getGauss(x, y, s);
    return a * b;
}

int EdgeLaplaceOfGauss::getSize()
{
    return size;
}
