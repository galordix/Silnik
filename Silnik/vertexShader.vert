#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Color;

out vec4 VertexColor;
void main()
{
	VertexColor = vec4(Color, 1.0f);
	gl_Position = vec4(Position.x, Position.y, Position.z, 1.0f);
}