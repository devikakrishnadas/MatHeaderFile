#include<iostream>
#include "matrix.h"
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;


template<class T>
void Mat<T>::PrintMat()
{
    cout<<"enter"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<getVal(i,j)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template<class T>
void Mat<T>::allocate()
{
    matrix = (T**)malloc(row * sizeof(T *));
    for(int i=0;i<row;i++)
        matrix[i] = (T *)malloc(col * sizeof(T));
}

template<class T>
Mat<T>::Mat(int r,int c)
{
    row=r;
    col=c;
    allocate();
}


template<class T>
void Mat<T>::fill_val(T val)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            matrix[i][j] = val;
        }
    }
}
template<class T>

Mat<T>::Mat(int r,int c,T val)
{
    row = r;
    col = c;
    allocate();
    fill_val(val);
}
template<class T>

Mat<T>::Mat( const Mat<T> &m)
{
    for(int i=0;i<m.getRow();i++)
    {
        for(int j=0;j<m.getCol();j++)
        {
            matrix[i][j] = m.getVal(i,j);
        }
    }
}
template<class T>

void Mat<T>::setElem(int r,int c,T val)
{
    matrix[r][c]=val;
}
template<class T>

Mat<T> Mat<T>::operator+(const Mat<T> &m)  
{
    Mat<T> result(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            T temp = m.getVal(i,j);
            T ans = this->matrix[i][j] + temp;
            result.setElem(i,j,ans);
        }
    }
    return result;
}
template<class T>

Mat<T> Mat<T>::operator*( const Mat<T> &m)   
{
    T result(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<m.getCol();j++)
        {
            result[i][j]=0;
            for(int k=0;k<m.getRow();k++)
            {
                result[i][j] += matrix[i][k] * m.getVal(k,j);
            }
        }
    }
    return result;
}
template<class T>

void Mat<T>::operator+=(const Mat<T> &m)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            matrix[i][j] = matrix[i][j] + m.getVal(i,j);
        }
    }
}

template<class T>

void Mat<T>::operator*=(const Mat<T> &m)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            matrix[i][j] = matrix[i][j] * m.getVal(i,j);
        }
//        cout<<endl;
    }
}

