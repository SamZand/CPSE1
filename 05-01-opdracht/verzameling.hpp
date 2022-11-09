#ifndef VERZAMELING_HPP
#define VERZAMELING_HPP

#include <iostream>

class verzameling {
private:
    std::array<int, 10> set;
    int size = 10;
    int filled = 0;

public:
    verzameling() {}
    void add(int interger) {
        for (int i = 0; i < filled; i++) {
            if (set[i] == interger) {
                return;
            }
        }
        set[filled] = interger;
        filled++;
    }
    void remove(int interger) {
        for (int i = 0; i < filled; i++) {
            if (set[i] == interger) {
                for (int j = i; j < filled; j++) {
                    set[j] = set[j + 1];
                }
                filled--;
                return;
            }
        }
    }
    bool contains(int interger) {
        for (int i = 0; i < filled; i++) {
            if (set[i] == interger) {
                return true;
            }
        }
        return false;
    }
    friend std::ostream& operator<<(std::ostream& os, const verzameling& verzameling) {
        os << "";
        for (int i = 0; i < verzameling.filled; i++) {
            os << verzameling.set[i];
            if (i != verzameling.filled - 1) {
                os << ",";
            }
        }
        os << "";
        return os;
    }
};
#endif // VERZAMELING_HPP