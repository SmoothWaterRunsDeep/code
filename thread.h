#pragma once
#include"buffer.h"
class thread
{
public:
    thread(buffer&buf);
    ~thread();
void start();//创建线程并执行入口函数
void stop();//阻塞主线程，等待对应的子线程结束


private:
static void*threadfunction(void*);//线程的入口函数
virtual void run()=0;//将不同线所要做的事记为run方法，留给派生类实现

private:
pthread_t thid;
bool isRunning;

protected:
buffer&_buf;
};

