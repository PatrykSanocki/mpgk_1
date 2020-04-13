#pragma once

template <class vec>
class Wektor
{
public:
	vec table;

	Wektor() {
		for (int i = 0; i < tabSize(); i++) {
			table[i] = 0.0f;
		}
	}

	Wektor(float val) {
		for (int i = 0; i < tabSize(); i++) {
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

	Wektor(vec tab) {
		for (int i = 0; i < tabSize(); i++) {
			table[i] = tab[i];
		}
	}

	Wektor& operator = (const Wektor& w) {
		for (int i = 0; i < tabSize(); i++) {
			this->table[i] = w.table[i];
		}
		return *this;
	}

	Wektor operator + (const Wektor& w) {
		Wektor<vec> temp;
		for (int i = 0; i < tabSize(); i++) {
			temp.table[i] = table[i] + w.table[i];
		}
		return temp;
	}


	Wektor& operator += (const Wektor& w) {
		for (int i = 0; i < tabSize(); i++) {
			table[i] += w.table[i];
		}
		return *this;
	}

	Wektor operator - (const Wektor& w) {
		Wektor<vec> temp;
		for (int i = 0; i < tabSize(); i++) {
			temp.table[i] = table[i] - w.table[i];
		}
		return temp;
	}

	Wektor& operator -= (const Wektor& w) {
		for (int i = 0; i < tabSize(); i++) {
			table[i] -= w.table[i];
		}
		return *this;
	}

	Wektor operator * (const int& c) {
		Wektor<vec> temp;
		for (int i = 0; i < tabSize(); i++) {
			temp.table[i] = table[i] * c;
		}
		return temp;
	}

	Wektor& operator *= (const int& c) {
		for (int i = 0; i < tabSize(); i++) {
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
		for (int i = 0; i < tabSize(); i++) {
			sum += table[i] * w.table[i];
		}
		return sum;
	}

	Wektor& cross(const Wektor& w) {
		Wektor<vec> temp;
		temp.table[0] = table[1] * w.table[2] - table[2] * w.table[1];
		temp.table[1] = -(table[0] * w.table[2] - table[2] * w.table[0]);
		temp.table[2] = table[2] * w.table[1] - table[1] * w.table[0];
		return temp;
	}

	Wektor& normalization() {
		Wektor<vec> temp;
		float length = 0;
		for (int i = 0; i < sizeof(this->table) / sizeof(*this->table); i++) {
			length += (this->table[i] * this->table[i]);
		}
		length = sqrt(length);

		for (int i = 0; i < sizeof(this->table) / sizeof(*this->table); i++) {
			temp.table[i] = this->table[i] / length;
		}
		return temp;
	}

	int tabSize() {
		return sizeof(table) / sizeof(*table);
	}

private:
	friend std::ostream & operator<<(std::ostream &os, const Wektor& w);

};

template <class vec>
std::ostream & operator<<(std::ostream &os, Wektor<vec>& w) {
	os << "[";
	for (int i = 0; i < sizeof(w.table) / sizeof(*w.table); i++) {
		os << w.table[i];
		if (i + 1 < sizeof(w.table) / sizeof(*w.table))
			os << ", ";
	}
	os << "]" << std::endl;
	return os;
}