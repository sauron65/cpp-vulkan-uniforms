#ifndef _VEC4
#define _VEC4
#include <stdexcept>
#include <math.h>
template<typename T> struct Vec4 {
  public:
    T x;
    T y;
    T z;
    T w;

    inline void set(T x, T y, T z) {
      (*this).x = x;
      (*this).y = y;
      (*this).z = z;
      (*this).w = w;
    }

    inline T mag() {
      return sqrt((*this).x * (*this).x + (*this).y * (*this).y + (*this).z * (*this).z + (*this).w * (*this).w);
    }

    inline void normalize() {
      T len = (*this).mag();
      (*this).x /= len;
      (*this).y /= len;
      (*this).z /= len;
      (*this).w /= len;
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

        case 3:
          return w;
          break;

        default:
          throw std::runtime_error("out of range");
          break;
      }
    }

    // static Vec4<T> cross(Vec4<T> a, Vec4<T> b) {
    //   return Vec4<T>(
    //     a.y * b.z - a.z * b.y,
    //     a.z * b.x - a.x * b.z,
    //     a.x * b.y - a.y * b.x
    //   );
    // }

    static Vec4<T> subtract(Vec4<T> a, Vec4<T> b) {
      return Vec4<T>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
    }

    static Vec4<T> add(Vec4<T> a, Vec4<T> b) {
      return Vec4<T>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
    }

    static Vec4<T> multiply(Vec4<T> a, Vec4<T> b) {
      return Vec4<T>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
    }

    static Vec4<T> divide(Vec4<T> a, Vec4<T> b) {
      return Vec4<T>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
    }

    Vec4<T> operator-(const Vec4<T> &rhs) {
      return Vec4<T>::subtract(*this, rhs);
    }

    Vec4<T> operator+(const Vec4<T> &rhs) {
      return Vec4<T>::add(*this, rhs);
    }

    Vec4<T> operator*(const Vec4<T> &rhs) {
      return Vec4<T>::multiply(*this, rhs);
    }

    Vec4<T> operator/(const Vec4<T> &rhs) {
      return Vec4<T>::divide(*this, rhs);
    }

    Vec4<T> operator-(const T &rhs) {
      return Vec4<T>::subtract(*this, Vec4<T>(rhs));
    }

    Vec4<T> operator+(const T &rhs) {
      return Vec4<T>::add(*this, Vec4<T>(rhs));
    }

    Vec4<T> operator*(const T &rhs) {
      return Vec4<T>::multiply(*this, Vec4<T>(rhs));
    }

    Vec4<T> operator/(const T &rhs) {
      return Vec4<T>::divide(*this, Vec4<T>(rhs));
    }

    Vec4<T> operator+=(const Vec4<T> &rhs) {
      x += rhs.x;
      y += rhs.y;
      z += rhs.z;
      w += rhs.w;
      return *this;
    }

    Vec4<T> operator-=(const Vec4<T> &rhs) {
      x -= rhs.x;
      y -= rhs.y;
      z -= rhs.z;
      w -= rhs.w;
      return *this;
    }

    Vec4<T> operator*=(const Vec4<T> &rhs) {
      x *= rhs.x;
      y *= rhs.y;
      z *= rhs.z;
      w *= rhs.w;
      return *this;
    }

    Vec4<T> operator/=(const Vec4<T> &rhs) {
      x /= rhs.x;
      y /= rhs.y;
      z /= rhs.z;
      w /= rhs.w;
      return *this;
    }

    Vec4<T> operator+=(const T &rhs) {
      x += rhs;
      y += rhs;
      z += rhs;
      w += rhs;
    }

    Vec4<T> operator-=(const T &rhs) {
      x -= rhs;
      y -= rhs;
      z -= rhs;
      w -= rhs;
    }

    Vec4<T> operator*=(const T &rhs) {
      x *= rhs;
      y *= rhs;
      z *= rhs;
      w *= rhs;
    }

    Vec4<T> operator/=(const T &rhs) {
      x /= rhs;
      y /= rhs;
      z /= rhs;
      w /= rhs;
    }
};
#endif