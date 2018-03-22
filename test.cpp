#include<iostream>
#include<stdlib.h>
#include "matrix.h"
#include "matrix.cpp"

int main()
{ 
    std::cout<<"Enter r,c "<<std::endl;
    int r,c;
    std::cin>>r>>c;
    Mat<int>mat(r,c);    
    std::cin>>mat;
    Mat<int> add(mat);
    Mat<int> mul(mat);
    add+=mat;
    std::cout<<"addition : "<<add<<std::endl;
    mul*=mat.transpose();
    std::cout<<"transpose : "<<mat.transpose()<<std::endl;
    std::cout<<"mult : "<<mul<<std::endl;
    return 0;
}
