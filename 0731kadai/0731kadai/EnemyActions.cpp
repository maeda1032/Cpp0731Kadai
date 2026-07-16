#include "EnemyActions.h"
#include <iostream>
#include <stdlib.h>

int EnemyActions::RandomCharacter()
{
	int randomCharaNum = 0;
	randomCharaNum = (rand() % 3) + 1;
	
	std::cout << "敵キャラクターが選択されました。" << std::endl;

	return randomCharaNum;
}

int EnemyActions::RandomDefenseAttack()
{
	int randomActionNum = 0;
	randomActionNum = (rand() % 2) + 1;

	std::cout << "敵の行動が選択されました。" << std::endl;

	return randomActionNum;
}