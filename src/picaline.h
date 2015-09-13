#ifndef PICALINE_PICALINE_H
#define PICALINE_PICALINE_H

#include <unistd.h>

typedef unsigned short int usi;

typedef enum {
	LW_EMPTY = 0,
	LW_SINGLE = 1,
	LW_DOUBLE = 2,
} E_PCL_LINE_WEIGHT;

typedef enum {
	LC_UP = 0,
	LC_DOWN = 1,
	LC_LEFT = 2,
	LC_RIGHT = 3,
} E_PCL_LINE_COURCE;

typedef struct {
	usi width;
	usi  heigh;
	unsigned char *data;
} S_PCL_FRAME;

extern S_PCL_FRAME *pcl_mkframe();

extern E_PCL_LINE_WEIGHT pcl_pntinf(S_PCL_FRAME *frame, usi x, usi y);

extern void pcl_point(S_PCL_FRAME *frame, usi x, usi y, E_PCL_LINE_WEIGHT lt);
extern void pcl_line(S_PCL_FRAME *frame, usi x, usi y, usi length, E_PCL_LINE_COURCE cource, E_PCL_LINE_WEIGHT lt);
extern void pcl_draw(S_PCL_FRAME *frame);

#endif
