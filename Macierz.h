#pragma once
template <int L>
class Macierz
{
public:
	float matrix[L][L];

	Macierz();
	Macierz(float value);
	Macierz(float matrix[L][L]);

	Macierz<L>& Macierz::operator = (const Macierz& m);
	Macierz<L>& Macierz::operator + (const Macierz& m);
	void Macierz::operator += (const Macierz& m);
	Macierz<L>& Macierz::operator - (const Macierz& m);
	void Macierz::operator -= (const Macierz& m);
	Macierz<L> Macierz::operator * (const int& c);
	void  Macierz::operator *= (const int& c);
	Macierz<L>& Macierz::operator * (const Macierz& m);
	void Macierz::operator *= (const Macierz& m);
	Macierz<L>& Macierz::operator * (const Wektor<L>& w);

private:
	friend std::ostream & operator<<(std::ostream &os, const Macierz& m);
};

template <int L>
Macierz<L>::Macierz() {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			matrix[i][j] = 0.0f;
		}
}

template <int L>
Macierz<L>::Macierz(float value) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			matrix[i][j] = value;
		}
}

template <int L>
Macierz<L>::Macierz(float mat[L][L]) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			matrix[i][j] = mat[i][j];
		}
}

template <int L>
Macierz<L>& Macierz<L>::operator = (const Macierz<L>& m) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	return *this;
}

template <int L>
Macierz<L>& Macierz<L>::operator + (const Macierz<L>& m) {
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			temp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
		}
	return temp;
}

template <int L>
void Macierz<L>::operator += (const Macierz<L>& m) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			matrix[i][j] += m.matrix[i][j];
		}
	return *this;
}

template <int L>
Macierz<L>& Macierz<L>::operator - (const Macierz<L>& m) {
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			temp.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
		}
	return temp;
}

template <int L>
void Macierz<L>::operator -= (const Macierz<L>& m) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			matrix[i][j] -= m.matrix[i][j];
			std::cout << matrix[i][j] << std::endl;
		}
}

template <int L>
Macierz<L> Macierz<L>::operator * (const int& c) {
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			temp.matrix[i][j] = matrix[i][j] * c;
		}
	return temp;
}

template <int L>
void Macierz<L>::operator *= (const int& c) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			matrix[i][j] *= c;
		}
	return *this;
}

template <int L>
Macierz<L>& Macierz<L>::operator * (const Macierz<L>& m) {
	Macierz<L> temp;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			temp.matrix[i][j] = matrix[i][j] * m.matrix[i][j];
		}
	return temp;
}

template <int L>
void Macierz<L>::operator *= (const Macierz<L>& m) {
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++) {
			matrix[i][j] *= m.matrix[i][j];
		}
	return *this;
}

template <int L>
Macierz<L>& Macierz<L>::operator * (const Wektor<L>& w) {

}