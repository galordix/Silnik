#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 normal;
layout (location = 4) in vec3 offset;

void main()
{
	gl_Position = vec4(Position.x + offset.x, Position.y + offset.y, Position.z + offset.z, 1.0f);
} 