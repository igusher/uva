#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n)
	{
		int sum = 1 ;
		for(int k = 1; k < n - 3; k++)
		{
			int i = k+1;
			int b = n - k - 2;
			int nn = b - i +1;
			
				sum += k*max(0,nn);
				//for(; i < n - k - 1; i++);
				i =  max (i , n - k -1);
			//	b= n-1;
				//sum+= ((n-i-1)+1) / 2 * (n-i-1);
				//cout<<(i == (n-k-1))<<endl;
			for(;i < n-1; i++)
				sum += n-i-1;

		}
		cout<< sum << endl;
		cin >> n;
	}
}