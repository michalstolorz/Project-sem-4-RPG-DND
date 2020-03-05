#include "Postac.h"



Postac::Postac()
{
}

vector<Vector2i> Postac::get_tab_co_movement_markers()
{
	return tab_co_movement_marker;
}

vector<Vector2i> Postac::get_tab_co_character()
{
	return tab_co_character;
}

int Postac::get_initiative()
{
	return initiative;
}

int Postac::get_id_number()
{
	return id_number;
}

int Postac::get_max_HP()
{
	return max_HP;
}

bool Postac::get_confusion_status()
{
	if (is_confused)
		return true;
	return false;
}

string Postac::get_name()
{
	return name;
}

IntRect Postac::get_hitbox_move_error_character()
{
	return hitbox_move_error_character;
}

void Postac::set_character_id_number(int id)
{
	id_number = id;
	return;
}

void Postac::set_initiative()
{
	Roll_Dice ob;
	initiative = ob.roll_d20() + tab_statistics_mod[dexterity];
	return;
}

void Postac::remember_original_speed()
{
	speed_memory = speed;
	return;
}

void Postac::reset_original_speed()
{
	speed = speed_memory;
	return;
}

void Postac::reset_actions()
{
	action = 1;
	bonus_action = 1;
	return;
}

int Postac::set_statistic_mod(int statistic)
{
	int mod;
	if (statistic == 1)
		mod = -5;
	else if (statistic == 2 || statistic == 3)
		mod = -4;
	else if (statistic == 4 || statistic == 5)
		mod = -3;
	else if (statistic == 6 || statistic == 7)
		mod = -2;
	else if (statistic == 8 || statistic == 9)
		mod = -1;
	else if (statistic == 10 || statistic == 11)
		mod = 0;
	else if (statistic == 12 || statistic == 13)
		mod = 1;
	else if (statistic == 14 || statistic == 15)
		mod = 2;
	else if (statistic == 16 || statistic == 17)
		mod = 3;
	else if (statistic == 18 || statistic == 19)
		mod = 4;
	else if (statistic == 20 || statistic == 21)
		mod = 5;
	else if (statistic == 22 || statistic == 23)
		mod = 6;
	else if (statistic == 24 || statistic == 25)
		mod = 7;
	return mod;
}

void Postac::set_co_movement_marker(Vector2i coordinates)
{
	tab_co_movement_marker.push_back(coordinates);
	return;
}

void Postac::set_co_character(Vector2i coordinates)
{
	tab_co_character.push_back(coordinates);
	return;
}

void Postac::set_hitbox_move_error_marker(Vector2i coordinates)
{
	Vector2i size_hitbox;
	size_hitbox.x = 99;
	size_hitbox.y = 99;
	hitbox_move_error_marker = new IntRect(coordinates, size_hitbox);
	return;
}

void Postac::set_hitbox_move_error_character(Vector2i coordinates)
{
	Vector2i size_hitbox;
	size_hitbox.x = 99;
	size_hitbox.y = 99;
	hitbox_move_error_character = IntRect(coordinates, size_hitbox);
	return;
}

void Postac::set_hitbox_move_error_enemy_4x4(Vector2i coordinates)
{
	Vector2i size_hitbox;
	size_hitbox.x = 399;
	size_hitbox.y = 399;
	hitbox_move_error_character = IntRect(coordinates, size_hitbox);
	return;
}

void Postac::set_hitbox_move_error_enemy_3x3(Vector2i coordinates)
{
	Vector2i size_hitbox;
	size_hitbox.x = 299;
	size_hitbox.y = 299;
	hitbox_move_error_character = IntRect(coordinates, size_hitbox);
	return;
}

void Postac::set_hitbox_move_error_enemy_2x2(Vector2i coordinates)
{
	Vector2i size_hitbox;
	size_hitbox.x = 199;
	size_hitbox.y = 199;
	hitbox_move_error_character = IntRect(coordinates, size_hitbox);
	return;
}

void Postac::set_hitbox_move_error_enemy_2x4(Vector2i coordinates)
{
	Vector2i size_hitbox;
	size_hitbox.x = 199;
	size_hitbox.y = 399;
	hitbox_move_error_character = IntRect(coordinates, size_hitbox);
	return;
}

void Postac::set_confusion_true()
{
	is_confused = true;
	return;
}

void Postac::set_confusion_false()
{
	is_confused = false;
	return;
}

void Postac::activate_haste()
{
	AC += 2;
	is_hasted = true;
	action++;
	return;
}

void Postac::deactivate_haste() //nie uzywane
{
	AC -= 2;
	is_hasted = false;
	return;
}

void Postac::activate_devil_mark()
{
	is_devil_marked = true;
	return;
}

void Postac::deactivate_devil_mark()
{
	is_devil_marked = false;
	return;
}

