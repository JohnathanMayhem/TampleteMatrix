#include <istream>

class Matrix{
  int  rows, column;
  double *v;
public:
  Matrix();

  Matrix( int rows, int coloms);

  Matrix(const Matrix& m);

  Matrix(const int& n);

  ~Matrix();

  Matrix &operator = (const Matrix& m);

  Matrix operator + (const Matrix& m) const;

  Matrix operator - (const Matrix& m) const;

  Matrix operator * (const Matrix& m) const;

  Matrix operator * (const double &x) const;

  double &operator[](int index);

  const double &operator[](int index) const;

  double &operator()(int indRow, int indCol);

  const double &operator()(int indRow, int indCol) const;

  bool operator == (const Matrix& m) const;

  bool operator != (const Matrix& m) const;

  Matrix &operator += (const Matrix& m);

  Matrix &operator -= (const Matrix& m);

  Matrix &operator *= (const Matrix& m);

  Matrix &operator *= (const double &x);

  friend Matrix operator * (const double& x, const Matrix &m);

  friend std::istream &operator>>(std::istream &in, Matrix& m);

  friend std::ostream &operator<<(std::ostream &out, const Matrix& m);
};
