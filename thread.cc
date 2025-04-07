#include"thread.h"

thread::thread(buffer&buf)
    :_buf(buf)
     ,thid(0)
     ,isRunning(false){

     }

thread::~thread(){};

void thread::start(){
    int ret=pthread_create(&thid,nullptr,threadfunction,this);
    if(ret)
        perror("pthread_create error!");
    isRunning=true;
}

void thread::stop(){
    if(isRunning){
        int ret=pthread_join(thid,nullptr);//pthread_join 函数会阻塞调用它的线程，直至指定的thid线程执行完毕。一旦目标线程终止，调用线程就会恢复执行，并且可以获取目标线程的退出状态。
        if(ret)
            perror("pthread_jpin error!");
    }
    isRunning=false;
}

void* thread::threadfunction(void*arg){
    thread* pth=(thread*)arg;
    pth->run(); //各线程的入口函数中执行的是run方法
    pthread_exit(nullptr);


}



