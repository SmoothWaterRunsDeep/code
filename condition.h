#pragma once
#include<stdio.h>
#include"mutex.h"
class condition
{
public:
    condition(mutex&mut);

    ~condition();//负责销毁条件变量
    
    void wait();    //让当前线程阻塞

    void wakeup();//唤醒进程
private:
mutex &_mut;
pthread_cond_t _cond;
};

