#pragma once
#include <rend/rend.h>
#include <memory>
#include <string>
//#include <iostream>

namespace zengine{	struct Resources;	struct Resource
	{
		virtual void onLoad() = 0; //virtual void used by model and texture classes
		std::string getPath() const
		{
			//std::cout << "Resource Path: " << m_path << std::endl;
			return m_path;		
		}
	private:
		friend struct zengine::Resources;

		std::string m_path;
		void load()
		{
			onLoad();
		}
	};} 