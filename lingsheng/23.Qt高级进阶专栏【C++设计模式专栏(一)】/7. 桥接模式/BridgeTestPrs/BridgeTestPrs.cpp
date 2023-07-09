
#include <iostream>
using namespace std;


// 支付模式--实现化角色（实现类接口，Implementation（实现类接口））
class IPayMode {
public:
    virtual bool security(string Uid) = 0;
};

// 具体实现化角色：密码支付（具体实现类）
class PayCypher :public IPayMode {
public:
    bool security(string uId) override {
        cout << "密码支付，风控校验环境安全." << endl;
        return true;
    }
};

// 人脸支付 
class PayFaceMode :public IPayMode {
public:
    bool security(string uId) override {
        cout << "人脸支付，风控校验脸部识别." << endl;
        return true;
    }
};

// 指纹支付
class PayFingerPrintMode :public IPayMode {
public:
    bool security(string uId) override {
        cout << "指纹支付，风控校验指令信息安全." << endl;
        return true;
    }
};

// 抽象化类：支付（抽象化角色）
class Pay {
public:
    IPayMode *payMode;

    Pay(IPayMode* payMode)
    {
        this->payMode = payMode; // 抽象类定义一个IPayMode，跟IPayMode存在关联关系
    }

    virtual ~Pay() {
        delete payMode;
    }

    virtual string transfer(string uId, string tradeId, long long amount) = 0;

};

// 扩展抽象化角色：微信支付
class WxPay :public Pay {
public:
    WxPay(IPayMode* payMode) :Pay(payMode) {}
    // 扩展抽象类（实现抽象类中定义的成员函数）
    string transfer(string uId, string tradeId, long long amount) {
        cout << "微信支付开始，用户ID：" << uId << "交易ID：" << tradeId << "交易金额：" << amount << endl;

        bool security = payMode->security(uId);
        if (!security)
        {
            cout << "微信支付失败，用户ID：" << uId << "交易ID：" << tradeId << "交易金额：" << amount << endl;
            return "Fail000";
        }
        else
        {
            cout << "微信支付成功，用户ID：" << uId << "交易ID：" << tradeId << "交易金额：" << amount << endl;
            return "Success001";
        }
    }
};


// 扩展抽象化角色：支付宝支付
class AliPay :public Pay {
public:
    AliPay(IPayMode* payMode) :Pay(payMode) {}
    // 扩展抽象类（实现抽象类中定义的成员函数）
    string transfer(string uId, string tradeId, long long amount) {
        cout << "支付宝支付开始，用户ID：" << uId << "交易ID：" << tradeId << "交易金额：" << amount << endl;

        bool security = payMode->security(uId);
        if (!security)
        {
            cout << "支付宝支付失败，用户ID：" << uId << "交易ID：" << tradeId << "交易金额：" << amount << endl;
            return "Fail000";
        }
        else
        {
            cout << "支付宝支付成功，用户ID：" << uId << "交易ID：" << tradeId << "交易金额：" << amount << endl;
            return "Success001";
        }
    }
};


// 扩展抽象化角色：华为支付
class HuaweiPay :public Pay {
public:
    HuaweiPay(IPayMode* payMode) :Pay(payMode) {}
    // 扩展抽象类（实现抽象类中定义的成员函数）
    string transfer(string uId, string tradeId, long long amount) {
        cout << "华为支付开始，用户ID：" << uId << "交易ID：" << tradeId << "交易金额：" << amount << endl;

        bool security = payMode->security(uId);
        if (!security)
        {
            cout << "华为支付失败，用户ID：" << uId << "交易ID：" << tradeId << "交易金额：" << amount << endl;
            return "Fail000";
        }
        else
        {
            cout << "华为支付成功，用户ID：" << uId << "交易ID：" << tradeId << "交易金额：" << amount << endl;
            return "Success001";
        }
    }
};


int main()
{
    cout << "--------------------请选择付款方式--------------------" << endl;
    Pay* wxpay = new WxPay(new PayFaceMode());
    wxpay->transfer("weixin_666", "20221201", 290000);
    cout << endl << endl;
    
    cout << "--------------------请选择付款方式--------------------" << endl;
    Pay* huawei = new HuaweiPay(new PayCypher());
    huawei->transfer("Huawei_888", "20221208", 1000000);
    cout << endl << endl;

    cout << "--------------------请选择付款方式--------------------" << endl;
    Pay* alipay = new AliPay(new PayFingerPrintMode());
    alipay->transfer("Alipay_999", "20221209", 9000000);
    cout << endl << endl;

    return 0;
}

