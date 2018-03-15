#include "matrix.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    cout<<"Enter r,c "<<endl;
    int r,c;
    cin>>r>>c;
    Mat<int>mat(r,c); 
/*    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int x;
            cin>>x;
            mat.setElem(i,j,x);
        }
    }
    cout<<mat.getRow()<<" "<<mat.getCol()<<endl;
    cout<<"hello"<<endl;
    mat.PrintMat();
  */  return 0;
}
