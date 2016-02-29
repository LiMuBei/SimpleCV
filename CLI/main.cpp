#include <iostream>
#include <boost/program_options.hpp>

#include "SimpleCVConfig.h"
#include "png.h"
#include "zlib.h"

#include "PNGLoader.h"

namespace po = boost::program_options;

int main(int argc, const char* argv[])
{
	std::string inputPath;
	std::string outputPath;

	// Declare the supported options.
	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "produce help message")
		("version", "print version information")
		("input-file", po::value<std::string>(&inputPath)->required(), "input file path")
		("output-file", po::value<std::string>(&outputPath)->required(), "output file path")
		;

	po::positional_options_description pos_options_desc;
	pos_options_desc
		.add("input-file", 1)
		.add("output-file", 1);

	po::variables_map vm;

	try {
		po::store(po::command_line_parser(argc, argv).options(desc).positional(pos_options_desc).run(), vm);

		if (vm.count("help"))
		{
			std::cout << desc << std::endl;
			return 1;
		}

		if (vm.count("version"))
		{
			std::cout << "This is SimpleCV version v" << SimpleCV_VERSION_STRING.c_str() << std::endl;
			std::cout << "Compiled with libpng " << PNG_LIBPNG_VER_STRING << " using " << png_libpng_ver << std::endl;
			std::cout << "Compiled with zlib " << ZLIB_VERSION << " using " << zlib_version << std::endl;
			return 1;
		}

		po::notify(vm);

		IO::PNG::load(vm["input-file"].as<std::string>());
	}
	catch (po::required_option& e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
		return -1;
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
		return -1;
	}

	return 0;
}