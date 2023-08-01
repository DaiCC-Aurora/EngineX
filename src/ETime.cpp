/*
 * @Author DaiCC
 * @brief
 * @file
 * @date
 * @version
 */

#include "ETime.h"

namespace Engine {
    ETimer::ETimer() : m_ms(100), m_activate(false), m_func() {}
    ETimer::ETimer(int ms) : m_ms(ms), m_activate(false), m_func() {}

    ETimer::~ETimer() = default;

    void ETimer::start(int ms) {
        m_ms = ms;
        m_activate = true;
        // check data
        if (m_ms == 0) {
            throw EException("Data Except...");
        }
        m_thread = std::thread([&]() {
            while (m_activate) {
                m_func();
                std::this_thread::sleep_for(std::chrono::milliseconds(m_ms));
            }
        });
    }

    void ETimer::start() {
        m_activate = true;
        // check data
        if (m_ms == 0) {
            throw EException("Data Except...");
        }
        m_thread = std::thread([&]() {
            while (m_activate) {
                m_func();
                std::this_thread::sleep_for(std::chrono::milliseconds(m_ms));
            }
        });
        m_thread.detach();
    }

    void ETimer::stop() {
        m_activate = false;
    }

    void ETimer::set_ms(int ms) {
        m_ms = ms;
    }
}