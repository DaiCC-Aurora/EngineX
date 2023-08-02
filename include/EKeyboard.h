#ifndef EKeyboard_
#define EKeyboard_

#include <thread>
#include <functional>
#include <windows.h>
#include <EException.h>
#include <EObject.h>

namespace Engine {
    /*
     * @class EHotkey
     * @brief Hotkey Class
     */
    class EHotkey : EObject {
    public:
        EHotkey();
        EHotkey(int id, UINT fsModifiers, UINT vk);
        template <typename F, typename... Args> explicit EHotkey(F func, Args &&... args);
        template <typename F, typename... Args> explicit EHotkey(int id, UINT fsModifiers, UINT vk, F func, Args &&... args);

        void set_hotkey(int id, UINT fsModifiers, UINT vk);
        template <typename F, typename... Args> void set_func(F func, Args &&... args);

        void run_hotkey();

        ~EHotkey() override;
    private:
        int m_id;
        UINT m_fsModifiers, m_vk;
        std::function<void()> m_func;
        std::thread m_thread;
    };

    // ---------- EHotkey TEMPLATE ----------
    template <typename F, typename... Args> EHotkey::EHotkey(F func, Args &&... args) :
    m_func(std::bind(std::forward<F>(func), std::forward<Args>(args)...)),
    m_id(0),
    m_fsModifiers(),
    m_vk() {}

    template <typename F, typename... Args> EHotkey::EHotkey(int id, UINT fsModifiers, UINT vk, F func, Args &&... args) :
    m_id(id),
    m_fsModifiers(fsModifiers),
    m_vk(vk),
    m_func(std::bind(std::forward<F>(func), std::forward<Args>(args)...)) {}

    template <typename F, typename... Args> void EHotkey::set_func(F func, Args &&... args) {
        m_func = std::bind(std::forward<F>(func), std::forward<Args>(args)...);
    }
}

#endif