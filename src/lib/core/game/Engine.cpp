//
// Created by Hakob Astvatsatryan on 5/28/16.
//

#include "Engine.h"
#include "../asset/win/WinAssetLoader.h"
#include "../../opengl/asset/OpenGLResourceManager.h"
#include "../input/sfml/SFMLInputManager.h"

Engine* Engine::instance_ = nullptr;

Engine& Engine::getInstance() {
    return *instance_;
}

Engine::Engine(){
    instance_ = this;

    inputManager_ = new SFMLInputManager;
    assetLoader_ = new WinAssetLoader;
    renderResourceManager_ = new OpenGLResourceManager(*assetLoader_);
}

Engine::~Engine(){
    delete assetLoader_;
    delete renderResourceManager_;
    delete inputManager_;
}

InputManager& Engine::getInputManager(){
    return *inputManager_;
}


AssetLoader& Engine::getAssetLoader(){
    return *assetLoader_;
}

RenderResourceManager& Engine::getRenderResourceManager(){
    return *renderResourceManager_;
}
