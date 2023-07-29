/*
 * @Author DaiCC
 * @brief EObject
 * @file EObject.cpp
 * @date 2023/7/29
 * @version deb0.0.1
 */

#include "EObject.h"


namespace Engine {
    EObject::EObject(Engine::EObject *parent) {

    }

    bool EObject::connect(EObject *sender, void (*receive)(), Engine::Event signal) {
        // 检测数据合法
        if (sender == nullptr || receive == nullptr) return false;
        // TODO: 链接信号
        return true;
    }

    EObject::~EObject() = default;
}