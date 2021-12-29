/*
 * @Author: your name
 * @Date: 2021-12-24 15:47:34
 * @LastEditTime: 2021-12-29 15:07:23
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /smallcv1/api/smallcv/border.hpp
 */
#pragma once

#include "smallcv/mat.hpp"
#include <vector>

namespace scv
{
    void findContours(scv::Mat image, std::vector<std::vector<scv::Point>>& contours,
        int mode, int method, scv::Point offset=scv::Point());

    scv::Rect maskBoundingRect(const scv::Mat& image);
}
