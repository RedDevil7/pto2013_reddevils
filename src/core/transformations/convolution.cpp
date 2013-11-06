#include "convolution.h"

/** Overloaded constructor */
Convolution::Convolution(PNM* img) :
    Transformation(img)
{
}

Convolution::Convolution(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

/** Returns a convoluted form of the image */
PNM* Convolution::transform()
{
    return convolute(getMask(3, Normalize), RepeatEdge);
}

/** Returns a sizeXsize matrix with the center point equal 1.0 */
math::matrix<double> Convolution::getMask(int size, Mode mode = Normalize)
{
    math::matrix<double> mask(size, size);
for (int i=0;i<size;i++)
	{ 
		for (int j=0; j<size;j++){
   mask(i,j)=0;
		}
}
mask(size/2,size/2)=1;

    return mask;
}

/** Does the convolution process for all pixels using the given mask. */
PNM* Convolution::convolute(math::matrix<double> mask, Mode mode = CyclicEdge)
{
	  double  suma;
	  int r,g,b;
    int width  = image->width(),
        height = image->height();
	int size=mask.RowNo();
	int radius = size/2;
	double weight = sum(mask);
	//int size=z*z;
    PNM* newImage = new PNM(width, height, image->format());
	

    
	/*  if (image->format() == QImage::Format_Indexed8)
	
    {       for (int x=0; x<width; x++){
           for (int y=0; y<height; y++){
			   math::matrix<double> okno = getWindow(x,y,size, , mode);
			   math::matrix<double> accumulator = join(mask,okno);
			 if (weight!=0){
			 suma= sum(accumulator)/weight;
			 }
			 else { 
				 suma=sum(accumulator);
			 
		   }
			 if (suma>255){
				int v=PIXEL_VAL_MAX;
				   newImage->setPixel(x,y, v);
				
			 }

			else if (suma<0){
				int v=PIXEL_VAL_MIN;
				   newImage->setPixel(x,y, v);
				
			 }
			else {
				int v=suma;
				newImage->setPixel(x,y,v);
			}					
	  }
	  }
	  } */
	

		   for (int x=0; x<width; x++){
           for (int y=0; y<height; y++){		
			  math::matrix<double> oknoR(size, size);
			math::matrix<double> oknoG(size, size);
			math::matrix<double> oknoB(size, size);

			math::matrix<double> accumulatorR(size, size);
			math::matrix<double> accumulatorG(size, size);
			math::matrix<double> accumulatorB(size, size);
			for (int i=0; i<size; i++){
				for (int j=0; j<size; j++){

			   QRgb pixel = getPixel(x+i-radius,y+j-radius,mode); // Getting the pixel(x,y) value
			   		oknoR(i,j)=qRed(pixel);
					oknoG(i,j)=qGreen(pixel);
					oknoB(i,j)=qBlue(pixel);
				}
			}
			 accumulatorR=join(mask,oknoR);
			 accumulatorB=join(mask,oknoB);
			 accumulatorG=join(mask,oknoG);
			 double sumR=sum(accumulatorR);
			  double sumG=sum(accumulatorG);
			   double sumB=sum(accumulatorB);

			 if (weight!=0){
			 sumR= sum(accumulatorR)/weight;
			 sumG= sum(accumulatorG)/weight;
			 sumB= sum(accumulatorB)/weight;

			 }
			
		

			 if (sumR>255){
				sumR=255;				   
				
			 }

			if (sumR<0){
				sumR=0;
				  
			 }
			if (sumG>255){
				sumG=255;				   
				
			 }

			if (sumG<0){
				sumG=0;
				  
			 }
			if (sumB>255){
				sumB=255;				   
				
			 }

			if (sumB<0){
				sumB=0;
				  
			 }

			
			  QColor newPixel = QColor(sumR,sumG,sumB);
                newImage->setPixel(x,y, newPixel.rgb()); 
		   }
	  }

	 
    return newImage;
}

/** Joins to matrices by multiplying the A[i,j] with B[i,j].
  * Warning! Both Matrices must be squares with the same size!
  */
const math::matrix<double> Convolution::join(math::matrix<double> A, math::matrix<double> B)
{
    int size = A.RowNo();
    math::matrix<double> C(size, size);

    for (int i=0; i<size;i++){
		for (int j=0; j<size;j++){
			C(i,j)=A(i,j)*B(i,j);
		}
	}

    return C;
}

/** Sums all of the matrixes elements */
const double Convolution::sum(const math::matrix<double> A)
{
    double sum = 0.0;
	int size=A.RowNo();
       for (int i=0; i<size;i++){
		for (int j=0; j<size;j++){
			sum+=A(i,j);
		}
	}

    return sum;

}
