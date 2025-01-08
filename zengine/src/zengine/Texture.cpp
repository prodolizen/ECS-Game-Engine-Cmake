#include "Texture.h"

namespace zengine {

	void Texture::onLoad()
	{
		m_texture = std::make_shared<rend::Texture>(sys::string(getPath().c_str()));
	}
}
