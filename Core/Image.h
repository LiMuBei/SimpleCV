#pragma once

#include <vector>

namespace SimpleCV {
	namespace Core {

		class Image
		{
		public:
			Image();
			Image(const Image& image);
			Image(int width, int height, int value = 0);
			Image(int width, int height, const std::vector<long>& data);

			int getWidth() const;
			int getHeight() const;

			long getPixel(int x, int y) const;
			const std::vector<long>& getBuffer() const;

			void setPixel(int x, int y, long value);

			void resize(int width, int height);

		private:
			int width;
			int height;

			std::vector<long> pixels;
		};

	} // Core
} // SimpleCV