#ifndef _VEC3
#define _VEC3
#include <math.h>
template<typename T> struct Vec3 {
  public:
    T x;
    T y;
    T z;

    Vec3(T x, T y, T z): x {x}, y {y}, z {z} {}

    Vec3(T v): x {v}, y {v}, z {v} {}

    Vec3(const Vec3<T>& rhs): x {rhs.x}, y {rhs.y}, z {rhs.z} {}

    Vec3(): x {0.0f}, y {0.0f}, z {0.0f} {}

    inline void set(T x, T y, T z) {
      (*this).x = x;
      (*this).y = y;
      (*this).z = z;
    }

    inline T mag() {
      return sqrt((*this).x * (*this).x + (*this).y * (*this).y + (*this).z * (*this).z);
    }

    inline Vec3<T> normalize() {
      T len = (*this).mag();
      (*this).x /= len;
      (*this).y /= len;
      (*this).z /= len;
      return *this;
    }

    T operator[](unsigned int i) {
      switch (i) {
        case 0:
          return x;
          break;

        case 1:
          return y;
          break;

        case 2:
          return z;
          break;

        default:
          throw "out of range";
          break;
      }
    }

    static Vec3<T> cross(Vec3<T> a, Vec3<T> b) {
      return Vec3<T>(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
      );
    }

    static Vec3<T> subtract(Vec3<T> a, Vec3<T> b) {
      return Vec3<T>(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    static Vec3<T> add(Vec3<T> a, Vec3<T> b) {
      return Vec3<T>(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    static Vec3<T> multiply(Vec3<T> a, Vec3<T> b) {
      return Vec3<T>(a.x * b.x, a.y * b.y, a.z * b.z);
    }

    static Vec3<T> divide(Vec3<T> a, Vec3<T> b) {
      return Vec3<T>(a.x / b.x, a.y / b.y, a.z / b.z);
    }

    Vec3<T> operator-(const Vec3<T> &rhs) {
      return Vec3<T>::subtract(*this, rhs);
    }

    Vec3<T> operator+(const Vec3<T> &rhs) {
      return Vec3<T>::add(*this, rhs);
    }

    Vec3<T> operator*(const Vec3<T> &rhs) {
      return Vec3<T>::multiply(*this, rhs);
    }

    Vec3<T> operator/(const Vec3<T> &rhs) {
      return Vec3<T>::divide(*this, rhs);
    }

    Vec3<T> operator-(const T &rhs) {
      return Vec3<T>::subtract(*this, Vec3<T>(rhs));
    }

    Vec3<T> operator+(const T &rhs) {
      return Vec3<T>::add(*this, Vec3<T>(rhs));
    }

    Vec3<T> operator*(const T &rhs) {
      return Vec3<T>::multiply(*this, Vec3<T>(rhs));
    }

    Vec3<T> operator/(const T &rhs) {
      return Vec3<T>::divide(*this, Vec3<T>(rhs));
    }

    Vec3<T> operator+=(const Vec3<T> &rhs) {
      x += rhs.x;
      y += rhs.y;
      z += rhs.z;
      return *this;
    }

    Vec3<T> operator-=(const Vec3<T> &rhs) {
      x -= rhs.x;
      y -= rhs.y;
      z -= rhs.z;
      return *this;
    }

    Vec3<T> operator*=(const Vec3<T> &rhs) {
      x *= rhs.x;
      y *= rhs.y;
      z *= rhs.z;
      return *this;
    }

    Vec3<T> operator/=(const Vec3<T> &rhs) {
      x /= rhs.x;
      y /= rhs.y;
      z /= rhs.z;
      return *this;
    }

    Vec3<T> operator+=(const T &rhs) {
      x += rhs;
      y += rhs;
      z += rhs;
    }

    Vec3<T> operator-=(const T &rhs) {
      x -= rhs;
      y -= rhs;
      z -= rhs;
    }

    Vec3<T> operator*=(const T &rhs) {
      x *= rhs;
      y *= rhs;
      z *= rhs;
    }

    Vec3<T> operator/=(const T &rhs) {
      x /= rhs;
      y /= rhs;
      z /= rhs;
    }
};
#endif