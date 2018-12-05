#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("./lenna.jpg",1);

void callback1(int t, void* s)
    {
  int i,j;
  Mat cpy=img.clone();
  for(i=0;i<img.rows;i++)
    {
    for(j=0;j<img.cols;j++)
      {
	if(img.at<Vec3b>(i,j)[0]>t)
	  cpy.at<Vec3b>(i,j)[0]=255;
	else if(img.at<Vec3b>(i,j)[0]<=t)
	  cpy.at<Vec3b>(i,j)[0]=0;
	if(img.at<Vec3b>(i,j)[1]>t)
	  cpy.at<Vec3b>(i,j)[1]=255;
	else  if(img.at<Vec3b>(i,j)[1]<=t)
	  cpy.at<Vec3b>(i,j)[1]=0;
	if(img.at<Vec3b>(i,j)[2]>t)
	  cpy.at<Vec3b>(i,j)[2]=255;
	else   if(img.at<Vec3b>(i,j)[2]<=t)
	  cpy.at<Vec3b>(i,j)[2]=0;
      }
    }
    imshow("lenna",cpy);
 
}



  int main()
  {
    int g=128;
    namedWindow("lenna",WINDOW_NORMAL);
    createTrackbar("Blue","lenna",&g,255,callback1,NULL);
    createTrackbar("Green","lenna",&g,255,callback1,NULL);
    createTrackbar("Red","lenna",&g,255,callback1,NULL);
    waitKey(0);
    return 0;

  }

