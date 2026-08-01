#pragma once

#include "Character.h"

class SwordsMan:public Character
{
private:
	void SetAttack() override;
public:

	SwordsMan()
	{
		SetAttack();
	}
};

