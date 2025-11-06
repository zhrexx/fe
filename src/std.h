#ifndef STD_H
#define STD_H

#ifndef FE_NO_STD
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define fe_strlen(s) strlen(s)
#define fe_strcmp(s1, s2) strcmp(s1, s2)
#define fe_strchr(s, c) strchr(s, c)
#define fe_sprintf(s, f, ...) sprintf(s, f, __VA_ARGS__)
#define fe_strtod(s, e) strtod(s, e)
#define fe_memset(s, c, n) memset(s, c, n)

#define fe_fprintf(s, f, ...) fprintf(s, f, __VA_ARGS__)
#define fe_fputc(c, s) fputc(c, s)
#define fe_printf(...) printf(__VA_ARGS__)
#define fe_fgetc(s) fgetc(s)
#define fe_fopen(p, m) fopen(p, m)

#define fe_exit(s) exit(s)
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define fe_setjmp(e) setjmp(e)
#define fe_longjmp(e, v) longjmp(e, v)
#else

#define DEF_REQUIRED_FN(name) \
enum { name##_is_required = 1 / (!!(0 && &name)) } // IF ERROR HAPPEND PROVIDE THESE



DEF_REQUIRED_FN(fe_strlen);
DEF_REQUIRED_FN(fe_strcmp);
DEF_REQUIRED_FN(fe_strchr);
DEF_REQUIRED_FN(fe_sprintf);
DEF_REQUIRED_FN(fe_strtod);
DEF_REQUIRED_FN(fe_memset);

DEF_REQUIRED_FN(fe_fprintf);
DEF_REQUIRED_FN(fe_fputc);
DEF_REQUIRED_FN(fe_printf);
DEF_REQUIRED_FN(fe_fgetc);
DEF_REQUIRED_FN(fe_fopen);

DEF_REQUIRED_FN(fe_exit);

DEF_REQUIRED_FN(fe_setjmp);
DEF_REQUIRED_FN(fe_longjmp);

#ifndef EXIT_FAILURE
    #define EXIT_FAILURE 1
#endif

#ifndef EXIT_SUCCESS
    #define EXIT_SUCCESS 0
#endif

#ifndef stderr
#error "stderr is needed"
#endif

#ifndef stdout
#error "stdout is needed"
#endif

#ifndef EOF
#error "EOF is needed"
#endif

typedef struct FILE FILE;

#endif
#endif