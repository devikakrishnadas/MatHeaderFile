#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "matrix.h"
#include "matrix.cpp"

using namespace std::chrono;

void routine(Mat<int> &m,int sz)
{
    Mat<int>add;
    Mat<int>mul;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    add = m + m;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    mul = m * m;
    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    add+=m;
    high_resolution_clock::time_point t4 = high_resolution_clock::now();
    mul*=m;
    high_resolution_clock::time_point t5 = high_resolution_clock::now();
    m = m.transpose();
    high_resolution_clock::time_point t6 = high_resolution_clock::now();

    std::cout<<"Time taken for functions when size is "<<sz<<" :"<<std::endl;
    std::cout<<"+  : "<<(int)std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()<<std::endl;
    std::cout<<"*  : "<<(int)std::chrono::duration_cast<std::chrono::microseconds>(t3-t2).count()<<std::endl;
    std::cout<<"+= : "<<(int)std::chrono::duration_cast<std::chrono::microseconds>(t4-t3).count()<<std::endl;
    std::cout<<"*= : "<<(int)std::chrono::duration_cast<std::chrono::microseconds>(t5-t4).count()<<std::endl;
    std::cout<<"Transpose :"<<(int)std::chrono::duration_cast<std::chrono::microseconds>(t6-t5).count()<<std::endl;
}
int main()
{
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        Mat<int>m(i,i,1);
        routine(m,i);
    }
    return 0;
}
