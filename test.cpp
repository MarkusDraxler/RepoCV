#include<stdio.h>
#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv) {
	VideoCapture cap;

	if(!cap.open(0)) {
		return 0;
	}	
	Mat frame;
	cap >> frame;
	Mat destination(frame.rows, frame.cols, CV_8UC3, Scalar(0,0,255));
	for(;;) {
		Mat frame;
		cap >> frame;
		flip(frame, frame, 0);

		//make the processing
		Mat structuringElement = Mat::ones(6,6, CV_32F);
//		morphologyEx(frame, frame, 6, structuringElement);
//		frame = frame * 1.08;
//		medianBlur(frame, frame, 21);		
//		frame.convertTo(destination, CV_8UC3);

		//printf("Type: %d \n", destination.type());
		bilateralFilter(frame, destination, 15, 40, 40);
//		GaussianBlur(frame, frame, Size(7,7), 0.3, 0.3, BORDER_DEFAULT);


		if(frame.empty()) break;
		imshow("this is you, smile! :)", destination);
		if(waitKey(10) == 27) break;
	}

	if(argc != 2) {
		printf("usage: DisplayImage.out <Image_Path \n");
		return -1;
	}

	Mat image;
	image = imread( argv[1], 1);

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
