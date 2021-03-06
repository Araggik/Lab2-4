#include "stdafx.h"
#include "FreeImage.h"

extern "C" __declspec(dllexport) char* load_image(const char* filename, int& width, int& height)
{
	FREE_IMAGE_FORMAT form = FreeImage_GetFIFFromFilename(filename);
	FIBITMAP *bitmap=FreeImage_Load(form,filename);
	FIBITMAP *bitmap2;
	width = FreeImage_GetWidth(bitmap);
	height = FreeImage_GetHeight(bitmap);
	bitmap2=FreeImage_ConvertTo32Bits(bitmap);
	char* c =(char*) FreeImage_GetBits(bitmap2);
	return c;
	FreeImage_Unload(bitmap);
	FreeImage_Unload(bitmap2);
};


