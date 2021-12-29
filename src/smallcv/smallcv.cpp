#include "smallcv/smallcv.hpp"


#include <assert.h>
#include <cmath>
#include <limits>
#include <iostream>
#include <string.h>

namespace scv {

Mat::Mat()
    : rows(0), cols(0), channels_(0), data_type_(kEmpty), data(NULL)
{

}

Mat::Mat(int _rows, int _cols, int type)
    : rows(_rows), cols(_cols)
{
    data_type_ = static_cast<Mat::DataType>(type / 10);
    channels_ = type % 10;

    size_t buf_size = rows * cols * channels_;
    data_.reset(new uchar[buf_size], [](uchar* p) {
        delete[] p;
    });
    
    data = data_.get();
}

Mat::Mat(int _rows, int _cols, int type, void* _data)
    : rows(_rows), cols(_cols)
{
    data_type_ = static_cast<Mat::DataType>(type / 10);
    channels_ = type % 10;

    data_.reset((uchar*)_data, [](uchar* p) { });
    data = data_.get();
}

Mat::Mat(Size size, int type)
    : rows(size.height), cols(size.width)
{
    data_type_ = static_cast<Mat::DataType>(type / 10);
    channels_ = type % 10;

    size_t buf_size = rows * cols * channels_;
    data_.reset(new uchar[buf_size], [](uchar* p) {
        delete[] p;
    });
    data = data_.get();
}

Mat::Mat(Size size, int type, void* _data)
    : rows(size.height), cols(size.width)
{
    data_type_ = static_cast<Mat::DataType>(type / 10);
    channels_ = type % 10;

    data_.reset((uchar*)_data, [](uchar* p) { });
    data = data_.get();
}

Mat::Mat(const Mat& m, const Rect& roi)
    :data_type_(m.data_type_), channels_(m.channels_)
{
    rows = roi.height;    
    cols = roi.width;
    if(roi.x + roi.width > m.cols){
        cols = m.cols - roi.x;
    }
    if(roi.y + roi.height > m.rows){
        rows = m.rows - roi.y;
    }

    size_t buf_size = rows * cols * channels_;
    data_.reset(new uchar[buf_size], [](uchar* p) {
        delete[] p;
    });
    data = data_.get();
    printf("%dx%dx%d\n", cols, rows, channels_);
    printf("src: %dx%dx%d\n", m.cols, m.rows, m.channels_);
    printf("data：%p\n", &data);
    std::cout<<"data is "<<&data<<std::endl;
    std::cout<<"m.data is "<<&m.data<<std::endl;
    std::cout<<"m.channels_ is "<<m.channels_<<std::endl;
    printf("roi.y %d, rows: %d\n", roi.y, rows);

    int j=0;
    
    for(int i=roi.y; i<roi.y+rows; i++){
        memcpy(data + j*cols*m.channels_, m.data + i*m.cols*m.channels_ + roi.x*m.channels_, cols*m.channels_*sizeof(uchar));
        // data += cols*m.channels_;
        j++;
    }
}


Mat::Mat(const Mat& mat)
    : rows(mat.rows), cols(mat.cols), data_type_(mat.data_type_), channels_(mat.channels_), data_(mat.data_), data(mat.data)
{

}

Mat& Mat::operator=(const Mat& mat)
{
    if (this!=&mat) {
        data_ = mat.data_;
        data = mat.data;
        rows = mat.rows;
        cols = mat.cols;
        data_type_ = mat.data_type_;
        channels_ = mat.channels_;
    }
    return *this;
}

Mat::~Mat()
{

}

int Mat::channels() const
{
    return channels_;
}

bool Mat::empty() const
{
    if (rows == 0 || cols == 0) {
        return true;
    }
    return false;
}

    void cvtColor(Mat src, Mat dst, int flag)
    {
        if (flag==COLOR_BGR2RGB && src.data==dst.data) {
            Mat& image = src;
            size_t h = image.rows;
            size_t w = image.cols;
            size_t c = image.channels();
            assert(c == 3);
            uchar* data = image.data;
            for (size_t i = 0; i < h; i++) {
                for (size_t j = 0; j < w; j++) {
                    size_t idx = i * w * 3 + j * 3;
                    unsigned char t = data[idx];
                    data[idx] = data[idx + 2];
                    data[idx + 2] = t;
                }
            }
        } else {
            fprintf(stderr, "! error: not supported yet\n");
            exit(1);
        }
    }
    /*
    void rgba2rgb(Mat& src, Mat& dst)
    {
        Mat& image = src;
        size_t h = image.rows;
        size_t w = image.cols;
        size_t c = image.channels();
        assert(c == 4);
        uchar* data = dst.data;
        for (size_t i = 0; i < h; i++) {
            for (size_t j = 0; j < w; j++) {
                size_t rgba_idx = i * w * c + j * c;
                size_t rgb_idx = i * w * 3 + j * 3;
                for(size_t k=0;k<3;k++){
                    data[rgb_idx] = data[rgba_idx];
                }
            }
        }
    }
    */
}

