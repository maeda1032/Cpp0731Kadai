#include "ResultManagement.h"
#include <iostream>

//引き分けの場合呼ぶ関数
void ResultManagement::Draw()
{
	std::cout << "同じ役職だったため引き分けになりました" << std::endl;
}

//クリティカルの場合呼ぶ関数
int ResultManagement::Critical(int winerAttackPower)
{
	//攻撃力を計算して渡す
	int attackPower = 0;
    attackPower = winerAttackPower * 2;
	return attackPower;
}

//カウンターの場合呼ぶ関数
int ResultManagement::Counter(int winerAttackPower)
{
	//攻撃力を計算して渡す
	int attackPower = 0;
	attackPower = winerAttackPower * 2;
	return attackPower;

}

//勝ち負けの判定をするだけ
int ResultManagement::WinerLoserCheck(int attackerNum, int defenderNum)
{
	//引き分け:1,クリティカル:2,カウンター3

	//引き分け
	if (attackerNum == defenderNum)
	{
		//引き分けの場合1を渡す
		int draw = 1;
		return draw;
	}
	//クリティカルまたはカウンター
	else if (attackerNum != defenderNum)
	{

		//クリティカルが発生する条件1:剣士2:魔法使い3:召喚士
		//剣士と召喚士のとき、魔法使いと剣士のとき、召喚士と魔法使いの時に発生
		if (attackerNum == 1 && defenderNum == 3 || attackerNum == 2 && defenderNum == 1 || attackerNum == 3 && defenderNum == 2)
		{
			int counter = 2;
			return counter;
		}

		//カウンター
		else if (attackerNum == 1 && defenderNum == 2 || attackerNum == 2 && defenderNum == 3 || attackerNum == 3 && defenderNum == 1)
		{
			int critical = 3;
			return critical;
		}

	}
}



//誰がダメージを受けたか、ダメージや残りHPを表示する
void ResultManagement::DispBattleInfo(int attacker,int hp,int attackPower)
{
	if (attacker == 1)
	{
		std::cout << "プレイヤーが" << attackPower << "ダメージ与えました。敵の残り戦力:" << hp << std::endl;
	}
	else
	{
		std::cout << "敵から" << attackPower << "ダメージ受けました。Playerの残り戦力:" << hp << std::endl;
	}
}

//どちらかの戦力が0になったタイミングで呼ぶ関数
void ResultManagement::Die(int winner)
{
	//1:playerWin2:EnemyWin
	if (winner == 1)
	{
		std::cout << "playerが勝利しました" << std::endl;
	}
	else
	{
		std::cout << "Enemyが勝利しました" << std::endl;
	}
}