#include "picaline.h"
#include <ncurses.h>

int main(void) {
	S_PCL_FRAME *frame;

	frame = pcl_mkframe();

	pcl_line(frame, 3, 1, 22, LC_RIGHT, LW_SINGLE);
	pcl_draw(frame);

	return 0;
}

