#include<stdio.h>
#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv) {
	VideoCapture cap;
	if(!cap.open(0)) {
		return 0;
	}
	for(;;) {
		Mat frame;
		cap >> frame;
		flip(frame, frame, 0);

		//make the processing
		Mat structuringElement = Mat::ones(6,6, CV_32F);
//		morphologyEx(frame, frame, 6, structuringElement);


		if(frame.empty()) break;
		imshow("this is you, smile! :)", frame);
		if(waitKey(10) == 27) break;
	}

	if(argc != 2) {
		printf("usage: DisplayImage.out <Image_Path \n");
		return -1;
	}

	Mat image;
	image = imread( argv[1], 1);
//	medianBlur(image, image, 7);

	if( !image.data) {
		printf("No image data \n");
		return -1;
	}
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", image);
//	imshow("Structuring Element", structuringElement);
//	for (int i=0; i< structuringElement.length; i++) {
//		printf("%d", structuringElement[i]);
//	}
	waitKey(0);

	return 0;
}
