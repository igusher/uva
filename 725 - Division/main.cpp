#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <fstream>

using namespace std;

int main()
{
	//ifstream fin("input.txt");
	int n = 0;
	bool digits[10];
	//fin >> n;
	cin>>n;
	while(n != 0)
	{
		int numOfSolutions = 0;
		for(int i = 1234; i < 98765; i++)
		{
			memset(digits, 1, sizeof(bool) * 10);
			int a = i;
			int b = a * n;
			if (( b > 98765) || (b < 10000)) continue;
			int distinctDigits = 0;
			if(a<10000)
			{
				distinctDigits = 1;
				digits[0] = 0;
			}
			do
			{
				int digit = a % 10;
				distinctDigits += digits[digit];
				digits[digit] = 0;
			} while((a/=10) > 0);

			do
			{
				int digit = b % 10;
				distinctDigits += digits[digit];
				digits[digit] = 0;
			} while((b/=10) > 0);

			if(distinctDigits == 10)
			{
				printf("%05d / %05d = %d\n", i*n , i,n);
				numOfSolutions++;
			}
		}
		if(numOfSolutions == 0)
			printf("There are no solutions for %d.\n", n);
		
		cin >> n;
		//fin >> n;
		if (n !=0) cout <<endl;
	}
	//fin.close();
}