#include<fstream>
#include<memory.h>
#include<iostream>
#include<cmath>

using namespace std;
bool isWhiteWin(bool board[200][200], int N);
bool isWhiteWin(bool board[200][200], int N, bool visited[200][200] , int x,int y);

int main()
{
	ifstream cin("input.txt");
	int N;
	int tc = 0;

	bool board[200][200];
	while(cin >> N)
	{
		if(N == 0) break;
		char c;
		for(int i = 0 ; i < N ; i++)
		{
			for(int j = 0 ; j < N; j++)
			{
				cin >> c;
				board[i][j] = c == 'w';
			}
		}

		bool result = isWhiteWin(board, N);
		cout << ++tc << " " << ( result ? 'W':'B') << '\n';
	
	}
	return 0;
}

bool isWhiteWin(bool board[200][200], int N)
{
	bool visited[200][200];
	memset(visited,0,sizeof(bool)*200*200);
	bool result = false;
	for(int i = 0 ; i < N; i++)
	{
		if(board[i][0])
		{
			visited[i][0] = true;
			result = isWhiteWin(board,N,visited,i,0);
			if(result)
				return result;
			visited[i][0] = false;
		}
	}
	return result;
}

bool isWhiteWin(bool board[200][200], int N, bool visited[200][200] , int x,int y)
{
	if(y == N-1)
		return true;

	int lowerX = max(0,x-1);
	int highestX = min(x+1, N-1);
	bool result = false;
	for(int i = lowerX; i <= highestX; i++)
	{
		int lowerY = y-1 + (int)(i/(x+1));
		int highestY = y+1 - (int)(x/(i+1));
		for(int j = highestY; j >= lowerY; j -= (2 - abs(i-x)))
		{
			if (j<0) continue;
			if((board[i][j])&&(!visited[i][j]))
			{
				visited[i][j] = true;
				result = isWhiteWin(board,N,visited,i,j);
				if(result)
					return result;
				visited[i][j] = false;
			}	
		}
	}

	return false;
}