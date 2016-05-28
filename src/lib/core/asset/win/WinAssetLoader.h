//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#ifndef WIN_ASSET_LOADER_H
#define WIN_ASSET_LOADER_H

#include "../AssetLoader.h"

class WinAssetLoader : public AssetLoader {
public:
	virtual ~WinAssetLoader();
	virtual AssetFile loadAsset(const char* path);
	virtual void releaseAsset(const AssetFile* asset);
};

#endif