#pragma once
#include <boost/filesystem.hpp>

namespace bf = boost::filesystem;

namespace IO {
	namespace PNG {
		void load(const std::string& imagePath);
		void load(const bf::path& imagePath);
	}
}