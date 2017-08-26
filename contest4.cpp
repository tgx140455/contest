#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>
using namespace std;

int Init(int &referees,int &players)
{

	cout << "输入评委人数：" << endl;
	cin >> referees;
	if (referees <= 2)
	{
		cout << "评委人数过少" << endl;
		return -1;
	}
	cout << "输入选手人数：" << endl;
	cin >> players;
	return 0;
}

int GetMemory(int referees, int players,int *&rank,double *&x,double *&aver)
{
	rank = new int[players];

	x = new double[players*referees];
	aver = new double[players];


	if (x == NULL || aver == NULL || rank == NULL)
	{

		if (x) delete[] x;
		if (aver) delete[] aver;
		if (rank) delete[] rank;
		return -2;

	}
	return 0;
}

void Calculate(int referees, int players, int *rank, double *&x, double *&aver)
{

	double max, min, sum;

	int  i, j;

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
			x[i*referees + j] = (rand() % 21 + 80) / 10.0;
			cout << x[i*referees + j] << '\t';  //空格
			if (x[i*referees + j] > max) max = x[i*referees + j];
			if (x[i*referees + j] < min) min = x[i*referees + j];
			sum += x[i*referees + j];
		}
		aver[i] = (sum - min - max) / (referees - 2);
		cout << "\n去掉一个最高分 " << max << endl
			<< "去掉一个最低分 " << min << endl
			<< "最后得分为 " << aver[i] << endl;
		getch();   //作用是任意键继续
	}
}

void Rank(int players,int *&rank,double *aver)
{
	for (int i = 0; i < players; i++)
	{
		rank[i] = 1;
		for (int j = 0; j < players; j++)
		{
			if (aver[j] > aver[i]) rank[i]++;
		}
	}
}

void Print(int referees, int players, int *rank, double *x, double *aver)
{
	cout << setprecision(3) << showpoint;
	cout << "\nNo";
	for (int j = 0; j < referees; j++)
		cout << "     " << char('A' + j);
	cout << "   Aver    Rank" << endl;

	for (int i = 0; i < players; i++)
	{
		cout << i + 1 << "  ";
		for (int j = 0; j < referees; j++)
			cout << setw(6) << x[i*referees + j];
		cout << setw(6) << aver[i]
			<< setw(6) << rank[i] << endl;
	}
}

void FreeMemory(int *&rank, double *&x, double *&aver)
{

	delete[]x;
	delete[]aver;
	delete[]rank;
}

int Competetion()
{
	int referees, players;
	int *rank;
	double *x, *aver;   

	if (Init(referees, players) == -1)
		return -1;

	if (GetMemory(referees, players, rank, x, aver) == -2)
		return -2;

	Calculate(referees, players, rank, x, aver);

	Rank(players, rank, aver);

	Print(referees, players, rank, x, aver);

	FreeMemory(rank, x, aver);

	return 0;
}