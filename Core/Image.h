#pragma once

#include <vector>

namespace SimpleCV {
	namespace Core {

		class Image
		{
		public:
			Image(const Image& image);
			Image(const int width, const int height, const int value = 0);

			int getWidth() const;
			int getHeight() const;

			int getPixel(const int x, const int y) const;
			const std::vector<int>& getBuffer() const;

		private:
			int width;
			int height;

			std::vector<int> pixels;
		};

	} // Core
} // SimpleCV