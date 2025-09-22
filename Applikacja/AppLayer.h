#pragma once
#include "Silnik/Layer.h"
#include "Silnik/Renderer.h"
#include "Silnik/Scene.h"
#include <memory>
class AppLayer : public Engine::Layer
{
    std::shared_ptr<Engine::Scene> _scene = nullptr;
    unsigned int _shader = 0;
    unsigned int _vertexArray = 0;
    unsigned int _vertexBuffer = 0;
    unsigned int _elementBuffer = 0;

public:
    AppLayer();
    virtual void onUpdate(float deltaTime) override;
    virtual void onRender() override;
};

