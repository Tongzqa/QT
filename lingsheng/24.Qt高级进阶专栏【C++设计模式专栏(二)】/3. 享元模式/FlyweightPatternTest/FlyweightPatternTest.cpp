
#include <iostream>
#include <map>
using namespace std;

// 1：定义抽象享元类。比如网络设备：路由器、交换机、集线器等等
class  NetDevice {
public:
    virtual string devicetype() = 0;
    virtual void link() = 0;
};

// 2：具体享元类
class Router :public NetDevice {
public:
    Router(string type) {
        this->type = type;
    }
    string devicetype() {
        return this->type;
    }
    void link() {
        cout << "连接型号为：" << this->type << " 路由器." << endl;
    }
private:
    string type;
};

class Switch :public NetDevice {
public:
    Switch(string type) {
        this->type = type;
    }
    string devicetype() {
        return this->type;
    }
    void link() {
        cout << "连接型号为：" << this->type << " 交换机." << endl;
    }
private:
    string type;
};

class Hub :public NetDevice {
public:
    Hub(string type) {
        this->type = type;
    }
    string devicetype() {
        return this->type;
    }
    void link() {
        cout << "连接型号为：" << this->type << " 集线器." << endl;
    }
private:
    string type;
};


// 3：享元工厂类
class DeviceFactory {
public:
    DeviceFactory() {
        shared_ptr<NetDevice> d1 = make_shared<Router>("TP-Link-01");
        devis.insert(make_pair("Tp", d1));

        shared_ptr<NetDevice> d2 = make_shared<Switch>("华为-01");
        devis.insert(make_pair("Huawei", d2));

        shared_ptr<NetDevice> d3 = make_shared<Hub>("中兴-01");
        devis.insert(make_pair("Zte", d3));
    }

    shared_ptr<NetDevice> getnetdevice(string type) {
        if (devis.count(type))
        {
            count++;
            return devis.find(type)->second;
        }
        else
        {
            return nullptr;
        }
    }

    int gettotaldevice() {
        return devis.size();
    }
    int getterminalcount() {
        return count;
    }

private:
    map <string, shared_ptr<NetDevice>> devis;
    int count = 0;
};


int main()
{
    shared_ptr<NetDevice> d1, d2, d3, d4, d5, d6, d7, d8;
    shared_ptr<DeviceFactory> df = make_shared<DeviceFactory>();

    d1 = df->getnetdevice("Huawei");
    d1->link();
    d2 = df->getnetdevice("Huawei");
    d2->link();
    d3 = df->getnetdevice("Huawei");
    d3->link();
    cout << endl;

    d4 = df->getnetdevice("Tp");
    d4->link();
    d5 = df->getnetdevice("Tp");
    d5->link();
    d6 = df->getnetdevice("Tp");
    d6->link();
    cout << endl;

    d7 = df->getnetdevice("Zte");
    d7->link();
    d8 = df->getnetdevice("Zte");
    d8->link();
    cout << endl;

    cout << "网络设备总数：" << df->gettotaldevice() << endl;
    cout << "网络终端总数：" << df->getterminalcount() << endl << endl;

    return 0;
}

