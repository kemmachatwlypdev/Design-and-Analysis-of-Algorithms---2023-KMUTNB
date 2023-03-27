#include <bits/stdc++.h>
using namespace std;
int main()
{
	int graph[100][100], dist[100][100], i, j, k, V = 0, n = 0, t1=0, t2=0, t3=0;
	for (i = 0; i < 100 ; i++)
	{
		for (j = 0; j < 100 ; j++)
		{
			graph[i][j] = 0;
		}
	}	
	cin>>V;
	cin>>n;
	for (i = 0; i < n; i++)
	{
		cin>>t1>>t2>>t3; 
		graph[t1][t2] = t3;
	}
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			dist[i][j] = graph[i][j];	
		}	
	}
	for (k = 0; k < V; k++) 
	{
		for (i = 0; i < V; i++) 
		{
			for (j = 0; j < V; j++) 
			{
				if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != 999999 && dist[i][k] != 999999))
				{
					dist[i][j] = dist[i][k] + dist[k][j];	
				}
			}
		}
	}
	for (int i = 0; i < V; i++) 
	{
		for (int j = 0; j < V; j++) 
		{
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
