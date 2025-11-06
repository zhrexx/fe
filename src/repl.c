#include <setjmp.h>

#define FE_IMPLEMENTATION
#include "fe.h"

static jmp_buf toplevel;
static char buf[64000];

static void onerror(fe_Context *ctx, const char *msg, fe_Object *cl) {
    unused(ctx), unused(cl);
    fe_fprintf(stderr, "error: %s\n", msg);
    longjmp(toplevel, -1);
}


int main(int argc, char **argv) {
    int gc;
    fe_Object *obj;
    FILE *volatile fp = stdin;
    fe_Context *ctx = fe_open(buf, sizeof(buf));

    /* init input file */
    if (argc > 1) {
        fp = fe_fopen(argv[1], "rb");
        if (!fp) { fe_error(ctx, "could not open input file"); }
    }

    if (fp == stdin) { fe_handlers(ctx)->error = onerror; }
    gc = fe_savegc(ctx);
    setjmp(toplevel);

    /* re(p)l */
    for (;;) {
        fe_restoregc(ctx, gc);
        if (fp == stdin) { fe_printf("> "); }
        if (!(obj = fe_readfp(ctx, fp))) { break; }
        obj = fe_eval(ctx, obj);
        if (fp == stdin) {
            fe_writefp(ctx, obj, stdout);
            fe_printf("\n");
        }
    }

    return EXIT_SUCCESS;
}
