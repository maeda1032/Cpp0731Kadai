
#include <iostream>
#include <memory>
#include "BattlePower.h"
#include "PlayerActions.h"
#include "EnemyActions.h"
#include "ResultManagement.h"
#include "Summoner.h"
#include "SwordsMan.h"
#include "Wizard.h"

/// <summary>
/// 両方が攻撃の場合
/// </summary>
void BothAttack()
{

}

void Turn()
{
	int player = 0;
	int playerAttackDefense = 0;

	//敵キャラクターを決める
	int randomCharaNum = 0;
	//敵キャラクターの行動を決める
	int randomActionNum = 0;

	int battleNum = 0;

	//playerの入力したキーの取得に使用
	std::unique_ptr<PlayerActions> playerPtr = std::make_unique<PlayerActions>();

	//enemyのランダムな数値の取得に使用
	std::unique_ptr<EnemyActions> enemy = std::make_unique<EnemyActions>();

	//バトルのメソッドを呼び出すときに使用
	ResultManagement result;

	//0:playerの戦力 1:enemyの戦力
	BattlePower battlePower[2];

	//攻撃力と
	std::shared_ptr<Character> characters[3];
	characters[0].reset(new SwordsMan);
	characters[1].reset(new Wizard);
	characters[2].reset(new Summoner);
 
	while (true)
	{
		//もし戦力が０ならターン処理を終了
		if (battlePower[0].battleStatus.battlePower < 0 || battlePower[1].battleStatus.battlePower < 0)
		{
			break;
		}
		//playerのキャラクターを選択する
		//入力されたキーで異なるキャラクターを使用する配列の中に入れるため-1
		player = playerPtr->InputCharacterKey();

		//playerの攻撃防御を選択する
		playerAttackDefense = playerPtr->AttackDefenseKey();

		//敵のキャラクターの決定
		randomCharaNum = enemy->RandomCharacter();

		//敵の行動の決定
		randomActionNum = enemy->RandomDefenseAttack();

		//選択された行動が異なるなら
		if (playerAttackDefense != randomActionNum)
		{
			//playerが攻撃をしていた場合
			if (playerAttackDefense == 1)
			{
				//勝利判定をbattleNumに記録
				battleNum = result.WinerLoserCheck(player,randomCharaNum);
				//カウンターの場合
				if (battleNum == 2)
				{
					int attackPower = 0;
					//カウンター攻撃力を計算
					attackPower = result.Counter(characters[player - 1]->param.attackPower);

					//自分のHPを減らす
					battlePower[0].LoserMinusHp(battlePower[0].battleStatus.battlePower, attackPower);

					//コメントの表示
					std::cout << "enemyのカウンター攻撃" << std::endl;

					//ダメージの表示
					result.DispBattleInfo(playerAttackDefense + 1, battlePower[0].battleStatus.battlePower, attackPower);
				}
				//クリティカルの場合
				else
				{
					int attackPower = 0;

					//クリティカルの攻撃力を設定
					attackPower = result.Critical(characters[player - 1]->param.attackPower);

					//敵のHPを減らす
					battlePower[1].LoserMinusHp(battlePower[1].battleStatus.battlePower, attackPower);

					//コメントの表示
					std::cout << "Playerのクリティカル攻撃" << std::endl;

					result.DispBattleInfo(playerAttackDefense, battlePower[1].battleStatus.battlePower, attackPower);
				}
			}
			//敵が攻撃をしていた場合
			else
			{
				//勝利判定をbattleNumに記録
				battleNum = result.WinerLoserCheck(randomCharaNum, player);
				//カウンターの場合
				if (battleNum == 2)
				{
					int attackPower = 0;
					attackPower = result.Counter(characters[randomCharaNum - 1]->param.attackPower);
					battlePower[1].LoserMinusHp(battlePower[1].battleStatus.battlePower, attackPower);

					std::cout << "Playerのカウンター攻撃" << std::endl;
					result.DispBattleInfo(1, battlePower[1].battleStatus.battlePower, attackPower);
				}

				//クリティカルの場合
				else
				{
					int attackPower = 0;

					//攻撃力の計算
					attackPower = result.Critical(characters[randomCharaNum - 1]->param.attackPower);

					//実際にHPを減らす処理
					battlePower[0].LoserMinusHp(battlePower[0].battleStatus.battlePower, attackPower);

					std::cout << "Enemyのクリティカル攻撃" << std::endl;

					//攻撃力と減ったHPを表示する
					result.DispBattleInfo(2, battlePower[0].battleStatus.battlePower, attackPower);
				}
			}



		}
		else
		{
			//二人とも攻撃を選択し、キャラクターが異なる場合高いほうがダメージを与える
			if (playerAttackDefense == 1 && randomActionNum == 1 && player != randomCharaNum)
			{
				//playerのほうが攻撃力が高い場合
				if (characters[randomCharaNum - 1]->param.attackPower < characters[player - 1]->param.attackPower)
				{
					//敵キャラクターのHPを減らす
					battlePower[1].LoserMinusHp(battlePower[1].battleStatus.battlePower, characters[player - 1]->param.attackPower);

					std::cout << "両者攻撃が選択されましたPlayerの攻撃力が高いため敵に" << characters[player - 1]->param.attackPower << "ダメージ入ります" << std::endl;
					std::cout << "敵残り戦力" << battlePower[1].battleStatus.battlePower << std::endl;

				}
				//enemyのほうが攻撃力が高い場合
				else
				{
					//プレイヤーのHPを減らす
					battlePower[0].LoserMinusHp(battlePower[0].battleStatus.battlePower, characters[randomCharaNum - 1]->param.attackPower);

					std::cout << "両者攻撃が選択されました敵の攻撃力が高いためプレイヤーに" << characters[randomCharaNum - 1]->param.attackPower << "ダメージ入ります" << std::endl;
					std::cout << "Player残り戦力" << battlePower[0].battleStatus.battlePower << std::endl;

				}
			}
			else
			{
				result.Draw();
			}
		}

		//倒したか確認する
		if (battlePower[0].battleStatus.battlePower < 0 || battlePower[1].battleStatus.battlePower < 0)
		{
			if (battlePower[0].battleStatus.battlePower > battlePower[1].battleStatus.battlePower)
			{
				//playerの勝利
				int winner = 1;

				result.Die(winner);
			}
			if (battlePower[0].battleStatus.battlePower < battlePower[1].battleStatus.battlePower)
			{
				//enemyの勝利
				int winner = 2;

				result.Die(winner);
			}
		}
	}
}

int main()
{
	//乱数の初期化(毎回違う点数にするため)
	srand((unsigned int)time(NULL));

	std::cout << "ゲーム開始" << std::endl;

	Turn();
	
}


