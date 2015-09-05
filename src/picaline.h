#ifndef PICALINE_PICALINE_H
#define PICALINE_PICALINE_H

#include <unistd.h>

typedef enum {
	LW_SINGLE = 0,
	LW_DOUBLE = 1,
} E_PCL_LINE_WEIGHT;

typedef struct {
	unsigned int width;
	unsigned int heigh;
	unsigned char *data;
} S_PCL_FRAME;

typedef struct {
	unsigned int x;
	unsigned int y;
} S_PCL_POINT;

extern S_PCL_FRAME *pcl_init();
extern S_PCL_POINT *pcl_point(unsigned int x, unsigned int y);
extern void pcl_line(S_PCL_FRAME *frame, const S_PCL_POINT *x, const S_PCL_POINT *y, const E_PCL_LINE_WEIGHT *lt);

#endif
