
#include <iostream>
#include <string>
#include <list>
using namespace std;

// 抽象的组件对象
class Component {
public:
	Component(string name) {
		strname = name;
	}

	virtual void add(Component* com) = 0;
	virtual void del(Component* com) = 0;
	virtual void print(int depths) = 0;

protected:
	string strname;
};

// Leaf在组合中表示叶子节点对象（叶子节点没有子节点）
class Leaf :public Component {
public:
	Leaf(string name) :Component(name) {

	}

	void add(Component* com) {
		cout << "无法添加叶子节点" << endl;
	}

	void del(Component* com) {
		cout << "无法删除叶子节点" << endl;
	}

	void print(int depths) {
		cout << string(depths, '-') + strname << endl;
	}
};

// 组合对象
class Composite :public Component {
public:
	Composite(string name) :Component(name) {

	}

	void add(Component* com) {
		children.push_back(com);
	}

	void del(Component* com) {
		children.remove(com);
	}

	// 输出枝节点名称，并对其下级进行遍历 
	void print(int depths) {
		cout << string(depths, '-') + strname << endl;
		for (Component* com : children)
		{
			com->print(depths + 2);
		}
	}

protected:
	// 定义子对象你方便，用来存储下属叶子节点和枝节点
	list<Component*> children;
};

int main()
{

	// 生成树根root ,根上长出两叶子LeafA LeafB
	Composite* root = new Composite("root树根");
	root->add(new Leaf("LeafA"));
	root->add(new Leaf("LeafB"));

	Composite* compx = new Composite("CompositeX");
	compx->add(new Leaf("CompositeX-LeafX-A"));
	compx->add(new Leaf("CompositeX-LeafX-B"));
	root->add(compx);

	Composite* compy = new Composite("CompositeY");
	compy->add(new Leaf("CompositeY-LeafY-A"));
	compy->add(new Leaf("CompositeY-LeafY-B"));
	root->add(compy);

	root->add(new Leaf("LeafC"));
	
	// 显示树的结构
	root->print(1);

	return 0;
}

