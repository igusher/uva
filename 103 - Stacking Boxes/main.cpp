#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <memory.h>

using namespace std;
int compare(const void* a, const void* b)
{
	return ( *(int*)a - *(int*)b);
}

bool compareBoxes(int *box1, int *box2, int dim);

int buildAdjList(int boxes[30][10], int boxCount, int dim, int source, int *adjList);
void normalizeDimensions(int * box, int len);
void findPaths(int adjList[30][30], int adjCount[30], int boxCount, int len[30], bool visited[30], int next[30]);
int findLen(int adjList[30][30], int adjCount[30], int box, int len[30], bool visited[30], int next[30]);

int main()
{

	//ifstream cin("input.txt");
	int boxCount;
	int dim;
	while(!cin.eof())
	{
		cin >> boxCount >> dim;
		int boxes[30][10];
		int adjList[30][30];
		int adjCount[30];
	
		for(int box = 0 ; box < boxCount; box++)
		{
			for(int d = 0 ; d < dim; d++)
			{
				cin >> boxes[box][d];
			}
			normalizeDimensions(boxes[box], dim);
		}

		for(int box = 0 ; box< boxCount; box++)
		{
			adjCount[box] = buildAdjList(boxes, boxCount, dim, box, adjList[box]);
		}
		bool visited[30];
		int len[30];
		int next[30];
		memset(visited,0,sizeof (bool)*30);
		memset(len,0,sizeof (int) * 30);
		memset(next,0,sizeof (int) * 30);
		int max = 1;
		int start = 0;
		findPaths(adjList,adjCount,boxCount,len,visited,next);
		for(int box = 0; box < boxCount; box++)
		{
			if(max < len[box])
			{
				max = len[box];
				start = box;
			}
		}

		cout<<max << endl;
		while(start != -1)
		{
			cout <<start +1<< " ";
			start = next[start];
		}
		cout<<endl;
	}
	return 0;
}
void findPaths(int adjList[30][30], int adjCount[30], int boxCount, int len[30], bool visited[30], int next[30])
{
	for(int box = 0 ; box < boxCount; box++)
	{
		if(visited[box] == true)
			continue;

		findLen(adjList,adjCount,box,len,visited, next);
	}
}

int findLen(int fullAdjList[30][30], int adjCount[30], int box, int len[30], bool visited[30], int next[30])
{
	
	int max = -1;
	if(adjCount[box] <= 0)
	{
		len[box] = 1;
		visited[box] = true;
		next[box] = -1;
		return 1;
	}
	int * adjList = fullAdjList[box];
	int adjBox;
	for(int adj = 0 ; adj < adjCount[box]; adj++)
	{
		adjBox = adjList[adj];
		if(!visited[adjBox])
		{
			findLen(fullAdjList,adjCount,adjBox, len,visited,next);
		}

		if( max < len[adjBox])
		{
			max = len[adjBox];
			next[box] = adjBox;
			len[box] = max+1;
		}
	}
	visited[box] = true;
	return len[box];
}


void normalizeDimensions(int * box, int len)
{
	qsort(box,len,sizeof(int), compare);
}

int buildAdjList(int boxes[30][10], int boxCount, int dim, int source, int *adjList)
{
	int adjCount = 0;
	for(int box = 0 ; box < boxCount; box++)
	{
		if(compareBoxes(boxes[source],boxes[box], dim))
		{
			adjList[adjCount] = box;
			adjCount ++;
		}
	}
	return adjCount;
}

bool compareBoxes(int * box1, int * box2, int dim)
{
	for(int d = 0 ; d < dim; d++)
		if (box1[d] >= box2[d])
			return false;
	
	return true;
}