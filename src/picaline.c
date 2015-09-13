#include "picaline.h"
#include <malloc.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>
#include "symbols.h"

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

void pcl_line(S_PCL_FRAME *frame, usi x, usi y, usi length, E_PCL_LINE_COURCE cource, E_PCL_LINE_WEIGHT lt){

	usi fx = x;
	usi fy = y;

	if (cource == LC_UP){
		y = length <= y ? y - length : 0;
	}
	if (cource == LC_DOWN){
		fy = y + length < frame->heigh ? y + length : frame->heigh - 1;
	}

	if (cource == LC_LEFT){
		x = length <= x ? x - length : 0;
	}

	if (cource == LC_RIGHT){
		fx = x + length < frame->width ? x + length : frame->width - 1;
	}

	printf("%d:%d,%d:%d\n", x, fx, y, fy);

	for(usi i = x; i <= fx; i++){
		pcl_point(frame, i, y, lt);
	}

	for(usi i = y; i <= fy; i++){
		pcl_point(frame, x, i, lt);
	}

}

void pcl_point(S_PCL_FRAME *frame, usi x, usi y, E_PCL_LINE_WEIGHT lt){
	if (x < frame->width && y < frame->heigh){
		*(frame->data + y * frame->width + x) = lt;
	}
}

E_PCL_LINE_WEIGHT pcl_pntinf(S_PCL_FRAME *frame, usi x, usi y){
	if (x < 0 || x >= frame->width || y < 0 || y >= frame->heigh){
		return LW_EMPTY;
	}

	return *(frame->data + y * frame->width + x);
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

				char ch[4];

				for (int i = 0; i < 4; i++){
					ch[i] = '\0';
				}

				strcpy(ch, "*");

				if (pcl_pntinf(frame, j, i - 1) == LW_SINGLE || pcl_pntinf(frame, j, i + 1) == LW_SINGLE){
					strcpy(ch, S_SGL_VER);
				}

				if (pcl_pntinf(frame, j - 1, i) == LW_SINGLE || pcl_pntinf(frame, j + 1, i) == LW_SINGLE){
					strcpy(ch, S_SGL_HOR);
				}

				printf("%s", ch);
				continue;

			}

		}
	}
}
