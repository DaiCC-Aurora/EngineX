/*
 * @Author DaiCC
 * @brief Test timer
 * @file Exam_Timer.cpp
 * @date 2023/8/1
 * @version rel0.0.1
 */

#include <ETime.h>
#include <iostream>
#include <chrono>
using namespace Engine;

void foo(int a) {
    std::cout << "Called foo, a = " << a << std::endl;
}

int main() {
    auto t1 = new ETimer();
    t1->set_func(foo, 10);
    t1->start();

    auto t2 = new ETimer(500);
    t2->set_func(foo, 20);
    t2->start(500);

    auto t3 = new ETimer(1000, foo, 521);
    t3->start();

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    t1->stop(); // stop

    std::getchar();
    return 0;
}