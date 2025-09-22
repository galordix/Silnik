#pragma once

#include "glm/gtc/quaternion.hpp"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
struct Vertex
{
	glm::vec3 position; // Position coordinates
	glm::vec3 normal;
	glm::vec4 colour; // Colour value
	glm::vec2 texCoords; // Texture coordinatess
	
	
	

	
	Vertex(float x = 0.0f, float y = 0.0f, float z = 0.0f,
		float nx = 0.0f, float ny = 0.0f, float nz = 0.0f,
		float s = 0.0f, float t = 0.0f,
		float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.0f
		)
		: position(x, y, z),
		texCoords(s, t),
		colour(r, g, b, a),
		normal(nx,ny,nz)
	{}
	
};