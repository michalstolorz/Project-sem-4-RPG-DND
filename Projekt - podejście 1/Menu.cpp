#include "Menu.h"

Menu::Menu()
{
}

void Menu::show_menu(RenderWindow & app_window, Postac *tab_characters[4])
{
	bool forward_condition = true;
	drawing draw_object;
	try
	{
		draw_object.load_textures();
	}
	catch (int)
	{
		cout << "Zle wczytane tekstury, wychodzenie z programu" << endl;
		system("pause");
		exit(0);
	}
	draw_object.load_sprites();
	Event event;
	bool button_condition = true;
	vector<Vector2i> tab_co_characters;
	vector<Vector2i> tab_co_num_buttons_characters;
	vector<Vector2i> tab_co_choice_num_buttons_characters;
	vector<Vector2i> tab_co_enemies;
	int enemies_co_x[5] = { 0, 400, 700, 900, 1200 };
	int enemies_co_y[5] = { 100, 150, 200, 150, 100 };
	int enemies_co_num_button_x[5] = { 170, 520, 770, 1020, 1370 };
	vector<Vector2i> tab_co_num_buttons_enemies;
	vector<Vector2i> tab_co_choice_num_buttons_enemies;
	vector<int> tab_choices;
	Vector2i bufor_co;
	for (int i = 1; i < 6; i++)
	{
		bufor_co.x = 233 * i + 55 * (i - 1);
		bufor_co.y = 400;
		tab_co_characters.push_back(bufor_co);
		bufor_co.y = 520;
		tab_co_num_buttons_characters.push_back(bufor_co);
		if (i < 4)
		{
			bufor_co.x = 700 + (i - 1) * 70;
			bufor_co.y = 700;
			tab_co_choice_num_buttons_characters.push_back(bufor_co);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		bufor_co.x = enemies_co_x[i];
		bufor_co.y = enemies_co_y[i];
		tab_co_enemies.push_back(bufor_co);
		bufor_co.x = enemies_co_num_button_x[i];
		bufor_co.y = 520;
		tab_co_num_buttons_enemies.push_back(bufor_co);
		if (i < 1)
		{
			bufor_co.x = 700;
			bufor_co.y = 700;
			tab_co_choice_num_buttons_enemies.push_back(bufor_co);
		}
	}
	//
	int clear_condition = 1;
	vector<Event> events;
	//
	while (forward_condition)
	{
		draw_object.draw_terrain_blur(app_window);
		draw_object.draw_choose_the_party(app_window);
		draw_object.draw_choose_an_enemy(app_window);
		draw_object.draw_ready_for_battle(app_window);
		if (Keyboard::isKeyPressed(Keyboard::Num2))
		{
			tab_choices.clear(); 
			enemies_screen(app_window, draw_object, tab_characters, tab_co_enemies, tab_co_num_buttons_enemies, tab_choices, tab_co_choice_num_buttons_enemies);
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Num1))
		{
			tab_choices.clear(); 
			characters_screen(app_window, draw_object, tab_characters, tab_co_characters, tab_co_num_buttons_characters, tab_choices, tab_co_choice_num_buttons_characters);
		}
		if (Keyboard::isKeyPressed(Keyboard::Num3))
		{
			clear_condition = 2;
			forward_condition = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			app_window.close();
			exit(0);
		}
		app_window.display();
		if (clear_condition == 2)
		{
			while (app_window.pollEvent(event))
				events.push_back(event);
			events.clear();
		}
	}
	return;
}

