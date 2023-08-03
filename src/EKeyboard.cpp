/*
 * @Author DaiCC
 * @brief
 * @file
 * @date
 * @version
 */

#include "EKeyboard.h"

namespace Engine {
    EHotkey::EHotkey() : m_id(), m_fsModifiers(), m_vk(), m_func(), m_thread() {}

    EHotkey::EHotkey(int id, UINT fsModifiers, UINT vk) :
    m_id(id),
    m_fsModifiers(fsModifiers),
    m_vk(vk) {}

    void EHotkey::set_hotkey(int id, UINT fsModifiers, UINT vk) {
        m_id = id;
        m_fsModifiers = fsModifiers;
        m_vk = vk;
    }

    void EHotkey::run_hotkey() {
        // RegisterHotkey
        if (!RegisterHotKey(nullptr, m_id, m_fsModifiers, m_vk)) {
            throw EException("Register Hotkey Error");
        }

        MSG msg = {nullptr};
        m_thread = std::thread([&]() -> void {
            while (GetMessage(&msg, nullptr, 0, 0) != 0) {
                if (msg.message == WM_HOTKEY && msg.wParam == m_vk) {
                    m_func();
                }
            }
        });
        m_thread.join();
    }

    EHotkey::~EHotkey() {
        UnregisterHotKey(GetConsoleWindow(), m_id);
    }
}