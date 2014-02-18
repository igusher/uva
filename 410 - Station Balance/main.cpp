#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
#include<stdio.h>
#include<memory.h>

using namespace std;

int compare(const void * a, const void * b)
{
	return  *((int*)b) -  *((int*)a) ;
}

int main()
{

	ifstream cin("input.txt");
	int C, S;
	int masses[10];
	int chambers[5];
	double avrg = 0;
	int tc = 0;
	while(cin >> C >> S)
	{
		avrg = 0;
		tc++;
		printf("Set #%d\n",tc);
		memset(chambers,0, sizeof(int)*5);
		for(int i = 0 ; i < S; i++)
		{
			cin >> masses[i];
			avrg += masses[i];
		}
		avrg /= C;
		qsort(masses, S, sizeof(int),compare);
		
		for(int i = 0 ; i < C; i++)
		{

			chambers[i] += masses[i];
			cout<<" "<< i << ":";
			if ( S > C*2 - i - 1)
				cout<<" "<<masses[C*2 -i - 1];
			cout<<" " <<masses[i];
			cout<<endl;
		}
		for(int i = C ; i < S; i++)
			chambers[2*C - i - 1] += masses[i];
		double imbalance=0;
		for(int i = 0 ; i < C ; i++)
			imbalance += abs(chambers[i] - avrg);
		printf("IMBALANCE = %.5f\n\n",imbalance);
	}
	return 0;
}