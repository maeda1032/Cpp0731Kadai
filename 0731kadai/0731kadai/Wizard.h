#pragma once

#include "Character.h"

class Wizard:public Character
{
private:

	void SetAttack() override;

public:

	Wizard()
	{
		SetAttack();
	}
};

