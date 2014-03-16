#include<stdio.h>
#include<iostream>
#include<fstream>
#include<queue>
#include<unordered_map>


using namespace std;

int main()
{
	ifstream cin ("input.txt");

	int NC;
	int tc = 0;
	int uniqueNodes = 0;
	bool **adjMatrix;
	bool *visited;
	unordered_map<int,int> nodes;
	int reached;

	int *fromEdge;
	int *toEdge;
	
	int fromQuery;
	int ttl;
	queue<int> nextNodes;
	int numOfNext = 0;

	cin >> NC;
	while(NC != 0)
	{
		
		fromEdge = new int[NC];
		toEdge = new int[NC];
		for(int edge = 0 ; edge < NC; edge++)
		{
			cin>> fromEdge[edge] >> toEdge[edge];
			std::unordered_map<int,int>::const_iterator got = nodes.find(fromEdge[edge]);
			if ( got == nodes.end() )
			{
				nodes.insert(pair<int,int>(fromEdge[edge], uniqueNodes++));
			}
			got = nodes.find(toEdge[edge]);
			if ( got == nodes.end() )
			{
				nodes.insert(pair<int,int>(toEdge[edge], uniqueNodes++));
			}
		}
		
		adjMatrix = new bool *[uniqueNodes];
		for(int i = 0; i < uniqueNodes; i++)
		{
			adjMatrix[i] = new bool[uniqueNodes];
			memset(adjMatrix[i],0, sizeof(bool) * uniqueNodes);
		}
		

		
		for(int i = 0 ; i < NC; i++)
		{
			int f = nodes[fromEdge[i]];
			int t = nodes[toEdge[i]];
			adjMatrix [f] [t] = 1;
			adjMatrix [t] [f] = 1;
		}

		visited = new bool[uniqueNodes];
		

		cin >> fromQuery >> ttl;
		while(fromQuery != 0 || ttl != 0)
		{
			int reached = 0;
			while(!nextNodes.empty())
				nextNodes.pop();
			memset(visited,0,sizeof(bool)*uniqueNodes);

			nextNodes.push(nodes[fromQuery]);
			//reached++;
			for(int tempttl = ttl ; tempttl >= 0 ; tempttl--)
			{
				int numOfNext = nextNodes.size();
				for(int nodeInQueue = 0; nodeInQueue < numOfNext; nodeInQueue++)
				{
					int next = nextNodes.front();
					if(!visited[next])
					{
						visited[next] = 1;
						reached ++ ;
						for(int node = 0 ; node < uniqueNodes; node++)
						{
							if (node == next ) continue;
							if (adjMatrix[node][next])
								nextNodes.push(node);
						}
					}
					nextNodes.pop();
				}
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++tc, uniqueNodes - reached, fromQuery, ttl);
			cin >> fromQuery >> ttl;
		
		}

		uniqueNodes = 0;

		nodes.clear();
		cin >> NC;

		delete [] visited;

		delete []fromEdge;
		delete []toEdge;
		
		for(int i = 0; i < uniqueNodes; i++)
			delete[] adjMatrix[i];
		delete [] adjMatrix;
	}

	return 0;
}
