#include <EKeyboard.h>
#include <windows.h>
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;
using namespace Engine;

bool mthread_print = true;

void foo_hotkey(int x, int y) {
    mthread_print = false;
    cout << "called foo_hotkey,\tx = " << x << "\t" << "y = " << y << endl;
}

int main() {
    vector<int> keys = {VK_CONTROL, VK_F1};
    EHotkey hk(keys, foo_hotkey, 1, 2);
    hk.start();

    while (mthread_print) {
        cout << "main thread is running" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}