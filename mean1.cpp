#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

    namedWindow("lenna", WINDOW_NORMAL);

    Mat img = imread("./lenna.jpg", 1);
    Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0,0,0));
    int i,j,k;
    for(i=0;i<img.rows;i++)
      {
	for(j=0;j<img.cols;j++)
	  {
	    img2.at<uchar>(i,j)=(int)(0.07*img.at<Vec3b>(i,j)[0])+(0.72*img.at<Vec3b>(i,j)[1])+(0.21*img.at<Vec3b>(i,j)[2]);
	  }
      }
    imshow("lenna", img2);
    waitKey(0);
    return 0;
}
