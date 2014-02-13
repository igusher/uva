#include <iostream>
#include <stdio.h>
#include <cmath>
#include <fstream>

using namespace std;

void place(int q[9], int x);
bool check(int q[9], int x, int y);
void printSolution(int q[9]);

int solutionCount = 0;
int x,y;

int main()
{
	int tcNum = 0;
	int q[9];	
	ifstream cin("input.txt");
	
	cin >> tcNum;
	
	for(int tc = 0; tc < tcNum; tc++)
	{
		cout<<"SOLN COLUMN\n";
		cout<<"# 1 2 3 4 5 6 7 8\n\n";
		solutionCount = 0;
		cin >> x >> y;
		q[x] = y;
		place(q,1);
		cout <<'\n';
	}
	return 0;
}

void place(int q[9], int xi)
{
	for(int yi = 1 ; yi < 9 ; yi ++)
	{
		if(!check(q, xi, yi))
		{
			continue;
		}
		q[xi] = yi;
		if (xi == 8)
		{	
			if(q[y] == x)
				printSolution(q);
		}
		else
		{
			place(q,xi+1);
		}
	}
}

bool check(int q[9], int x, int y)
{
	for(int xi = 1; xi < x; xi++)
	{
		if(q[xi] == y) return false;
		if(abs(xi - x) == abs(q[xi] - y)) return false;
	}
	return true;
}

void printSolution(int q[9])
{
	cout << ++solutionCount <<" ";
	for( int i = 1 ; i < 9 ; i++)
	{
		cout <<q[i] << " ";
	}
	cout << endl;
}