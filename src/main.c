#include <stdio.h>
#include "picaline.h"

int main(void) {
	S_PCL_FRAME *frame;

	frame = pcl_mkframe();
	frame->heigh--;

	pcl_line(frame, pcl_mkpoint(10, 10), pcl_mkpoint(50, 100), LW_SINGLE);
	pcl_draw(frame);

	return 0;
}