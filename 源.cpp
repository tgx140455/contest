#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int main()
{
	int referees, players;
	double x, max, min, sum, aver;
	cout << "������ί������" << endl;
	cin >> referees;
	if(referees<=2)
	{
		cout << "��ί��������" << endl;
		return -1;
	}
	cout << "����ѡ��������" << endl;
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
			cout << x << '\t';  //�ո�
			if (x > max) max = x;
			if (x < min) min = x;
			sum += x;
		}
		aver = (sum - min - max) / (referees - 2);
		cout << "\nȥ��һ����߷� " << max << endl
			<< "ȥ��һ����ͷ� " << min << endl
			<< "���÷�Ϊ " << aver << endl;
		getch();   //���������������
	}


	return 0;
}