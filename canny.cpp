#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("./sga.png",1);
void callback1(int t, void* s)
{
  Mat cpy=img.clone();
  Canny(img,cpy,t,3*t,3);
  imshow("lenna",cpy);
 
}



  int main()
  {
  	int g=15;
    namedWindow("lenna",WINDOW_NORMAL);
 	createTrackbar("A","lenna",&g,200,callback1,NULL); 
    waitKey(0);
    return 0;

  }

