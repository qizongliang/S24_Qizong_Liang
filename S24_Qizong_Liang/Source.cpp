#include "Notreal.h"
#include <iostream>


class MyGame : public Notreal::NotrealApplication
{
	virtual void Initialize() override 
	{
		my_window.Create(1000, 800);
	}

	virtual void OnUpdate() override
	{
		std::cout << "engine is running" << std::endl;
	}
private:
	Notreal::NotrealWindow my_window;

};

START_GAME(MyGame)