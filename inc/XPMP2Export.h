
#ifndef XPMP2_EXPORT_H
#define XPMP2_EXPORT_H

#ifdef XPMP2_STATIC_DEFINE
#  define XPMP2_EXPORT
#  define XPMP2_NO_EXPORT
#else
#  ifndef XPMP2_EXPORT
#    ifdef XPMP2_EXPORTS
        /* We are building this library */
#      define XPMP2_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define XPMP2_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef XPMP2_NO_EXPORT
#    define XPMP2_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef XPMP2_DEPRECATED
#  define XPMP2_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef XPMP2_DEPRECATED_EXPORT
#  define XPMP2_DEPRECATED_EXPORT XPMP2_EXPORT XPMP2_DEPRECATED
#endif

#ifndef XPMP2_DEPRECATED_NO_EXPORT
#  define XPMP2_DEPRECATED_NO_EXPORT XPMP2_NO_EXPORT XPMP2_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef XPMP2_NO_DEPRECATED
#    define XPMP2_NO_DEPRECATED
#  endif
#endif

#endif /* XPMP2_EXPORT_H */
