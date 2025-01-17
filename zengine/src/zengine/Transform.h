#pragma once
#include <rend/rend.h>
#include "Component.h"

namespace zengine
{
	struct Transform : Component
	{
		glm::vec3 getPosition();
		glm::vec3 getRotation();
		glm::vec3 getScale();

		void setPosition(glm::vec3 position);	
		void setRotation(glm::vec3 rotation);
		void setScale(glm::vec3 scale);

		glm::mat4 getModel();

		void onInitialize();

	private:
		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;
	};
}