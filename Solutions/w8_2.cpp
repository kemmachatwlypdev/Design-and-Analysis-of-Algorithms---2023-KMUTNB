#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { if(a > b){ return a; }else{ return b; } }
int weight[100]; 
int value[100];  
int row = 0; 
int col = 0; 
int ar_ray[100][100];  	 
	 
int main()
{	
	cin>>row;
	for(int i=0 ; i < row ; i++)
	{
		cin >> weight[i] >> value[i];
	}	
	cin>>col;
//------------------------------------	
	for(int i=0 ; i <= row ; i++) //Row
	{
		for(int j=0 ; j <= col ; j++)  //Weight
		{
            if (i == 0 || j == 0) 
            {
                ar_ray[i][j] = 0;
            }	
            else if ( weight[i - 1] <= j )  //Previous < Max Weight => can insert
            {
                ar_ray[i][j] = max( value[i - 1] + ar_ray[i - 1][ j - weight[i - 1] ], ar_ray[i - 1][j] );
            }
            else
            {
                ar_ray[i][j] = ar_ray[i - 1][j];
            }
		}
	}
//------------------------------------	
	for(int i=0 ; i < row+1 ; i++)
	{
		for(int j=0 ; j < col+1 ; j++)
		{
			cout<<ar_ray[i][j]<<" ";
		}
		cout<<endl;
	}
//------------------------------------	
    return 0;
}
