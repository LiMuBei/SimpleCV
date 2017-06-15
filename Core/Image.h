#pragma once

#include <vector>

namespace SimpleCV {
	namespace Core {

		class Image
		{
		public:
			Image();
			Image(const Image& image);
			Image(int width, int height, unsigned int value = 0);
			Image(int width, int height, const std::vector<unsigned int>& data);

			int getWidth() const;
			int getHeight() const;

			unsigned int getPixel(int x, int y) const;			
			const std::vector<unsigned int>& getBuffer() const;

			void setPixel(int x, int y, unsigned int value);
			void setPixel(int x, int y, unsigned int r, unsigned int g, unsigned int b, unsigned int a);

			void resize(int width, int height);

		private:
			int width;
			int height;

			std::vector<unsigned int> pixels;
		};

	} // Core
} // SimpleCV