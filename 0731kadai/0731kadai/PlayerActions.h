#pragma once
class PlayerActions
{
public:
	int InputCharacterKey();

	int AttackDefenseKey();
	
private:
	int characterNumber = 0;
	int attackDefenseNumber = 0;
};

