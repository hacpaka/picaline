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

extern S_PCL_FRAME *pcl_mkframe();
extern S_PCL_POINT *pcl_mkpoint(unsigned int x, unsigned int y);

extern void pcl_draw(S_PCL_FRAME *frame);
extern void pcl_point(S_PCL_FRAME *frame, S_PCL_POINT *pnt, E_PCL_LINE_WEIGHT lt);
extern void pcl_line(S_PCL_FRAME *frame, const S_PCL_POINT *fp, const S_PCL_POINT *sp, const E_PCL_LINE_WEIGHT lt);

#endif
