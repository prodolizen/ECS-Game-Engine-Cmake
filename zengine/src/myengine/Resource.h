#pragma once
#include <iostream>

struct Resource
{
	virtual void onLoad() = 0;
	std::string getPath() const;
private:
	std::string m_path;
	void load();
};