#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>

template<class T>
class Mat
{
    private :

    T ** matrix;
    int row;
    int col;
    public :
    //allocate
    void allocate();

    //fillval
    void fill_val(T val);

    //constructors
    Mat(int r,int c);
    Mat(int r,int c,T val);
    Mat(const Mat<T> &m);

    //set val
    void setElem(int r,int c, T val);


    //getters
    int getRow() const { return row; }
    int getCol() const { return col; }
    int getVal(int r,int c) const { return this->matrix[r][c]; }

    //operators
    Mat operator+( const Mat<T> &m);
    Mat operator*( const Mat<T> &m);
    Mat operator=( const Mat<T> &m);
    Mat transpose();
    void operator+=(const  Mat &m);
    void operator*=(const  Mat &m);
};




#endif
