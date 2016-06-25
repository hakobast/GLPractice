//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#ifndef CLEARN_IMAGEINFO_H
#define CLEARN_IMAGEINFO_H


class ImageInfo {
public:
	unsigned char* data;
	int width;
	int height;
	int channels;

	bool success(){
		return data != 0;
	}
};


#endif //CLEARN_IMAGEINFO_H
