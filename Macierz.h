#pragma once
#define PI 3.14
template <int L>
struct Matrix {
	float M[L][L];
};
template <int L>
class Macierz
{
private:
	Matrix<L> macierz;
	friend std::ostream & operator<<(std::ostream &os, const Macierz& m);
public:
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
	Macierz<L> invert();
};

template <int L>
Macierz<L>::Macierz() 
{
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			macierz.M[i][j] = 0.0f;
		}
}

template <int L>
Macierz<L>::Macierz(float value) 
{
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			macierz.M[i][j] = value;
		}
}

template <int L>
Macierz<L>::Macierz(float mat[L][L]) 
{
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			macierz.M[i][j] = mat[i][j];
		}
}

template <int L>
void Macierz<L>::operator = (const Macierz<L>& m) 
{
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			macierz.M[i][j] = m.macierz.M[i][j];
		}
}

template <int L>
Macierz<L> Macierz<L>::operator + (const Macierz<L>& m) 
{
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			temp.macierz.M[i][j] = macierz.M[i][j] + m.macierz.M[i][j];
		}
	return temp;
}

template <int L>
void Macierz<L>::operator += (const Macierz<L>& m) 
{
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			macierz.M[i][j] += m.macierz.M[i][j];
		}
}

template <int L>
Macierz<L> Macierz<L>::operator - (const Macierz<L>& m) 
{
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			temp.macierz.M[i][j] = macierz.M[i][j] - m.macierz.M[i][j];
		}
	return temp;
}

template <int L>
void Macierz<L>::operator -= (const Macierz<L>& m) 
{
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			macierz.M[i][j] -= m.macierz.M[i][j];
		}
}

template <int L>
Macierz<L> Macierz<L>::operator * (const int& c) 
{
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			temp.macierz.M[i][j] = macierz.M[i][j] * c;
		}
	return temp;
}

template <int L>
void Macierz<L>::operator *= (const int& c) 
{
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) 
		{
			macierz.M[i][j] *= c;
		}
}

template <int L>
Macierz<L> Macierz<L>::operator * (const Macierz<L>& m) 
{
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
void Macierz<L>::operator *= (const Macierz<L>& m) 
{
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
Wektor<L> Macierz<L>::operator * (const Wektor<L>& w) 
{
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

template <int L>
Macierz<L - 1> getSubmatrix(Macierz<L> source, int row, int col)
{
	int colCount = 0, rowCount = 0;

	Macierz<L - 1> destination;
	for (int i = 0; i < L; i++)
	{
		if (i != row)
		{
			colCount = 0;
			for (int j = 0; j < L; j++)
			{
				if (j != col)
				{
					destination.setter(rowCount, colCount, source.getter(i, j));
					colCount++;
				}
			}
			rowCount++;
		}
	}

	return destination;
}

template <int L>
double calculateDeterminant(Macierz<L> mat)
{
	float det = 0.0f;

	for (int i = 0; i < L; i++)
	{
		// Get minor of element (0, i)
		float minor = calculateMinor<L>(mat, 0, i);

		// If this is an odd-numbered row, negate the value.
		float factor = (i % 2 == 1) ? -1.0f : 1.0f;

		det += factor * mat.getter(0, i) * minor;
	}

	return det;
}

template <>
double calculateDeterminant<2>(Macierz<2> mat)
{
	return mat.getter(0, 0)* mat.getter(1, 1) - mat.getter(0, 1) * mat.getter(1, 0);
}

template <int L>
double calculateMinor(Macierz<L> source, int row, int col)
{
	auto minorSubmatrix = getSubmatrix<L>(source, row, col);
	return calculateDeterminant<L - 1>(minorSubmatrix);
}

template <int L>
Macierz<L> Macierz<L>::invert()
{
	// Calculate the inverse of the determinant of m.
	float det = calculateDeterminant<L>(*this);
	float inverseDet = 1.0f / det;

	Macierz<L> result;

	for (int j = 0; j < L; j++)
		for (int i = 0; i < L; i++)
		{
			// Get minor of element (j, i) - not (i, j) because
			// this is where the transpose happens.
			float minor = calculateMinor<L>(*this, j, i);

			// Multiply by (−1)^{i+j}
			float factor = ((i + j) % 2 == 1) ? -1.0f : 1.0f;
			float cofactor = minor * factor;

			result.setter(i, j, inverseDet * cofactor);
		}

	return result;
}