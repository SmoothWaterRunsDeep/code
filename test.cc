#include"consumer.h"
#include"producer.h"
#include"buffer.h"



void test(){
buffer task(10);
producer pro(task);
consumer con(task);

pro.start();
con.start();

pro.stop();
con.stop();

}

int main(){

    test();
    return 0;
}

