#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
int main()
{
	map<string,int> arrayMap;
	ifstream cin("input.txt");
	string * arrays;
	int * dSizes[10];
	int * dimensions;
	int * elemSize;
	int * baseAddr;
	int *upper[10];
	int *lower[10];
	int N,R;
	cin >> N >> R;
	dimensions = new int[N];
	arrays = new string[N];
	elemSize = new int[N];
	baseAddr = new int[N];
	
	for(int i = 0 ; i < 10 ; i++)
	{
		lower[i] = new int[N];
		upper[i] = new int[N];
		dSizes[i] = new int[N];
	}

	for(int i = 0 ; i < N; i++)
	{
		
		cin >> arrays[i] >> baseAddr[i]  >> elemSize[i] >> dimensions[i];
		arrayMap.insert(pair<string,int>( arrays[i],i));
		for(int j = 0 ; j < dimensions[i]; j++)
		{
			cin >> lower[j][i] >> upper[j][i];
		}
		for(int j = dimensions[i] - 1; j >= 0; j--)
		{
			if(j == dimensions[i] - 1)
				dSizes[j][i] = elemSize[i];
			else
				dSizes[j][i] = dSizes[j+1][i] * (upper[j+1][i] - lower[j+1][i]+1);
		}
	}

	string reqArr;
	int reqArrId;
	int reqDim;
	int result;
	for(int i = 0 ; i < R; i++)
	{
		result = 0;
		cin >> reqArr;
		reqArrId =  arrayMap[reqArr];
		cout << reqArr << "[";
		for(int j = 0 ; j < dimensions[reqArrId]; j++)
		{
			cin >> reqDim;
			cout << reqDim;
			if( j+1 < dimensions[reqArrId])
				cout<<", ";
			result += (reqDim - lower[j][reqArrId]) * dSizes[j][reqArrId];
		}
		result += baseAddr[reqArrId];
		cout<<"] = " << result << endl;
	}

	for(int i = 0 ; i < 10 ; i++)
	{
		delete [] lower[i];
		delete [] upper[i];
		delete [] dSizes[i];
	}

	delete [] dimensions;
	delete [] arrays;
	delete [] elemSize;
	delete [] baseAddr;
}