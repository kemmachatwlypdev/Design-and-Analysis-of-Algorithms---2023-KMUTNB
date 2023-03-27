#include<bits/stdc++.h>
using namespace std;

int D[100][100] ;
int ans[100];
int size = 4;




int fitness()
{
	int sum = 0;
	sum = sum + D[ 0 ][ ans[0] ];
	for(int i=0 ; i < size-1 ; i++)
	{
		sum = sum + D[ ans[i] ][ ans[i+1] ];
	}
	sum = sum + D[ ans[size-1]  ][ 0 ];
	return sum;
}


int best = 9999;
void brute(int j)
{
   	if (j == size )
   	{

   		best = fitness();
   		cout<<0<<" ";
   		for (int i = 0; i < size ; i++)
   		{
   			cout<<ans[i]<<" ";
		}
		cout<<0<<" ";
		cout<<best<<endl;
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
	 		cin>>D[i][j];
	 	}
	}
	size = size-1;
	for(int i=0 ; i < size ; i++){ans[i] = i+1;}
	brute(0);
    return 0;
}
