#include "Transform.h"

namespace zengine
{
	/*glm::vec3 Transform::getPosition()
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
	}*/

	void Transform::setPosition(glm::vec3 position)
	{
		m_position = position;
	}

	/*void Transform::setRotation(glm::vec3 rotation)
	{
		m_rotation = rotation;
	}*/

	void Transform::setRotation(float angle, glm::vec3 axis)
	{
		m_angle = angle;
		m_axis = axis;
	}

	void Transform::setScale(glm::vec3 scale)
	{
		m_scale = scale;
	}

	glm::mat4 Transform::model()
	{
		glm::mat4 mod(1.0f);
		mod = glm::translate(mod, m_position);
		mod = glm::scale(mod, m_scale);
		mod = glm::rotate(mod, m_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
		return mod;
	}

	void Transform::onInitialize()
	{
		m_scale = glm::vec3(1,1,1);
	}
}
