#pragma once

template <int L>
class Przeksztalcenia
{
public:
	Macierz<L> macierz;

	void scale2D(float value);
	void scale2D(float valueX, float valueY);
	void scale2D(float valueTable[]);

	void rotate2D(float angle);

	void translate2D(float value);
	void translate2D(float valueX, float valueY);
	void translate2D(float valueTable[]);

	void scale3D(float value);
	void scale3D(float valueX, float valueY, float valueZ);
	void scale3D(float valueTable[]);

	void rotate3D(float valueTable[], char axis);
	void rotate3D(float valueTable[], Wektor<3> wektor);

	void translate3D(float value);
	void translate3D(float valueX, float valueY, float valueZ);
	void translate3D(float valueTable[]);

};

template<int L>
void Przeksztalcenia<L>::scale2D(float value)
{
	macierz.setter(0, 0, value);
	macierz.setter(1, 1, value);
	macierz.setter(2, 2, 1);
}

template<int L>
void Przeksztalcenia<L>::scale2D(float valueX, float valueY)
{
	macierz.setter(0, 0, valueX);
	macierz.setter(1, 1, valueY);
	macierz.setter(2, 2, 1);
}

template<int L>
void Przeksztalcenia<L>::scale2D(float valueTable[])
{
	macierz.setter(0, 0, valueTable[0]);
	macierz.setter(1, 1, valueTable[1]);
	macierz.setter(2, 2, 1);
}

template<int L>
void Przeksztalcenia<L>::translate2D(float value)
{
	macierz.setter(0, 0, 1);
	macierz.setter(1, 1, 1);
	macierz.setter(2, 2, 1);
	macierz.setter(0, 2, value);
	macierz.setter(1, 2, value);
}

template<int L>
void Przeksztalcenia<L>::translate2D(float valueX, float valueY)
{
	macierz.setter(0, 0, 1);
	macierz.setter(1, 1, 1);
	macierz.setter(2, 2, 1);
	macierz.setter(0, 2, valueX);
	macierz.setter(1, 2, valueY);
}

template<int L>
void Przeksztalcenia<L>::translate2D(float valueTable[])
{
	macierz.setter(0, 0, 1);
	macierz.setter(1, 1, 1);
	macierz.setter(2, 2, 1);
	macierz.setter(0, 2, valueTable[0]);
	macierz.setter(1, 2, valueTable[1]);
}

template<int L>
void Przeksztalcenia<L>::scale3D(float value)
{
	macierz.setter(0, 0, value);
	macierz.setter(1, 1, value);
	macierz.setter(2, 2, value);
	macierz.setter(3, 3, 1);
}

template<int L>
void Przeksztalcenia<L>::scale3D(float valueX, float valueY, float valueZ)
{
	macierz.setter(0, 0, valueX);
	macierz.setter(1, 1, valueY);
	macierz.setter(2, 2, valueZ);
	macierz.setter(3, 3, 1);
}

template<int L>
void Przeksztalcenia<L>::scale3D(float valueTable[])
{
	macierz.setter(0, 0, valueTable[0]);
	macierz.setter(1, 1, valueTable[1]);
	macierz.setter(2, 2, valueTable[2]);
	macierz.setter(3, 3, 1);
}

template<int L>
void Przeksztalcenia<L>::translate3D(float value)
{
	macierz.setter(0, 0, 1);
	macierz.setter(1, 1, 1);
	macierz.setter(2, 2, 1);
	macierz.setter(3, 3, 1);
	macierz.setter(0, 3, value);
	macierz.setter(1, 3, value);
	macierz.setter(2, 3, value);
}

template<int L>
void Przeksztalcenia<L>::translate3D(float valueX, float valueY, float valueZ)
{
	macierz.setter(0, 0, 1);
	macierz.setter(1, 1, 1);
	macierz.setter(2, 2, 1);
	macierz.setter(3, 3, 1);
	macierz.setter(0, 3, valueX);
	macierz.setter(1, 3, valueY);
	macierz.setter(2, 3, valueZ);
}

template<int L>
void Przeksztalcenia<L>::translate3D(float valueTable[])
{
	macierz.setter(0, 0, 1);
	macierz.setter(1, 1, 1);
	macierz.setter(2, 2, 1);
	macierz.setter(3, 3, 1);
	macierz.setter(0, 3, valueTable[0]);
	macierz.setter(1, 3, valueTable[1]);
	macierz.setter(2, 3, valueTable[2]);
}
