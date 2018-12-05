#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("./lenna.jpg",1);

void callback1(int t, void* s)
{
     Mat cpy=img.clone();
     int k=img.rows/2;
     int l=img.cols/2;
     int i,j;
     for(i=0;i<img.rows;i++)
     {
      for(j=0;j<img.cols;j++)
      {
        int d=sqrt((k-i)*(k-i)+(l-j)*(l-j));
        if(d>t)
        {
          cpy.at<Vec3b>(i,j)={0,0,0};
        }
        else
        {
          cpy.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0]*(t-d)/(t);
          cpy.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1]*(t-d)/(t);
          cpy.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2]*(t-d)/(t);
        }
      }
     }
     imshow("lenna",cpy);
 
  }


int main()
  {
    int g=25;
    namedWindow("lenna",WINDOW_NORMAL);
    createTrackbar("Red","lenna",&g,img.cols,callback1,NULL);
    waitKey(0);
    return 0;

  }

