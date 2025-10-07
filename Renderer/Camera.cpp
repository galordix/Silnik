#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
glm::mat4 Camera::GetViewMatrix()
{
    glm::mat4 view;
    view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f));
    return view;
}
