#include "PNGLoader.h"

#include <iostream>
#include <stdexcept>

#include "png.h"
#include "PNGCommon.h"

namespace bf = boost::filesystem;

using namespace SimpleCV::IO::PNG;


PNGParams setupLoading(const bf::path& imagePath)
{
	if (!bf::exists(imagePath))
		throw std::invalid_argument("Image file does not exist " + imagePath.string());

	PNGParams params;

	params.filePointer = fopen(imagePath.string().c_str(), "rb");
	unsigned char sig[8];

	fread(sig, 1, 8, params.filePointer);
	if (!png_check_sig(sig, 8))
	{
		throw std::runtime_error("Not a valid PNG file " + imagePath.string());   /* bad signature */
		fclose(params.filePointer);
	}

	std::cout << "Encountered valid PNG file " << imagePath.string() << std::endl;

	params.png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!params.png_ptr)
	{
		fclose(params.filePointer);
		throw std::runtime_error("Out of memory when reading image file " + imagePath.string());   /* out of memory */
	}

	params.png_info_ptr = png_create_info_struct(params.png_ptr);
	if (!params.png_info_ptr)
	{
		png_destroy_read_struct(&params.png_ptr, (png_infopp)NULL, (png_infopp)NULL);
		fclose(params.filePointer);
		throw std::runtime_error("Out of memory when reading image file " + imagePath.string());   /* out of memory */
	}

	params.png_end_info_ptr = png_create_info_struct(params.png_ptr);
	if (!params.png_end_info_ptr)
	{
		png_destroy_read_struct(&params.png_ptr, &params.png_info_ptr, (png_infopp)NULL);
		fclose(params.filePointer);
		throw std::runtime_error("Out of memory when reading image file " + imagePath.string());   /* out of memory */
	}

	return params;
}


void SimpleCV::IO::PNG::load(const bf::path& imagePath, Core::Image& image)
{
	PNGParams params = setupLoading(imagePath);

	if (setjmp(png_jmpbuf(params.png_ptr)))
	{
		png_destroy_read_struct(&(params.png_ptr), &(params.png_info_ptr), &(params.png_end_info_ptr));
		fclose(params.filePointer);
		throw std::runtime_error("Error when reading image file " + imagePath.string());   /* out of memory */
	}

	png_init_io(params.png_ptr, params.filePointer);
	png_set_sig_bytes(params.png_ptr, 8);

	png_read_png(params.png_ptr, params.png_info_ptr, NULL, NULL);
	std::cout << "Read image file " << imagePath.string() << " successfully!" << std::endl;
	params.width = png_get_image_width(params.png_ptr, params.png_info_ptr);
	params.height = png_get_image_height(params.png_ptr, params.png_info_ptr);
	std::cout << "Image size is " << params.width << " x " << params.height << " pixels." << std::endl;

	image.resize(params.width, params.height);

	png_bytepp rowPointers = png_get_rows(params.png_ptr, params.png_info_ptr);

	// copy image data
	for (int y = 0; y < params.height; ++y)
	{
		for (int x = 0; x < params.width; ++x)
		{
			png_byte rawPixel = rowPointers[y][x];
			image.setPixel(x, y, static_cast<long>(rawPixel));
		}
	}

	png_destroy_read_struct(&(params.png_ptr), &(params.png_info_ptr), &(params.png_end_info_ptr));
	fclose(params.filePointer);
}

void SimpleCV::IO::PNG::load(const std::string& imagePath, Core::Image& image)
{
	load(bf::path(imagePath), image);
}
