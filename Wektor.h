#pragma once

template <int L>
class Wektor
{
public:
	float table[L];

	Wektor() {
		for (int i = 0; i < L; i++) {
			table[i] = 0.0f;
		}
	}

	Wektor(float val) {
		for (int i = 0; i < L; i++) {
			table[i] = val;
		}
	}

	Wektor(float val_X, float val_Y, float val_Z) {
		table[0] = val_X;
		table[1] = val_Y;
		table[2] = val_Z;
	}

	Wektor(float val_X, float val_Y, float val_Z, float val_W) {
		table[0] = val_X;
		table[1] = val_Y;
		table[2] = val_Z;
		table[3] = val_W;
	}

	Wektor(float tab[L]) {
		for (int i = 0; i < L; i++) {
			table[i] = tab[i];
		}
	}

	Wektor& operator = (const Wektor& w) {
		for (int i = 0; i < L; i++) {
			this->table[i] = w.table[i];
		}
		return *this;
	}

	Wektor operator + (const Wektor& w) {
		Wektor<L> temp;
		for (int i = 0; i < L; i++) {
			temp.table[i] = table[i] + w.table[i];
		}
		return temp;
	}


	Wektor& operator += (const Wektor& w) {
		for (int i = 0; i < L; i++) {
			table[i] += w.table[i];
		}
		return *this;
	}

	Wektor operator - (const Wektor& w) {
		Wektor<L> temp;
		for (int i = 0; i < L; i++) {
			temp.table[i] = table[i] - w.table[i];
		}
		return temp;
	}

	Wektor& operator -= (const Wektor& w) {
		for (int i = 0; i < L; i++) {
			table[i] -= w.table[i];
		}
		return *this;
	}

	Wektor operator * (const int& c) {
		Wektor<L> temp;
		for (int i = 0; i < L; i++) {
			temp.table[i] = table[i] * c;
		}
		return temp;
	}

	Wektor& operator *= (const int& c) {
		for (int i = 0; i < L; i++) {
			table[i] *= c;
		}
		return *this;
	}

	float getX() {
		return table[0];
	}

	void setX(float x) {
		table[0] = x;
	}

	float getY() {
		return table[1];
	}

	void setY(float x) {
		table[1] = x;
	}

	float getZ() {
		return table[2];
	}

	void setZ(float x) {
		table[2] = x;
	}

	float getW() {
		return table[3];
	}

	void setW(float x) {
		table[3] = x;
	}

	float scalar(const Wektor& w) {
		float sum = 0;
		for (int i = 0; i < L; i++) {
			sum += table[i] * w.table[i];
		}
		return sum;
	}

	Wektor cross(const Wektor& w) {
		Wektor<L> temp;
		temp.table[0] = table[1] * w.table[2] - table[2] * w.table[1];
		temp.table[1] = -(table[0] * w.table[2] - table[2] * w.table[0]);
		temp.table[2] = table[2] * w.table[1] - table[1] * w.table[0];
		return temp;
	}

	Wektor normalization() {
		Wektor<L> temp;
		float length = 0;
		for (int i = 0; i < L; i++) {
			length += (this->table[i] * this->table[i]);
		}
		length = sqrt(length);

		for (int i = 0; i < L; i++) {
			temp.table[i] = this->table[i] / length;
		}
		std::cout << temp << std::endl;
		return temp;
	}

private:
	friend std::ostream & operator<<(std::ostream &os, const Wektor& w);

};

template <int L>
std::ostream & operator<<(std::ostream &os, Wektor<L>& w) {
	os << "[";
	for (int i = 0; i < L; i++) {
		os << w.table[i];
		if (i + 1 < L)
			os << ", ";
	}
	os << "]" << std::endl;
	return os;
}