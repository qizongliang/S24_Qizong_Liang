#pragma once

#include "Notreal.h"
#include <cstdlib>
#include <time.h> 


class MyGame : public Notreal::NotrealApplication
{
	void OnKeyPress(const Notreal::KeyPressed& event){
		if (event.GetKeyCode() == NOTREAL_KEY_RIGHT)
			xPacMan += 100;
		if (event.GetKeyCode() == NOTREAL_KEY_LEFT)
			xPacMan -= 100;
		if (event.GetKeyCode() == NOTREAL_KEY_UP)
			yPacMan += 100;
		if (event.GetKeyCode() == NOTREAL_KEY_DOWN)
			yPacMan -= 100;
		if (monRest == 2) {
			chasePlayer();
			monRest = 0;
		}
		monRest += 1;
	}
	void generateBurger() 
	{
		srand(time(0));

		int yburgArr[7] = { 100, 200, 300, 400, 500,600 };
		yBurg = yburgArr[rand() % 7];

		int xburgArr[9] = { 100, 200, 300, 400, 500,600,700,800 };
		xBurg = xburgArr[rand() % 9];
	}
	void detectGameOver()
	{
		if (xPacMan == xBurg && yPacMan == yBurg) {
			gameover = true;
			win = true;
		}
		if (xPacMan == xMon && yPacMan == yMon) {
			gameover = true;
		}
	}
	void chasePlayer() 
	{
		if (yPacMan > yMon) {
			yMon += 100;
		}
		else if (yPacMan < yMon) {
			yMon -= 100;
		}
		else if (xPacMan < xMon) {
			xMon -= 100;
		}
		else if (xPacMan > xMon) {
			xMon += 100;
		}
	}
	virtual void Initialize() override 
	{
		generateBurger();

		SetKeyPressedCallback([this](const Notreal::KeyPressed& e) {OnKeyPress(e); });

	}

	virtual void OnUpdate() override
	{
		//Notreal::Image pic{"..Assets\\test.png"};
		if (!gameover) {
			Notreal::Image picBackGround{ "../Assets/bg.png" };
			Notreal::Renderer::Draw(picBackGround, 0, 0);

			Notreal::Image picbg{ "../Assets/hamburger.png" };
			Notreal::Image picpac{ "../Assets/pacman.png" };
			Notreal::Renderer::Draw(picbg, xBurg, yBurg);
			Notreal::Renderer::Draw(picpac, xPacMan, yPacMan);

			Notreal::Image picmon{ "../Assets/saladmonster.png" };
			Notreal::Renderer::Draw(picmon, xMon, yMon);
			
			detectGameOver();
		}
		else {

			if (win) 
			{
				Notreal::Image picBackGroundGameover{ "../Assets/win.png" };
				Notreal::Renderer::Draw(picBackGroundGameover, -10, -40);
			}
			else {
				Notreal::Image picBackGroundGameover{ "../Assets/lose.png" };
				Notreal::Renderer::Draw(picBackGroundGameover, -20,-80);
			}
		}

		//Notreal::Renderer::Draw(pic, x, 100);
		//std::cout << "window width "<< Notreal::NotrealWindow::GetWindow()->GetWidth() << "window height " << Notreal::NotrealWindow::GetWindow()->GetHeight() << std::endl;
	}
private:
	int xPacMan{ 0 };
	int yPacMan{ 0 };

	int xBurg{0};
	int yBurg{0};
	
	int xMon{900};
	int yMon{700};

	int monRest{ 0 };
	bool gameover{ false };
	bool win{ false };

	
};

START_GAME(MyGame)