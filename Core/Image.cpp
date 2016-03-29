#include "Image.h"

#include <stdexcept>

using namespace SimpleCV::Core;

namespace {
	void checkBounds(int x, int y, int width, int height)
	{
		if (x < 0 || x >= width || y < 0 || y >= height)
			throw std::out_of_range("Out of bounds access");
	}
}

Image::Image()
	: width(0), height(0)
{}

Image::Image(int width, int height, int value)
	: width(width), height(height)
{
	pixels.resize(width*height, value);
}

Image::Image(const Image& image)
	: width(image.getWidth()), height(image.getHeight())
{
	pixels.assign(image.getBuffer().begin(), image.getBuffer().end());
}

Image::Image(int width, int height, const std::vector<long>& data)
	: width(width), height(height)
{
	pixels.assign(data.begin(), data.end());
}

int Image::getHeight() const
{
	return width;
}

int Image::getWidth() const
{
	return height;
}

long Image::getPixel(int x, int y) const
{
	checkBounds(x, y, width, height);

	return pixels.at(y*width + x);
}

const std::vector<long>& Image::getBuffer() const
{
	return pixels;
}

void Image::setPixel(int x, int y, long value)
{
	checkBounds(x, y, width, height);

	pixels.at(y*width + x) = value;
}

void Image::resize(int w, int h)
{
	if (width == w && height == h)
		return;

	width = w;
	height = h;
	pixels.resize(width*height, 0);
}