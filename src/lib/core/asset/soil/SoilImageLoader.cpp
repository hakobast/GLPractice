//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#include <cstdio>
#include "SoilImageLoader.h"
#include "../../../../dependency/soil/SOIL.h"

SoilImageLoader::~SoilImageLoader(){
	printf("~SoilImageLoader\n");
}

ImageInfo SoilImageLoader::loadImage(const char* imageFile){
	int width = 0, height = 0, channels = 0;
	unsigned char *img_data = SOIL_load_image(imageFile, &width, &height, &channels, SOIL_LOAD_AUTO);

	// reverting by y
	if(img_data){
		int i, j;
		for( j = 0; j*2 < height; ++j ) {
			int index1 = j * width * channels;
			int index2 = (height - 1 - j) * width * channels;
			for( i = width * channels; i > 0; --i ) {
				unsigned char temp = img_data[index1];
				img_data[index1] = img_data[index2];
				img_data[index2] = temp;
				++index1;
				++index2;
			}
		}
	}else{
		printf("Result: %s\n", SOIL_last_result());
	}

	ImageInfo info;
	info.data = img_data;
	info.width = width;
	info.height = height;
	info.channels = channels;

	return info;
}

ImageInfo SoilImageLoader::freeImage(const ImageInfo& imageInfo){
	SOIL_free_image_data(imageInfo.data);
}