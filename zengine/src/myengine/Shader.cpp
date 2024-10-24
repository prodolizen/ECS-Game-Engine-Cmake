#include "Shader.h"
#include <exception>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Mesh.h"
#include <fstream>
#include <iostream>
#include <glm/ext.hpp>





Shader::Shader(std::string vertPath, std::string fragPath)
{
	m_id = 0;
	{
		std::ifstream file(vertPath.c_str());
		if (!file.is_open())
		{
			throw std::exception();
		}
		std::string line;
		while (std::getline(file, line))
		{
			m_vertSrc += line + "\n";
		}
	}



	{
		std::ifstream file(fragPath.c_str());
		if (!file.is_open())
		{
			throw std::exception();
		}
		std::string line;
		while (std::getline(file, line))
		{
			m_fragSrc += line + "\n";
		}
	}
}





void render(Mesh* _mesh)
{





}





void Shader::setUniform(std::string uniform, glm::vec4 value)
{



	GLint loc = glGetUniformLocation(id(), uniform.c_str());



	glUseProgram(m_id);
	glUniform4f(loc, value.x, value.y, value.z, value.w);
}





void Shader::setUniform(std::string uniform, glm::mat4 value)
{
	GLint loc = glGetUniformLocation(id(), uniform.c_str());



	glUseProgram(m_id);
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}





void Shader::setUniform(std::string uniform, int value)
{



	GLint loc = glGetUniformLocation(id(), uniform.c_str());
	glUseProgram(m_id);

}





GLuint Shader::id()
{
	if (!m_id)
	{
		const GLchar* temp;





		GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		temp = m_vertSrc.c_str();
		glShaderSource(vertexShaderId, 1, &temp, NULL);
		glCompileShader(vertexShaderId);
		GLint success = 0;
		glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);





		if (!success)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH,
				&maxLength);
			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(vertexShaderId, maxLength,
				&maxLength, &errorLog[0]);
			std::cout << &errorLog.at(0) << std::endl;
		}





		// Create a new fragment shader, attach source code, compile it and check for errors.
		GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
		temp = m_fragSrc.c_str();
		glShaderSource(fragmentShaderId, 1, &temp, NULL);
		glCompileShader(fragmentShaderId);
		glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);





		if (!success)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShaderId, GL_INFO_LOG_LENGTH,
				&maxLength);
			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(fragmentShaderId, maxLength,
				&maxLength, &errorLog[0]);
			std::cout << &errorLog.at(0) << std::endl;
			throw std::exception();
		}





		// Create new shader program and attach our shader objects
		m_id = glCreateProgram();
		glAttachShader(m_id, vertexShaderId);
		glAttachShader(m_id, fragmentShaderId);






		// Ensure the VAO "position" attribute stream gets set as the first position
		// during the link.
		glBindAttribLocation(m_id, 0, "in_Position");
		glBindAttribLocation(m_id, 1, "a_TexCoord");
		glBindAttribLocation(m_id, 2, "a_Normal");








		// Perform the link and check for failure
		glLinkProgram(m_id);
		glGetProgramiv(m_id, GL_LINK_STATUS, &success);





		if (!success)
		{
			throw std::exception();
		}







		// Detach and destroy the shader objects. These are no longer needed
		// because we now have a complete shader program.
		glDetachShader(m_id, vertexShaderId);
		glDeleteShader(vertexShaderId);
		glDetachShader(m_id, fragmentShaderId);
		glDeleteShader(fragmentShaderId);
	}
	return m_id;
}