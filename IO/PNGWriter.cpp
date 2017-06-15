#include "PNGWriter.h"

#include "PNGCommon.h"

namespace bf = boost::filesystem;

using namespace SimpleCV::IO::PNG;

PNGParams setupWriting(const bf::path& imagePath)
{
	PNGParams params;
	params.filePointer = fopen(imagePath.string().c_str(), "wb");

	if (!params.filePointer)
	{
		throw std::runtime_error("Error opening file for writing image!");
	}

	params.png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!params.png_ptr)
		throw std::runtime_error("Error creating PNG write struct for writing image!");

	params.png_info_ptr = png_create_info_struct(params.png_ptr);
	if (!params.png_info_ptr)
	{
		png_destroy_write_struct(&params.png_ptr, (png_infopp)NULL);
		throw std::runtime_error("Error creating PNG info struct for writing image!");
	}

	return params;
}

void SimpleCV::IO::PNG::save(const bf::path& imagePath, const Core::Image& image)
{
	PNGParams params = setupWriting(imagePath);

	if (setjmp(png_jmpbuf(params.png_ptr)))
	{
		png_destroy_write_struct(&params.png_ptr, &params.png_info_ptr);
		fclose(params.filePointer);
		throw std::runtime_error("Error encountered during PNG writing!");
	}	

	png_set_IHDR(params.png_ptr, params.png_info_ptr, 
		image.getWidth(), image.getHeight(), 8, PNG_COLOR_TYPE_RGBA, 
		PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	png_text comment[1];
	comment[0].key = "Software";
	comment[0].text = "SimpleCV";
	comment[0].compression = PNG_TEXT_COMPRESSION_NONE;	

	// TODO: Add creation time

	png_set_text(params.png_ptr, params.png_info_ptr, comment, 1);

	// set image data
	png_bytepp rows = new png_bytep[image.getHeight()];
	for (int y = 0; y < image.getHeight(); ++y)
	{
		png_bytep row = new png_byte[image.getWidth()*4];
		for (int x = 0; x < image.getWidth(); ++x)
		{
			unsigned int pix = image.getPixel(x, y);
			row[x*4] = static_cast<png_byte>(pix >> 24);
			row[x*4+1] = static_cast<png_byte>(pix >> 16);
			row[x*4+2] = static_cast<png_byte>(pix >> 8);
			row[x * 4 + 3] = static_cast<png_byte>(pix);
		}
		rows[y] = row;
	}
	
	png_init_io(params.png_ptr, params.filePointer);

	png_set_rows(params.png_ptr, params.png_info_ptr, rows);

	png_write_png(params.png_ptr, params.png_info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
	
	fclose(params.filePointer);

	png_destroy_write_struct(&params.png_ptr, &params.png_info_ptr);

	for (int y = 0; y < image.getHeight(); ++y)
		delete[] rows[y];
	delete[] rows;
}
