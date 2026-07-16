#pragma once
class ResultManagement
{
public:
	//引き分けの場合呼ぶ関数
	void Draw();

	//クリティカルの場合呼ぶ関数
	int Critical(int winerAttackPower);

	//カウンターの場合呼ぶ関数
	int Counter(int winerAttackPower);

	//勝ち負けの判定をするだけ
	int WinerLoserCheck(int attackerNum,int defenderNum);



	//誰がダメージを受けたか、ダメージや残りHPを表示する
	void DispBattleInfo(int attacker, int hp, int attackPower);

	//どちらかのHPが0になったタイミングで呼ぶ関数
	void Die(int winner);
};


