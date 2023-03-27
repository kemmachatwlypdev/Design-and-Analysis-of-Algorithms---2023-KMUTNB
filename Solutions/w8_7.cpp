#include <bits/stdc++.h>
using namespace std;
int main()
{	
    int _set[100]; // = {3, 4, 5, 2}; 
    int sum; // = 6; 
    int n;// = 4; 
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>_set[i];
	}
	cin>>sum;
    
    int subset[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)   //first column = 0
    {
    	subset[i][0] = 1;
	}
    for (int i = 1; i <= sum; i++) //first row = 0
    {
        subset[0][i] = 0;	
	}

    for (int i = 1; i <= n; i++) 
	{
        for (int j = 1; j <= sum; j++) 
		{
            if (j < _set[i - 1])
            {
               subset[i][j] = subset[i - 1][j];	
			}
 
            if (j >= _set[i - 1])
            {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - _set[i - 1]];	
			}
        }
    }
        
     for (int i = 0; i <= n; i++)
     {
       	for (int j = 0; j <= sum; j++)
       	{
       		cout<<subset[i][j]<<" ";
	   	}
       	cout <<"\n";
     }
        
    return 0;
}
