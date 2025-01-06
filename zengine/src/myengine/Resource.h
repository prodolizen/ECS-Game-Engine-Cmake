#pragma once
#include <iostream>
#include <rend/rend.h>
#include <memory>

namespace zengine{	struct Resources;	struct Resource
	{
		virtual void onLoad() = 0;
		std::string getPath() const;
	private:
		std::string m_path;
		void load();
		friend struct zengine::Resources;
	};} 