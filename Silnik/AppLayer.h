#pragma once
#include "Layer.h"

class AppLayer : public Engine::Layer
{
    unsigned int shader = 0;
    unsigned int vertexArray = 0;
    unsigned int vertexBuffer = 0;
public:
    AppLayer();
    virtual void onUpdate(float deltaTime) override;
    virtual void onRender() override;
};

