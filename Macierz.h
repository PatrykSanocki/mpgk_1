#pragma once
#define PI 3.14
template <int L>
struct Matrix {
	float M[L][L];
};
template <int L>
class Macierz
{
	Matrix<L> macierz;
public:
	//float matrix[L][L];
	Macierz();
	Macierz(float value);
	Macierz(float matrix[L][L]);

	void operator = (const Macierz& m);
	Macierz<L> operator + (const Macierz& m);
	void operator += (const Macierz& m);
	Macierz<L> operator - (const Macierz& m);
	void operator -= (const Macierz& m);
	Macierz<L> operator * (const int& c);
	void operator *= (const int& c);
	Macierz<L> operator * (const Macierz& m);
	void operator *= (const Macierz& m);
	Wektor<L> operator * (const Wektor<L>& w);

	void setter(int row, int col, float val);
	float getter(int row, int col);

	Matrix<L> getMacierz();

	Macierz<L> transposition();
	Macierz<L> identity();

private:
	friend std::ostream & operator<<(std::ostream &os, const Macierz& m);
};

template <int L>
Macierz<L>::Macierz() {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			macierz.M[i][j] = 0.0f;
		}
}

template <int L>
Macierz<L>::Macierz(float value) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			macierz.M[i][j] = value;
		}
}

template <int L>
Macierz<L>::Macierz(float mat[L][L]) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			macierz.M[i][j] = mat[i][j];
		}
}

template <int L>
void Macierz<L>::operator = (const Macierz<L>& m) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			macierz.M[i][j] = m.macierz.M[i][j];
		}
}

template <int L>
Macierz<L> Macierz<L>::operator + (const Macierz<L>& m) {
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			temp.macierz.M[i][j] = macierz.M[i][j] + m.macierz.M[i][j];
		}
	return temp;
}

template <int L>
void Macierz<L>::operator += (const Macierz<L>& m) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			macierz.M[i][j] += m.macierz.M[i][j];
		}
}

template <int L>
Macierz<L> Macierz<L>::operator - (const Macierz<L>& m) {
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			temp.macierz.M[i][j] = macierz.M[i][j] - m.macierz.M[i][j];
		}
	return temp;
}

template <int L>
void Macierz<L>::operator -= (const Macierz<L>& m) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			macierz.M[i][j] -= m.macierz.M[i][j];
		}
}

template <int L>
Macierz<L> Macierz<L>::operator * (const int& c) {
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			temp.macierz.M[i][j] = macierz.M[i][j] * c;
		}
	return temp;
}

template <int L>
void Macierz<L>::operator *= (const int& c) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			macierz.M[i][j] *= c;
		}
}

template <int L>
Macierz<L> Macierz<L>::operator * (const Macierz<L>& m) {
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			for (int k = 0; k < L; k++)
			{
				temp.macierz.M[i][j] += macierz.M[i][k] * m.macierz.M[k][j];
			}
		}
	return temp;
}

template <int L>
void Macierz<L>::operator *= (const Macierz<L>& m) {
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			for (int k = 0; k < L; k++)
			{
				temp.macierz.M[i][j] += macierz.M[i][k] * m.macierz.M[k][j];
			}
		}
	macierz = temp.macierz;
}

template <int L>
Wektor<L> Macierz<L>::operator * (const Wektor<L>& w) {
	Wektor<L> temp;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++) 
		{
			temp.macierz.table[i] += macierz.M[i][j] * w.table[j];
		}
	}
	return temp;
}

template <int L>
std::ostream& operator<<(std::ostream& os, Macierz<L>& m) 
{
	Matrix<L> macierz = m.getMacierz();
	for (int i = 0; i < L; ++i) 
	{
		for (int j = 0; j < L; ++j) 
		{
			os << macierz.M[i][j] << "  ";
		}
		os << "\n";
	}

	return os;

}

template<int L>
void Macierz<L>::setter(int row, int col, float val)
{
	macierz.M[row][col] = val;
}

template<int L>
float Macierz<L>::getter(int row, int col)
{
	return macierz.M[row][col];
}

float toDegree(float rad) 
{
	float degree = rad * 180 / PI;
	return degree;
}

float toRadian(float deg) 
{
	float radian = deg * PI / 180;
	return radian;
}

template<int L>
inline Matrix<L> Macierz<L>::getMacierz()
{
	return macierz;
}

template <int L>
Macierz<L> Macierz<L>::transposition() 
{
	Macierz<L> temp;
	for (int i = 0; i < L; i++) 
	{
		for (int j = 0; j < L; j++) 
		{
			temp.macierz.M[j][i] = macierz.M[i][j];
		}
	}
	return temp;
}

template <int L>
Macierz<L> Macierz<L>::identity() 
{
	Macierz<L> temp;
	for (int i = 0; i < L; i++) 
	{
		for (int j = 0; j < L; j++) 
		{
			if (i == j) 
			{
				temp.macierz.M[j][i] = 1;
			}
			else temp.macierz.M[j][i] = 0;
		}
	}
	return temp;
}