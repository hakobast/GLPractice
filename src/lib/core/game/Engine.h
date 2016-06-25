//
// Created by Hakob Astvatsatryan on 5/28/16.
//

#ifndef CLEARN_ENGINE_H
#define CLEARN_ENGINE_H


#include "../asset/FileLoader.h"
#include "../asset/ImageLoader.h"
#include "../asset/RenderResourceManager.h"
#include "../input/InputManager.h"
#include "../window/WindowManager.h"

class Engine {
public:
    static Engine& getInstance();

    Engine();
    ~Engine();
    InputManager& getInputManager();
    WindowManager& getWindowManager();
    FileLoader& getAssetLoader();
    RenderResourceManager& getRenderResourceManager();

    virtual void run();
protected:
    static Engine* instance_;

    InputManager* inputManager_ = 0;
    WindowManager* windowManager_ = 0;
    FileLoader* assetLoader_ = 0;
	ImageLoader* imageLoader_ = 0;
    RenderResourceManager* renderResourceManager_ = 0;

    virtual void initSystems();
    virtual void gameLoop();
};


#endif //CLEARN_ENGINE_H
