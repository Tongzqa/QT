#include <iostream>
using namespace std;

class ProtoType {  // 凡是含有纯虚函数的类叫做抽象类
public:
	ProtoType(){
	}
	~ProtoType() {
	}

	virtual ProtoType* CloneFunc() = 0;  // 纯虚函数
};

class ConreteProtoType:public ProtoType
{
public:
	ConreteProtoType(int imember):_member(imember) {
		cout << "执行ConreteProtoType带参构造函数.\n" << endl;
	}
	~ConreteProtoType() {
		cout << "执行ConreteProtoType析构函数." << endl;
	}

	// 拷贝构造函数（若有指针成员变量，要进行实现深拷贝）
	ConreteProtoType(const ConreteProtoType& rhs) {
		_member = rhs._member;
		cout << "数据成员_member1：" << _member << endl;
	}

	ConreteProtoType* CloneFunc() { // 派生类实现
		cout << "正在处理克隆." << endl;
		cout << "数据成员_member2：" << _member << endl;
		return new ConreteProtoType(*this);
	}

private:
	int _member;

};

int main()
{
	cout << "main()函数-->原型模式开始.\n" << endl;

	ConreteProtoType* CloneObjA = new ConreteProtoType(88);
	ConreteProtoType* CloneObjB = CloneObjA->CloneFunc();

	cout << endl;

	delete CloneObjA;
	CloneObjA = nullptr;
	delete CloneObjB;
	CloneObjB = nullptr;

	return 0;
}





