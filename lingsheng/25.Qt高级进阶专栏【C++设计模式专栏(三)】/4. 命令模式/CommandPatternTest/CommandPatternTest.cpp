
#include <iostream>
using namespace std;

class Receiver { // 接收者
public:
    void ActionFunc() {
        cout<<"\nReceiver-->ActionFunc()"<<endl;
    }
};

class Command { // 写信命令接口
public:
    virtual void Execute() = 0;
};

class ConcreteCommand :public Command { // 命令接口实现对象
public:
    ConcreteCommand(Receiver* preceiver) :mpreceiver(preceiver){}

    void Execute() {
        mpreceiver->ActionFunc();
    }

private:
    Receiver* mpreceiver;
};

class Invoker { // 要求命令对象执行请求
public:
    Invoker(Command *pcommand):mpcommand(pcommand){}

    void Invoke() {
        mpcommand->Execute();
    }

private:
    Command* mpcommand;
};

int main()
{
    Receiver* preceiver = new Receiver();
    Command* pcommand = new ConcreteCommand(preceiver);
    Invoker* pinvoker = new Invoker(pcommand);

    pinvoker->Invoke();
    
    delete pinvoker;
    delete pcommand;
    delete preceiver;

    return 0;
}

