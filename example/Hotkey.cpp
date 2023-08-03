#include <iostream>
#include <Windows.h>
#include <thread>

using namespace std;

// 全局标志，用于控制循环打印"Helloworld"的线程是否运行
bool isPrinting = true;

// 函数原型
void HotkeyThread();
void PrintThread();

int main() {
    // 创建热键检测线程
    thread hotkeyThread(HotkeyThread);

    // 创建循环打印线程
    thread printThread(PrintThread);

    // 主线程等待热键线程和打印线程执行完毕
    hotkeyThread.join();
    printThread.join();

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

            // 设置标志为false，终止打印线程
            isPrinting = false;
        }
    }

    // 注销热键
    UnregisterHotKey(NULL, 1);
}

void PrintThread() {
    while (isPrinting) {
        cout << "Helloworld" << endl;
        this_thread::sleep_for(chrono::seconds(1)); // 休眠1秒
    }
}
