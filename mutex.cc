#include"mutex.h"
#include<stdio.h>

mutex::mutex(){
    int ret=pthread_mutex_init(&mut,nullptr);//初始化互斥锁
    if(ret)
        perror("pthread_mutex_init error!");
}

mutex::~mutex(){
    int ret=pthread_mutex_destroy(&mut);   //销毁互斥锁 
    if(ret)
        perror("pthread_mutex_destroy error!");
}

void mutex::lock(){
    int ret= pthread_mutex_lock(&mut);
    if(ret)
        perror("pthread_mutex_lock error!");
}

void mutex::trylock(){
    int ret= pthread_mutex_trylock(&mut);
    if(ret)
        perror("pthrad_mutex_trylock error!");
}

void mutex::unlock(){
    int ret=pthread_mutex_unlock(&mut);
    if(ret)
        perror("pthread_mutex_unlock error!");
}

pthread_mutex_t* mutex::get_mutex(){
    return &mut;
}

