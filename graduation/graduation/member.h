#ifndef MEMBER_H_
#define MEMBER_H_

#include <iostream>
#include <string>
#include <stdlib>
using namespace std;

typedef unsigned int uint;

enum ENUM_MEMBER_LEVEL
{
    ENUM_MEMBER_LEVEL_MIN = 0,
    ENUM_MEMBER_LEVEL_COMMON_MEMBER,
    ENUM_MEMBER_LEVEL_WEEK_VIP_MEMBER,
    ENUM_MEMBER_LEVEL_MONTH_VIP_MEMBER,
    ENUM_MEMBER_LEVEL_YEAR_VIP_MEMBER,
    ENUM_MEMBER_LEVEL_VISITOR,
    ENUM_MEMBER_LEVEL_MAX = 0x00ffffff
};

class Member
{
    public:
        Member();//设置初始值
        ~Member();
        string &setInitialName();
        string &getStrName();
        string &getStrPwd();
        string &getData();
        string &getAddress();
        string &getNote();
        void setStrName();
        void setStrPwd();
        void setAddress();
        void setNote();
        void recharge();//充值
        void upgrade();//升级VIP
        void getBicycleInfo()//获得车辆信息
        void borrowBicycle()//借车
        void returnBicycle()//还车
        void freezeAccount()//冻结账户
        void unsubscribe();//注销账户
        void signUp();//注册
        void logIn();//登录
        void withDrawDeposit();//提现
        void vehicleError();//车辆报错
    private:
    //    uint m_id;
        uint m_level;
        string m_strName;
        string m_strPwd;
        string m_strDate;
        string m_address;
        string m_strNote;
        bool m_deposit;//押金
        uint m_accountBalance;//账户余额
}；

#endif