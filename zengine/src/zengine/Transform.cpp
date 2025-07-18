#include "Transform.h"
#include "iostream"

namespace zengine
{
	glm::vec3 Transform::getPosition()
	{
		return m_position;
	}

	glm::vec3 Transform::getRotation()
	{
		return m_rotation;
	}

	glm::vec3 Transform::getScale()
	{
		return m_scale;
	}

	void Transform::setPosition(glm::vec3 position)
	{
		m_position = position;
	}

	void Transform::setRotation(glm::vec3 rotation)
	{
		m_rotation = rotation;
	}

	void Transform::setScale(glm::vec3 scale)
	{
		m_scale = scale;
	}

	glm::mat4 Transform::getModel()
	{
		//calculate the model matrix using the position and rotation of the model
		//this is then passed to the renderer class 
		glm::mat4 rtn(1.0f);
		rtn = glm::translate(rtn, m_position);
		rtn = glm::scale(rtn, m_scale);
		rtn = glm::rotate(rtn, m_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f)); // Rotate around Z-axis
		rtn = glm::rotate(rtn, m_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate around Y-axis
		rtn = glm::rotate(rtn, m_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f)); // Rotate around X-axis
		return rtn;
	}

	void Transform::onInitialize()
	{
		m_scale = glm::vec3(1,1,1);
	}
}
