#include "Texture.h"
#include "iostream"

namespace zengine {

	void Texture::onLoad()
	{
		printf("hello");
		std::cout << "Texture.cpp no c_str " << getPath() << std::endl;
		std::cout << "Texture.cpp c_str " << std::string(getPath()).c_str() << std::endl;
		m_texture = std::make_shared<rend::Texture>(std::string(getPath()).c_str());
		std::cout << "dhusaidhsauidas" << std::endl;
	}
} 