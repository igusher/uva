#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream cin ("input.txt");
	int size;
	int initSeq[21];
	int checkSeq[21];
	int len[21];
	cin >> size;
	int next;

	for(int i = 0 ; i < size; i++)
	{
		cin >> initSeq[i+1];
	}

	

	while( cin >> next)
	{
		checkSeq[next] = 1;
		len[1] = 1;
		for(int i = 1 ; i < size ; i++)
		{
			len[i+1] = 1;
			cin >> next;
			checkSeq[next] = i+1;
		}
		for(int i = 1 ; i <= size ; i++)
			for(int j = i-1; j >= 1 ; j--)
				if(initSeq[checkSeq[j]] < initSeq[checkSeq[i]])
					if(len[i] < len[j] + 1)
						len[i] = len[j]+1;
		int maxSeq = 0;
		for(int i = 1 ; i <= size; i++)
			if(len[i] > maxSeq)
				maxSeq = len[i];

		cout << maxSeq << endl;
	}
}