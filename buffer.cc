#include"buffer.h"

buffer::buffer(size_t size)
    :_capcity(size)
    ,__mutex()
    ,_notempty(__mutex)
    ,_notfull(__mutex)//虽然条件变量中有互斥锁，但是要注意刚刚在condition中只是定义了互斥锁和条件变量之间的关系和行为，而这里才是开始应用它们
     ,que()
{}

buffer::~buffer(){}//在condition和mutex中的析构函数已经实现出了销毁条件变量和互斥锁的代码，所以这里不用再实现了
//que和_capacity都不是new出来的，也没必要显示进行回收

bool buffer::isempty(){
    return que.size()==0;
}

bool buffer::isfull(){
    return que.size()==_capcity;
}

void buffer::push(const int&value){
    __mutex.lock();//先上锁
    while(isfull()){    //再判断（并且结合虚假唤醒）
        _notfull.wait();//若缓冲区满，则等待信号量_notfull
    }
    que.push(value);//向缓冲区放入元素
    _notempty.wakeup();//唤醒等待信号量_notempty的线程
    __mutex.unlock();//最后别忘了解锁
}

int buffer::pop(){
    __mutex.lock();//先上锁
    while(isempty()){
        _notempty.wait();//若缓冲区为空，则等待信号量_notempty
    }
    int ret=que.front();
    que.pop();
    _notfull.wakeup();//唤醒等待信号量_notfull的线程
    __mutex.unlock();//解锁
    return ret;
}



















