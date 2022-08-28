#ifndef _MAT4
#define _MAT4
#include "Vec3.cpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iterator>
template<typename T> class Mat4 {
  public:

    T m[16];

    Mat4(): m {
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
    } {}

    Mat4(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T n, T m, T o, T p): m {
      a, b, c, d,
      e, f, g, h,
      i, j, k, l,
      n, m, o, p
    } {}

    Mat4(const Mat4<T>& rhs): m {
      rhs.m[0], rhs.m[1], rhs.m[2], rhs.m[3],
      rhs.m[4], rhs.m[5], rhs.m[6], rhs.m[7],
      rhs.m[8], rhs.m[9], rhs.m[10], rhs.m[11],
      rhs.m[12], rhs.m[13], rhs.m[14], rhs.m[15]
    } {}

    void set(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p) {
      (*this).m[0] = a;
      (*this).m[1] = b;
      (*this).m[2] = c;
      (*this).m[3] = d;
      (*this).m[4] = e;
      (*this).m[5] = f;
      (*this).m[6] = g;
      (*this).m[7] = h;
      (*this).m[8] = i;
      (*this).m[9] = j;
      (*this).m[10] = k;
      (*this).m[11] = l;
      (*this).m[12] = m;
      (*this).m[13] = n;
      (*this).m[14] = o;
      (*this).m[15] = p;
    }

    void identity() {
      (*this).m[0] = 1;
      (*this).m[1] = 0;
      (*this).m[2] = 0;
      (*this).m[3] = 0;
      (*this).m[4] = 0;
      (*this).m[5] = 1;
      (*this).m[6] = 0;
      (*this).m[7] = 0;
      (*this).m[8] = 0;
      (*this).m[9] = 0;
      (*this).m[10] = 1;
      (*this).m[11] = 0;
      (*this).m[12] = 0;
      (*this).m[13] = 0;
      (*this).m[14] = 0;
      (*this).m[15] = 1;
    }

    void multiply(Mat4<T> b) {
      T a11 {m[0]}, a12 {m[4]}, a13 {m[8]}, a14 {m[12]};
		  T a21 {m[1]}, a22 {m[5]}, a23 {m[9]}, a24 {m[13]};
		  T a31 {m[2]}, a32 {m[6]}, a33 {m[10]}, a34 {m[14]};
		  T a41 {m[3]}, a42 {m[7]}, a43 {m[11]}, a44 {m[15]};

		  T b11 {b.m[0]}, b12 {b.m[4]}, b13 {b.m[8]}, b14 {b.m[12]};
		  T b21 {b.m[1]}, b22 {b.m[5]}, b23 {b.m[9]}, b24 {b.m[13]};
		  T b31 {b.m[2]}, b32 {b.m[6]}, b33 {b.m[10]}, b34 {b.m[14]};
		  T b41 {b.m[3]}, b42 {b.m[7]}, b43 {b.m[11]}, b44 {b.m[15]};

		  m[0] = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
		  m[4] = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
		  m[8] = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
		  m[12] = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;

		  m[1] = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
		  m[5] = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
		  m[9] = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
		  m[13] = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;

		  m[2] = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
		  m[6] = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
		  m[10] = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
		  m[14] = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;

		  m[3] = a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41;
		  m[7] = a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42;
		  m[11] = a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43;
		  m[15] = a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44;
    }

    static void multiply(Mat4<T> a, Mat4<T> b) {
      Mat4<T> dst;
      T a11 {a.m[0]}, a12 {a.m[4]}, a13 {a.m[8]}, a14 {a.m[12]};
		  T a21 {a.m[1]}, a22 {a.m[5]}, a23 {a.m[9]}, a24 {a.m[13]};
		  T a31 {a.m[2]}, a32 {a.m[6]}, a33 {a.m[10]}, a34 {a.m[14]};
		  T a41 {a.m[3]}, a42 {a.m[7]}, a43 {a.m[11]}, a44 {a.m[15]};

		  T b11 {b.m[0]}, b12 {b.m[4]}, b13 {b.m[8]}, b14 {b.m[12]};
		  T b21 {b.m[1]}, b22 {b.m[5]}, b23 {b.m[9]}, b24 {b.m[13]};
		  T b31 {b.m[2]}, b32 {b.m[6]}, b33 {b.m[10]}, b34 {b.m[14]};
		  T b41 {b.m[3]}, b42 {b.m[7]}, b43 {b.m[11]}, b44 {b.m[15]};/*

      +--- doesn't matter that it's a because no Mat4<T>&
      |
      V    */
		  a.m[0] = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
		  a.m[4] = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
		  a.m[8] = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
		  a.m[12] = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;

		  a.m[1] = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
		  a.m[5] = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
		  a.m[9] = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
		  a.m[13] = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;

		  a.m[2] = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
		  a.m[6] = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
		  a.m[10] = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
		  a.m[14] = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;

		  a.m[3] = a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41;
		  a.m[7] = a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42;
		  a.m[11] = a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43;
		  a.m[15] = a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44;
    }

    void copy(Mat4<T> rhs) {
      set(rhs.m[0], rhs.m[1], rhs.m[2], rhs.m[3],
      rhs.m[4], rhs.m[5], rhs.m[6], rhs.m[7],
      rhs.m[8], rhs.m[9], rhs.m[10], rhs.m[11],
      rhs.m[12], rhs.m[13], rhs.m[14], rhs.m[15]);
    }

    void translate(T x, T y, T z) {
      multiply(Mat4<T>(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        x, y, z, 1
      ));
    }

    void translate(Vec3<T> v) {
      multiply(Mat4<T>(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        v.x, v.y, v.z, 1
      ));
    }

    void XRotate(T angle) {
      const T c {cos(angle)};
      const T s {sin(angle)};

      multiply(Mat4<T>(
        1, 0, 0, 0,
        0, c, s, 0,
        0,-s, c, 0,
        0, 0, 0, 1
      ));
    }

    void YRotate(T angle) {
      const T c {cos(angle)};
      const T s {sin(angle)};

      multiply(Mat4<T>(
        c, 0,-s, 0,
        0, 1, 0, 0,
        s, 0, c, 0,
        0, 0, 0, 1
      ));
    }

    void ZRotate(T angle) {
      const T c {cos(angle)};
      const T s {sin(angle)};

      multiply(Mat4<T>(
        c, s, 0, 0,
       -s, c, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
      ));
    }

    void rotate(Vec3<T> v) {
      XRotate(v.x);
      YRotate(v.y);
      ZRotate(v.z);
    }

    void rotate(T x, T y, T z) {
      XRotate(x);
      YRotate(y);
      ZRotate(z);
    }

    void scale(T x, T y, T z) {
      multiply(Mat4<T>(
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
      ));
    }

    Mat4<T> operator*(const Mat4<T> &rhs) {
      return Mat4<T>(*this, rhs);
    }

    Mat4<T> operator*=(const Mat4<T> &rhs) {
      multiply(rhs);
      return *this;
    }

    /*Mat4<T> operator*(const Vec3<T> &rhs) {
      multiply(Mat3<T>(
        rhs.x, 0, 0, 0,
        0, rhs.y, 0, 0,
        0, 0, rhs.z, 0,
        0, 0,     0, 1
      ));
    }

    Mat4<T> operator+(const Vec3<T> &rhs) {
      multiply(Mat4<T>(
        1,         0,     0,     0,
        0,         1,     0,     0,
        0,         0,     1,     0,
        rhs.x, rhs.y, rhs.z,     1
      ));
    }*/

    static Mat4<T> orthographic(T left, T right, T bottom, T top, T near, T far) {
      return Mat4<T>(
        2 / (right - left), 0, 0, 0,
        0, 2 / (top - bottom), 0, 0,
        0, 0, 2 / (near - far), 0,
 
        (left + right) / (left - right),
        (bottom + top) / (bottom - top),
        (near + far) / (near - far),
        1
      );
    }

    static Mat4<T> inverse(Mat4<T> matrix) {
      T m[16];
      std::copy(std::begin(matrix.m), std::end(matrix.m), std::begin(m));
      T m00 {m[0 * 4 + 0]};
      T m01 {m[0 * 4 + 1]};
      T m02 {m[0 * 4 + 2]};
      T m03 {m[0 * 4 + 3]};
      T m10 {m[1 * 4 + 0]};
      T m11 {m[1 * 4 + 1]};
      T m12 {m[1 * 4 + 2]};
      T m13 {m[1 * 4 + 3]};
      T m20 {m[2 * 4 + 0]};
      T m21 {m[2 * 4 + 1]};
      T m22 {m[2 * 4 + 2]};
      T m23 {m[2 * 4 + 3]};
      T m30 {m[3 * 4 + 0]};
      T m31 {m[3 * 4 + 1]};
      T m32 {m[3 * 4 + 2]};
      T m33 {m[3 * 4 + 3]};
      T tmp0  {m22 * m33};
      T tmp1  {m32 * m23};
      T tmp2  {m12 * m33};
      T tmp3  {m32 * m13};
      T tmp4  {m12 * m23};
      T tmp5  {m22 * m13};
      T tmp6  {m02 * m33};
      T tmp7  {m32 * m03};
      T tmp8  {m02 * m23};
      T tmp9  {m22 * m03};
      T tmp10 {m02 * m13};
      T tmp11 {m12 * m03};
      T tmp12 {m20 * m31};
      T tmp13 {m30 * m21};
      T tmp14 {m10 * m31};
      T tmp15 {m30 * m11};
      T tmp16 {m10 * m21};
      T tmp17 {m20 * m11};
      T tmp18 {m00 * m31};
      T tmp19 {m30 * m01};
      T tmp20 {m00 * m21};
      T tmp21 {m20 * m01};
      T tmp22 {m00 * m11};
      T tmp23 {m10 * m01};

      T t0 = (tmp0 * m11 + tmp3 * m21 + tmp4 * m31) -
             (tmp1 * m11 + tmp2 * m21 + tmp5 * m31);
      T t1 = (tmp1 * m01 + tmp6 * m21 + tmp9 * m31) -
             (tmp0 * m01 + tmp7 * m21 + tmp8 * m31);
      T t2 = (tmp2 * m01 + tmp7 * m11 + tmp10 * m31) -
             (tmp3 * m01 + tmp6 * m11 + tmp11 * m31);
      T t3 = (tmp5 * m01 + tmp8 * m11 + tmp11 * m21) -
             (tmp4 * m01 + tmp9 * m11 + tmp10 * m21);

      T d = 1.0 / (m00 * t0 + m10 * t1 + m20 * t2 + m30 * t3);

      return Mat4<T>(
        d * t0,
        d * t1,
        d * t2,
        d * t3,
        d * ((tmp1 * m10 + tmp2 * m20 + tmp5 * m30) -
          (tmp0 * m10 + tmp3 * m20 + tmp4 * m30)),
        d * ((tmp0 * m00 + tmp7 * m20 + tmp8 * m30) -
          (tmp1 * m00 + tmp6 * m20 + tmp9 * m30)),
        d * ((tmp3 * m00 + tmp6 * m10 + tmp11 * m30) -
          (tmp2 * m00 + tmp7 * m10 + tmp10 * m30)),
        d * ((tmp4 * m00 + tmp9 * m10 + tmp10 * m20) -
          (tmp5 * m00 + tmp8 * m10 + tmp11 * m20)),
        d * ((tmp12 * m13 + tmp15 * m23 + tmp16 * m33) -
          (tmp13 * m13 + tmp14 * m23 + tmp17 * m33)),
        d * ((tmp13 * m03 + tmp18 * m23 + tmp21 * m33) -
          (tmp12 * m03 + tmp19 * m23 + tmp20 * m33)),
        d * ((tmp14 * m03 + tmp19 * m13 + tmp22 * m33) -
          (tmp15 * m03 + tmp18 * m13 + tmp23 * m33)),
        d * ((tmp17 * m03 + tmp20 * m13 + tmp23 * m23) -
          (tmp16 * m03 + tmp21 * m13 + tmp22 * m23)),
        d * ((tmp14 * m22 + tmp17 * m32 + tmp13 * m12) -
          (tmp16 * m32 + tmp12 * m12 + tmp15 * m22)),
        d * ((tmp20 * m32 + tmp12 * m02 + tmp19 * m22) -
          (tmp18 * m22 + tmp21 * m32 + tmp13 * m02)),
        d * ((tmp18 * m12 + tmp23 * m32 + tmp15 * m02) -
          (tmp22 * m32 + tmp14 * m02 + tmp19 * m12)),
        d * ((tmp22 * m22 + tmp16 * m02 + tmp21 * m12) -
          (tmp20 * m12 + tmp23 * m22 + tmp17 * m02))
      );
    }

    void inverse() {
      T m00 {m[0 * 4 + 0]};
      T m01 {m[0 * 4 + 1]};
      T m02 {m[0 * 4 + 2]};
      T m03 {m[0 * 4 + 3]};
      T m10 {m[1 * 4 + 0]};
      T m11 {m[1 * 4 + 1]};
      T m12 {m[1 * 4 + 2]};
      T m13 {m[1 * 4 + 3]};
      T m20 {m[2 * 4 + 0]};
      T m21 {m[2 * 4 + 1]};
      T m22 {m[2 * 4 + 2]};
      T m23 {m[2 * 4 + 3]};
      T m30 {m[3 * 4 + 0]};
      T m31 {m[3 * 4 + 1]};
      T m32 {m[3 * 4 + 2]};
      T m33 {m[3 * 4 + 3]};
      T tmp0  {m22 * m33};
      T tmp1  {m32 * m23};
      T tmp2  {m12 * m33};
      T tmp3  {m32 * m13};
      T tmp4  {m12 * m23};
      T tmp5  {m22 * m13};
      T tmp6  {m02 * m33};
      T tmp7  {m32 * m03};
      T tmp8  {m02 * m23};
      T tmp9  {m22 * m03};
      T tmp10 {m02 * m13};
      T tmp11 {m12 * m03};
      T tmp12 {m20 * m31};
      T tmp13 {m30 * m21};
      T tmp14 {m10 * m31};
      T tmp15 {m30 * m11};
      T tmp16 {m10 * m21};
      T tmp17 {m20 * m11};
      T tmp18 {m00 * m31};
      T tmp19 {m30 * m01};
      T tmp20 {m00 * m21};
      T tmp21 {m20 * m01};
      T tmp22 {m00 * m11};
      T tmp23 {m10 * m01};

      T t0 = (tmp0 * m11 + tmp3 * m21 + tmp4 * m31) -
             (tmp1 * m11 + tmp2 * m21 + tmp5 * m31);
      T t1 = (tmp1 * m01 + tmp6 * m21 + tmp9 * m31) -
             (tmp0 * m01 + tmp7 * m21 + tmp8 * m31);
      T t2 = (tmp2 * m01 + tmp7 * m11 + tmp10 * m31) -
             (tmp3 * m01 + tmp6 * m11 + tmp11 * m31);
      T t3 = (tmp5 * m01 + tmp8 * m11 + tmp11 * m21) -
             (tmp4 * m01 + tmp9 * m11 + tmp10 * m21);

      T d = 1.0 / (m00 * t0 + m10 * t1 + m20 * t2 + m30 * t3);

      set(
        d * t0,
        d * t1,
        d * t2,
        d * t3,
        d * ((tmp1 * m10 + tmp2 * m20 + tmp5 * m30) -
          (tmp0 * m10 + tmp3 * m20 + tmp4 * m30)),
        d * ((tmp0 * m00 + tmp7 * m20 + tmp8 * m30) -
          (tmp1 * m00 + tmp6 * m20 + tmp9 * m30)),
        d * ((tmp3 * m00 + tmp6 * m10 + tmp11 * m30) -
          (tmp2 * m00 + tmp7 * m10 + tmp10 * m30)),
        d * ((tmp4 * m00 + tmp9 * m10 + tmp10 * m20) -
          (tmp5 * m00 + tmp8 * m10 + tmp11 * m20)),
        d * ((tmp12 * m13 + tmp15 * m23 + tmp16 * m33) -
          (tmp13 * m13 + tmp14 * m23 + tmp17 * m33)),
        d * ((tmp13 * m03 + tmp18 * m23 + tmp21 * m33) -
          (tmp12 * m03 + tmp19 * m23 + tmp20 * m33)),
        d * ((tmp14 * m03 + tmp19 * m13 + tmp22 * m33) -
          (tmp15 * m03 + tmp18 * m13 + tmp23 * m33)),
        d * ((tmp17 * m03 + tmp20 * m13 + tmp23 * m23) -
          (tmp16 * m03 + tmp21 * m13 + tmp22 * m23)),
        d * ((tmp14 * m22 + tmp17 * m32 + tmp13 * m12) -
          (tmp16 * m32 + tmp12 * m12 + tmp15 * m22)),
        d * ((tmp20 * m32 + tmp12 * m02 + tmp19 * m22) -
          (tmp18 * m22 + tmp21 * m32 + tmp13 * m02)),
        d * ((tmp18 * m12 + tmp23 * m32 + tmp15 * m02) -
          (tmp22 * m32 + tmp14 * m02 + tmp19 * m12)),
        d * ((tmp22 * m22 + tmp16 * m02 + tmp21 * m12) -
          (tmp20 * m12 + tmp23 * m22 + tmp17 * m02))
      );
    }

    T& operator[](size_t i) {
      return m[i];
    }

    static Mat4<T> perspective(T fieldOfViewInRadians, T aspect, T near, T far) {
      T f = tan(M_PI * 0.5 - 0.5 * fieldOfViewInRadians);
      T rangeInv = 1.0 / (near - far);
 
      return Mat4<T>(
        f / aspect, 0, 0, 0,
        0, f, 0, 0,
        0, 0, (near + far) * rangeInv, -1,
        0, 0, near * far * rangeInv * 2, 0
      );
    }

    static Mat4<T> lookAt(Vec3<T> cameraPosition, Vec3<T> target, Vec3<T> up) {
      Vec3<T> zAxis {((cameraPosition - target).normalize())};
      Vec3<T> xAxis {(Vec3<T>::cross(up, zAxis)).normalize()};
      Vec3<T> yAxis {(Vec3<T>::cross(zAxis, xAxis)).normalize()};

      return Mat4<T>(
        xAxis.x, xAxis.y, xAxis.z, 0,
        yAxis.x, yAxis.y, yAxis.z, 0,
        zAxis.x, zAxis.y, zAxis.z, 0,
        cameraPosition.x,
        cameraPosition.y,
        cameraPosition.z,
        1
      );
    }
};
#endif