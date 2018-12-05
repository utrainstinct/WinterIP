#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("./rubik.jpg",0);

void callback1(int t, void* s)
{
  int i,j,k,l,z,x;
  int gx,gy,o;
  Mat cpy=img.clone();
  int a[9]={-1,0,1,-1,0,1,-1,0,1};
  int b[9]={-1,-1,-1,0,0,0,1,1,1};
  for(i=1;i<img.rows-1;i++)
  {
    for(j=1;j<img.cols-1;j++)
    {
      z=0,x=0;
      gx=0,gy=0;
      for(k=-1;k<=1;k++)
      {
        for(l=-1;l<=1;l++)
        {
          gx=gx+a[x++]*img.at<uchar>(k+i,l+j);
          gy=gy+b[z++]*img.at<uchar>(k+i,l+j);
        }
      }
      o=sqrt(gx*gx+gy*gy)/6;
      if(o<t)
        cpy.at<uchar>(i,j)=0;
    }
  }
  
  imshow("lenna",cpy);
 
}



  int main()
  {
    int g=12;
    namedWindow("lenna",WINDOW_NORMAL);
    createTrackbar("Blue","lenna",&g,200,callback1,NULL);
    waitKey(0);
    return 0;

  }

