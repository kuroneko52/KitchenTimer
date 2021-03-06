// KitchenTimer.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

#define ONE_SECOND 1000

void TimeShow(int sec);
int TimeConverter(int i[3]);

int main()
{
	int enterTime[3];
	int sec;

	cout << "時を入力してください\n";
	cin >> enterTime[0];
	cout << "\n";

	cout << "分を入力してください\n";
	cin >> enterTime[1];
	cout << "\n";

	cout << "秒を入力してください\n";
	cin >> enterTime[2];
	cout << "\n";

	system("cls");

	sec = TimeConverter(enterTime);

	if (sec < 0) {
		Beep(440, 200);
		Beep(440, 200);
		exit(EXIT_FAILURE);
	}

	TimeShow(sec);

	while (1) {
		if (sec == 0) {
			cout << "\n";
			break;
		}

		sec--;

		Sleep(ONE_SECOND);
		system("cls");
		TimeShow(sec);
	}

	Beep(659, 200);
	Beep(659, 200);
	cout << "時間になりました\n";

	return 0;
}

void TimeShow(int sec) {
	long h;
	long m;
	long s;

	h = sec / 3600;
	m = (sec - h * 3600) / 60;
	s = sec - h * 3600 - m * 60;

	cout << h << "時間" << m << "分" << s << "秒" << "\n";

	return;
}

int TimeConverter(int i[3]) {
	long h = i[0];
	long m = i[1];
	long s = i[2];

	h *= 3600;
	m *= 60;

	return h + m + s;
}