#ifndef ADMIN_H_
#define ADMIN_H_

#include "bicycle.h"
#include "member.h"
#include "datatable.h"

class Admin:public Bicycle,public member
{
    public:
        Admin (string name = "JiangSu University");
        virtual ~Admin();

        
        Datatable dataTableAdmin;
        Bicycle bicycle;
        Member member;
        void addBicycle();//新加车
        void removeBicycle();//移除坏车
        void logIn();//登录 账户 密码 被锁死
        void checkBicycle();//显示报错的提示，以及人为的更改
        
};

#endif
