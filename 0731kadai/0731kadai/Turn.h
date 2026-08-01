#include "ResultManagement.h"

#pragma once
class Turn
{
public:
	void TurnStart();

	void TurnProcess();

	void TurnEndCheck(int playerBattlePower, int enemyBattlePowers);

private:
	//バトルのメソッドを呼び出すときに使用
	ResultManagement result;

};

