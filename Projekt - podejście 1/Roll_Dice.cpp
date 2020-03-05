#include "Roll_Dice.h"

int Roll_Dice::roll_d4()
{
	static random_device rd;
	static mt19937 rng(rd());
	static std::uniform_int_distribution<int> uid(1, 4);
	return uid(rng);
}

int Roll_Dice::roll_d6()
{
	static random_device rd;
	static mt19937 rng(rd());
	static std::uniform_int_distribution<int> uid(1, 6);
	return uid(rng);
}

int Roll_Dice::roll_d8()
{
	static random_device rd;
	static mt19937 rng(rd());
	static std::uniform_int_distribution<int> uid(1, 8);
	return uid(rng);
}

int Roll_Dice::roll_d10()
{
	static random_device rd;
	static mt19937 rng(rd());
	static std::uniform_int_distribution<int> uid(1, 10);
	return uid(rng);
}

int Roll_Dice::roll_d12()
{
	static random_device rd;
	static mt19937 rng(rd());
	static std::uniform_int_distribution<int> uid(1, 12);
	return uid(rng);
}

int Roll_Dice::roll_d20()
{
	static random_device rd;
	static mt19937 rng(rd());
	static std::uniform_int_distribution<int> uid(1, 20);
	return uid(rng);
}

bool Roll_Dice::is_it_draw(vector<int> tab_initiative)
{
	for (int i = 0; i < tab_initiative.size(); i++)
		for (int j = 0; j < tab_initiative.size(); j++)
		{
			if (i != j)
				if (tab_initiative[i] == tab_initiative[j])
					return true;
		}
	return false;
}

void Roll_Dice::same_initiative_solution(vector<int> &tab_initiative)
{
	int tab_postion_initiatives_in_vector[2];
	int tab_rng[2];
	bool is_find = false;
	for (int i = 0; i < tab_initiative.size(); i++)
	{
		for (int j = 0; j < tab_initiative.size(); j++)
		{
			if (i != j)
				if (tab_initiative[i] == tab_initiative[j])
				{
					tab_postion_initiatives_in_vector[0] = i;
					tab_rng[0] = roll_d20();
					tab_postion_initiatives_in_vector[1] = j;
					tab_rng[1] = roll_d20();
					is_find = true;
					break;
				}
		}
		if (is_find)
			break;
	}
	if (tab_rng[0] >= tab_rng[1])
		tab_initiative[tab_postion_initiatives_in_vector[0]] += 1;
	else if(tab_rng[0] < tab_rng[1])
		tab_initiative[tab_postion_initiatives_in_vector[1]] += 1;
	//else if(tab_rng[0] == tab_rng[1])
		//tab_initiative[tab_postion_initiatives_in_vector[0]] += 1;
	return;
}

Roll_Dice::Roll_Dice()
{
}


Roll_Dice::~Roll_Dice()
{
}
