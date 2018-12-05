#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;



int main()
{
  namedWindow("hist",WINDOW_NORMAL);
  Mat img = imread("./veg.jpg",0);
  Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
  int i,j,k,l,z=0;
  int a[9];
  for(i=1;i<img.rows-1;i++)
  {
    for (j= 1;j<img.cols-1;j++)
    {
      z=0;
      for (k = -1;k<=1;k++)
      {
        for (l =-1;l<=+1;l++)
        {

          a[z++]=img.at<uchar>(i+k,j+l);

        }
      }

      sort(a,a+9);
      img2.at<uchar>(i,j)=a[4];
    }
  }
  imshow("hist",img2);

    
    waitKey(0);
    return 0;
}