#include "TriangleRenderer.h"
#include "Entity.h"
#include "Texture.h"
#include "Core.h"
#include "Resources.h"
#include "Transform.h"

namespace zengine
{
	/*TriangleRenderer::TriangleRenderer()
		: m_shader("../src/myengine/vertShader.txt", "../src/myengine/fragShader.txt")
		, m_mesh("../models/curuthers/curuthers.obj")
	{
	}*/

	void TriangleRenderer::onInitialize()
	{
		printf("shsahahdsjkahdjkasd");
		m_shader = std::make_shared<rend::Shader>(rend::TEXTURE_SHADER);
		m_mesh = std::make_shared<rend::Mesh>(rend::TRIANGLE_MESH);
		m_texture = getEntity()->getCore()->getResources()->load<Texture>("../assets/triangle/triangleTexture.png");
		//std::cout << "Loaded texture path: " << m_texture->getPath() << std::endl;
	}
	void TriangleRenderer::onDisplay() //render a simple triangle on the screen
	{
		if (!m_texture)
			return;
		//m_shader.set_mesh(m_mesh);
		
		//m_shader.setUniform("u_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f));
		//m_shader.setUniform("u_Model", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -10)));
		//m_shader.render(&m_mesh);
		glm::mat4 model(1.0f);
		model = getEntity()->getTransform()->getModel();
		m_shader->uniform("u_Projection", glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f));
		m_shader->uniform("u_Model", model);
		m_shader->uniform("u_Texture", *m_texture->m_texture);
		m_shader->attribute("a_Position", *m_mesh->positions());
		m_shader->attribute("a_TexCoord", *m_mesh->texcoords());
		m_shader->depth_test(true);
		m_shader->render();
	
		printf("Rendering\n");
	}
	void TriangleRenderer::setTexture(std::shared_ptr<Texture> texture)
	{
		m_texture = texture;
	}
}