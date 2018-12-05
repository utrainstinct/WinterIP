#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;


 



  int main()
  {
    namedWindow("rotation",WINDOW_NORMAL);
    Mat img = imread("./lenna.jpg",1);
    int g =0;
    int p=img.rows/2,q=img.cols/2;

    float r=(g*3.14)/180;
    Mat img2(img.rows*2,img.cols*2,CV_8UC3,Scalar(0,0,0));
    int i,j,k,l,a,s;
    for (i = 0; i < img.rows; ++i)
    {
      for (j = 0; j < img.cols; ++j)
      {
        k=j-q;
        l=p-i;
        a=k*cos(3.14/4)-l*sin(3.14/4);
        s=k*sin(3.14/4)+l*cos(3.14/4);
        img2.at<Vec3b>(a+q,p-k)=img.at<Vec3b>(i,j);
      }
    }
    imshow("rotation",img2);
    waitKey(0);
    return 0;

  }