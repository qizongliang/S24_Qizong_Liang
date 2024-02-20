#include "Notreal.h"
#include <iostream>


class MyGame : public Notreal::NotrealApplication
{
	virtual void OnUpdate() override
	{
		std::cout << "engine is running" << std::endl;
	}
};

START_GAME(MyGame)