#include <stdio.h>
#include "picaline.h"
#include <iconv.h>

int main(void) {
	S_PCL_FRAME *frame;

	frame = pcl_mkframe();
	frame->heigh--;

	pcl_line(frame, pcl_mkpoint(3, 3), pcl_mkpoint(3, 6), LW_SINGLE);
	pcl_draw(frame);

	return 0;
}

