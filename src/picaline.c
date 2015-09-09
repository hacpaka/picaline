#include "picaline.h"
#include <malloc.h>
#include <sys/ioctl.h>
#include "symbols.h"
//#include <stdio.h>


S_PCL_POINT *pcl_mkpoint(unsigned int x, unsigned int y){
	S_PCL_POINT *point = malloc(sizeof(S_PCL_POINT));
	point->x = x;
	point->y = y;
	return point;
}

S_PCL_FRAME *pcl_mkframe(){
	struct winsize win;
	S_PCL_FRAME *frame = malloc(sizeof(S_PCL_FRAME));

	ioctl(0, TIOCGWINSZ, &win);
	frame->width = win.ws_col;
	frame->heigh = win.ws_row;
	frame->data = malloc(win.ws_col * win.ws_row * sizeof(unsigned  char));

	for (int i = 0; i < frame->heigh; i++){
		for(int j = 0; j < frame->width; j++) {
			*(frame->data + i*frame->width+j) = LW_EMPTY;
		}
	}

	return frame;
}

void pcl_line(S_PCL_FRAME *frame, const S_PCL_POINT *fp, const S_PCL_POINT *sp, const E_PCL_LINE_WEIGHT lt){

	unsigned int fx = fp->x;
	unsigned int sx = sp->x;
	if (fp->x > sp->x){
		fx = sp->x;
		sx = fp->x;
	}

	unsigned int fy = fp->y;
	unsigned int sy = sp->y;
	if (fp->y > sp->y){
		fy = sp->y;
		sy = fp->y;
	}

	while(fx < sx || fy < sy){
		pcl_point(frame, pcl_mkpoint(fx, fy), lt);
		if (fx < sx) {
			fx++;
		}
		if (fy < sy) {
			fy++;
		}
	}
	pcl_point(frame, pcl_mkpoint(fx, fy), lt);

}

void pcl_point(S_PCL_FRAME *frame, S_PCL_POINT *pnt, E_PCL_LINE_WEIGHT lt){
	if (pnt->x < frame->width && pnt->y < frame->heigh){
		*(frame->data + pnt->y * frame->width + pnt->x) = lt;
	}
}

void pcl_draw(S_PCL_FRAME *frame){
	E_PCL_LINE_WEIGHT lw;
	for (int i = 0; i < frame->heigh; i++){
		for(int j = 0; j < frame->width; j++) {
			lw = *(frame->data + i*frame->width+j);

			if (lw == LW_EMPTY){
				printf("%c", '.');
				continue;
			}

			if (lw == LW_SINGLE){
				printf("%c", '|');
				continue;
			}
		}
	}
}
