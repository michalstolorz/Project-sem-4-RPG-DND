#include "Turn.h"



Turn::Turn()
{
}

void Turn::in_game_turn(Postac *tab_characters[4], vector<int> tab_initiative, RenderWindow &app_window)
{
	Vector2i dead_characters_coordinates;
	dead_characters_coordinates.x = 0;
	dead_characters_coordinates.y = 0;
	bool main_condition = true, sub_condition;
	int counter = 0, id, excluded_list_counter = 0;
	Event event;
	Roll_Dice dice;
	vector<Event> events;
	drawing draw_object;
	terminal term;
	fill_what_happend_in_battle();
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
	while (main_condition)
	{
		sub_condition = true;
		for (int i = 0; i < 4; i++)
			if (tab_characters[i]->get_initiative() == tab_initiative[counter])
			{
				id = tab_characters[i]->get_id_number();
				break;
			}
		if ((id < 3 && tab_characters[id]->check_if_alive()) || id == 3)
		{
			if (id != 3 && tab_characters[id]->check_devil_mark())
			{
				tab_characters[id]->HP -= dice.roll_d6() + dice.roll_d6() + dice.roll_d6();
				tab_characters[id]->check_if_died();
			}
			if ((id < 3 && tab_characters[id]->check_if_alive()) || id == 3)
			{
				is_game_over(app_window, tab_characters, main_condition, sub_condition);
				if (game_over == 2)
					term.draw_you_lose(app_window);
			}
			while (sub_condition)
			{
				if ((id < 3 && !tab_characters[id]->check_if_alive()))
					sub_condition = false;
				if (tab_characters[3]->get_confusion_status() && id == 3)
				{
					what_happend_in_battle.push_back("Przeciwnik traci ture z powodu magicznego zametu w jego glowie");
					sub_condition = false;
					tab_characters[3]->set_confusion_false();
				}
				else if (id == 3)
				{
					tab_characters[id]->attack(app_window, tab_characters, what_happend_in_battle);
					sub_condition = false;
					while (app_window.pollEvent(event))
						events.push_back(event);
					events.clear();
				}
				while (app_window.pollEvent(event))
				{
					if (event.type == Event::KeyPressed)
					{
						if (Keyboard::isKeyPressed(Keyboard::Num1))
						{
							tab_characters[id]->movement(app_window, tab_characters, what_happend_in_battle);
						}
						else if (Keyboard::isKeyPressed(Keyboard::Num2))
						{
							tab_characters[id]->attack(app_window, tab_characters, what_happend_in_battle);
							is_game_over(app_window, tab_characters, main_condition, sub_condition);
						}
						else if (Keyboard::isKeyPressed(Keyboard::Num3))
						{
							sub_condition = false;
						}
					}
				}
				for (int i = 0; i < 3; i++)
				{
					tab_characters[i]->check_if_died();
					if (!tab_characters[i]->check_if_alive())
					{
						for (int j = 0; j < 3; j++)
							tab_characters[j]->excluded_character_list[i] = i;
						tab_characters[i]->set_co_character(dead_characters_coordinates);
						tab_characters[i]->set_hitbox_move_error_character(dead_characters_coordinates);
					}
				}
				draw_object.draw_terrain(app_window);
				draw_object.rerender(app_window, tab_characters);
				term.draw_what_happend_terminal(app_window, what_happend_in_battle);
				if (id != 3 && tab_characters[id]->check_if_alive())
				{
					term.draw_string(app_window, tab_characters[id]->get_name(), term.get_tab_co_name(), 30);
					term.draw_string(app_window, term.get_HP_string(), term.get_tab_co_HP_string(), 30);
					term.draw_string(app_window, to_string(tab_characters[id]->HP), term.get_tab_co_HP_number(), 30);
					term.draw_action_menu(app_window);
				}
				if (game_over == 1)
					term.draw_you_win(app_window);
				else if (game_over == 2)
					term.draw_you_lose(app_window);
				app_window.display();
			}
		}
		counter++;
		if (counter == 4)
		{
			counter = 0;
			for (int i = 0; i < 4; i++)
			{
				tab_characters[i]->reset_actions();
				tab_characters[i]->reset_original_speed();
			}
		}
	}
	//cout << "cos nie gra" << endl;
	return;
}

void Turn::is_game_over(RenderWindow &app_window, Postac *tab_characters[4], bool &main_condition, bool &sub_condition)
{
	if (tab_characters[3]->HP <= 0)
	{
		game_over = 1;
		main_condition = false;
		sub_condition = false;
	}
	else if (tab_characters[0]->HP <= 0 && tab_characters[1]->HP <= 0 && tab_characters[2]->HP <= 0)
	{
		game_over = 2;
		main_condition = false;
		sub_condition = false;
	}
	return;
}


void Turn::fill_what_happend_in_battle()
{
	what_happend_in_battle.push_back("Straszliwe monstrum wyszlo z leza");
	what_happend_in_battle.push_back("Bohaterowie sa w pelni gotowi");
	what_happend_in_battle.push_back("Niech zacznie sie bitwa");
	return;
}

vector<string> Turn::get_what_happend_in_battle()
{
	return what_happend_in_battle;
}

Turn::~Turn()
{
}