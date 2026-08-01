#include <iostream>
#include "Turn.h"



int main()
{
	//乱数の初期化(毎回違う点数にするため)
	srand((unsigned int)time(NULL));

	std::cout << "ゲーム開始" << std::endl;

	Turn turn;

	turn.TurnProcess();
	
}


