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
} S_PCL_FRAME;

extern S_PCL_FRAME pcl_init();


//extern void pcl_line(E_LINE_WEIGHT lt);

#endif
