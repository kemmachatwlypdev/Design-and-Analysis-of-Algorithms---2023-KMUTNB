#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	cin>>n;
	int dp2[100][100]; 
    //initail
    for(int i = 0; i <= n; i++)
    {
    	dp2[i][0] = 1;
	}
    for(int i = 0; i <= n; i++)
    {
    	dp2[i][i] = 1;
	}
    for(int i = 1; i <= n; i++)
	{
        for(int j = 1; j <= i; j++)
		{
            dp2[i][j] = dp2[i-1][j-1] + dp2[i-1][j];
        }
    }    
    //print
    for(int i = 0; i <= n; i++)
    {
	    for(int j = 0; j <= n; j++)
	    {
	    	cout<<dp2[i][j]<<" ";
	    }	
	    cout<<endl;
    }
    return 0;
}
