
#include <iostream>
using namespace std;

// 抽象处理者：领导者类
class Leader {
public:
    void SetNext(Leader* next) {
        this->mnext = next;
    }

    Leader* GetNext()const {
        return mnext;
    }

    virtual ~Leader() {
    }

    // 处理请求方法
    virtual void HandlerRequest(int days) = 0;

private:
    Leader* mnext;
};

// 具体处理者1：班主任
class headmaster :public Leader {
public:
    void HandlerRequest(int days)override {
        if (days <= 3)
        {
            cout << "\n班主任已经批准你请假：" << days << "天。" << endl;
        }
        else
        {
            if (GetNext() != nullptr)
            {
                GetNext()->HandlerRequest(days);
            }
            else
            {
                cout << "\n你请假的天数太多，没有人能够批准你请假。" << endl;
            }
        }
    }
};

// 具体处理者2：系主任
class departmentHead :public Leader {
public:
    void HandlerRequest(int days)override {
        if (days <= 10)
        {
            cout << "\n系主任已经批准你请假：" << days << "天。" << endl;
        }
        else
        {
            if (GetNext() != nullptr)
            {
                GetNext()->HandlerRequest(days);
            }
            else
            {
                cout << "\n你请假的天数太多，没有人能够批准你请假。" << endl;
            }
        }
    }
};

// 具体处理者3：校长
class principal :public Leader {
public:
    void HandlerRequest(int days)override {
        if (days <= 30)
        {
            cout << "\n校长已经批准你请假：" << days << "天。" << endl;
        }
        else
        {
            if (GetNext() != nullptr)
            {
                GetNext()->HandlerRequest(days);
            }
            else
            {
                cout << "\n你请假的天数太多，没有人能够批准你请假。" << endl;
            }
        }
    }
};


int main()
{
    // 组装责任链
    Leader* t1 = new headmaster();
    Leader* t2 = new departmentHead();
    Leader* t3 = new principal();

    t1->SetNext(t2);
    t2->SetNext(t3);

    // 提交请假请求天数day
    int day = 0;
    cout << "\n\n请输入请假天数:";
    while (cin >> day)
    {
        t1->HandlerRequest(day);
    }

    delete t1;
    t1 = nullptr;
    delete t2;
    t2 = nullptr;
    delete t3;
    t3 = nullptr;    

    return 0;
}

