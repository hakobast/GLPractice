//
// Created by Hakob Astvatsatryan on 4/26/16.
//

#include <stdio.h>
#include <fstream>

#include "WinFileLoader.h"

using namespace std;

WinFileLoader::~WinFileLoader() {
	printf("~WinFileLoader\n");
}

AssetFile WinFileLoader::loadAsset(const char* path) {
	if (path != NULL) {
		ifstream file(path, ios::in | ios::binary | ios::ate);
		if (file.is_open()) {
			file.seekg(0, ios::end);
			long length = file.tellg();
			char *contents = new char[length];
			file.seekg(0, ios::beg);
			file.read(contents, length);
			file.close();
			
			return AssetFile(length, contents, NULL);
		}
	}

	return AssetFile();
}

void WinFileLoader::releaseAsset(const AssetFile* asset) {
	if (asset != NULL && asset->data != NULL) {
		delete[] asset->data;
	}
}