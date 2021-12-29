/*
 * @Author: your name
 * @Date: 2021-12-24 15:47:34
 * @LastEditTime: 2021-12-29 15:08:02
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /smallcv1/examples/example.cpp
 */

#if defined(_MSC_VER) && defined(VLD) // for memory leak detection
#include <vld.h>
#endif

#include <string>
#include <memory>
#include <iostream>
#include <string.h>
#include "smallcv/smallcv.hpp"

using namespace std;

int main() {
    {
        /*
        shared_ptr<char> cshptr = make_shared<char>();
        // char* cptr = cshptr.get();
        cshptr.reset(new char[1024]);
        char* cptr = cshptr.get();
        cout<<"cshptr: "<<&cshptr<<endl;
        cout<<"cptr: "<<&cptr<<endl;
        cout<<"cptr: "<<*cptr<<endl;
        char* tmp = cshptr.get();
        char* tmp2 = cshptr.get();
        cout<<"cshptr.ptr tmp: "<<&tmp<<endl;
        cout<<"cshptr.ptr tmp2: "<<&tmp2<<endl;
        memcpy(tmp, "0123456789abcdefghijklmnopqrstuvwxyz", 30);
        cout<<"cptr: "<<&cptr<<endl;
        cout<<"cptr: "<<cptr<<endl;
        cout<<"cshptr.ptr: "<<cshptr.get()<<endl;
        cout<<"--------> "<<cshptr.use_count()<<endl;
        cout<<"tmp: "<<tmp<<endl;
        cout<<"tmp2: "<<tmp2<<endl;   
        char test[1024] = {0}; 

        memcpy(test, cshptr.get() + 5, 5*sizeof(uchar));
        cout<<"test: "<<test<<endl;
        */

        std::string image_path = "mingren.jpg";
        //std::string image_path = "E:/projects/arccv/smallcv/build/vs2019-x64/mingren.jpg";
        scv::Mat image = scv::imread(image_path);
        printf("image: %dx%dx%d\n", image.cols, image.rows, image.channels());
        scv::Rect rect(100, 100, 233, 233);
        scv::rectangle(image, rect, scv::Scalar(0,0,255), 2);
        scv::imwrite("mingren-copy.jpg", image);

        scv::Mat crop(image, scv::Rect(100, 100, 233, 1000));
        scv::imwrite("mingren-crop.jpg", crop);
        printf("crop: %dx%dx%d\n", crop.cols, crop.rows, crop.channels());
        // cv::imshow("mingren", image);
        // cv::waitKey(0);

        scv::Mat bgr;
        scv::cvtColor(image, image, 1);
        scv::imwrite("mingren-rgb.jpg", image);
        scv::cvtColor(image, image, 1);
        scv::imwrite("mingren-bgr.jpg", image);
        cout<<"-------------------------> "<<endl;

        // std::string rgba_path = "snap.rgba";
        // cv::Mat rgba = cv::imread(rgba_path);
        // printf("rgba: %dx%dx%d\n", rgba.cols, rgba.rows, rgba.channels());
        // cv::Mat rgb;
        // rgba2rgb(rgba, rgb);
        // printf("rgb: %dx%dx%d\n", rgb.cols, rgb.rows, rgb.channels());
    }

#ifdef VLD
    VLDReportLeaks();
#endif

    return 0;
}
