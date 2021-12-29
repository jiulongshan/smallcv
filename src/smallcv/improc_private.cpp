/*
 * @Author: your name
 * @Date: 2021-12-24 15:47:34
 * @LastEditTime: 2021-12-29 15:01:50
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /smallcv1/src/smallcv/improc_private.cpp
 */
#include "smallcv/mat.hpp"
#include "smallcv/improc_private.hpp"
#include <assert.h>
#include <string.h>

namespace scv {

    void image_upside_down(const Mat& im, Mat& im_upsd)
    {
        int height = im.rows;
        int width = im.cols;
        int channels = im.channels();
        assert(channels == 3);
        int linebytes = im_upsd.cols * channels;

        unsigned char* dst = im_upsd.data + linebytes*(height-1);
        unsigned char* src = im.data;
        unsigned char* outbuf = im_upsd.data;

        unsigned char* input = im.data;

        for (int h = 0; h < height; h++) {
            for (int wc = 0; wc < width*channels; wc++) {
                size_t src_idx = h*linebytes + wc;
                size_t dst_idx = (height-1-h)*linebytes + wc;
                outbuf[dst_idx] = input[src_idx];
            }
            memcpy(dst, src, linebytes);
            dst -= linebytes;
            src += linebytes;
        }
    }

}
