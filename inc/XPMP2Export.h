/// @file       XPMP2Export.h
/// @brief      Symbol export macros for building and using XPMP2 as a static or shared library.
/// @details    Hand-maintained, portable for MSVC/MinGW (Windows) and GCC/Clang (Linux, macOS).
///             It replaces the per-compiler header CMake's generate_export_header() wrote into
///             the source tree, which flipped between platforms on every configure.
///             - XPMP2_STATIC_DEFINE: defined when XPMP2 is built or used as a static library.
///             - XPMP2_EXPORTS:       defined while building XPMP2 as a shared library.

#ifndef XPMP2_EXPORT_H
#define XPMP2_EXPORT_H

#ifdef XPMP2_STATIC_DEFINE
#  define XPMP2_EXPORT
#  define XPMP2_NO_EXPORT
#else
#  if defined(_WIN32) || defined(__CYGWIN__)
#    ifndef XPMP2_EXPORT
#      ifdef XPMP2_EXPORTS
         /* We are building this library */
#        define XPMP2_EXPORT __declspec(dllexport)
#      else
         /* We are using this library */
#        define XPMP2_EXPORT __declspec(dllimport)
#      endif
#    endif
#    ifndef XPMP2_NO_EXPORT
#      define XPMP2_NO_EXPORT
#    endif
#  else
#    ifndef XPMP2_EXPORT
#      define XPMP2_EXPORT __attribute__((visibility("default")))
#    endif
#    ifndef XPMP2_NO_EXPORT
#      define XPMP2_NO_EXPORT __attribute__((visibility("hidden")))
#    endif
#  endif
#endif

#ifndef XPMP2_DEPRECATED
#  if defined(_MSC_VER)
#    define XPMP2_DEPRECATED __declspec(deprecated)
#  else
#    define XPMP2_DEPRECATED __attribute__ ((__deprecated__))
#  endif
#endif

#ifndef XPMP2_DEPRECATED_EXPORT
#  define XPMP2_DEPRECATED_EXPORT XPMP2_EXPORT XPMP2_DEPRECATED
#endif

#ifndef XPMP2_DEPRECATED_NO_EXPORT
#  define XPMP2_DEPRECATED_NO_EXPORT XPMP2_NO_EXPORT XPMP2_DEPRECATED
#endif

#endif /* XPMP2_EXPORT_H */
