#pragma once
class Turn
{
public:
	void TurnStart();

	void TurnProcess();

	void TurnEnd();

private:
	//バトルのメソッドを呼び出すときに使用
	ResultManagement result;

};

