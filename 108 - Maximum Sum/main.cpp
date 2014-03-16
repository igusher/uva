#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream cin("input.txt");
	int arr[101][101];
	int N;
	while(cin >> N)
	{
		memset(arr,0,sizeof(int)*101*101);
		for(int i = 0 ; i < N ; i++)
		{
			//cin >> arr[i][0];
			for(int j = 0 ; j  < N ; j++)
			{
				cin >> arr[i][j];
				//arr[i][j] += arr[i][j-1];
			}
		}

		long max = -1280000;
		long temp[100];
		for(int left = 0 ; left < N ; left++)
		{
			memset(temp,0,sizeof(temp));
			for(int right = left ; right < N ; right++)
			{
				for(int row = 0 ; row < N ; row++)
				{
					temp[row]+= arr[row][right];
				}
				long sum = 0;
				for(int i = 0 ; i < N; i++)
				{
					sum += temp[i];
					if(max < sum)
							max = sum;
					if(sum < 0)
					{
						sum = 0;
					}

				}
			
			}
		
		}
		cout<<max<<endl;
	}
	
	return 0;
}