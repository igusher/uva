#include <fstream>
#include <iostream>
#include <memory.h>
#include<stdio.h>

using namespace std;

int main()
{
	//ifstream cin("input.txt");
	//$100, $50, $20, $10, and $5 notes and $2, $1, 50c, 20c, 10c and 5c 
	// * 20
	unsigned long long ways[30100];
	int coins[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
	int CC=11;
	double sum;
	int sum_int;
	int a,b;
	scanf("%d.%d",&a,&b);
	while(a + b != 0)
	{
		
		sum_int = a* 100 + b;
		memset(ways,0,sizeof(long long)*(sum_int+1));
		ways[0] = 1;
		ways[1] = 1;
		for(int c = 0 ; c < CC; c++)
		{
			for(int i = coins[c]; i <= sum_int; i++)
			{
				ways[i] += ways[i - coins[c]];
			}
		}
		printf("%3d.%.2d%17llu\n",a,b,ways[sum_int]);
		
		//cout <<sum  << " " << ways[sum_int]<< endl;
		//cin>>sum;
		scanf("%d.%d",&a,&b);
	}
	return 0;
}