int Postac::find_closest_hero(Postac *tab_characters[4])
{
	vector<int> heroes_co;
	int bufor;
	int length_difference;
	for (int i = 0; i < 3; i++)
		if (!(excluded_character_list[i] == i))
		{
			bufor = tab_characters[3]->tab_co_character.back().x - tab_characters[i]->tab_co_character.back().x;
			heroes_co.push_back(bufor);
		}
	sort(heroes_co.rbegin(), heroes_co.rend());
	length_difference = heroes_co.back();
	for (int i = 0; i < 3; i++)
	{
		bufor = tab_characters[3]->tab_co_character.back().x - tab_characters[i]->tab_co_character.back().x;
		if (bufor == length_difference)
			return tab_characters[i]->id_number;
	}
	return 0;
}

bool Postac::check_if_alive()
{
	if (!this->is_dead)
		return true;
	return false;
}

void Postac::check_if_died()
{
	if (this->HP <= 0)
		is_dead = true;
	return;
}

bool Postac::check_haste()
{
	if (is_hasted)
		return true;
	return false;
}

bool Postac::check_devil_mark()
{
	if (is_devil_marked)
		return true;
	return false;
}

bool Postac::check_hitbox(Postac *tab_characters[4], bool &it_is_collision)
{
	set_hitbox_move_error_marker(tab_co_movement_marker.back());
	for (int i = 0; i < 4; i++)
		if (this->hitbox_move_error_marker->intersects(tab_characters[i]->hitbox_move_error_character))
		{
			it_is_collision = true;
			return true;
		}
	it_is_collision = false;
	return false;
}

bool Postac::check_range(Postac *tab_characters[4])
{
	Vector2i bufor_co = tab_co_movement_marker.back();
	for (int i = 1; i < 9; i++)
	{
		if (i == 1)
		{
			set_hitbox_move_error_marker(bufor_co);
			if (this->hitbox_move_error_marker->intersects(tab_characters[3]->hitbox_move_error_character))
				return true;
		}
		if (i == 2)
		{
			bufor_co.y += movement_100;
			set_hitbox_move_error_marker(bufor_co);
			if (this->hitbox_move_error_marker->intersects(tab_characters[3]->hitbox_move_error_character))
				return true;
		}
		if (i == 3 || i == 4)
		{
			bufor_co.x -= movement_100;
			set_hitbox_move_error_marker(bufor_co);
			if (this->hitbox_move_error_marker->intersects(tab_characters[3]->hitbox_move_error_character))
				return true;
		}
		if (i == 5 || i == 6)
		{
			bufor_co.y -= movement_100;
			set_hitbox_move_error_marker(bufor_co);
			if (this->hitbox_move_error_marker->intersects(tab_characters[3]->hitbox_move_error_character))
				return true;
		}
		if (i == 7 || i == 8)
		{
			bufor_co.x += movement_100;
			set_hitbox_move_error_marker(bufor_co);
			if (this->hitbox_move_error_marker->intersects(tab_characters[3]->hitbox_move_error_character))
				return true;
		}
	}
	return false;
}

bool Postac::is_critical_hit(int roll, Postac *current_character)
{
	if (dynamic_cast<Warrior*>(current_character) && (roll == 19 || roll == 20))
		return true;
	else if (roll == 20)
		return true;
	return false;
}

bool Postac::is_hit_attack(int roll, Postac *tab_characters)
{
	if (roll + main_statistic_mod_for_attack + proficiency_bonus >= tab_characters->AC)
		return true;
	return false;
}

bool Postac::is_hit_spell(int roll, Postac *tab_characters)
{
	if (roll + main_statistic_mod_for_spell + proficiency_bonus >= tab_characters->AC)
		return true;
	return false;
}

bool Postac::saving_throw(statistics stat, Postac *tab_characters, int DC)
{
	Roll_Dice roll;
	if (roll.roll_d20() + tab_characters->tab_saving_throws[stat] >= DC)
	{
		cout << "Saving throw sie powiodl" << endl;
		return true;
	}
	cout << "Saving throw nie powiodl sie" << endl;
	return false;
}

vector<Vector2i> Postac::move_up(Vector2i bufor_wsp, Postac *tab_characters[4], bool &it_is_collision)
{
	bufor_wsp.x = tab_co_movement_marker.back().x;
	bufor_wsp.y = tab_co_movement_marker.back().y - movement_100;
	tab_co_movement_marker.push_back(bufor_wsp);
	check_hitbox(tab_characters, it_is_collision);
	return tab_co_movement_marker;
}

vector<Vector2i> Postac::move_down(Vector2i bufor_wsp, Postac *tab_characters[4], bool &it_is_collision)
{
	bufor_wsp.x = tab_co_movement_marker.back().x;
	bufor_wsp.y = tab_co_movement_marker.back().y + movement_100;
	tab_co_movement_marker.push_back(bufor_wsp);
	check_hitbox(tab_characters, it_is_collision);
	return tab_co_movement_marker;
}

