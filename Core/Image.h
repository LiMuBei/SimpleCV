#pragma once

#include <vector>

namespace SimpleCV {
	namespace Core {

		class Image
		{
		public:
			Image(const Image& image);
			Image(const int width, const int height, const int value = 0);
			Image(const int width, const int height, const std::vector<long>& data);

			int getWidth() const;
			int getHeight() const;

			long getPixel(const int x, const int y) const;
			const std::vector<long>& getBuffer() const;

		private:
			int width;
			int height;

			std::vector<long> pixels;
		};

	} // Core
} // SimpleCV