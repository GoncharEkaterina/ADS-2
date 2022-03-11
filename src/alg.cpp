// Copyright 2022 NNTU-CS
#include "alg.h"
#include <math.h>
#include <cstdint>
#include <iostream>

double pown(double value, uint16_t n);
uint16_t fact(uint16_t n);
double calcItem(double x, uint16_t n);
double expn(double x, uint16_t count);
double sinn(double x, uint16_t count);
double cosn(double x, uint16_t count);

double pown(double value, uint16_t n) {
    return pow(value, n);
}

uint16_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    } else { return n * fact(n - 1); }
}

double calcItem(double x, uint16_t n) {
    return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
    double per = 0, y = 1, exp = 1e-10;
    int i = 0;
  while (fabs(y) > exp) {
      per += y;
      y += x / (i + 1.0);
      i++;
  }
    return per;
}

double sinn(double x, uint16_t count) {
    double sin = 0, y = x;
    int i = 1;
    if (x == 0) {
        return x;
    } else {
          while (fabs(y) > count) {
              sin += y;
              i++;
              y *= -x * x / (2.0 * i - 1.0) / (2.0 * i - 2.0);
          }
          return sin;
      }
    return 0;
}

double cosn(double x, uint16_t count) {
    double cos = 0, y = x;
    int i = 1;
    if (x == 0) {
        return 1;
    } else {
          while (fabs(y) > count) {
              cos += y;
              i++;
              y *= -x * x / (2.0 * i - 1.0) / (2.0 * i);
          }
          return cos;
      }
    return 0;
}

int main() {
    double value = 0, x = 0;
    uint16_t n = 0;
    std::cin >> value >> n >> x;
    std::cout << pown(value, n) << std::endl;
    std::cout << fact(n) << std::endl;
    std::cout << calcItem(value, n) << std::endl;
    std::cout << expn(x, n) << std::endl;
    std::cout << sinn(x, n) << std::endl;
    std::cout << cosn(x, n) << std::endl;
}
