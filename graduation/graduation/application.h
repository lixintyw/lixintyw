#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include "datatable.h"
#include "bicycle.h"
#include "member.h"
#include "admin.h"

using namespace std;

class Application 
{
    public:
        Application();
        ~Application();
        void CreateAdmin();
        void work();
    private:
        DataTable dataTable;
        Admin admin;
        Bicycle bicycle;
        Member member;
        Visitor visior;
};

#endif
