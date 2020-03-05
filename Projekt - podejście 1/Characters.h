#pragma once
#include "Postac.h"
#include "drawing.h"

using namespace std;
using namespace sf;


class Blue_Dragon : public Postac
{
	int current_location = 1;
public:
	Blue_Dragon();
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	~Blue_Dragon();
};

class Fire_Gigant : public Postac
{
	int current_location = 1;
public:
	Fire_Gigant();
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	~Fire_Gigant();
};

class Devil : public Postac
{
	int current_location = 1;
	int spell_save_DC;
public:
	Devil();
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	~Devil();
};

class Earth_Elemental : public Postac
{
	int current_location = 1;
public:
	Earth_Elemental();
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	~Earth_Elemental();
};

class Shield_Guardian : public Postac
{
	int current_location = 1;
public:
	Shield_Guardian();
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);

	~Shield_Guardian();
};

class Czarodziejka : public Postac
{
	int current_location = 1;
	int spell_slots_1st;
	int spell_slots_2st;
	int spell_slots_3st;
	int spell_save_DC;
public:
	Czarodziejka();
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	int choose_spell(string first_spell, string second_spell, RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	void Poison_spray(Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	void Teleport(RenderWindow &app_window, Postac *tab_characters[4]);
	void Fire_bolt(Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	void Haste(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	void Magic_armor(vector<string> &what_happend_in_battle);
	void Confusion(Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	void Lightning_bolt(Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	~Czarodziejka();
};

class Monk : public Postac
{
	int current_location = 1;
	int ki;
	int wholeness_body;
public:
	Monk();
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	~Monk();
};

class Ranger : public Postac
{
	int current_location = 1;
public:
	Ranger();
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	~Ranger();
};

class Warrior : public Postac
{
	int current_location = 1;
	int action_surge;
	int second_wind;
public:
	Warrior();
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	~Warrior();
};

class Paladin : public Postac
{
	int current_location = 1;
	int hp_lay_on_hands;
	bool is_sacred_weapon_activated;
public:
	Paladin();
	virtual void movement(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	virtual void attack(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	bool heal(RenderWindow &app_window, Postac *tab_characters[4], vector<string> &what_happend_in_battle);
	bool is_someone_in_range_to_heal(Postac *tab_characters[4], int character_id_number[2]);
	~Paladin();
};

