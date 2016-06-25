//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#ifndef CLEARN_IMAGELOADER_H
#define CLEARN_IMAGELOADER_H

#include "ImageInfo.h"

class ImageLoader {
public:
	virtual ~ImageLoader(){}
	virtual ImageInfo loadImage(const char* imageFile) = 0;
	virtual ImageInfo freeImage(const ImageInfo& imageInfo) = 0;
};


#endif //CLEARN_IMAGELOADER_H
