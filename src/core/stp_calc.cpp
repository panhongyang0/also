/* also: Advanced Logic Synthesis and Optimization tool
 * Copyright (C) 2019- Ningbo University, Ningbo, China */

#include <iostream>
#include<Eigen/Eigen>
#include "stp_calc.hpp"

using Eigen::MatrixXd;

namespace also
{

/******************************************************************************
 * Types                                                                      *
 ******************************************************************************/
  void matrix_construct()
  {
    
  }

/******************************************************************************
 * Private functions                                                          *
 ******************************************************************************/
public:
  int **  kron(int **a, int m, int n, int** b, int p, int q)
  {
    int **martix;
    martix = (int**) malloc(sizeof(int*) * m * p);
    for (int i = 0; i < m * p; i++)
    {
      martix[i] = (int*) malloc(sizeof(int) * n * q);
      for (int j = 0; j < n * q; j++)
      {
        martix[i][j] = a[i / p][j / q] * b[i % p][j % q];
      }
    }
    return martix;
  }

  int stpm2(MatrixXd A(),MatrixXd B())   //函数 两个左半张量积 AB为矩阵
  {
    int n,p;
    n=A.cols();                          //返回一个行向量，表示矩阵（行数，列数）
    p=B.rows();
    if n%p==0                            //取余
    {
      z=n/p;
      r=A*kron(B,B.rows(),B.cols(),MatrixXd::Identity(z),z,z);    //Kronecker积，返回大小为z*z的单位矩阵
    }
    else if p%n==0
    {
      z=p/n;
      r=kron(A,A.rows(),A.cols(),MatrixXd::Identity(z),z,z)*B;
    }
    else
      r=0;
    return r;
  }

  int fchange(int m,int n)       //换位矩阵计算函数
  {
    int d,j,I;
    m_matrix=Eigen::MatrixXf::Zero(m,n);
    d=m*n;
    for(k=1;k<=d;k++)
    {
      j=k%n;
      if( j==0)
        j=n;
      i=(k-j)/n+1;
     ( w=fchange((j-1)*m+i,k))=1;
    }
    return w;
  }
/******************************************************************************
 * Public functions                                                           *
 ******************************************************************************/

}
