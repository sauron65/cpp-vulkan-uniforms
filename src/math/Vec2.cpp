#ifndef _VEC2
#define _VEC2
#include <math.h>
#include <stdexcept>
template<typename T> struct Vec2 {
  public:
    T x;
    T y;

    Vec2(T X, T Y): x {X}, y {Y} {}

    inline void set(T x, T y) {
      (*this).x = x;
      (*this).y = y;
    }

    inline T mag() {
      return sqrt((*this).x * (*this).x + (*this).y * (*this).y);
    }

    inline void normalize() {
      T len = (*this).mag();
      (*this).x /= len;
      (*this).y /= len;
    }

    T operator[](size_t i) {
      switch (i) {
        case 0:
          return x;
          break;

        case 1:
          return y;
          break;

        default:
          throw std::runtime_error("out of range");
          break;
      }
    }

    static Vec2<T> subtract(Vec2<T> a, Vec2<T> b) {
      return Vec2<T>(a.x - b.x, a.y - b.y);
    }

    static Vec2<T> add(Vec2<T> a, Vec2<T> b) {
      return Vec2<T>(a.x + b.x, a.y + b.y);
    }

    static Vec2<T> multiply(Vec2<T> a, Vec2<T> b) {
      return Vec2<T>(a.x * b.x, a.y * b.y);
    }

    static Vec2<T> divide(Vec2<T> a, Vec2<T> b) {
      return Vec2<T>(a.x / b.x, a.y / b.y);
    }

    Vec2<T> operator-(const Vec2<T> &rhs) {
      return Vec2<T>::subtract(*this, rhs);
    }

    Vec2<T> operator+(const Vec2<T> &rhs) {
      return Vec2<T>::add(*this, rhs);
    }

    Vec2<T> operator*(const Vec2<T> &rhs) {
      return Vec2<T>::multiply(*this, rhs);
    }

    Vec2<T> operator/(const Vec2<T> &rhs) {
      return Vec2<T>::divide(*this, rhs);
    }

    Vec2<T> operator-(const T &rhs) {
      return Vec2<T>::subtract(*this, Vec2<T>(rhs));
    }

    Vec2<T> operator+(const T &rhs) {
      return Vec2<T>::add(*this, Vec2<T>(rhs));
    }

    Vec2<T> operator*(const T &rhs) {
      return Vec2<T>::multiply(*this, Vec2<T>(rhs));
    }

    Vec2<T> operator/(const T &rhs) {
      return Vec2<T>::divide(*this, Vec2<T>(rhs));
    }

    Vec2<T> operator+=(const Vec2<T> &rhs) {
      x += rhs.x;
      y += rhs.y;
      return *this;
    }

    Vec2<T> operator-=(const Vec2<T> &rhs) {
      x -= rhs.x;
      y -= rhs.y;
      return *this;
    }

    Vec2<T> operator*=(const Vec2<T> &rhs) {
      x *= rhs.x;
      y *= rhs.y;
      return *this;
    }

    Vec2<T> operator/=(const Vec2<T> &rhs) {
      x /= rhs.x;
      y /= rhs.y;
      return *this;
    }

    Vec2<T> operator+=(const T &rhs) {
      x += rhs;
      y += rhs;
    }

    Vec2<T> operator-=(const T &rhs) {
      x -= rhs;
      y -= rhs;
    }

    Vec2<T> operator*=(const T &rhs) {
      x *= rhs;
      y *= rhs;
    }

    Vec2<T> operator/=(const T &rhs) {
      x /= rhs;
      y /= rhs;
    }
};
#endif