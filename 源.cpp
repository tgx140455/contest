#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
	const int MAX_REFEREES = 50, MAX_PLAYERS = 100;

	int referees, players;
	double x[MAX_PLAYERS][MAX_REFEREES], aver[MAX_PLAYERS];   //��������Ϊ���� 1

	double max, min, sum;

	int rank[MAX_PLAYERS], i, j;

	cout << "������ί������" << endl;
	cin >> referees;
	if (referees <= 2||referees>MAX_REFEREES)
	{
		cout << "��ί�������ٻ����" << endl;
		return -1;
	}
	cout << "����ѡ��������" << endl;
	cin >> players;
	if (players > MAX_PLAYERS)
	{
		cout << "ѡ�ֹ���" << endl;
		return -2;
	}

	time_t t;
	srand(time(&t));

	for (i = 0; i < players; i++)
	{
		cout << "\n\n==== No. " << i + 1 << endl;
		min = 10;
		max = 0;
		sum = 0;
		for (j = 0; j < referees; j++)
		{
			x[i][j] = (rand() % 21 + 80) / 10.0;
			cout << x[i][j] << '\t';  //�ո�
			if (x[i][j] > max) max = x[i][j];
			if (x[i][j] < min) min = x[i][j];
			sum += x[i][j];
		}
		aver[i] = (sum - min - max) / (referees - 2);
		cout << "\nȥ��һ����߷� " << max << endl
			<< "ȥ��һ����ͷ� " << min << endl
			<< "���÷�Ϊ " << aver[i] << endl;
		getch();   //���������������
	}

	for(i=0;i<players;i++)
	{
		rank[i] = 1;
		for(j=0;j<players;j++)
		{
			if (aver[j] > aver[i]) rank[i]++;
		}
	}

	cout << setprecision(3) << showpoint;
	cout << "\nNo";
	for (j = 0; j < referees; j++)
	    cout << "     " << char('A' + j);
	cout << "   Aver    Rank" << endl;

	for (i = 0; i < players; i++)
		{
			cout <<  i + 1<<"  ";
			for (j = 0; j < referees; j++)
				cout << setw(6) << x[i][j];
			cout << setw(6) << aver[i]
				<< setw(6) << rank[i] << endl;
		}
	

	return 0;
}