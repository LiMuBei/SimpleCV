#pragma once
#include <boost/filesystem.hpp>

#include "Image.h"

namespace bf = boost::filesystem;

namespace SimpleCV {
	namespace IO {
		namespace PNG {
			void load(const std::string& imagePath, Core::Image& image);
			void load(const bf::path& imagePath, Core::Image& image);
		} // PNG
	} // IO
} // SimpleCV