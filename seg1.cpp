#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("./lenna.jpg",1);
int blue=128,green=128,red=128;

void callback1(int t, void* s)
    {
  int i,j;
  Mat cpy=img.clone();
  for(i=0;i<img.rows;i++)
    {
    for(j=0;j<img.cols;j++)
      {
    if(img.at<Vec3b>(i,j)[0]>blue)
    cpy.at<Vec3b>(i,j)[0]=255;
    else
    cpy.at<Vec3b>(i,j)={0,0,0};
    if(img.at<Vec3b>(i,j)[1]>green)
    cpy.at<Vec3b>(i,j)[1]=255;
    else
    cpy.at<Vec3b>(i,j)={0,0,0};
    if(img.at<Vec3b>(i,j)[2]>red)
    cpy.at<Vec3b>(i,j)[2]=255;
    else 
    cpy.at<Vec3b>(i,j)={0,0,0};
    }
    }
    imshow("lenna",cpy);
 
}



  int main(){
    namedWindow("lenna",WINDOW_NORMAL);
    createTrackbar("Blue","lenna",&blue,255,callback1,NULL);
    createTrackbar("Green","lenna",&green,255,callback1,NULL);
    createTrackbar("Red","lenna",&red,255,callback1,NULL);
    waitKey(0);
    return 0;

  }