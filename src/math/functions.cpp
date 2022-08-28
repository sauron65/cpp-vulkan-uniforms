#define _USE_MATH_DEFINES
#include <math.h>

template<typename T> inline T radToDeg(T a) {
  return a * (180 / M_PI);
}

template<typename T> inline T degToRad(T a) {
  return a * (M_PI / 180);
}