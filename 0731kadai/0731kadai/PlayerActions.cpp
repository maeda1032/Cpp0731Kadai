#include "PlayerActions.h"
#include <iostream>

int PlayerActions::InputCharacterKey()
{
	int charaNumber = 0;

	while (true)
	{
		std::cout << "キャラクターを選択してください 1:剣士 2:魔法使い 3:召喚士" << std::endl;
		std::cin >> charaNumber;

		if (charaNumber == 1)
		{
			std::cout << "剣士が選択されました。" << std::endl;
			break;
		}
		else if (charaNumber == 2)
		{
			std::cout << "魔法使いが選択されました。" << std::endl;
			break;
		}
		else if (charaNumber == 3)
		{
			std::cout << "召喚士が選択されました。" << std::endl;
			break;
		}
		else
		{
			std::cout << "対象外のキーが押されましたもう一度選択してください" << std::endl;
		}
	}

	return charaNumber;
}

int PlayerActions::AttackDefenseKey()
{
	int attackDefenseNum = 0;

	while (true)
	{
		std::cout << "攻撃をするか防御をするかを選択してください 1:攻撃 2:防御" << std::endl;
		std::cin >> attackDefenseNum;

		if (attackDefenseNum == 1)
		{
			std::cout << "攻撃が選択されました。" << std::endl;

			break;
		}
		else if (attackDefenseNum == 2)
		{
			std::cout << "防御が選択されました。" << std::endl;

			break;
		}
		else
		{
			std::cout << "対象外のキーが押されましたもう一度選択してください" << std::endl;
		}
	}

	return attackDefenseNum;
}