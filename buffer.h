#pragma once
#include"condition.h"
#include<queue>
using std::queue;
class buffer
{
public:
    buffer(size_t size);
    ~buffer();
    bool isempty();
    bool isfull();
    void push(const int&value);
    int pop();

private:
size_t _capcity; //缓冲区应有容量限制
mutex __mutex;
condition _notempty;    
condition _notfull; //空和满都是条件变量
queue<int>que;  //缓冲区的底层容器采用队列
};

/*通过互斥锁与条件变量实现生产者与消费者的同步*/
