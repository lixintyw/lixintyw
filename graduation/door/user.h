#ifndef USER_H
#define USER_H

#include "system.h"

class Guest
{
public:
	void pressRing(DoorSystem &ds)
	{
		cout << "以访客身份按门铃...\n";
		ds.setRing();
	}
};

class Employee: public Guest
{
public:
	void input(DoorSystem &ds)
	{
		ds.m_input.inputData();
	}
};

class Admin: public Employee
{
public:
	void pressOpenButton(DoorSystem &ds)
	{
		cout << "管理员按开门按钮...\n";
		ds.setOpen();
	}	

	void addUsrInfo(DoorSystem &ds)
	{
		ds.m_input.inputData();
		string strType = ds.m_input.dataType();
		ds.m_computer.addData(ds.m_input.getData()
						      , strType);
	}
};


#endif
