#pragma once

#include "Character.h"

class Summoner:public Character
{
public:
	void SetAttack() override;

	Summoner()
	{
		SetAttack();
	}
};

