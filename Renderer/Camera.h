#pragma once
#include <glm/glm.hpp>
class Camera
{
	glm::mat4 GetViewMatrix();
private:
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	glm::mat4 viewProjectionMatrix;
};

