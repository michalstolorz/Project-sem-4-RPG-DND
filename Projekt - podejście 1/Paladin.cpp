#include "Characters.h"

Paladin::Paladin()
{
	name = "Paladin";
	proficiency_bonus = 3;
	tab_statistics[strength] = 18; tab_statistics_mod[strength] = set_statistic_mod(tab_statistics[strength]); tab_saving_throws[strength] = tab_statistics_mod[strength];
	tab_statistics[dexterity] = 10; tab_statistics_mod[dexterity] = set_statistic_mod(tab_statistics[dexterity]); tab_saving_throws[dexterity] = tab_statistics_mod[dexterity];
	tab_statistics[constitution] = 14; tab_statistics_mod[constitution] = set_statistic_mod(tab_statistics[constitution]); tab_saving_throws[constitution] = tab_statistics_mod[constitution];
	tab_statistics[intelligence] = 9; tab_statistics_mod[intelligence] = set_statistic_mod(tab_statistics[intelligence]); tab_saving_throws[intelligence] = tab_statistics_mod[intelligence];
	tab_statistics[wisdom] = 8; tab_statistics_mod[wisdom] = set_statistic_mod(tab_statistics[wisdom]); tab_saving_throws[wisdom] = tab_statistics_mod[wisdom] + proficiency_bonus;
	tab_statistics[charisma] = 16; tab_statistics_mod[charisma] = set_statistic_mod(tab_statistics[charisma]); tab_saving_throws[charisma] = tab_statistics_mod[charisma] + proficiency_bonus;
	main_statistic_mod_for_attack = tab_statistics_mod[strength];
	main_statistic_mod_for_spell = tab_statistics_mod[charisma];
	set_initiative();
	speed = 30;
	remember_original_speed();
	HP = 67;
	max_HP = HP;
	AC = 21;
	action = 1;
	bonus_action = 1;
	is_dead = false;
	is_hasted = false;
	is_devil_marked = false;
	hp_lay_on_hands = 40; //8 * 5 -> piêciokrotnoœæ poziomu
	is_sacred_weapon_activated = false;
}

void Paladin::movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	drawing draw_object;
	terminal term;
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
	bool movement_condition = true;
	bool it_is_collision = false;
	Event event;
	Vector2i bufor_wsp;
	check_hitbox(tab_characters, it_is_collision);
	while (movement_condition)
	{
		draw_object.true_rerender(app_window, tab_characters, what_happend_in_battle, draw_object, id_number);
		if (it_is_collision)
			draw_object.draw_hitbox_move_error(app_window, tab_co_movement_marker.back());
		else
			draw_object.draw_movement_marker(app_window, tab_co_movement_marker.back());
		while (app_window.pollEvent(event))
			if (event.type == Event::KeyPressed)
				movement_switch(event, bufor_wsp, tab_characters, it_is_collision, current_location);
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			movement_condition = false;
			tab_co_movement_marker.clear();
			bufor_wsp.x = tab_co_character.back().x + 80;
			bufor_wsp.y = tab_co_character.back().y;
			tab_co_movement_marker.push_back(bufor_wsp);
			current_location = 1;
		}
		if (speed)
			if (!it_is_collision)
				if (Keyboard::isKeyPressed(Keyboard::Enter))
				{
					movement_condition = false;
					tab_co_character.back() = tab_co_movement_marker.back();
					set_hitbox_move_error_character(tab_co_character.back());
					tab_co_character.back().x += 20;
					tab_co_movement_marker.clear();
					bufor_wsp.x = tab_co_character.back().x + 80;
					bufor_wsp.y = tab_co_character.back().y;
					tab_co_movement_marker.push_back(bufor_wsp);
					current_location = 1;
					speed -= 5;
				}
		app_window.display();
	}
	return;
}

