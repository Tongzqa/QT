
#include <iostream>
#include <list>
using namespace std;

class Observer { // 定义观察者的接口（抽象观察者）
public:
    virtual void Update(int) = 0;
};

class Subject { // 目标对象（抽象通知者）
public:
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
};

// 观察者的具体实现对象
class ConreteObserver1 :public Observer {
public:
    ConreteObserver1(Subject* psubject) :mpsubject(psubject) {}

    // Upadte()方法（更新方法）
    void Update(int values) {
        cout << "ConreteObserver1获取更新，新状态为：" << values << endl;
    }

private:
    Subject* mpsubject;
};

class ConreteObserver2 :public Observer {
public:
    ConreteObserver2(Subject* psubject) :mpsubject(psubject) {}

    // Upadte()方法（更新方法）
    void Update(int values) {
        cout << "ConreteObserver2获取更新，新状态为：" << values << endl;
    }

private:
    Subject* mpsubject;
};


// 具体的目标实现对象
class ConceteSubject :public Subject {
public:
    void Attach(Observer* pobserver) {
        mobserverlist.push_back(pobserver);
    }
    void Detach(Observer* pobserver) {
        mobserverlist.remove(pobserver);
    }
    void Notify() {
        std::list<Observer*>::iterator it = mobserverlist.begin();
        while (it != mobserverlist.end()) {
            (*it)->Update(mstate);
            ++it;
        }
    }

    void SetState(int state) { // 设置状态
        mstate = state;
    }

private:
    int mstate;
    std::list<Observer*>mobserverlist;
};


int main()
{
    // 创建目标对象
    ConceteSubject* psubject = new ConceteSubject();

    // 创建观察者
    Observer* pobserver1 = new ConreteObserver1(psubject);
    Observer* pobserver2 = new ConreteObserver2(psubject);

    // 更改状态
    psubject->SetState(666);

    // 注册观察者接口
    psubject->Attach(pobserver1);
    psubject->Attach(pobserver2);
    psubject->Notify();

    // 注销观察者
    psubject->Detach(pobserver1);
    cout << endl;

    psubject->SetState(888);
    psubject->Notify();

    delete pobserver1;
    delete pobserver2;
    delete psubject;


    return 0;
}


