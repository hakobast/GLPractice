//
// Created by Hakob Astvatsatryan on 5/28/16.
//

#ifndef CLEARN_ENGINE_H
#define CLEARN_ENGINE_H


#include "../asset/AssetLoader.h"
#include "../asset/RenderResourceManager.h"
#include "../input/InputManager.h"

class Engine {
public:
    Engine();
    ~Engine();
    static Engine& getInstance();
    InputManager& getInputManager();
    AssetLoader& getAssetLoader();
    RenderResourceManager& getRenderResourceManager();
private:
    static Engine* instance_;
    AssetLoader* assetLoader_;
    RenderResourceManager* renderResourceManager_;
    InputManager* inputManager_;
};


#endif //CLEARN_ENGINE_H
