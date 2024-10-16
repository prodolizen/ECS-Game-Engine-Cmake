#include <iostream>
struct Component
{
private:
	virtual void onTick();
	virtual void onDisplay();
	void tick();
	void display();
};