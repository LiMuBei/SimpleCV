//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "Core"

//VERY IMPORTANT - include this last
#include <boost/test/unit_test.hpp>

#include "Image.h"

using namespace SimpleCV::Core;

BOOST_AUTO_TEST_SUITE(BaseImageTests)

BOOST_AUTO_TEST_CASE(constructors)
{
	Image img1(100, 100);
	BOOST_REQUIRE(img1.getWidth() == 100);
	BOOST_REQUIRE(img1.getHeight() == 100);

	Image img2(100, 100);
	BOOST_REQUIRE(img1.getWidth() == img2.getWidth());
	BOOST_REQUIRE(img1.getHeight() == img2.getHeight());
}

BOOST_AUTO_TEST_CASE(buffer_access)
{
	Image img1(1, 1);
	BOOST_REQUIRE(img1.getPixel(0, 0) == 0);
	BOOST_CHECK_THROW(img1.getPixel(2, 0), std::out_of_range);
	BOOST_CHECK_THROW(img1.getPixel(0, 2), std::out_of_range);
	BOOST_CHECK_THROW(img1.getPixel(-1, 0), std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()