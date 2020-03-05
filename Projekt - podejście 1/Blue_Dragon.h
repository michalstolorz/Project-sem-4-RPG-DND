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

class Blue_Dragon : public Postac
{
	vector<Vector2i> tab_co_movement_marker;
	vector<Vector2i> tab_co_blue_dragon;
	int id = 6;
public:
	Blue_Dragon();
	vector<Vector2i> get_tab_co_movement_markers();
	vector<Vector2i> get_tab_co_blue_dragon();
	virtual void movement(RenderWindow &app_window, drawing &draw_object, Postac *tab_characters[4]);
	int get_id();
	~Blue_Dragon();
};

