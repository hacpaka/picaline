#include <stdio.h>
#include "picaline.h"

int main(void) {
	S_PCL_FRAME *frame;
	frame = pcl_init();

	printf("%d:%d\n", frame->width, frame->heigh);

	for (int i = 0; i < frame->heigh; i++){
		for (int j = 0; j < frame->width; j++){
			printf("%c", *(frame->data + i*frame->width + j));
		}
	}

	pcl_line(frame, pcl_point(10, 10), pcl_point(19, 100), LW_SINGLE);

	return 0;
}