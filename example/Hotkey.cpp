#include <EKeyboard.h>
#include <iostream>
#include <windows.h>

using namespace Engine;
using namespace std;

void func(int x) {
    cout << "x + y = " << x << endl;
}

int main() {
    try {
        EHotkey e(func, 2);
        e.set_hotkey(1, MOD_NOREPEAT | MOD_CONTROL, 0x43);
        e.run_hotkey();
    } catch (std::exception &e) {
        cout << e.what() << endl;
    }
    getchar();
    return 0;
}