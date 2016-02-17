#include "Image.h"

#include <exception>

using namespace SimpleCV::Core;

Image::Image(const int width, const int height, const int value)
	: width(width), height(height)
{
	pixels.resize(width*height, value);
}

Image::Image(const Image& image)
	: width(image.getWidth()), height(image.getHeight())
{
	pixels.assign(image.getBuffer().begin(), image.getBuffer().end());
}

int Image::getHeight() const
{
	return width;
}

int Image::getWidth() const
{
	return height;
}

int Image::getPixel(const int x, const int y) const
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		throw new std::exception("Out of bounds access");

	return pixels.at(y*width + x);
}

const std::vector<int>& Image::getBuffer() const
{
	return pixels;
}