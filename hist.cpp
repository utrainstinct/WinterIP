#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;



int main()
  {
  Mat img = imread("./lowcontrast.PNG",0);
  namedWindow("hist",WINDOW_NORMAL);
  int a[256];
  int i,j,d;
  for(int k=0;k<256;k++)
  {
    a[k]=0;
  }
    for ( i =0; i<img.rows ; i++)
    {
      for(int j=0;j<img.cols;j++)
      {
        a[img.at<uchar>(i,j)]++;
      }
    }

  int m=a[0];
  for(i=0;i<256;i++)
  {
    if(m<=a[i])
      m=a[i];
  }
  Mat img2(m,256,CV_8UC1,Scalar(0));

  for(i=0;i<256;i++)
  {
    for(j=0;j<=a[i];j++)
    {
      img2.at<uchar>(m-j,i)=255;
    }
  }
  imshow("hist",img2);

    
    waitKey(0);
    return 0;

  }