void Menu::enemies_screen(RenderWindow &app_window, drawing draw_object, Postac *tab_characters[4], vector<Vector2i> tab_co_enemies, vector<Vector2i> tab_co_num_buttons_enemies, vector<int> tab_choices, vector<Vector2i> tab_co_choice_num_buttons_enemies)
{
	bool button_condition = true;
	Event event;
	Vector2i bufor_co;
	int clear_condition = 1;
	vector<Event> events;
	while (button_condition)
	{
		draw_object.draw_terrain_blur(app_window);
		draw_object.draw_blue_dragon(app_window, tab_co_enemies[0]);
		draw_object.draw_fire_gigant(app_window, tab_co_enemies[1]);
		draw_object.draw_devil(app_window, tab_co_enemies[2]);
		draw_object.draw_earth_elemental(app_window, tab_co_enemies[3]);
		draw_object.draw_shield_guardian(app_window, tab_co_enemies[4]);
		draw_object.draw_button1(app_window, tab_co_num_buttons_enemies[0]);
		draw_object.draw_button2(app_window, tab_co_num_buttons_enemies[1]);
		draw_object.draw_button3(app_window, tab_co_num_buttons_enemies[2]);
		draw_object.draw_button4(app_window, tab_co_num_buttons_enemies[3]);
		draw_object.draw_button5(app_window, tab_co_num_buttons_enemies[4]);
		draw_object.draw_your_choice(app_window);
		if (tab_choices.size())
		{
			if (tab_choices[0] == 1)
				draw_object.draw_button1(app_window, tab_co_choice_num_buttons_enemies[0]);
			else if (tab_choices[0] == 2)
				draw_object.draw_button2(app_window, tab_co_choice_num_buttons_enemies[0]);
			else if (tab_choices[0] == 3)
				draw_object.draw_button3(app_window, tab_co_choice_num_buttons_enemies[0]);
			else if (tab_choices[0] == 4)
				draw_object.draw_button4(app_window, tab_co_choice_num_buttons_enemies[0]);
			else if (tab_choices[0] == 5)
				draw_object.draw_button5(app_window, tab_co_choice_num_buttons_enemies[0]);
		}
		if (clear_condition)
		{
			while (app_window.pollEvent(event))
				events.push_back(event);
			events.clear();
			clear_condition = 0;
		}
		while (app_window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				if (tab_choices.size() <= 0 || event.key.code == Keyboard::BackSpace)
				{
					if (event.key.code == Keyboard::Num1)
						tab_choices.push_back(1);
					else if (event.key.code == Keyboard::Num2)
						tab_choices.push_back(2);
					else if (event.key.code == Keyboard::Num3)
						tab_choices.push_back(3);
					else if (event.key.code == Keyboard::Num4)
						tab_choices.push_back(4);
					else if (event.key.code == Keyboard::Num5)
						tab_choices.push_back(5);
					else if (event.key.code == Keyboard::BackSpace)
						if (!tab_choices.empty())
							tab_choices.pop_back();
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			if (tab_choices.size())
			{
				if (tab_choices[0] == 1)
				{
					Blue_Dragon *wsk_blue_dragon;
					wsk_blue_dragon = new Blue_Dragon;
					tab_characters[3] = wsk_blue_dragon;
				}
				else if (tab_choices[0] == 2)
				{
					Fire_Gigant *wsk_fire_gigant;
					wsk_fire_gigant = new Fire_Gigant;
					tab_characters[3] = wsk_fire_gigant;
				}
				else if (tab_choices[0] == 3)
				{
					Devil *wsk_devil;
					wsk_devil = new Devil;
					tab_characters[3] = wsk_devil;
				}
				else if (tab_choices[0] == 4)
				{
					Earth_Elemental *wsk_earth_elemental;
					wsk_earth_elemental = new Earth_Elemental;
					tab_characters[3] = wsk_earth_elemental;
				}
				else if (tab_choices[0] == 5)
				{
					Shield_Guardian *wsk_shield_guardian;
					wsk_shield_guardian = new Shield_Guardian;
					tab_characters[3] = wsk_shield_guardian;
				}
			}
			if (tab_choices.size())
			{
				bufor_co.x = 1000;
				bufor_co.y = 300;
				tab_characters[3]->set_co_character(bufor_co);
				if (tab_choices[0] == 1)
					tab_characters[3]->set_hitbox_move_error_enemy_4x4(bufor_co); //ró¿ne dla ró¿nych wielkoœci wrogów
				else if (tab_choices[0] == 2 || tab_choices[0] == 4)
					tab_characters[3]->set_hitbox_move_error_enemy_3x3(bufor_co);
				else if (tab_choices[0] == 3)
					tab_characters[3]->set_hitbox_move_error_enemy_2x2(bufor_co);
				else if (tab_choices[0] == 5)
				{
					bufor_co.x = 1100;
					tab_characters[3]->set_hitbox_move_error_enemy_2x4(bufor_co);
				}
				tab_characters[3]->set_character_id_number(3);
			}
			button_condition = false;
		}
		app_window.display();
	}
	tab_choices.clear();
}

void Menu::characters_screen(RenderWindow &app_window, drawing draw_object, Postac *tab_characters[4], vector<Vector2i> tab_co_characters, vector<Vector2i> tab_co_num_buttons_characters, vector<int> tab_choices, vector<Vector2i> tab_co_choice_num_buttons_characters)
{
	bool button_condition = true;
	Event event;
	Vector2i bufor_co;
	int clear_condition = 1;
	vector<Event> events;
	while (button_condition)
	{
		draw_object.draw_terrain_blur(app_window);
		draw_object.draw_paladin(app_window, tab_co_characters[0]);
		draw_object.draw_ranger(app_window, tab_co_characters[1]);
		draw_object.draw_sorceress(app_window, tab_co_characters[2]);
		draw_object.draw_warrior(app_window, tab_co_characters[3]);
		draw_object.draw_monk(app_window, tab_co_characters[4]);
		draw_object.draw_button1(app_window, tab_co_num_buttons_characters[0]);
		draw_object.draw_button2(app_window, tab_co_num_buttons_characters[1]);
		draw_object.draw_button3(app_window, tab_co_num_buttons_characters[2]);
		draw_object.draw_button4(app_window, tab_co_num_buttons_characters[3]);
		draw_object.draw_button5(app_window, tab_co_num_buttons_characters[4]);
		draw_object.draw_your_choice(app_window);
		for (int i = 0; i < tab_choices.size(); i++)
		{
			if (tab_choices[i] == 1)
				draw_object.draw_button1(app_window, tab_co_choice_num_buttons_characters[i]);
			else if (tab_choices[i] == 2)
				draw_object.draw_button2(app_window, tab_co_choice_num_buttons_characters[i]);
			else if (tab_choices[i] == 3)
				draw_object.draw_button3(app_window, tab_co_choice_num_buttons_characters[i]);
			else if (tab_choices[i] == 4)
				draw_object.draw_button4(app_window, tab_co_choice_num_buttons_characters[i]);
			else if (tab_choices[i] == 5)
				draw_object.draw_button5(app_window, tab_co_choice_num_buttons_characters[i]);
		}
		if (clear_condition)
		{
			while (app_window.pollEvent(event))
				events.push_back(event);
			events.clear();
			clear_condition = 0;
		}
		while (app_window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				if (tab_choices.size() <= 2 || event.key.code == Keyboard::BackSpace)
				{
					if (event.key.code == Keyboard::Num1)
						tab_choices.push_back(1);
					else if (event.key.code == Keyboard::Num2)
						tab_choices.push_back(2);
					else if (event.key.code == Keyboard::Num3)
						tab_choices.push_back(3);
					else if (event.key.code == Keyboard::Num4)
						tab_choices.push_back(4);
					else if (event.key.code == Keyboard::Num5)
						tab_choices.push_back(5);
					else if (event.key.code == Keyboard::BackSpace)
						if (!tab_choices.empty())
							tab_choices.pop_back();
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			if (tab_choices.size() == 3)
			{
				for (int i = 0; i < tab_choices.size(); i++)
				{
					if (tab_choices[i] == 1)
					{
						Paladin *wsk_paladin;
						wsk_paladin = new Paladin;
						tab_characters[i] = wsk_paladin;
					}
					else if (tab_choices[i] == 2)
					{
						Ranger *wsk_ranger;
						wsk_ranger = new Ranger;
						tab_characters[i] = wsk_ranger;
					}
					else if (tab_choices[i] == 3)
					{
						Czarodziejka *wsk_sorceress;
						wsk_sorceress = new Czarodziejka;
						tab_characters[i] = wsk_sorceress;
					}
					else if (tab_choices[i] == 4)
					{
						Warrior *wsk_warrior;
						wsk_warrior = new Warrior;
						tab_characters[i] = wsk_warrior;
					}
					else if (tab_choices[i] == 5)
					{
						Monk *wsk_monk;
						wsk_monk = new Monk;
						tab_characters[i] = wsk_monk;
					}
				}
				for (int i = 0; i < tab_choices.size(); i++)
				{
					bufor_co.x = 420;
					bufor_co.y = 200 + 200 * i;
					tab_characters[i]->set_co_character(bufor_co);
					bufor_co.x = 500;
					tab_characters[i]->set_co_movement_marker(bufor_co);
					bufor_co.x = 400;
					tab_characters[i]->set_hitbox_move_error_character(bufor_co);
					tab_characters[i]->set_character_id_number(i);
				}
			}
			button_condition = false;
		}
		app_window.display();
	}
}

Menu::~Menu()
{
}
