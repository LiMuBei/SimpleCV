//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "CoreModule"

//VERY IMPORTANT - include this last
#include <boost/test/unit_test.hpp>

#include "Image.h"

using namespace SimpleCV::Core;

BOOST_AUTO_TEST_CASE(constructors)
{
	Image img1(100, 100);
	BOOST_CHECK(img1.getWidth() == 100);
	BOOST_CHECK(img1.getHeight() == 100);
	BOOST_CHECK(img1.getPixel(0, 0) == 0);

	Image img2(100, 100);
	BOOST_CHECK(img1.getWidth() == img2.getWidth());
	BOOST_CHECK(img1.getHeight() == img2.getHeight());
}