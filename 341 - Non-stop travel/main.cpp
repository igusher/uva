#include <iostream>
#include <fstream>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>

using namespace std;
void strrev1(char *p)
{
  char *q = p;
  while(q && *q) ++q;
  for(--q; p < q; ++p, --q)
    *p = *p ^ *q,
    *q = *p ^ *q,
    *p = *p ^ *q;
}
void dijkstra(int * len, int , int, int*);

int N;
vector<int*> adjLists;
vector<int*> costs;
int * adjCount;

int main()
{
	
	
	ifstream cin("input.txt");
	
	int bigInt = 1 << 30;
	int start,end;
	cin >> N;	
	int tc = 1;
	while(N!=0)
	{
		adjLists.clear();
		costs.clear();
		adjCount = new int[N];
		for(int i = 0 ; i < N ; i++)
		{
			int edges;
			cin >> edges;
			int * cost = new int[edges];
			int * adjList = new int[edges];
			for(int j = 0 ; j < edges; j++)
			{
				cin>>adjList[j] >> cost[j];
				adjList[j]--; 
			}
			adjLists.push_back(adjList);
			costs.push_back(cost);
			adjCount[i] = edges;
		}
		cin >> start >> end;

		int * len = new int[N];
		int * prev = new int[N];
		for(int i = 0 ; i < N ; i++)
		{
			len[i] = bigInt;
			prev[i] = 0;
		}
		if(start == end)
		{
			printf("Case %d: Path = %d; %d second delay\n",tc++,start,0);
			cin >> N;
			continue;
		}
		dijkstra(len, start-1, end-1, prev);
		
		int pointer = 0;
		char* path = new char[N*2];
		pointer += sprintf(path, "%d", end);
		int prevNode = prev[end-1];
		while(prevNode != start -1)
		{
			pointer += sprintf(&path[pointer], " %d", prevNode+1);
			prevNode = prev[prevNode];
		}
		sprintf(&path[pointer], " %d\0", start);
		strrev1(path);
	//	cout<<len[end-1] << endl;
		
		printf("Case %d: Path = %s; %d second delay\n",tc++,path,len[end-1]);
		cin >> N;
	}
	return 0;
}

void dijkstra(int * len, int start, int end , int * prev)
{
	list<int> que;
	bool * visited = new bool[N];
	memset(visited,0,sizeof(bool)*N);
	int next;
	len[start] = 0;
	que.push_back(start);

	while(!que.empty())
	{
		next = *que.begin();
		que.pop_front();
		if(visited[next])
			continue;
		visited[next] = true;
		for(int i = 0 ; i < adjCount[next]; i++)
		{
			int adjV = adjLists.at(next)[i];
			int adjC = costs.at(next)[i];
			que.push_back(adjV);
			if(len[adjV] > len[next] + adjC )
			{
				len[adjV] = len[next] + adjC;
				prev[adjV] = next;
			}
		}
	}
}