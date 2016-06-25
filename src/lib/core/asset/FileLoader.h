//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#ifndef FILE_LOADER_H
#define FILE_LOADER_H

struct AssetFile {
	AssetFile(long length, const void* data, const void* handler)
		:length(length), data(data), handler(handler){}
	AssetFile()
		:length(0), data(0), handler(0){}

	const long length;
	const void* data = 0;
	const void* handler = 0;
};

class FileLoader {
public:
	virtual ~FileLoader(){}
	virtual AssetFile loadAsset(const char* path) = 0;
	virtual void releaseAsset(const AssetFile* asset) = 0;
};

#endif