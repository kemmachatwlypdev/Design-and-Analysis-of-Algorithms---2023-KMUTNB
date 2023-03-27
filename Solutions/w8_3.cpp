#include <bits/stdc++.h>
using namespace std;
char X[100]; // = "acbcf";
char Y[100]; // = "abcdaf";   
int s_x; //= 5; 
int s_y; //= 6;  
int ar_ray[100][100];
int max(int a, int b){if( a > b ){ return a; }else{ return b; }}


int main()
{
	cin>>X;
	cin>>Y;
	s_x = strlen(X),s_y = strlen(Y);		
	for(int i=0 ; i <= s_x ; i++)
	{
		for(int j=0 ; j <= s_y ; j++)
		{
			if (i == 0 || j == 0){ ar_ray[i][j] = 0; }
			
		    else if ( X[i-1] == Y[j-1] )   
		    {
		        ar_ray[i][j] = 1 + ar_ray[i-1][j-1];
		    }	
			
			else
			{
				ar_ray[i][j] = max( ar_ray[i][j-1] , ar_ray[i-1][j] );
			}	
		}
	}
	
	for(int i=0 ; i <= s_x ; i++)
	{
		for(int j=0 ; j <= s_y ; j++)
		{
			cout<<ar_ray[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}