void Paladin::attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	bool forward_condition = true;
	Event event;
	int clear_condition = 1;
	vector<Event> events;
	string what_happend = "";
	terminal term;
	if (clear_condition)
	{
		while (app_window.pollEvent(event))
			events.push_back(event);
		events.clear();
		clear_condition = 0;
	}
	term.draw_action_menu_paladin(app_window);
	app_window.display();
	while (forward_condition)
	{
		while (app_window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Num1)) //atak
				{
					if (!action)
					{
						what_happend_in_battle.push_back("Akcja zostala juz wykonana");
						return;
					}
					Postac *current_character = new Warrior;
					Roll_Dice dice;
					int roll;
					if (is_sacred_weapon_activated)
					{
						if (check_range(tab_characters))
						{
							for (int i = 0; i < 2; i++)
							{
								roll = dice.roll_d20();
								if (is_hit_attack(roll + tab_statistics_mod[charisma], tab_characters[3]))
								{
									if (is_critical_hit(roll, current_character))
										tab_characters[3]->HP -= dice.roll_d8() * 2 + main_statistic_mod_for_attack;
									else
										tab_characters[3]->HP -= dice.roll_d8() + main_statistic_mod_for_attack;
									what_happend += "Trafienie ";
								}
								else
									what_happend += "Nie trafiono ";
							}
							what_happend_in_battle.push_back(what_happend);
							action--;
						}
						else
							what_happend_in_battle.push_back("Przeciwnik poza zasiegiem");
					}
					else
					{
						if (check_range(tab_characters))
						{
							for (int i = 0; i < 2; i++)
							{
								roll = dice.roll_d20();
								if (is_hit_attack(roll, tab_characters[3]))
								{
									if (is_critical_hit(roll, current_character))
										tab_characters[3]->HP -= dice.roll_d8() * 2 + main_statistic_mod_for_attack;
									else
										tab_characters[3]->HP -= dice.roll_d8() + main_statistic_mod_for_attack;
									what_happend += "Trafienie ";
								}
								else
									what_happend += "Nie trafiono ";
							}
							what_happend_in_battle.push_back(what_happend);
							action--;
						}
						else
							what_happend_in_battle.push_back("Przeciwnik poza zasiegiem");
					}
					delete current_character;
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num2)) //Sacred weapon
				{
					if (!action)
					{
						what_happend_in_battle.push_back("Akcja zostala juz wykonana");
						return;
					}
					if (is_sacred_weapon_activated)
					{
						what_happend_in_battle.push_back("Juz poswieciles swoja bron");
						return;
					}
					action--;
					is_sacred_weapon_activated = true;
					what_happend_in_battle.push_back("Poswiecono bron");
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num3)) //Lay on hands
				{
					if (!action)
					{
						what_happend_in_battle.push_back("Akcja zostala juz wykonana");
						return;
					}
					if (!hp_lay_on_hands)
					{
						what_happend_in_battle.push_back("Pula punktow do wyleczenia zostala wykorzystana");
						return;
					}
					if (heal(app_window, tab_characters, what_happend_in_battle))
					{
						action--;
						what_happend_in_battle.push_back("Leczenie powiodlo sie");
					}
					forward_condition = false;
				}
			}
		}
	}
	return;
}

