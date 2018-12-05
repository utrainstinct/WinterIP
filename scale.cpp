#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;






  int main()
  {
    Mat img=imread("./lenna.jpg",1);
    Mat img2(img.rows*3,img.cols*3,CV_8UC3,Scalar(0,0,0));
    namedWindow("lenna",WINDOW_AUTOSIZE);
    int i,j;
    for (i = 0; i < img.rows; ++i)
    {
      for (j = 0; j < img.cols; ++j)
      {
        img2.at<Vec3b>()
      }
    }
    waitKey(0);
    return 0;

  }