vector<Vector2i> Postac::move_left(Vector2i bufor_wsp, Postac *tab_characters[4], bool &it_is_collision)
{
	bufor_wsp.x = tab_co_movement_marker.back().x - movement_100;
	bufor_wsp.y = tab_co_movement_marker.back().y;
	tab_co_movement_marker.push_back(bufor_wsp);
	check_hitbox(tab_characters, it_is_collision);
	return tab_co_movement_marker;
}

vector<Vector2i> Postac::move_right(Vector2i bufor_wsp, Postac *tab_characters[4], bool &it_is_collision)
{
	bufor_wsp.x = tab_co_movement_marker.back().x + movement_100;
	bufor_wsp.y = tab_co_movement_marker.back().y;
	tab_co_movement_marker.push_back(bufor_wsp);
	check_hitbox(tab_characters, it_is_collision);
	return tab_co_movement_marker;
}

void Postac::movement_switch(Event event, Vector2i bufor_wsp, Postac *tab_characters[4], bool &it_is_collision, int &current_location)
{
	switch (current_location)
	{
	case 1:
	{
		if (event.key.code == Keyboard::Up)
		{
			move_up(bufor_wsp, tab_characters, it_is_collision);
			current_location = 8;
		}
		else if (event.key.code == Keyboard::Down)
		{
			move_down(bufor_wsp, tab_characters, it_is_collision);
			current_location = 2;
		}
		else if (event.key.code == Keyboard::Left)
		{
			move_down(bufor_wsp, tab_characters, it_is_collision);
			move_left(bufor_wsp, tab_characters, it_is_collision);
			move_left(bufor_wsp, tab_characters, it_is_collision);
			move_up(bufor_wsp, tab_characters, it_is_collision);
			current_location = 5;
		}
		break;
	}
	case 2:
	{
		if (event.key.code == Keyboard::Up)
		{
			move_up(bufor_wsp, tab_characters, it_is_collision);
			current_location = 1;
		}
		else if (event.key.code == Keyboard::Left)
		{
			move_left(bufor_wsp, tab_characters, it_is_collision);
			current_location = 3;
		}
		break;
	}
	case 3:
	{
		if (event.key.code == Keyboard::Right)
		{
			move_right(bufor_wsp, tab_characters, it_is_collision);
			current_location = 2;
		}
		else if (event.key.code == Keyboard::Left)
		{
			move_left(bufor_wsp, tab_characters, it_is_collision);
			current_location = 4;
		}
		break;
	}
	case 4:
	{
		if (event.key.code == Keyboard::Up)
		{
			move_up(bufor_wsp, tab_characters, it_is_collision);
			current_location = 5;
		}
		else if (event.key.code == Keyboard::Right)
		{
			move_right(bufor_wsp, tab_characters, it_is_collision);
			current_location = 3;
		}
		break;
	}
	case 5:
	{
		if (event.key.code == Keyboard::Up)
		{
			move_up(bufor_wsp, tab_characters, it_is_collision);
			current_location = 6;
		}
		else if (event.key.code == Keyboard::Down)
		{
			move_down(bufor_wsp, tab_characters, it_is_collision);
			current_location = 4;
		}
		else if (event.key.code == Keyboard::Right)
		{
			move_down(bufor_wsp, tab_characters, it_is_collision);
			move_right(bufor_wsp, tab_characters, it_is_collision);
			move_right(bufor_wsp, tab_characters, it_is_collision);
			move_up(bufor_wsp, tab_characters, it_is_collision);
			current_location = 1;
		}
		break;
	}
	case 6:
	{
		if (event.key.code == Keyboard::Right)
		{
			move_right(bufor_wsp, tab_characters, it_is_collision);
			current_location = 7;
		}
		else if (event.key.code == Keyboard::Down)
		{
			move_down(bufor_wsp, tab_characters, it_is_collision);
			current_location = 5;
		}
		break;
	}
	case 7:
	{
		if (event.key.code == Keyboard::Right)
		{
			move_right(bufor_wsp, tab_characters, it_is_collision);
			current_location = 8;
		}
		else if (event.key.code == Keyboard::Left)
		{
			move_left(bufor_wsp, tab_characters, it_is_collision);
			current_location = 6;
		}
		break;
	}
	case 8:
	{
		if (event.key.code == Keyboard::Left)
		{
			move_left(bufor_wsp, tab_characters, it_is_collision);
			current_location = 7;
		}
		else if (event.key.code == Keyboard::Down)
		{
			move_down(bufor_wsp, tab_characters, it_is_collision);
			current_location = 1;
		}
		break;
	}
	default:
		break;
	}
}

Postac::~Postac()
{
}
