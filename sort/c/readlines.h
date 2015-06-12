#ifndef _READLINES_H
#define _READLINES_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int freelines(char **lines, size_t n);
int readlines(char ***lines, size_t *n, FILE *stream);

#endif /* _READLINES_H */
