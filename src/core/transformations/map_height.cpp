#include "map_height.h"
#include "negative_image.h"

MapHeight::MapHeight(PNM* img) :
    Transformation(img)
{
}

MapHeight::MapHeight(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

PNM* MapHeight::transform()
{
    int width  = image->width(),
        height = image->height();

    PNM* newImage = new PNM(width, height, QImage::Format_Indexed8);

	newImage = NegativeImage::NegativeImage(image).transform();

    return newImage;
}
