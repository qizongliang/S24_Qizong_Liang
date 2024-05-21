#include "Notreal.h"
#include <iostream>


class MyGame : public Notreal::NotrealApplication
{
	virtual void Initialize() override 
	{

	}

	virtual void OnUpdate() override
	{
		//Notreal::Renderer::Draw(pic, x, 100);
		//std::cout << "window width "<< Notreal::NotrealWindow::GetWindow()->GetWidth() << "window height " << Notreal::NotrealWindow::GetWindow()->GetHeight() << std::endl;
	}
private:

};

START_GAME(MyGame)