/*
 * @Author: your name
 * @Date: 2021-12-24 15:47:34
 * @LastEditTime: 2021-12-29 15:00:40
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /smallcv1/api/smallcv/imshow.hpp
 */
#pragma once

#include "smallcv/mat.hpp"

namespace scv {

void imshow(const char* winname, const Mat& im);

void waitKey(int milli_secs);

} // namespace scv


