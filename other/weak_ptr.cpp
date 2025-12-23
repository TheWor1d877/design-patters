#include <iostream>
#include <memory>
#include <unistd.h>

class B;
class A
{
public:
    std::shared_ptr<B> pb_;
    ~A()
    {
        std::cout << "A delete" << std::endl;
    }
};

class B
{
public:
    std::weak_ptr<A> pa_;
    ~B()
    {
        std::cout << "B delete" << std::endl;
    }
};

void func()
{
    std::shared_ptr<A> pa(new A());
    std::shared_ptr<B> pb(new B());

    pa->pb_ = pb;
    pb->pa_ = pa;

    std::cout << pb->pa_.lock() << std::endl;
    std::cout << pb->pa_.expired() << std::endl;

    std::cout << "pa use_count: " << pa.use_count() << std::endl;
    std::cout << "pb use_count: " << pb.use_count() << std::endl;
}

int main()
{
    func();
    sleep(100);
    return 0;
}