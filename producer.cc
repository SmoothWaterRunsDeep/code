#include"producer.h"
#include<iostream>
#include<time.h>
#include<unistd.h>

using std::cout;
using std::endl;

producer::producer(buffer&buf)
    :thread(buf){}

    producer::~producer(){}

    void producer::run(){
        srand(clock());
        int cnt=20;
        while(cnt--){
            _buf.push(rand());
            cout<<"produce successfully!"<<endl;
            sleep(1);
        }
    }
