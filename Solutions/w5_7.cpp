#include<bits/stdc++.h>
using namespace std;

char str[100];
void permute (char *a, int l, int r)
{ 
	if (l == r)
	{
		cout<<a<<endl;
	}
	else
	{ 
		for (int i = l; i <= r; i++)
		{ 
			char t   = str[ l ];
			str[ l ] = str[ i ];
			str[ i ] = t;
			permute(a, l+1, r);
			t 		 = str[ l ];
			str[ l ] = str[ i ];
			str[ i ] = t;
		}
	}
}


int main()
{ 
	cin>>str;
	int n = strlen(str);
	permute(str, 0, n-1);
}

