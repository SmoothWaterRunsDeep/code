#include"consumer.h"
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<unistd.h>


using  std::cout;
using std::endl;
consumer::consumer(buffer&buf)
    :thread(buf){
    }

consumer::~consumer(){}

void consumer::run(){
    int cnt=20;
    while(cnt--){
        int num=_buf.pop();
        cout<<"consume"<<num<<"successfully!"<<endl;
        sleep(1);
    }
}
