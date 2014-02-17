#include<iostream>
#include<fstream>
#include<memory.h>
#include<stdio.h>
#include<cstdio>
#include<algorithm>

using namespace std;

unsigned long next(unsigned long);
unsigned long nextEven(unsigned long);
unsigned long nextOdd(unsigned long);
	
int main()
{
	ifstream cin("input.txt");
	unsigned long from, to;
	bool visited[1000001];
	unsigned long len;
	 long nextN = -1;
	unsigned long maxChainLen = 0;
	unsigned long chainLen = 0;
	int f,t;
	while(scanf ("%d %d", &f, &t) != EOF )
	{
		from = f;
		to = t;
		if(from > to)
			swap(from, to);
		maxChainLen = 0;
		
		memset(visited,0,sizeof(bool)*(1000001));
		for(long i = to; i >= from; i--)
		{

			if(visited[i])
				continue;
			chainLen = 1;
			nextN = i;
			while(nextN != 1){
				nextN = next(nextN);
				chainLen++;
				if (nextN <= to) 
					visited[nextN] = true;
			}
			if (chainLen > maxChainLen)
			{
				maxChainLen = chainLen;
			}
		}

		printf ("%d %d %d\n", f, t, maxChainLen);
	}
	return 0;
}

unsigned long next(unsigned long num)
{
	if ((num & 1) == 0)
		return nextEven(num);
	return nextOdd(num);
}

unsigned long nextEven(unsigned long num)
{
	return num/2;
}

unsigned long nextOdd(unsigned long num)
{
	return num*3 + 1;
}
