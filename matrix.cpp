#include<iostream>
#include<stdlib.h>
#include "matrix.h"


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
    
    row=m.getRow();
    col=m.getCol();
    allocate();
    for(int i=0;i<m.getRow();i++)
    {
        for(int j=0;j<m.getCol();j++)
        {
            matrix[i][j] = m.getVal(i,j);
        }
    }
    

    /*Mat<T> temp(m.getRow(),m.getCol());
    for(int i=0;i<m.getRow();i++)
    {
        for(int j=0;j<m.getCol();j++)
        {
            temp.setElem(i,j,m.getVal(i,j));
        }
    }
    std::swap(temp,*this);
    */
}
template<class T>

void Mat<T>::setElem(int r,int c,T val)
{
    matrix[r][c]=val;
}

template<class T>

std::ostream & operator<<( std::ostream& os, const Mat<T>&m )
{
    for(int i=0;i<m.getRow();i++)
    {
        for(int j=0;j<m.getCol();j++)
        {
            os<<m.getVal(i,j)<<" ";
        }
        os<<std::endl;
    }
    return os;
}

template<class T>

std::istream & operator>>( std::istream& os, Mat<T>&m )
{
    for(int i=0;i<m.getRow();i++)
    {
        for(int j=0;j<m.getCol();j++)
        {
            int x;
            os>>x;
            m.setElem(i,j,x);
        }
    }
    return os;
}

template<class T>

Mat<T> Mat<T>::operator=(const Mat<T> &m)
{
    row = m.getRow();
    col = m.getCol();
    allocate();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            matrix[i][j] = m.getVal(i,j);
        }
    }
}
template<class T>

Mat<T> Mat<T>::operator+(const Mat<T> &m)  
{
    Mat<T> result(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            result.setElem(i,j,m.getVal(i,j)+matrix[i][j]);
        }
    }
    return result;
}
template<class T>

Mat<T> Mat<T>::operator*( const Mat<T> &m)   
{
    Mat<T> result(row,m.getCol());
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<m.getCol();j++)
        {
            for(int k=0;k<m.getRow();k++)
            {
                result.setElem(i,j, result.getVal(i,j) + matrix[i][k] * m.getVal(k,j) );
            }
        }
    }
    return result;
}
template<class T>

void Mat<T>::operator+=(const Mat<T> &m)
{
    Mat<T>temp(m);
    temp = (temp + temp);
    std::swap(temp,*this);
}

template<class T>

void Mat<T>::operator*=(const Mat<T> &m)
{
    Mat<T>temp(*this);
    temp = temp * m;
    std::swap(temp,*this);
}

template<class T>

Mat<T> Mat<T>::transpose()
{
    Mat<T> temp(col,row);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp.setElem(j,i,matrix[i][j]);
        }
    }
    return temp;
}

