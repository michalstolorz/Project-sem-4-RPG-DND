#include "Characters.h"


Czarodziejka::Czarodziejka()
{
	name = "Sorceress";
	proficiency_bonus = 3;
	tab_statistics[strength] = 10; tab_statistics_mod[strength] = set_statistic_mod(tab_statistics[strength]); tab_saving_throws[strength] = tab_statistics_mod[strength];
	tab_statistics[dexterity] = 14; tab_statistics_mod[dexterity] = set_statistic_mod(tab_statistics[dexterity]); tab_saving_throws[dexterity] = tab_statistics_mod[dexterity];
	tab_statistics[constitution] = 16; tab_statistics_mod[constitution] = set_statistic_mod(tab_statistics[constitution]); tab_saving_throws[constitution] = tab_statistics_mod[constitution] + proficiency_bonus;
	tab_statistics[intelligence] = 10; tab_statistics_mod[intelligence] = set_statistic_mod(tab_statistics[intelligence]); tab_saving_throws[intelligence] = tab_statistics_mod[intelligence];
	tab_statistics[wisdom] = 12; tab_statistics_mod[wisdom] = set_statistic_mod(tab_statistics[wisdom]); tab_saving_throws[wisdom] = tab_statistics_mod[wisdom];
	tab_statistics[charisma] = 18; tab_statistics_mod[charisma] = set_statistic_mod(tab_statistics[charisma]); tab_saving_throws[charisma] = tab_statistics_mod[charisma] + proficiency_bonus;
	main_statistic_mod_for_attack = tab_statistics_mod[strength];
	main_statistic_mod_for_spell = tab_statistics_mod[charisma];
	set_initiative();
	speed = 30;
	remember_original_speed();
	HP = 48; //do zmiany, patrz kartka
	max_HP = HP;
	AC = 10 + tab_statistics_mod[dexterity];
	spell_slots_1st = 4;
	spell_slots_2st = 3;
	spell_slots_3st = 2;
	spell_save_DC = 8 + main_statistic_mod_for_spell + proficiency_bonus;
	action = 1;
	bonus_action = 1;
	is_dead = false;
	is_hasted = false;
	is_devil_marked = false;
}

void Czarodziejka::movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
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

void Czarodziejka::attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	if (!action)
	{
		what_happend_in_battle.push_back("Akcja zostala juz wykonana");
		return;
	}
	int choice, clear_condition = 1;
	bool forward_condition = true;
	Event event;
	vector<Event> events;
	string what_happend = "";
	terminal term;
	term.draw_action_menu_sorceress(app_window);
	app_window.display();
	while (forward_condition)
		while (app_window.pollEvent(event))
			if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Num1))
				{
					choice = 1;
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num2))
				{
					choice = 2;
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num3))
				{
					choice = 3;
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num4))
				{
					choice = 4;
					forward_condition = false;
				}
			}
	if (clear_condition)
	{
		while (app_window.pollEvent(event))
			events.push_back(event);
		events.clear();
		clear_condition = 0;
	}
	switch (choice)
	{
	case 1:
	{
		Poison_spray(tab_characters, what_happend_in_battle);
		break;
	}
	case 2:
	{
		if (!spell_slots_1st == 0)
		{
			string teleport = "Teleport", fire_bolt = "Fire Bolt";
			choice = choose_spell(teleport, fire_bolt, app_window, tab_characters, what_happend_in_battle);
			if (choice == 1)
				Teleport(app_window, tab_characters);
			else
				Fire_bolt(tab_characters, what_happend_in_battle);
		}
		else
			what_happend_in_battle.push_back("Brak pierwszo poziomowych slotow");
		break;
	}
	case 3:
	{
		if (!spell_slots_2st == 0)
		{
			string haste = "Haste", magic_armor = "Magic Armor";
			choice = choose_spell(haste, magic_armor, app_window, tab_characters, what_happend_in_battle);
			if (choice == 1)
				Haste(app_window, tab_characters, what_happend_in_battle);
			else
				Magic_armor(what_happend_in_battle);
		}
		else
			what_happend_in_battle.push_back("Brak drugo poziomowych slotow");
		break;
	}
	case 4:
	{
		if (!spell_slots_3st == 0)
		{
			string confusion = "Confusion", lightning_bolt = "Lightning Bolt";
			choice = choose_spell(confusion, lightning_bolt, app_window, tab_characters, what_happend_in_battle);
			if (choice == 1)
				Confusion(tab_characters, what_happend_in_battle);
			else
				Lightning_bolt(tab_characters, what_happend_in_battle);
		}
		else
			what_happend_in_battle.push_back("Brak trzecio poziomowych slotow");
		break;
	}
	default:
	{
		break;
	}
	}
}

int Czarodziejka::choose_spell(string first_spell, string second_spell, RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	bool forward_condition = true;
	Event event;
	int choice;
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
	while (forward_condition)
	{
		while (app_window.pollEvent(event))
			if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Num1))
				{
					choice = 1;
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num2))
				{
					choice = 2;
					forward_condition = false;
				}
			}
		draw_object.true_rerender(app_window, tab_characters, what_happend_in_battle, draw_object, id_number);
		term.draw_action_menu_sorceress(app_window);
		term.draw_sorceress_spells(app_window, first_spell, second_spell);
		app_window.display();
	}
	return choice;
}

