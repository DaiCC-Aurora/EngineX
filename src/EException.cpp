/*
 * @Author DaiCC
 * @brief Exception Class
 * @file EException.cpp
 * @date 2023/7/29
 * @version deb0.0.1
 */

#include "EException.h"

namespace Engine {
    EException::EException(const char *err_string) noexcept {
        this->err_msg = err_string;
    }
    EException::~EException() noexcept = default;

    const char *EException::what() noexcept {
        return (this->err_msg == nullptr) ? "No Data" : this->err_msg;
    }
}
