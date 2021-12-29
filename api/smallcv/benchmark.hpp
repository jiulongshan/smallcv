/*
 * @Author: your name
 * @Date: 2021-12-24 15:47:34
 * @LastEditTime: 2021-12-29 15:01:10
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /smallcv1/api/smallcv/benchmark.hpp
 */
#pragma once

namespace scv {

    /// @brief get now timestamp in ms（毫秒）
    double get_current_time();

    /// @brief sleep for specified milliseconds (10^-3 second)
    /// 等待指定的毫秒数
    void sleep(int milli_secs);
}
