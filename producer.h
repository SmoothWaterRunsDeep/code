#pragma once
#include"thread.h"
class producer
:public thread
{
public:
    producer(buffer&buf);
    ~producer();

private:
void run()override;
};

