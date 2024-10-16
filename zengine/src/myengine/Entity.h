#include <iostream>
struct Entity
{
	std::shared_ptr<T> addComponent<T>();
	void kill();
private:
	void tick();
	void display();
	std::vector < std::shared_ptr<Component> m_components;
	bool m_alive;
	std::weak_ptr<Core> m_core;
	std::weak_ptr<Entity> m_self;
}