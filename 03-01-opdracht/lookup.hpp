#ifndef LOOKUP_HPP
#define LOOKUP_HPP
#include <cmath>

#define PI 3.14159265359

class cos_lookup {
private:
  std::array<float, 60> values;

public:
  constexpr cos_lookup() : values{} {
    for (int i = 0; i < 60; i++) {
      values[i] = cos(i * 6 * PI / 180.0);
    }
  }

  constexpr float get(int n) const { return values[n]; }
};

class sin_lookup {
private:
  std::array<float, 60> values;

public:
  constexpr sin_lookup() : values{} {
    for (int i = 0; i < 60; i++) {
      values[i] = sin(i * 6 * PI / 180.0);
    }
  }

  constexpr float get(int n) const { return values[n]; }
};

#endif // LOOKUP_HPP