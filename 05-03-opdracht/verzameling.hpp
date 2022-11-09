#ifndef VERZAMELING_HPP
#define VERZAMELING_HPP

#include <iostream>

template< int N, typename T >
class verzameling {
private:
	std::array<T, N> set;
	int filled = 0;

public:
	verzameling() {}
	void add(T item) {
		for (int i = 0; i < filled; i++) {
			if (set[i] == item) {
				return;
			}
		}
		set[filled] = item;
		filled++;
	}
	void remove(T item) {
		for (int i = 0; i < filled; i++) {
			if (set[i] == item) {
				for (int j = i; j < filled; j++) {
					set[j] = set[j + 1];
				}
				filled--;
				return;
			}
		}
	}
	bool contains(T item) {
		for (int i = 0; i < filled; i++) {
			if (set[i] == item) {
				return true;
			}
		}
		return false;
	}
	T max() {
		if (filled == 0) {
			std::cout << "verzameling is leeg" << std::endl;
			return 0;
		}
		else if (filled == 1) {
			return set[0];
		}
		else {
			T max = set[0];
			for (int check = 1; check < filled; check++) {
				if (set[check] > max) {
					max = set[check];
				}
			}
			return max;
		}
	}
	friend std::ostream& operator<<(std::ostream& os, const verzameling& rhs) {

		for (int i = 0; i < rhs.filled; i++) {
			os << rhs.set[i];
			if (i != rhs.filled - 1) {
				os << ",";
			}
		}

		return os;
	}
};
#endif // VERZAMELING_HPP