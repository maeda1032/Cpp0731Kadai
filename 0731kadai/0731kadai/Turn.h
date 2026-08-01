#include "ResultManagement.h"
#include "PlayerActions.h"
#include "EnemyActions.h"

#pragma once
class Turn
{
public:
	void TurnStart(std::shared_ptr<PlayerActions> playerPtr, std::shared_ptr<EnemyActions> enemy);

	void TurnProcess();

	void TurnEndCheck(int playerBattlePower, int enemyBattlePowers);

private:
	//バトルのメソッドを呼び出すときに使用
	ResultManagement result;

	int player;

	int playerAttackDefense;

	//敵のキャラクターの決定
	int randomCharaNum;

	//敵の行動の決定
	int randomActionNum;

};

