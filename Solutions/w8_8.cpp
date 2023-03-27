#include <iostream>
using namespace std;
class graph
{
public:	
	//-----------------------------------------------------------------
	int edges[1000][1000];
	int n_vertices;				//Node
	int n_edges;				//Line
	//-----------------------------------------------------------------
	void print_graph()
	{
		for( int i=0 ; i < n_vertices ; i++)
		{
			cout<<i<<" : ";		
			for(int j=0 ; j <= n_vertices ; j++ )
			{
				if(edges[i][j] > 0)
				{
					cout<<j<<" ";
				}
			}
			cout<<endl;
		}
	}
	//-----------------------------------------------------------------
	void initial_graph(int n)
	{
		n_vertices 	= n;
		n_edges 	= 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				edges[i][j] = 0;
			}
		}
	}
	//-----------------------------------------------------------------
	void insert_graph(int x, int y ) //direct grpah
	{
		edges[x][y] = 1;
		n_edges++;
	}
	void insert_graph(int x, int y,int z) //direct grpah
	{
		edges[x][y] = z;
		n_edges++;
	}
	//-----------------------------------------------------------------
	bool tc[1000][1000];
	bool visited_dfs[1000]; 
	int index_i; 
	int first_time;
	void DFSUtil(int start)
	{
		if(first_time > 0)			     // first time case start visit is not count first node but after travel can access own node It is counted.
		{	
			visited_dfs[start] = true;	//DFS can access any node
			tc[index_i][start] = 1;		//save all node is accessed except first time | index_i = row --> access any node is column
		}
		first_time++;

		for (int j=0 ; j < n_vertices ; j++ )							//DFS
		{
			if ( edges[start][j] > 0  && visited_dfs[j] == false)
			{
				DFSUtil(j);
			}
		}
	}
	void transitiveClosure()
	{
		//----------print matrix --------------
		for (int i = 0; i < n_vertices ; i++)
		{
			for (int j=0; j<n_vertices ; j++)
			{
				cout << edges[i][j] << " ";
			}
			cout << endl;
		}
		//-------- reset -------------------
		for (int i = 0; i < n_vertices ; i++)
		{
			for (int j=0; j<n_vertices ; j++)
			{
				tc[i][j] = false;
			}
		}
		//-------- recurive ----------------
		for (int i = 0; i < n_vertices ; i++)
		{
			for (int j=0; j<n_vertices ; j++) //clear
			{
				visited_dfs[j] = false;
			}
			first_time = 0;
			index_i = i;
			DFSUtil(i);
		}
		//---------------------------------
		for (int i=0; i < n_vertices; i++)
		{
			for (int j=0; j<n_vertices ; j++)
			{
				cout << tc[i][j] << " ";
			}
			cout << endl;
		}
		//--------------------------------
	}
	//-----------------------------------------------------------------
	int reach[1000][1000];
	void Warshall()
	{
		for (int i = 0; i < n_vertices; i++)			//reset
		{
			for (int j = 0; j < n_vertices; j++)
			{
				reach[i][j] = edges[i][j];
			}
		}
		for (int k = 0; k < n_vertices; k++)			//R1 To R4
		{
			////---------------------------------------------
//			for(int ii=0 ; ii < n_vertices; ii++)
//			{
//				for(int jj=0 ; jj < n_vertices; jj++)
//				{ 
//					cout<<( reach[k][jj] && reach[ii][k])<<" ";
//				}
//				cout<<endl;
// 			}
//			cout<<"---------------------------"<<endl;
			////---------------------------------------------
			for (int i = 0; i < n_vertices; i++)		// X
			{
				for (int j = 0; j < n_vertices; j++)	//Y
				{
					reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]); // create table and matching 
				}
			}
		}
		for(int ii=0 ; ii < n_vertices; ii++)
		{
			for(int jj=0 ; jj < n_vertices; jj++)
			{ 
				cout<<reach[ii][jj]<<" ";
			}
			cout<<endl;
 		}
	}
	//-----------------------------------------------------------------
};
int main() 
{
    graph *g = new graph();
    int n,t,c1,c2;
    cin>>n;
    g->initial_graph(n);
    cin>>t;
    for(int i=0;i<t;i++)
    {
    	cin>>c1>>c2;
    	g->insert_graph(c1, c2);
	}
	g->Warshall();
	return 0;
}
