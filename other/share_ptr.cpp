#include<iostream>
#include<memory>


int main(){
    std::shared_ptr<int> s1(new int(10));
    std::shared_ptr<int> s2 = s1;

    std::cout<< "s1 use_count:" << s1.use_count() <<std::endl;
    std::cout<< "s2 use_count:" << s2.use_count() <<std::endl;    
    s1.reset(); 
    std::cout << "s2 use_count: " << s2.use_count() << std::endl; 
    return 0;

}   