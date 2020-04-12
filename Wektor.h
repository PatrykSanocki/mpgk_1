#pragma once

template <class vec>
class Wektor
{
public:
	vec table;

	Wektor() {
		for (int i = 0; i < sizeof(table) / sizeof(*table); i++) {
			table[i] = 0;
		}
	}

	Wektor(float val) {
		for (int i = 0; i < sizeof(table) / sizeof(*table); i++) {
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
		for (int i = 0; i < sizeof(table) / sizeof(*table); i++) {
			table[i] = tab[i];
		}
	}

	void operator = (Wektor w) {
		for (int i = 0; i < sizeof(w.table) / sizeof(*w.table); i++) {
			table[i] = w.table[i];
		}
	}

	Wektor operator + (Wektor w) {
		Wektor temp;
		for (int i = 0; i < sizeof(w.table) / sizeof(*w.table); i++) {
			temp.table[i] = table[i] + w.table[i];
		}
		return temp;
	}

	void operator += (Wektor w) {
		for (int i = 0; i < sizeof(w.table) / sizeof(*w.table); i++) {
			table[i] += w.table[i];
		}
	}

	Wektor operator - (Wektor w) {
		Wektor temp;
		for (int i = 0; i < sizeof(w.table) / sizeof(*w.table); i++) {
			temp.table[i] = table[i] - w.table[i];
		}
		return temp;
	}

	void operator -= (Wektor w) {
		for (int i = 0; i < sizeof(w.table) / sizeof(*w.table); i++) {
			table[i] -= w.table[i];
		}
	}

	Wektor operator * (int c) {
		Wektor temp;
		for (int i = 0; i < sizeof(w.table) / sizeof(*w.table); i++) {
			temp.table[i] = table[i] * c;
		}
		return temp;
	}

	void operator *= (int c) {
		for (int i = 0; i < sizeof(table) / sizeof(*table); i++) {
			table[i] *= c;
		}
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
	os << "]" << endl;
	return os;
}