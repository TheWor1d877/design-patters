#include<iostream>
#include<memory>

int main(){
    std::unique_ptr<int> u1(new int(10));
    // std::unique_ptr<int> u2 = u1;
    std::unique_ptr<int> u3 = std::move(u1);
    if(!u1) std::cout<<"u1 is nullptr"<<std::endl;
    std::cout << *u3 <<std::endl;
    return 0;
}