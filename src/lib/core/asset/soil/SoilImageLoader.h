//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#ifndef CLEARN_SOILIMAGELOADER_H
#define CLEARN_SOILIMAGELOADER_H

#include "../ImageLoader.h"

class SoilImageLoader : public ImageLoader{
public:
	virtual ~SoilImageLoader();
	virtual ImageInfo loadImage(const char* imageFile);
	virtual ImageInfo freeImage(const ImageInfo& imageInfo);
};


#endif //CLEARN_SOILIMAGELOADER_H
