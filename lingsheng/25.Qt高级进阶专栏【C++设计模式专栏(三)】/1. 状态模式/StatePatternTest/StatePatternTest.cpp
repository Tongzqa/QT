
#include <iostream>
using namespace std;

class Context;

class State { // 状态接口
public:
	State() {
		cout << "调用:State构造函数." << endl;
	}
	~State() {
		cout << "调用:State析构函数." << endl;
	}

	virtual void Handle(Context* pContext) {
	}
};

class Context { // 环境（又称为上下文）
public:
	Context() {
		cout << "调用:Context默认构造函数." << endl;
	}
	Context(State* pstate) :pState(pstate) {
	}
	~Context() {
		cout << "调用:Context析构函数." << endl;
	}

	void Request() {
		if (pState)
		{
			pState->Handle(this);
		}
	}

	void ChangedState(State* p) {
		if (pState != NULL)
		{
			delete pState;
			pState = NULL;
		}
		pState = p;
	}

private:
	State* pState;
};

class ConcreteStateA :public State { // 具体实现状态处理类
public:
	void Handle(Context* pcontext);
};
class ConcreteStateB :public State { // 具体实现状态处理类
public:
	void Handle(Context* pcontext);
};
class ConcreteStateC :public State { // 具体实现状态处理类
public:
	void Handle(Context* pcontext);
};




void ConcreteStateA::Handle(Context* pcontext)
{
	cout << "第1种状态" << endl;
	pcontext->ChangedState(new ConcreteStateB());
}
void ConcreteStateB::Handle(Context* pcontext)
{
	cout << "第2种状态" << endl;
	pcontext->ChangedState(new ConcreteStateC());
}
void ConcreteStateC::Handle(Context* pcontext)
{
	cout << "第3种状态" << endl;
	pcontext->ChangedState(new ConcreteStateA());
}


int main()
{
	State* pstate = new ConcreteStateA();
	Context* pcontext = new Context(pstate);

	pcontext->Request();
	cout << endl;

	pcontext->Request();
	cout << endl;

	pcontext->Request();
	cout << endl;


	return 0;
}




