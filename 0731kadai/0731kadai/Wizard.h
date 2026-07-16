#pragma once

#include "Character.h"

class Wizard:public Character
{
public:
	void SetAttack() override;

	Wizard()
	{
		SetAttack();
	}
};

