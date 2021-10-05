#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace cv;
using namespace cv::xfeatures2d;
int main(int argc, char** argv){
    VideoCapture cap(0);
    while (1) {
		Mat frame;
		cap >> frame;
		//-- Step 1: Detect the keypoints using a FAST Detector
		Ptr<FastFeatureDetector> detector = FastFeatureDetector::create();
		std::vector<KeyPoint> keypoints_1;
		detector->detect(frame, keypoints_1);
		
		//-- Draw keypoints
		Mat img_keypoints_1; Mat img_keypoints_2;
		drawKeypoints(frame, keypoints_1, img_keypoints_1, Scalar::all(-1),
			DrawMatchesFlags::DEFAULT);
		
		//-- Show detected (drawn) keypoints
		imshow("Keypoints 1", img_keypoints_1);
		imshow("Frame", frame);
        char c = (char)waitKey(25);
        if (c == 27)
            break;
    }
    cap.release();
    destroyAllWindows();
    return 0;
}
