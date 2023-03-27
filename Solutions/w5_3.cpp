#include<bits/stdc++.h>
using namespace std;
int size = 0;
int _set[100];

void printPowerSet()
{ 
	for(int i = 0 ; i < (int)pow(2.0,size) ; i++)
	{ 
		for(int j = 0; j < size; j++)
		{ 
			if( i & (1<<j) )
			{
				cout<<_set[j]<<" ";	
			}
		}
		cout<<endl;
	}
}
int main()
{
	cin>>size;
	for( int i=0 ; i < size ; i++ )
	{
	 	cin>>_set[i];
	}
	
	printPowerSet();
    return 0;
}


