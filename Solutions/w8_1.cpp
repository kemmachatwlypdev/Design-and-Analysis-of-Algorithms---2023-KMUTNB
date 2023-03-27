#include <bits/stdc++.h>
using namespace std;
int arr[1000];    
int n = 0; 
int MatrixChainOrder(int i, int j)
{
    if (i == j){ return 0; }
    int min = 99999999999;
    int count;
    for (int k = i; k < j; k++)  
    {
        count = MatrixChainOrder(i, k) + MatrixChainOrder(k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (count < min) { min = count; }
    }
    return min; 
}
int main()
{
	cin>>n;
	for(int i=0 ; i < n ; i++)
	{
		cin>>arr[i] >> arr[i+1];
	}
	n = n + 1;
//	for(int i=0 ; i < n ; i++)
//	{
//		cout<<arr[i]<<endl;
//	}
	cout<<MatrixChainOrder(1, n - 1);
}
