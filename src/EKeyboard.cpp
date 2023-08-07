/*
 * @Author DaiCC
 * @brief
 * @file
 * @date
 * @version
 */

#include "EKeyboard.h"

namespace Engine {
    EHotkey::EHotkey() : m_keys(), m_thread(), m_func() {}
    EHotkey::EHotkey(std::vector<int> keys) :
    m_keys(std::move(keys)),
    m_thread(),
    m_func() {}

    void EHotkey::set_keys(std::vector<int> keys) {
        m_keys = std::move(keys);
    }

    void EHotkey::start() {
        switch (m_keys.size()) {
            case 1: {
                m_thread = std::thread([&]() -> void {
                    while (GetAsyncKeyState(m_keys[0]) & 0x8000) {
                        m_func();
                    }
                    m_thread.detach();
                });
                m_thread.join();
                break;
            }
            case 2: {
                m_thread = std::thread([&]() -> void {
                    while (
                            GetAsyncKeyState(m_keys[0]) & 0x8000 &&
                            GetAsyncKeyState(m_keys[1]) & 0x8000
                            ) {
                        m_func();
                    }
                });
                m_thread.join();
                break;
            }
            case 3: {
                m_thread = std::thread([&]() -> void {
                    while (
                            GetAsyncKeyState(m_keys[0]) & 0x8000 &&
                            GetAsyncKeyState(m_keys[1]) & 0x8000 &&
                            GetAsyncKeyState(m_keys[2]) & 0x8000
                            ) {
                        m_func();
                    }
                });
                m_thread.join();
                break;
            }

            default: throw EException("Except keys");
        }
    }
}