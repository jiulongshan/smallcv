/*
 * @Author: your name
 * @Date: 2021-12-24 15:47:34
 * @LastEditTime: 2021-12-29 15:01:16
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /smallcv1/api/smallcv/resize.hpp
 */
#pragma once

#include "smallcv/mat.hpp"

namespace scv
{
    enum class Interpolation
    {
        NEAREST = 0,
        LINEAR = 1,
        AREA = 2,
        CUBIC = 3
    };

    void resize(Mat src, Mat dst, Size dsize, double fx = 0, double fy = 0, Interpolation method = Interpolation::LINEAR);

} // namespace scv