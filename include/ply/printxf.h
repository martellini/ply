#ifndef _PRINTXF_H
#define _PRINTXF_H

#include <stdio.h>

struct printxf;

typedef int (*vfprintxf_fn)(struct printxf *pxf,
			    FILE *fp, const char *spec, va_list ap);

extern int printxf_vfprintf(struct printxf *pxf,
			    FILE *fp, const char *spec, va_list ap);

struct printxf {
	vfprintxf_fn vfprintxf[0x80];
};

extern struct printxf printxf_default;

int vfprintxf(struct printxf *pxf, FILE *stream, const char *fmt, va_list ap);
int  fprintxf(struct printxf *pxf, FILE *stream, const char *fmt, ...);
int  vprintxf(struct printxf *pxf,               const char *fmt, va_list ap);
int   printxf(struct printxf *pxf,               const char *fmt, ...);

#endif	/* _PRINTXF_H */