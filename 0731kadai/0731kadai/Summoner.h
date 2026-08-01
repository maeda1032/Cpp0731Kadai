#pragma once

#include "Character.h"

class Summoner:public Character
{

private:
	void SetAttack() override;

public:

	Summoner()
	{
		SetAttack();
	}
};

