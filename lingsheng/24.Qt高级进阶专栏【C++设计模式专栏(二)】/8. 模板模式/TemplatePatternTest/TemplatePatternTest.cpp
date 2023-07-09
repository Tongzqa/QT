
#include <iostream>
using namespace std;

class AbstractClass {
public:
	void TemplateMethod() {
		cout << "调用：模板方法模式." << endl;
		PrimitiveOperation1();
		PrimitiveOperation2();
	}

protected:
	virtual void PrimitiveOperation1() {
		cout << "默认操作--Operation1." << endl;
	}
	virtual void PrimitiveOperation2() {
		cout << "默认操作--Operation2." << endl;
	}
};

class ConreteClass1 :public AbstractClass {
protected:
	virtual void PrimitiveOperation1() {
		cout << "具体操作实现1--Operation1." << endl;
	}
	virtual void PrimitiveOperation2() {
		cout << "具体操作实现1--Operation2." << endl;
	}
};

class ConreteClass2 :public AbstractClass {
protected:
	virtual void PrimitiveOperation1() {
		cout << "具体操作实现2--Operation1." << endl;
	}
	virtual void PrimitiveOperation2() {
		cout << "具体操作实现2--Operation2." << endl;
	}
};

class ConreteClass3 :public AbstractClass {
protected:
	virtual void PrimitiveOperation1() {
		cout << "具体操作实现3--Operation1." << endl;
	}
	virtual void PrimitiveOperation2() {
		cout << "具体操作实现3--Operation2." << endl;
	}
};


int main()
{
	AbstractClass* pabst1 = new ConreteClass1;
	pabst1->TemplateMethod();
	cout << endl;
   
	AbstractClass* pabst2 = new ConreteClass2;
	pabst2->TemplateMethod();
	cout << endl;

	AbstractClass* pabst3 = new ConreteClass3;
	pabst3->TemplateMethod();
	cout << endl;

	if (pabst1)
		delete pabst1;
	if (pabst2)
		delete pabst2;
	if (pabst3)
		delete pabst3;

	return 0;
}

