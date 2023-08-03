#include <iostream>
#include <Windows.h>
#include <thread>

using namespace std;

// 函数原型
void HotkeyThread();

int main() {
    // 创建热键检测线程
    thread hotkeyThread(HotkeyThread);

    // 主线程循环打印"Helloworld"
    while (true) {
        cout << "Helloworld" << endl;
        this_thread::sleep_for(chrono::seconds(1)); // 休眠1秒

        // 可以在此处添加其他主线程需要处理的任务
    }

    // 等待热键线程执行完毕
    hotkeyThread.join();

    return 0;
}

void HotkeyThread() {
    // 注册热键，使用Ctrl + Alt + H作为热键
    if (!RegisterHotKey(NULL, 1, MOD_CONTROL | MOD_ALT, 'H')) {
        cout << "注册热键失败！" << endl;
        return;
    }

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) != 0) {
        if (msg.message == WM_HOTKEY) {
            cout << "热键被触发！" << endl;

            // 可以在此处添加热键触发后需要处理的任务
            // ...

            // 热键触发后退出主循环，结束程序
            break;
        }
    }

    // 注销热键
    UnregisterHotKey(NULL, 1);
}
