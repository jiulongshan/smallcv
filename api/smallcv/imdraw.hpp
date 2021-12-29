/*
 * @Author: your name
 * @Date: 2021-12-24 15:47:34
 * @LastEditTime: 2021-12-29 15:00:59
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /smallcv1/api/smallcv/imdraw.hpp
 */
#pragma once

#include "smallcv/mat.hpp"

namespace scv {

    void line(Mat& image, Point pt1, Point pt2, const Scalar& color, int thickness = 1);
    void line(Mat& image, Point2f pt1, Point2f pt2, const Scalar& color, int thickness = 1);

    void circle(Mat& image, Point center, int radius, const Scalar& color, int thickness = 1);
    void circle(Mat& image, Point2f center, int radius, const Scalar& color, int thickness = 1);

    void rectangle(Mat& im, const Rect& rect, const Scalar& color, int thickness=1);

}

