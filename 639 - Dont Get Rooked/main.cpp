#include<iostream>
#include<fstream>
#include<memory.h>

using namespace std;

int maxNumOfRooks(int map[4][4], int size, int x,int y);
bool check(int map[4][4], int size, int,int);


int main()
{
	int map[4][4];
	ifstream cin("input.txt");
	int size;
	cin >> size;
	char cell;
	while( size != 0)
	{
		memset(map,0,sizeof(int) * 16);
		for(int i = 0 ; i < size; i++)
		{
			for(int j = 0 ; j < size ; j++)
			{
				cin.get(cell);
				if(cell == 'X') 
					//wall
					map[i][j] = 10;
				else
					if(cell != '.')
						//skip
						j--;
			}
		}

		cout << maxNumOfRooks(map, size,0,0) << endl;
		cin >> size;
	}

	return 0;
}

int maxNumOfRooks(int map[4][4], int size,int x,int y)
{
	//if((x!=0 || y!=0))
	//	map[x][y] = 1;

	int maxCount = 0;
	int count = 0;
	for(int i = 0 ; i < size; i++)
		for(int j = 0 ; j < size; j++)
			if(map[i][j] == 0)
				if(check(map,size, i,j))
				{
					map[i][j] = 1;
					count =1 + maxNumOfRooks(map,size,i,j);
					if(count > maxCount)
						maxCount = count;
					map[i][j] = 0;
				}

	return maxCount;
}

bool check(int map[4][4], int size, int x, int y)
{
	for(int i = x+1  ; i < size; i++)
	{
		if(map[i][y] == 1)
			return false;
		if(map[i][y] == 10)
			break;
	}
	for(int i = x - 1 ; i>=0; i--)
	{
		if(map[i][y] == 1)
			return false;
		if(map[i][y] == 10)
			break;
	}
	for(int j = y+1 ; j < size; j++)
	{
		if(map[x][j] == 1)
			return false;
		if(map[x][j] == 10)
			break;
	}
	for(int j = y-1; j >=0 ; j--)
	{
		if(map[x][j] == 1)
			return false;
		if(map[x][j] == 10)
			break;
	}
}
