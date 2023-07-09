
#include <iostream>
using namespace std;

// 我们要定义客户端使用的接口，与特殊领域相关的
class Target {
public:
    virtual void RequestFunc() = 0;
    virtual ~Target() {
        cout << "调用Target类析构函数." << endl;
    }
};

// 已经存在的接口，这个接口需要被适配
class Adaptee {
public:
    void SpecificRequestFunc() {
        cout << "\nAadaptee类特殊请求处理实现模块.\n" << endl;
    }
    ~Adaptee() {
        cout << "调用Adaptee类析构函数." << endl;
    }
};

// 适配器，将现在接口转为需要的接口
class Apapter :public Target {
private:
    Adaptee* adaptee;

public:
    Apapter() {
        adaptee = new Adaptee();
        cout << "调用Apapter类构造函数." << endl;
    }

public:
    virtual void RequestFunc() { // 可以转调已经实现的方法，进行适配

        adaptee->SpecificRequestFunc();
    }

    virtual ~Apapter() {
        if (adaptee != NULL)
        {
            delete adaptee;
            adaptee = NULL;
        }
        cout << "调用Apapter类析构函数." << endl;
    }   
};


int main()
{
    // 创建客户端需要调用的接口对象
    Target* target = new Apapter();

    target->RequestFunc(); // 请求处理操作

    if (target != NULL)
    {
        delete target;
        target = NULL;
    }
    
    return 0;
}