bool Paladin::heal(RenderWindow &app_window, Postac * tab_characters[4], vector<string> &what_happend_in_battle)
{
	Event event;
	terminal term;
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
	vector<Event> events;
	bool forward_condition = true, clear_condition = true;
	string tab_names[3], terminal_bufor[3] = { "","","" };
	for (int i = 0; i < 3; i++)
	{
		if (!(excluded_character_list[i] == i))
		{
			terminal_bufor[i] = terminal_bufor[i] + to_string(i + 1) + ". " + tab_characters[i]->get_name() + "  " + to_string(tab_characters[i]->HP) + "    ";
			tab_names[i] = tab_characters[i]->get_name();
		}
	}
	int choice, how_much_to_heal, character_id_number[2], counter = 0;
	while (forward_condition)
	{
		while (app_window.pollEvent(event))
			if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Num1))
				{
					choice = 0;
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num2))
				{
					choice = 1;
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num3))
				{
					choice = 2;
					forward_condition = false;
				}
			}
		draw_object.true_rerender(app_window, tab_characters, what_happend_in_battle, draw_object, id_number);
		term.draw_action_menu_paladin(app_window);
		term.draw_heal_string(app_window);
		for (int i = 0; i < 3; i++)
			term.draw_paladin_heal_person(app_window, terminal_bufor[i], i);
		app_window.display();
	}
	if (tab_names[choice] == "Paladin")
	{
		how_much_to_heal = max_HP - HP;
		if (how_much_to_heal > hp_lay_on_hands)
		{
			HP += hp_lay_on_hands;
			hp_lay_on_hands = 0;
		}
		else
		{
			HP += how_much_to_heal;
			hp_lay_on_hands -= how_much_to_heal;
		}
		if (check_devil_mark())
			deactivate_devil_mark();
	}
	else
	{
		for (int i = 0; i < 3; i++)
			if (tab_names[i] != "Paladin")
			{
				character_id_number[counter] = i;
				counter++;
			}
		if (is_someone_in_range_to_heal(tab_characters, character_id_number))
		{
			how_much_to_heal = tab_characters[choice]->get_max_HP() - tab_characters[choice]->HP;
			if (how_much_to_heal > hp_lay_on_hands)
			{
				tab_characters[choice]->HP += hp_lay_on_hands;
				hp_lay_on_hands = 0;
			}
			else
			{
				tab_characters[choice]->HP += how_much_to_heal;
				hp_lay_on_hands -= how_much_to_heal;
			}
			if (tab_characters[choice]->check_devil_mark())
				tab_characters[choice]->deactivate_devil_mark();
		}
		else
		{
			what_happend_in_battle.push_back("Twoich towarzyszy nie ma w Twoim zasiegu, aby ich uleczyc");
			return false;
		}
	}
	return true;
}

bool Paladin::is_someone_in_range_to_heal(Postac * tab_characters[4], int character_id_number[2])
{
	Vector2i bufor_co = tab_co_movement_marker.back();
	for (int i = 1; i < 9; i++)
	{
		if (i == 1)
		{
			set_hitbox_move_error_marker(bufor_co);
			if (this->hitbox_move_error_marker->intersects(tab_characters[character_id_number[0]]->get_hitbox_move_error_character()) || this->hitbox_move_error_marker->intersects(tab_characters[character_id_number[1]]->get_hitbox_move_error_character()))
				return true;
		}
		if (i == 2)
		{
			bufor_co.y += movement_100;
			set_hitbox_move_error_marker(bufor_co);
			if (this->hitbox_move_error_marker->intersects(tab_characters[character_id_number[0]]->get_hitbox_move_error_character()) || this->hitbox_move_error_marker->intersects(tab_characters[character_id_number[1]]->get_hitbox_move_error_character()))
				return true;
		}
		if (i == 3 || i == 4)
		{
			bufor_co.x -= movement_100;
			set_hitbox_move_error_marker(bufor_co);
			if (this->hitbox_move_error_marker->intersects(tab_characters[character_id_number[0]]->get_hitbox_move_error_character()) || this->hitbox_move_error_marker->intersects(tab_characters[character_id_number[1]]->get_hitbox_move_error_character()))
				return true;
		}
		if (i == 5 || i == 6)
		{
			bufor_co.y -= movement_100;
			set_hitbox_move_error_marker(bufor_co);
			if (this->hitbox_move_error_marker->intersects(tab_characters[character_id_number[0]]->get_hitbox_move_error_character()) || this->hitbox_move_error_marker->intersects(tab_characters[character_id_number[1]]->get_hitbox_move_error_character()))
				return true;
		}
		if (i == 7 || i == 8)
		{
			bufor_co.x += movement_100;
			set_hitbox_move_error_marker(bufor_co);
			if (this->hitbox_move_error_marker->intersects(tab_characters[character_id_number[0]]->get_hitbox_move_error_character()) || this->hitbox_move_error_marker->intersects(tab_characters[character_id_number[1]]->get_hitbox_move_error_character()))
				return true;
		}
	}
	return false;
}

Paladin::~Paladin()
{
}
