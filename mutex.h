/*条件变量需要互斥锁，缓冲区也要用到互斥锁*/

#pragma once
#include<pthread.h>
class mutex
{
public:
    mutex();
    ~mutex();
    void lock();
    void trylock();
    void unlock();
    pthread_mutex_t* get_mutex();//获取互斥锁，因为它是私有成员，在类外是不能访问的，所以需要一个公有成员函数当作中介
private:
    pthread_mutex_t mut;
};

