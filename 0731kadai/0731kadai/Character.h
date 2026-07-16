#pragma once

struct Parametor
{
	//攻撃力
	int attackPower = 0;

};

class Character
{
public:
	//charactorのステータス
	Parametor param;

protected:
	virtual void SetAttack();

};


