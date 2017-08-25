#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;


int main()
{
	int referees, players;
	double x, max, min, sum, aver;
	cout << "输入评委人数：" << endl;
	cin >> referees;
	if(referees<=2)
	{
		cout << "评委人数过少" << endl;
		return -1;
	}
	cout << "输入选手人数：" << endl;
	cin >> players;

	time_t t;
	srand(time(&t));

	for (int i = 0; i < players; i++)
	{
		cout << "\n\n==== No. " << i + 1 << endl;
		min = 10;
		max = 0;
		sum = 0;
		for (int j = 0; j < referees; j++) 
		{
			x = (rand() % 21 + 80) / 10.0;
			cout << x << '\t';  //空格
			if (x > max) max = x;
			if (x < min) min = x;
			sum += x;
		}
		aver = (sum - min - max) / (referees - 2);
		cout << "\n去掉一个最高分 " << max << endl
			<< "去掉一个最低分 " << min << endl
			<< "最后得分为 " << aver << endl;
		getch();   //作用是任意键继续
	}


	return 0;
}
