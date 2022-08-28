#ifndef _HELLO_TRIANGLE_MACROS
#define _HELLO_TRIANGLE_MACROS
#ifdef PRODUCTION
#define NDEBUG
//               +--- ../Resources/ doesn't work
//               |
//               V
#define PATH(X) "./../Resources/" X
#else
#define PATH(X) "./" X
#endif
#endif
#define FPS_UPDATE_RATE 0.5
#define VERSION_STRING "1.1.0"

/*
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
  #ifdef _WIN64
    #define WINDOWS
  #else
    #error "32-bit windows not supported"
  #endif
#elif __APPLE__
  #include <TargetConditionals.h>
  #if TARGET_IPHONE_SIMULATOR
    #define APPLE_SIMULATOR
  //#elif TARGET_OS_MACCATALYST 
  #elif TARGET_OS_IPHONE
    #define APPL_ES
  #elif TARGET_OS_MAC
    #define MACOS
  #else
    #error "Unknown Apple platform"
  #endif
#elif __ANDROID__
  
#elif __linux__

#elif __unix__

#elif defined(_POSIX_VERSION)
  
#else
  #error "Unknown compiler"
#endif*/
