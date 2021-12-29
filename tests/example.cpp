/*
 * @Author: your name
 * @Date: 2021-12-23 16:22:34
 * @LastEditTime: 2021-12-24 15:37:48
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /smallcv/tests/example.cpp
 */

#if defined(_MSC_VER) && defined(VLD) // for memory leak detection
#include <vld.h>
#endif

#include <string>
#include <memory>
#include <iostream>
#include <string.h>
#include "smallcv.hpp"

using namespace std;

int main() {
    {
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
        memcpy(tmp, "123412341234", 12);
        cout<<"cptr: "<<&cptr<<endl;
        cout<<"cptr: "<<cptr<<endl;
        cout<<"cshptr.ptr: "<<cshptr.get()<<endl;
        cout<<"--------> "<<cshptr.use_count()<<endl;
        cout<<"tmp: "<<tmp<<endl;
        cout<<"tmp2: "<<tmp2<<endl;
    
        std::string image_path = "mingren.jpg";
        //std::string image_path = "E:/projects/arccv/smallcv/build/vs2019-x64/mingren.jpg";
        cv::Mat image = cv::imread(image_path);
        cv::Rect rect(100, 100, 233, 233);
        printf("image: %dx%dx%d\n", image.cols, image.rows, image.channels());
        // cv::Mat crop(image, cv::Rect(100, 100, 233, 234));
        // cv::Mat crop = image(cv::Rect(100, 100, 233,233)).clone();
        cv::rectangle(image, rect, cv::Scalar(0,0,255), 2);
        // cv::imshow("mingren", image);
        // cv::waitKey(0);
        cv::imwrite("mingren-copy.png", image);
        // cv::imwrite("mingren-crop.png", crop);
    }

#ifdef VLD
    VLDReportLeaks();
#endif

    return 0;
}