void Czarodziejka::Poison_spray(Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	if (check_range(tab_characters))
	{
		if (!saving_throw(constitution, tab_characters[3], spell_save_DC))
		{
			Roll_Dice roll;
			tab_characters[3]->HP -= roll.roll_d12() + roll.roll_d12();
			what_happend_in_battle.push_back("Przeciwnik otrzymal obrazenia");
		}
		else
			what_happend_in_battle.push_back("Przeciwnik oparl sie zakleciu");
		action--;
	}
	else
		what_happend_in_battle.push_back("Przeciwnik poza zasiegiem");
	return;
}

void Czarodziejka::Teleport(RenderWindow &app_window, Postac *tab_characters[4])
{
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
	bool movement_condition = true;
	bool it_is_collision = false;
	Event event;
	Vector2i bufor_wsp;
	check_hitbox(tab_characters, it_is_collision);
	while (movement_condition)
	{
		draw_object.draw_terrain(app_window);
		draw_object.rerender(app_window, tab_characters);
		if (it_is_collision)
			draw_object.draw_hitbox_move_error(app_window, tab_co_movement_marker.back());
		else
			draw_object.draw_movement_marker(app_window, tab_co_movement_marker.back());
		while (app_window.pollEvent(event))
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up)
					move_up(bufor_wsp, tab_characters, it_is_collision);
				if (event.key.code == Keyboard::Down)
					move_down(bufor_wsp, tab_characters, it_is_collision);
				if (event.key.code == Keyboard::Left)
					move_left(bufor_wsp, tab_characters, it_is_collision);
				if (event.key.code == Keyboard::Right)
					move_right(bufor_wsp, tab_characters, it_is_collision);
			}
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
			}
		app_window.display();
	}
	action--;
	spell_slots_1st--;
	return;
}

void Czarodziejka::Fire_bolt(Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	Roll_Dice roll;
	if (is_hit_spell(roll.roll_d20(), tab_characters[3]))
	{
		tab_characters[3]->HP -= roll.roll_d10() + roll.roll_d10();
		what_happend_in_battle.push_back("Przeciwnik otrzymal obrazenia");
	}
	else
		what_happend_in_battle.push_back("Zaklecie nie trafilo przeciwnika");
	action--;
	spell_slots_1st--;
	return;
}

void Czarodziejka::Haste(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	Event event;
	vector<Event> events;
	bool forward_condition = true, clear_condition = true;
	terminal term;
	drawing draw_object;
	string terminal_bufor[2] = { "","" };
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
	int counter = 0, tab_id[2], choice;
	for (int i = 0; i < 3; i++)
	{
		if (!(tab_characters[i]->get_name() == "Sorceress"))
		{
			if (!(excluded_character_list[i] == i))
			{
				terminal_bufor[counter] = terminal_bufor[counter] + to_string(counter + 1) + ". " + tab_characters[i]->get_name();
				tab_id[counter] = tab_characters[i]->get_id_number();
				counter++;
			}
		}
	}
	while (forward_condition)
	{
		while (app_window.pollEvent(event))
			if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Num1))
				{
					choice = tab_id[0];
					forward_condition = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Num2))
				{
					choice = tab_id[1];
					forward_condition = false;
				}
			}
		draw_object.true_rerender(app_window, tab_characters, what_happend_in_battle, draw_object, id_number);
		term.draw_action_menu_sorceress(app_window);
		term.draw_haste_characters(app_window, terminal_bufor);
		app_window.display();
	}
	if (tab_characters[choice]->check_haste())
	{
		what_happend_in_battle.push_back("Na ta postac dziala juz to zaklecie");
		return;
	}
	what_happend_in_battle.push_back("Zaklecie sie powiodlo");
	tab_characters[choice]->activate_haste();
	action--;
	spell_slots_2st--;
	return;
}

void Czarodziejka::Magic_armor(vector<string> &what_happend_in_battle)
{
	AC = 13 + tab_statistics_mod[dexterity];
	what_happend_in_battle.push_back("Magiczna zbroja otacza Twoje cialo");
	action--;
	spell_slots_2st--;
	return;
}

void Czarodziejka::Confusion(Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	if (saving_throw(wisdom, tab_characters[3], spell_save_DC))
		what_happend_in_battle.push_back("Przeciwnik oparl sie zakleciu");
	else
	{
		what_happend_in_battle.push_back("Przeciwnik wpada w magiczny zamet");
		tab_characters[3]->set_confusion_true();
	}
	action--;
	spell_slots_3st--;
	return;
}

void Czarodziejka::Lightning_bolt(Postac *tab_characters[4], vector<string> &what_happend_in_battle)
{
	Roll_Dice roll;
	int dmg = 0;
	if (saving_throw(dexterity, tab_characters[3], spell_save_DC))
	{
		for (int i = 0; i < 4; i++)
			dmg += roll.roll_d6();
		tab_characters[3]->HP -= dmg;
		what_happend_in_battle.push_back("Przeciwnik czesciowo uniknal zaklecia lecz otrzymal obrazenia");
	}
	else
	{
		for (int i = 0; i < 8; i++)
			dmg += roll.roll_d6();
		tab_characters[3]->HP -= dmg;
		what_happend_in_battle.push_back("Przeciwnik otrzymal obrazenia");
	}
	action--;
	spell_slots_3st--;
	return;
}

Czarodziejka::~Czarodziejka()
{
}
