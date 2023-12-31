#include "Matrix.h"
#include <iostream>
Matrix::Matrix(): rows(1), column(1)
{
  v = new double [1];
  v[0] = 0;
}

Matrix::Matrix(int rows, int coloms): rows(rows), column(coloms)
{
  v = new double[coloms*rows];
  for (int i = 0; i < coloms*rows; ++i) {
    v[i]= 0;
  }
}

Matrix::Matrix(const Matrix &m)
{
  column = m.column;
  rows = m.rows;
  v = new double [column*rows];
  for (int i = 0; i < column*rows; ++i) {
    v[i] = m[i];
  }
}

Matrix::~Matrix()
{
  delete[] v;
}

const double & Matrix::operator[](const int index) const
{
  return v[index];
}

double & Matrix::operator[](const int index)
{
  return v[index];
}

const double & Matrix::operator()(const int indRow, const int indCol) const
{
  int index = indRow * column + indCol;
  return v[index];
}

double & Matrix::operator()(const int indRow, const int indCol)
{
  int index = indRow * column + indCol;
  return v[index];
}

bool Matrix::operator!=(const Matrix &m) const
{
  return !(*this == m);
}

bool Matrix::operator==(const Matrix &m) const
{
  if (column != m.column || rows != m.rows)
    return false;
  else
  {
    for (int i = 0; i < column * rows; ++i)
    {
      if (v[i] != m[i])
        return false;
      else{}
    }
  }
  return true;
}

Matrix& Matrix::operator=(const Matrix &m){
  if (&m == this){
    return *this;
  }else{
    delete [] v;
    column = m.column;
    rows = m.rows;
    v = new double [column * rows];
    for (int i =0; i < column * rows; ++i){
      v[i] = m[i];
    }
    return *this;
  }
}

Matrix &Matrix::operator+=(const Matrix &m)
{
  try {
    if (rows != m.rows || column != m.column)
      throw std::length_error("not capable size of Matrix");
    else
      for (int i = 0; i < column * rows; ++i)
        v[i] += m[i];
  }
  catch (std::length_error &error){
    std::cout<<error.what()<<'\n';
  }
  return *this;
}

Matrix &Matrix::operator-=(const Matrix &m)
{
  try {
    if (rows != m.rows || column != m.column)
      throw std::length_error("not capable size of Matrix");
    else
      for (int i = 0; i < column * rows; ++i)
        v[i] -= m[i];
  }
  catch (std::length_error &error)
  {
    std::cout<<error.what()<<'\n';
  }
  return *this;
}

Matrix Matrix::operator+(const Matrix &m) const
{
  try {
    if (rows != m.rows || column != m.column)
      throw std::length_error("not capable size of Matrix");
    else
    {
      Matrix res = Matrix(*this);
      res += m;
      return res;
    }
  }
  catch (std::length_error &error)
  {
    std::cout<<error.what()<<'\n';
    return {1, 1};
  }
}

Matrix Matrix::operator-(const Matrix &m) const
{
  try {
    if (rows != m.rows || column != m.column)
      throw std::length_error("not capable size of Matrix");
    else
    {
      Matrix res = Matrix(*this);
      res -= m;
      return res;
    }
  }
  catch (std::length_error &error)
  {
    std::cout<<error.what()<<'\n';
    return {1, 1};
  }
}

Matrix &Matrix::operator*=(const Matrix &m)
{
  try {
    if (rows != m.rows || column != m.column)
      throw std::length_error("not capable size of Matrix");
    else {
      Matrix res(rows, m.column);
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < m.column; ++j) {
          for (int k = 0; k < column; ++k) {
            res(i, j) += v[i * rows + k] * m(k, j);
          }
        }
      }
      *this = res;
    }
  }
  catch (std::length_error &error)
  {
    std::cout<<error.what()<<'\n';
  }
  return *this;
}

Matrix &Matrix::operator*=(const double &x)
{
  for (int i = 0; i < column * rows; ++i)
  {
    v[i] *= x;
  }
  return *this;
}

Matrix Matrix::operator*(const Matrix &m) const
{
  try {
    if (rows != m.rows || column != m.column)
      throw std::length_error("not capable size of Matrix");
    else {
      Matrix res = Matrix(*this);
      res *= m;
      return res;
    }
  }
  catch (std::length_error &error)
  {
    std::cout<<error.what()<<'\n';
    return {1, 1};
  }
}

Matrix Matrix::operator*(const double &x) const
{
  Matrix res = Matrix(*this);
  res *= x;
  return res;
}

Matrix operator*(const double &x, const Matrix &m)
{
  Matrix res = Matrix(m);
  res *= x;
  return res;
}

std::istream &operator>>(std::istream &in, Matrix &m)
{
  in >> m.rows;
  in >> m.column;
  delete(m.v);
  m.v = new double [m.rows*m.column];
  for (int i = 0; i < m.rows * m.column; ++i) {
    in >> m[i];
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, const Matrix &m) {
  for (int i = 0; i < m.rows; ++i) {
    for (int j = 0; j < m.column; ++j) {
      out << m(i, j) << " ";
    }
    out << "\n";
  }
  return out;
}
