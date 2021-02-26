#ifndef SLIDE_H
#define SLIDE_H

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2
#define false 0
#define true 1

int slide_line(int *line, size_t size, int direction);
void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);


#endif
