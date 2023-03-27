#include<bits/stdc++.h>
using namespace std;

int J[10][10];
int ans[10]; 
int size = 0;
int fitness()
{
	int sum = 0;
	for(int i=0 ; i < size ; i++)
	{
		sum = sum + J[i][ ans[i] ];
	}
	return sum;
}
void brute(int j)
{
   	if (j == size)
   	{	
		for(int i=0 ; i < size ; i++)	
		{	
			cout<<ans[i]<<" ";	
		}	
		cout<<fitness()<<endl;		
	}
   	else
   	{
       for (int i = j ; i < size ; i++)
       {   		
	   		int T = ans[j];
	   		ans[j] = ans[i]; 
			ans[i] = T;
	      	brute(j+1);
			T = ans[j];
	   		ans[j] = ans[i]; 
			ans[i] = T;
		}
   	}
}
int main()
{
	cin>>size;
	for( int i=0 ; i < size ; i++ )
	{
		for( int j=0 ; j < size ; j++ )
		{		
	 		cin>>J[i][j];
	 	}
	}
	
	for(int i=0 ; i < size ; i++){ans[i] = i+1;}
	brute(0);
	
    return 0;
}
