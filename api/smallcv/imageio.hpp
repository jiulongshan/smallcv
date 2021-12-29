/*
 * @Author: your name
 * @Date: 2021-12-24 15:47:34
 * @LastEditTime: 2021-12-29 15:06:39
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /smallcv1/api/smallcv/imageio.hpp
 */
#pragma once

#include "smallcv/mat.hpp"

namespace scv {

    Mat imread(const char* image_path);
    Mat imread(const std::string& image_path);
    void imwrite(const char* filename, const scv::Mat& image);
    void imwrite(const std::string& save_path, const scv::Mat& image);

} // scv
