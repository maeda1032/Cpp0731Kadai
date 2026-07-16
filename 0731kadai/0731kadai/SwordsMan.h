#pragma once

#include "Character.h"

class SwordsMan:public Character
{
public:
	void SetAttack() override;

	SwordsMan()
	{
		SetAttack();
	}
};

