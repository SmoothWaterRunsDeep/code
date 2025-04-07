#include"condition.h"
condition::condition(mutex&mut)
    :_mut(mut)//对锁进行初始化
{
    int ret=pthread_cond_init(&_cond,nullptr);
    if(ret)
        perror("pthread_cond_init error!");
}

condition:: ~condition() {
    int ret=pthread_cond_destroy(&_cond);   //销毁条件变量
    if(ret)
        perror("pthread_cond_destroy error!");
}

void condition::wait(){    //让当前线程阻塞
    int ret=pthread_cond_wait(&_cond,_mut.get_mutex());
    if(ret)
        perror("pthread_cond_wait error!");
}
    void condition::wakeup(){   //唤醒线程
      pthread_cond_signal(&_cond);      
    }



