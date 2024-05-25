#pragma once

#include "Notreal.h"
#include <cstdlib>
#include <time.h> 
#include <string>
#include <vector> 

class MyGame : public Notreal::NotrealApplication
{
	//x = 0 left xPacMan = 900
	//y = 0 down yPacMan = 700
	// x = 900 right xPacMan = 0
	// y = 700 up yPacMan = 0
	void OnKeyPress(const Notreal::KeyPressed& event){
		if (event.GetKeyCode() == NOTREAL_KEY_RIGHT) {

			xPacMan += 100;
			directionPac = "r";
			// outofbound
		}
		if (event.GetKeyCode() == NOTREAL_KEY_LEFT) {
			xPacMan -= 100;
			directionPac = "l";
			// outofbound
		}
		if (event.GetKeyCode() == NOTREAL_KEY_UP) {
			yPacMan += 100;
			directionPac = "u";
			// outofbound
		}
		if (event.GetKeyCode() == NOTREAL_KEY_DOWN) {
			yPacMan -= 100;
			directionPac = "d";
			// outofbound
		}
		if (monRest == 2) {
			chasePlayer();
			monRest = 0;
		}
		monRest += 1;
	}
	void generateBurger() 
	{
		srand(time(0));

		for (int i = 0; i < 5; i++) {
			int bYtemp = rand() % yburgArr.size();
			int bXtemp = rand() % xburgArr.size();

			yBurg[i] = yburgArr[bYtemp];
			yburgArr.erase(yburgArr.begin()+bYtemp, yburgArr.begin() + bYtemp +1);

			
			xBurg[i] = xburgArr[bXtemp];
			xburgArr.erase(xburgArr.begin()+bXtemp, xburgArr.begin() + bXtemp+1);

		}
		for (int i = 0; i < 5; i++) {
			std::cout << yBurg[i]<<" "<< xBurg[i] << std::endl;
		}
	}
	
	void detectGameOver()
	{
		if (burgAte == 5) {
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
	void ateBurger() {
		for (int i = 0; i < 5; i++) {
			if (xPacMan == xBurg[i] && yPacMan == yBurg[i])
			{
				burgAte += 1;

				std::cout << "Burger " << xBurg[i] << " " << yBurg[i] << std::endl;
				std::cout << "Pacman " << xPacMan << " " << yPacMan << std::endl;
				xBurg[i] = -10000;
				yBurg[i] = -10000;
			}
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

			
			if (directionPac == "r") {
				Notreal::Image picpac{ "../Assets/pacmanright.png" };
				Notreal::Renderer::Draw(picpac, xPacMan, yPacMan);
			}else if (directionPac == "d") {
				Notreal::Image picpac{ "../Assets/pacmandown.png" };
				Notreal::Renderer::Draw(picpac, xPacMan, yPacMan);
			}else if (directionPac == "u") {
				Notreal::Image picpac{ "../Assets/pacmanup.png" };
				Notreal::Renderer::Draw(picpac, xPacMan, yPacMan);
			}else if (directionPac == "l") {
				Notreal::Image picpac{ "../Assets/pacmanleft.png" };
				Notreal::Renderer::Draw(picpac, xPacMan, yPacMan);
			}
			for (int i = 0; i < 5; i++) {
				Notreal::Image picbg{ "../Assets/hamburger.png" };
				Notreal::Renderer::Draw(picbg, xBurg[i], yBurg[i]);
			}
			Notreal::Image picmon{ "../Assets/saladmonster.png" };
			Notreal::Renderer::Draw(picmon, xMon, yMon);
			ateBurger();
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
	std::string directionPac = "r";


	int xBurg[5]{0,0,0,0,0};
	int yBurg[5]{0,0,0,0,0};
	
	int xMon{900};
	int yMon{700};

	std::vector<int> yburgArr = { 100, 200, 300, 400, 500,600 };
	std::vector<int> xburgArr = { 100, 200, 300, 400, 500,600,700,800 };
	int burgAte{ 0 };

	int monRest{ 0 };
	bool gameover{ false };
	bool win{ false };

	
};

START_GAME(MyGame)