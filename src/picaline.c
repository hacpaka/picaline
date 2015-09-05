#include "picaline.h"
#include <malloc.h>
#include <sys/ioctl.h>
//#include <stdio.h>

S_PCL_FRAME *pcl_init(){
	struct winsize win;
	S_PCL_FRAME *frame = malloc(sizeof(S_PCL_FRAME));

	ioctl(0, TIOCGWINSZ, &win);
	frame->width = win.ws_col;
	frame->heigh = win.ws_row;
	frame->data = malloc(win.ws_col * win.ws_row * sizeof(unsigned  char));

	for (int i = 0; i < frame->heigh; i++){
		for(int j = 0; j < frame->width; j++) {
			*(frame->data + i*frame->width+j) = '.';
		}
	}

	return frame;
}

S_PCL_POINT *pcl_point(unsigned int x, unsigned int y){
	S_PCL_POINT *point = malloc(sizeof(S_PCL_POINT));
	point->x = x;
	point->y = y;
	return point;
}

void pcl_line(S_PCL_FRAME *frame, const S_PCL_POINT *x, const S_PCL_POINT *y, const E_PCL_LINE_WEIGHT *lt){

	

}
