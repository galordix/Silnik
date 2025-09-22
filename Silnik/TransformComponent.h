#pragma once
#include "Vertex.h"


namespace Engine
{
	struct TransformComponent
	{
		glm::vec3 position;
		glm::quat angle;
		glm::vec3 scale;
	};
}