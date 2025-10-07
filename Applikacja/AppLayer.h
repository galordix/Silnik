#pragma once
#include "Silnik/Layer.h"
#include "Renderer/Renderer.h"
#include "Silnik/Scene.h"
#include <memory>
class AppLayer : public Engine::Layer
{
    std::shared_ptr<Engine::Scene> _scene = nullptr;
    Engine::Shader _shader;
    Engine::VertexArray _vertexArray;
    Engine::VertexBuffer _vertexBuffer;
    Engine::ElementBuffer _elementBuffer;

public:
    AppLayer();
    virtual void onUpdate(float deltaTime) override;
    virtual void onRender() override;
};

