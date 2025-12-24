#include<iostream>
#include<thread>
#include<mutex>

std::once_flag flag;

void init(){
    std::cout<<"only once"<<std::endl;
}

void worker(){
    std::call_once(flag,init);
}

int main(){
    std::thread t1(worker);
    std::thread t2(worker);
    std::thread t3(worker);

    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}