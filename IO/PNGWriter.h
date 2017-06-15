#pragma once
#include <boost/filesystem.hpp>

#include "Image.h"

namespace bf = boost::filesystem;

namespace SimpleCV {
	namespace IO {
		namespace PNG {
			void save(const bf::path& imagePath, const Core::Image& image);
		} // PNG
	} // IO
} // SimpleCV