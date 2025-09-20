#pragma once
#include "Renderable.h"
#include "Vertex.h"

class Kwadrat :
    public Renderable
{
public:
    void Render() override;
private:
    Vertex vertexes[4];
    unsigned int indices[6];

    
};

