#pragma once

namespace Core  {

	class Image
	{
	public:
		Image();
		Image(const Image& image);

		int getWidth() const;
		int getHeight() const;

	private:
		int width;
		int height;
	};

}