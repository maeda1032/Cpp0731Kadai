#pragma once

struct BattleStatus
{
	//í—ÍHp‚Ì‚æ‚¤‚È‚à‚Ì
	int battlePower = 300;
};
class BattlePower
{
public:
	//•‰‚¯‚½‘¤‚ÌHp‚ğŒ¸‚ç‚·
	void LoserMinusHp(int& battlePower, int attackPower);

	BattleStatus battleStatus;

};

