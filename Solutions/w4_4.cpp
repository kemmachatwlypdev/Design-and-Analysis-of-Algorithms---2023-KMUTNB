#include<bits/stdc++.h>
using namespace std;

class matrix
{
      public:
             int t[64][64];
             int s;
      matrix()
      {
              s = 0;
      }
      void print()
      {
           for(int i=0;i<s;i++)
           {
                   for(int j=0;j<s;j++)
                   {
                           cout<<t[i][j]<<" ";
                   }
                   cout<<endl;
           }
      }
      
      
};

matrix plus_matrix(matrix a, matrix b)
{
       matrix m;
       m.s = a.s;
       for(int i=0;i<a.s;i++)
       {
               for(int j=0;j<a.s;j++)
               {
                       m.t[i][j] = a.t[i][j] + b.t[i][j];
               }
       }
       return m;
}
matrix diff_matrix(matrix a, matrix b)
{
	matrix m;
	m.s = a.s;
	for(int i=0;i<a.s;i++)
	{
		for(int j=0;j<a.s;j++)
		{
			m.t[i][j] = a.t[i][j] - b.t[i][j];
		}
	}
	return m;
}
matrix strassen2M2(matrix X, matrix Y)
{
       matrix m;
       m.s = 2;
       int a = X.t[0][0];
       int b = X.t[0][1];
       int c = X.t[1][0];
       int d = X.t[1][1];
       int e = Y.t[0][0];
       int f = Y.t[0][1];
       int g = Y.t[1][0];
       int h = Y.t[1][1];
       
       int p1 = a * (f-h);
       int p2 = (a+b)*h;
       int p3 = (c+d)*e;
       int p4 = d*(g-e);
       int p5 = (a+d)*(e+h);
       int p6 = (b-d)*(g+h);
       int p7 = (a-c)*(e+f);
       
       cout<<p1<<"\n"<<p2<<"\n"<<p3<<"\n"<<p4<<"\n"<<p5<<"\n"<<p6<<"\n"<<p7<<"\n";
       
       m.t[0][0] = p5+p4-p2+p6;
       m.t[0][1] = p1+p2;
       m.t[1][0] = p3+p4;
       m.t[1][1] = p1+p5-p3-p7;
       
       return m;
}
matrix split (matrix m, int p1, int p2, int p3, int p4)
{
       int x=0, y=0;
       matrix n;
       n.s = m.s / 2;
       for(int i=p1 ; i<p2 ; i++)
       {
               y=0;
               for(int j=p3 ; j<p4 ; j++)
               {
                       n.t[x][y] = m.t[i][j];
                       y++;
               }
               x++;
       }
       return n;
}
matrix combine (matrix m, matrix sub, int p1, int p2)
{
       int x=0, y=0;
       for(int i=p1 ; i < p1+sub.s ; i++)
       {
               y=0;
               for(int j=p2 ; j < p2+sub.s ; j++)
               {
                       m.t[i][j] = sub.t[x][y];
                       y++;
               }
               x++;
       }
       return m;
}
matrix strassen(matrix A, matrix B)
{
       if ( A.s <= 2 ){ return strassen2M2(A, B);}
       
       matrix a = split(A, 0, A.s/2, 0, A.s/2);
       matrix b = split(A, 0, A.s/2, A.s/2, A.s);
       matrix c = split(A, A.s/2, A.s, 0, A.s/2);
       matrix d = split(A, A.s/2, A.s, A.s/2, A.s);
       matrix e = split(B, 0, B.s/2, 0, B.s/2);
       matrix f = split(B, 0, B.s/2, B.s/2, B.s);
       matrix g = split(B, B.s/2, B.s, 0, B.s/2);
       matrix h = split(B, B.s/2, B.s, B.s/2, B.s); 
       
       matrix p1 = strassen( a, diff_matrix(f,h) );
       matrix p2 = strassen( plus_matrix(a,b), h);
       matrix p3 = strassen( plus_matrix(c,d), e);
       matrix p4 = strassen( d, diff_matrix(g,e) );
       matrix p5 = strassen( plus_matrix(a,d), plus_matrix(e,h) );
       matrix p6 = strassen( diff_matrix(b,d), plus_matrix(g,h) );
       matrix p7 = strassen( diff_matrix(a,c), plus_matrix(e,f) );
       
       p1.print(); p2.print();p3.print(); p4.print();p5.print(); p6.print();p7.print();
       
       matrix C11 = plus_matrix( diff_matrix( plus_matrix(p5,p4), p2), p6);
       matrix C12 = plus_matrix(p1 , p2);
       matrix C21 = plus_matrix(p3 , p4);
       matrix C22 = diff_matrix( diff_matrix( plus_matrix(p1, p5), p3), p7);   
         
       matrix C;
       C.s = (2 * C11.s);
       C = combine(C, C11, 0, 0);
       C = combine(C, C12, 0, C12.s);
       C = combine(C, C21, C21.s, 0);
       C = combine(C, C22, C22.s, C22.s);
       
       return C;
}

int main()
{
    matrix A,B,C;
    int my_s = 0,t=0;
    cin>>my_s;
    
    A.s = my_s;
    B.s = my_s;
    C.s = my_s;
    
    for(int i=0;i<my_s;i++)
    {
            for(int j=0;j<my_s;j++)
            {
                    cin>>t;
                    A.t[i][j] = t;
            }
    }
    for(int i=0;i<my_s;i++)
    {
            for(int j=0;j<my_s;j++)
            {
                    cin>>t;
                    B.t[i][j] = t;
            }
    }
    for(int i=0;i<my_s;i++)
    {
            for(int j=0;j<my_s;j++)
            {
                    C.t[i][j] = 0;
            }
    }
    
//    A.print();
//    B.print();
    
    C = strassen(A,B);
    C.print();
    
    return 0;
}

       
              
               
                       
           
           
