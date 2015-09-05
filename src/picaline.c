#include "picaline.h"
#include <sys/ioctl.h>
#include <stdio.h>

S_PCL_FRAME pcl_init(){
	struct winsize win;
	S_PCL_FRAME frame;

	ioctl(0, TIOCGWINSZ, &win);

	frame.width = win.ws_col;
	frame.heigh = win.ws_row;

	return frame;
}

