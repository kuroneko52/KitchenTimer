// KitchenTimer.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

#define ONE_SECOND 1000

void time(int i);

int main()
{
	int i;

	cout << "秒数を入力してください\n";
	cin >> i;
	cout << "\n";
	system("cls");
	time(i);

	while (1) {
		i--;

		Sleep(ONE_SECOND);
		system("cls");
		time(i);

		if (i == 0) {
			cout << "\n";
			break;
		}
	}

	Beep(554, 200);
	cout << "時間になりました\n";

	return 0;
}

void time(int i) {
	long h;
	long m;
	long s;

	h = i / 3600;
	m = (i - h * 3600) / 60;
	s = i - h * 3600 - m * 60;

	cout << h << "時間" << m << "分" << s << "秒" << "\n";

	return;
}