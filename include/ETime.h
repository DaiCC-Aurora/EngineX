#ifndef ETime_
#define ETime_
#include <EException.h>
#include <thread>
#include <functional>
#include <thread>
#include <chrono>

namespace Engine {
    /*
     * @class ETimer
     * @brief Timer Class
     */
    class ETimer {
    public:
        /*
         * default = 100ms
         */
        ETimer();
        explicit ETimer(int ms);
        template<typename F, typename... Args>
        explicit ETimer(int ms, F func, Args &&... args);

        ~ETimer();

        template<typename F, typename... Args>
        void set_func(F func, Args &&... args);
        void set_ms(int ms);
        void start(int ms);
        void start();
        void stop();

    protected:
        int m_ms;
        bool m_activate;
        std::function<void()> m_func;
        std::thread m_thread;
    };

    template<typename F, typename... Args>
    ETimer::ETimer(int ms, F func, Args &&... args) :
            m_ms(ms),
            m_activate(false),
            m_func(std::bind(std::forward<F>(func), std::forward<Args>(args)...)) {}

    template<typename F, typename... Args>
    void ETimer::set_func(F func, Args &&... args) {
        m_func = std::bind(std::forward<F>(func), std::forward<Args>(args)...);
    }
}
#endif