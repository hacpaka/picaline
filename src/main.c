#include <stdio.h>
#include "picaline.h"

int main(void) {
	S_PCL_FRAME *frame;

	frame = pcl_init();
	frame->heigh--;

	pcl_draw(frame);
	pcl_line(frame, pcl_point(10, 10), pcl_point(19, 100), LW_SINGLE);

	return 0;
}