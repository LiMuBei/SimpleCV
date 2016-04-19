#pragma once

#include "png.h"

struct PNGParams {
	png_structp png_ptr;
	png_infop png_info_ptr;
	png_infop png_end_info_ptr;
	int width;
	int height;

	FILE* filePointer;

	PNGParams() : png_ptr(NULL), png_info_ptr(NULL), png_end_info_ptr(NULL), width(-1), height(-1), filePointer(NULL) {}
};