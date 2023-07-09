
#include <iostream>
using namespace std;

#define freeptr(p) if(p) delete p; p=nullptr;

// 设计所有支持算法的公共接口 Strategy类
class Strategy
{
public:
	~Strategy(){
        cout << "调用Strategy类-->析构函数." << endl;
    };
    virtual void AlgorithmInterfaceFunc() = 0;
};

// 继承Strategy类，封装具体算法和行为
class ConcreteStrategyA :public Strategy {
    void AlgorithmInterfaceFunc() {
        cout << "调用ConcreteStrategyA类-->算法A操作实现." << endl;
    }
};

class ConcreteStrategyB :public Strategy {
    void AlgorithmInterfaceFunc() {
        cout << "调用ConcreteStrategyB类-->算法B操作实现." << endl;
    }
};

class ConcreteStrategyC :public Strategy {
    void AlgorithmInterfaceFunc() {
        cout << "调用ConcreteStrategyC类-->算法C操作实现." << endl;
    }
};

class Context {
public:
    Context(Strategy* strategy) :mstrategy(strategy) {
    }
    ~Context() {
        freeptr(mstrategy);
    }
    void AlgorithmInterfaceFunc() {
        mstrategy->AlgorithmInterfaceFunc();
    }

private:
    Strategy* mstrategy;
};

int main()
{
    Strategy* concretestrategyA = new ConcreteStrategyA();
    Strategy* concretestrategyB = new ConcreteStrategyB();
    Strategy* concretestrategyC = new ConcreteStrategyC();

    concretestrategyA->AlgorithmInterfaceFunc();
    concretestrategyB->AlgorithmInterfaceFunc();
    concretestrategyC->AlgorithmInterfaceFunc();
    cout << endl;

    freeptr(concretestrategyA);
    freeptr(concretestrategyB);
    freeptr(concretestrategyC);    

    return 0;
}

