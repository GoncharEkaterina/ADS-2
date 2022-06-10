// Copyright 2022 NNTU-CS
#include "alg.h"
#include <math.h>
#include <cstdint>
#include <iostream>

double pown(double value, uint16_t n);
uint64_t fact(uint16_t n);
double calcItem(double x, uint16_t n);
double expn(double x, uint16_t count);
double sinn(double x, uint16_t count);
double cosn(double x, uint16_t count);

double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }
    double res = value;
    for (uint16_t i = 0; i < n-1; i++) {
        res *= value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    } else { return n * fact(n - 1); }
}

double calcItem(double x, uint16_t n) {
    return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double res = 1;
  for (int i = 1; i <= count; i++)
    res += calcItem(x, i);
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0;
  for (int i = 1; i <= count; i++)
    res += pown((-1), i - 1) * (pown(x, 2*i - 1) / fact(2*i - 1));
  return res;
}

double cosn(double x, uint16_t count) {
    if (count == 1) {
        return 1;
    }
    double tmp = pown(-1, count - 1) * calcItem(x, 2 * count - 2);
    return tmp + cosn(x, count - 1);
}
