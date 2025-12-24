#include<iostream>
#include<memory>
#include<vector>

struct Child;

struct Parent {
    std::shared_ptr<Child> child;
    std::weak_ptr<Parent>  self;
    ~Parent(){
        std::cout<<"parent destoryed\n";
    }
};

struct Child{
    std::weak_ptr<Parent> parent;
    ~Child(){
        std::cout<<"child destoryed\n";
    }

   void sayHi() {
        /* 典型的 lock() 用法：尝试提升 */
        if (auto sp = parent.lock(); sp) {
            std::cout << "Hi from Child! Parent use_count = "
                        << sp.use_count() << '\n';
        } else {
            std::cout << "Parent is gone\n";
        }
   }
};



