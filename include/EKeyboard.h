#ifndef EKeyboard_
#define EKeyboard_

#include <thread>
#include <utility>
#include <vector>
#include <functional>
#include <windows.h>
#include <EException.h>
#include <EObject.h>

#include <iostream>

namespace Engine {
    /*
     * @class EHotkey
     * @brief Hotkey Class
     */
    class EHotkey : EObject {
    public:
        EHotkey();
        explicit EHotkey(std::vector<int> keys);
        template <typename F, typename... Args> explicit EHotkey(F && func, Args &&... args);
        template <typename F, typename... Args> explicit EHotkey(std::vector<int> keys, F && func, Args &&... args);

        void set_keys(std::vector<int> keys);
        template <typename F, typename... Args> void set_func(F && func, Args &&... args);
        void start();

    private:
        std::thread m_thread;
        std::function<void()> m_func;
        std::vector<int> m_keys;
    };

    // ---------- EHotkey TEMPLATE ----------
    template <typename F, typename... Args> EHotkey::EHotkey(F && func, Args &&... args) :
    m_func(std::bind(std::forward<F>(func), std::forward<Args>(args)...)),
    m_thread(),
    m_keys() {}

    template <typename F, typename... Args> EHotkey::EHotkey(std::vector<int> keys, F && func, Args &&... args) :
    m_func(std::bind(std::forward<F>(func), std::forward<Args>(args)...)),
    m_keys(std::move(keys)),
    m_thread() {}

    template <typename F, typename... Args> void EHotkey::set_func(F && func, Args &&... args) {
        m_func = std::bind(std::forward<F>(func), std::forward<Args>(args)...);
    }
}

#endif