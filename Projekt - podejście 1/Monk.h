#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "Postac.h"
#include "drawing.h"

using namespace std;
using namespace sf;

class Postac;
class Menu;
class drawing;
class Blue_Dragon;
class Czarodziejka;
class Monk;
class Ranger;
class Warrior;
class Paladin;

class Monk : public Postac
{
	//vector<Vector2f> tab_co_movement_marker;
	//vector<Vector2f> tab_co_monk;
	int current_location = 1;
	int id = 3;
public:
	Monk();
	virtual void movement(RenderWindow &app_window, drawing &draw_object, Postac *tab_characters[4]);
	vector<Vector2i> move_up(Vector2f bufor_wsp);
	vector<Vector2i> move_down(Vector2f bufor_wsp);
	vector<Vector2i> move_left(Vector2f bufor_wsp);
	vector<Vector2i> move_right(Vector2f bufor_wsp);
	//vector<Vector2f> get_tab_co_movement_markers();
	//vector<Vector2f> get_tab_co_monk();
	int get_id();
	~Monk();
};

