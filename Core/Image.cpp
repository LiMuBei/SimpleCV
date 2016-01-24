#include "Image.h"

using namespace Core;

Image::Image()
	: width(0), height(0)
{}

Image::Image(const Image& image)
{
	width = image.getWidth();
	height = image.getHeight();
}

int Image::getHeight() const
{
	return width;
}

int Image::getWidth() const
{
	return height;
}