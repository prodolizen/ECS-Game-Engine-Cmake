#include "TriangleRenderer.h"
#include <glm/ext.hpp>

namespace zengine
{
	TriangleRenderer::TriangleRenderer()
		: m_shader("../src/myengine/vertShader.txt", "../src/myengine/fragShader.txt")
		, m_mesh("../models/curuthers/curuthers.obj")
	{
	}

	void TriangleRenderer::onInitialize()
	{
	}
	void TriangleRenderer::onDisplay()
	{
		
		//m_shader.set_mesh(m_mesh);
		
		m_shader.setUniform("u_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f));
		m_shader.setUniform("u_Model", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -10)));
		m_shader.render(&m_mesh);

		printf("Rendering\n");
	}
}