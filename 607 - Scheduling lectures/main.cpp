#include <iostream>
#include <fstream>
#include <list>


using namespace std;

int main()
{
	list<pair<int,int>> times;
	list<int> times2;
	ifstream cin("input.txt");
	int topicNum, C, lectureLen;
	int topics[1000];
	int sums[1000];
	int res[1000][500];
	while(!cin.eof())
	{
		cin >> topicNum >> lectureLen >> C;
		for(int t = 0 ; t < topicNum; t++)
		{
			cin >> topics[t];
			sums[t] = topics[t];
			if(t>0)
				sums[t] += sums[t-1];
		}
		int lec=0;
		int cur = 0;
		for(int t = 0 ;t < topicNum; t++)
		{
			if (cur + topics[t] < lectureLen)
			{
				res[lec][cur+topics[t]] = t;
				times.push_back(pair<int,int>(cur+topics[t], t));
			}
			else
				break;
		}
		
		for(list<int>::iterator it=times.begin(); it!=times.end(); ++it)
		{
			int nextT = *it + 1;
			for(;nextT < topicNum; nextT++)
			{
				
			}
		}
	}
	return 0;
}