#include <iostream>
#include "Matrix.h"

int main() {
//  Matrix m1 (1, 1);
//  m1[0] = 1;
//  std::cout<<m1;
//  Matrix m2 (1, 1);
//  m2[0] = 1;
//  std::cout<<(m1!=m2);
//  Matrix bigMat1;
//  std::cin>> bigMat1;
//  Matrix bigMat2;
//  std::cin>> bigMat2;
//  Matrix res;
//  res = bigMat1 * bigMat2;
//  std::cout<< res;
//  res *= 2;
//  std::cout<< res;
//  res = bigMat1 + bigMat2;
//  std::cout<<res;
  Matrix m1; //тут лежит 0
  Matrix m2 = m1;
  m1[0] = 1;
  std::cout << m1 << '\n' << m2;
  return 0;
}
