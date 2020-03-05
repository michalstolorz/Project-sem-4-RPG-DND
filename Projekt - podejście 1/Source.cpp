#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "Characters.h"
#include "drawing.h"
#include "Menu.h"
#include "Turn.h"
#include "Roll_Dice.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow app_window(sf::VideoMode(1600, 1000, 32), "D&D");
	drawing all;
	Roll_Dice dice;
	try
	{
		all.load_textures();
	}
	catch (int)
	{
		cout << "Zle wczytane tekstury, wychodzenie z programu" << endl;
		system("pause");
		return 0;
	}
	all.load_sprites();
	Postac *tab_characters[4];
	Menu menu;
	Turn turn;
	Event event;
	menu.show_menu(app_window, tab_characters);
	vector<int> tab_initiative;
	for (int i = 0; i < 4; i++)
		tab_initiative.push_back(tab_characters[i]->get_initiative());
	sort(tab_initiative.rbegin(), tab_initiative.rend());
	for (int i = 0; i < 4; i++)
		if (dice.is_it_draw(tab_initiative))
			dice.same_initiative_solution(tab_initiative);
	//for (int i = 0; i < 4; i++) //linijka testowa
		//cout << tab_initiative[i] << endl; //linijka testowa
	while (app_window.isOpen())
	{
		all.draw_terrain(app_window);
		all.rerender(app_window, tab_characters);
		while (app_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				app_window.close();
		}
		turn.in_game_turn(tab_characters, tab_initiative, app_window);
		for(int i=0; i<4; i++)
			delete tab_characters[i];
		app_window.display();
		system("pause");
		return 1;
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			app_window.close();
			return 0;
		}
		app_window.display();
	}
	return 0;
}