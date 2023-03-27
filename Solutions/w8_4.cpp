#include <bits/stdc++.h>
using namespace std;
 
int max(int a, int b) { if(a > b){ return a; }else{ return b; } }
int min(int a, int b) { if(a < b){ return a; }else{ return b; } } 

int main()
{
 	int size; // = 4;
 	int arr[100]; // = { 3, 9, 1, 2  };
	int table[100][100];
	
	
 	cin>>size;
	for(int i=0 ; i < size ; i++)
	{
		cin>>arr[i]; 	
	}
	
	
    for (int gap = 0; gap < size; ++gap) 
	{
        for ( int i = 0, j = gap ; j < size ; ++i, ++j ) 
		{
			//cout<<i<<" "<<j<<endl;
			//-----------------------------
			int x = 0;
			if( (i + 2) <= j )
			{
				x = table[i + 2][j];
			}
			//-----------------------------
			int y = 0;
			if( (i + 1) <= (j - 1) )
			{
				y = table[i + 1][j-1];
			}
			//-----------------------------
			int z = 0;
			if( i <= (j - 2) )
			{
				z = table[i][j - 2];
			}
			//-----------------------------
			table[i][j] = max( arr[i] + min(x, y), arr[j] + min(y, z) );
        }
    }	
    
    for (int i = 0; i < size; i++) 
	{
	    for (int j = 0; j < size; j++) 
		{
			cout<<table[i][j]<<" ";
		}	
		cout<<endl;
	}
    
    return 0;
}


//int optimalStrategyOfGame(int* arr, int n)
//{
//    int table[n][n];
//    for (int gap = 0; gap < n; ++gap) 
//	{
//        for (int i = 0, j = gap; j < n; ++i, ++j) 
//		{
//            // Here x is value of F(i+2, j),
//            // y is F(i+1, j-1) and
//            // z is F(i, j-2) in above recursive
//            // formula
//            int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
//            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
//            int z = (i <= (j - 2)) ? table[i][j - 2] : 0;
// 
//            table[i][j] = max( arr[i] + min(x, y), arr[j] + min(y, z));
//        }
//    }
//    return table[0][n - 1];
//}
   // int n = sizeof(arr1) / sizeof(arr1[0]);
  //  printf("%d\n", optimalStrategyOfGame(arr1, n));
//    int arr2[] = { 2, 2, 2, 2 };
//    n = sizeof(arr2) / sizeof(arr2[0]);
//    printf("%d\n",
//           optimalStrategyOfGame(arr2, n));
// 
//    int arr3[] = { 20, 30, 2, 2, 2, 10 };
//    n = sizeof(arr3) / sizeof(arr3[0]);
//    printf("%d\n",
//           optimalStrategyOfGame(arr3, n));
            //int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
            //int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
            //int z = (i <= (j - 2)) ? table[i][j - 2] : 0;
