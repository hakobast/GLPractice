//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#ifndef WIN_FILE_LOADER_H
#define WIN_FILE_LOADER_H

#include "../FileLoader.h"

class WinFileLoader : public FileLoader {
public:
	virtual ~WinFileLoader();
	virtual AssetFile loadAsset(const char* path);
	virtual void releaseAsset(const AssetFile* asset);
};

#endif