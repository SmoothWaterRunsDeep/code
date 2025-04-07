#pragma once
#include"thread.h"
class consumer
:public thread
{
public:
    consumer(buffer&buf);//显然在生产者与消费者都继承自thread的时候，反之每次构造函数都要传一下参数buf,所以其实没有必要在抽象类中把_buf当作成员函数
    ~consumer();

    void run()override;
};
