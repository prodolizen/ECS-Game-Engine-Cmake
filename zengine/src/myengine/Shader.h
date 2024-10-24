#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>

struct Mesh;

struct Shader
{
	Shader(std::string vertPath, std::string fragPath);
	void render(Mesh* _mesh);
	void setUniform(std::string uniform, glm::vec4 value);
	void setUniform(std::string uniform, int value);
	void setUniform(std::string uniform, glm::mat4 value);
	GLuint id();




private:
	GLuint m_id;
	std::string m_vertSrc;
	std::string m_fragSrc;
};

#endif // SHADER_H