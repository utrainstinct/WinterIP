#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img=imread("./lenna.jpg",1);

void Callback(int t,void* s)
{
  int i,j;
  Mat cpy = img.clone();
  for(i=0;i<img.rows;i++)
      {
	for(j=0;j<img.cols;j++)
	  {
	    if(img.at<Vec3b>(i,j)[2]<t)
	      cpy.at<Vec3b>(i,j)=(0,0,0);
	    else if(img.at<Vec3b>(i,j)[2]>t)
	      cpy.at<Vec3b>(i,j)=(255,255,255);
	    
	  }
	
      }
  imshow("lenna", cpy);
   
}

int main()
{

    namedWindow("lenna", WINDOW_NORMAL);
    int g=127;
    Mat img2 = imread("./lenna.jpg", 1);
    createTrackbar("C","lenna",&g,255,Callback,NULL);
    waitKey(0);
    return 0;
}
