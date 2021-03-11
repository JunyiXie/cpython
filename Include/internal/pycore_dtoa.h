#ifndef PY_NO_SHORT_FLOAT_REPR
#ifndef Py_CORE_DTOA_H
#define Py_CORE_DTOA_H
#ifdef __cplusplus
extern "C" {
#endif

#ifndef Py_BUILD_CORE
#  error "this header requires Py_BUILD_CORE define"
#endif

/* These functions are used by modules compiled as C extension like math:
   they must be exported. */

PyAPI_FUNC(double) _Py_dg_strtod(const char *str, char **ptr);
PyAPI_FUNC(char *) _Py_dg_dtoa(double d, int mode, int ndigits,
                        int *decpt, int *sign, char **rve);
PyAPI_FUNC(void) _Py_dg_freedtoa(char *s);
PyAPI_FUNC(double) _Py_dg_stdnan(int sign);
PyAPI_FUNC(double) _Py_dg_infinity(int sign);

#define Kmax 7

typedef uint32_t ULong;
typedef int32_t Long;
typedef uint64_t ULLong;

struct
Bigint {
    struct Bigint *next;
    int k, maxwds, sign, wds;
    ULong x[1];
};

typedef struct Bigint Bigint;
#ifdef __cplusplus
}
#endif
#endif /* !Py_CORE_DTOA_H */
#endif   /* !PY_NO_SHORT_FLOAT_REPR */
