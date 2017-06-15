//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "IO"

#include <random>
#include <map>
#include <utility>
#include <iostream>

//VERY IMPORTANT - include this last
#include <boost/test/unit_test.hpp>

#include "Image.h"
#include "PNGWriter.h"

namespace core = SimpleCV::Core;
namespace io = SimpleCV::IO;

BOOST_AUTO_TEST_SUITE(BaseWritingTests)

BOOST_AUTO_TEST_CASE(writeblank)
{
    const int IMAGE_SIZE = 500;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(IMAGE_SIZE / 2, 100);

    core::Image img = core::Image(IMAGE_SIZE, IMAGE_SIZE);
    std::map<std::pair<int, int>, unsigned int> hist;
    for (int i=0; i<1000000; ++i)
    {
        int x = static_cast<int>(std::round(dis(gen)));
        int y = static_cast<int>(std::round(dis(gen)));
        auto p = std::make_pair(x, y);
        hist[p] += 10;        
    }
    for (int x = 0; x < IMAGE_SIZE; ++x)
    {
        for (int y = 0; y < IMAGE_SIZE; ++y)
        {
            auto p = std::make_pair(x,y);
            auto value = hist[p];
            img.setPixel(x, y, value, value, value, 255);
        }
    }
    io::PNG::save("test.png", img);
    BOOST_REQUIRE(img.getWidth() == IMAGE_SIZE);
}

BOOST_AUTO_TEST_SUITE_END()