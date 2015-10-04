#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <windows.h>

using namespace std;
using namespace cv;
void main(){
cout << "OpenCV detectada " << endl;
Mat im;
im = imread("lena.jpg",1);
cout << "Imagen detectada " << endl;

namedWindow("ventana",1);
waitKey(1000);

cout << "Ventana creada " << endl;
imshow("ventana",im);

waitKey(0);
cout << "imagen mostrada " << endl;
destroyWindow("ventana");

}