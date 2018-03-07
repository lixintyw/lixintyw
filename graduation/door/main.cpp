#include "system.h"
#include "user.h"

void testGuest()
{
	Guest guest;
	DoorSystem ds;
	Admin admin;

	//访客按门铃
	guest.pressRing(ds);
	sleep(1);
	
	//管理员按开门按钮
	admin.pressOpenButton(ds);
	sleep(1);

	ds.work();
}

void testEmployee()
{
	Admin admin;
	DoorSystem ds;

	admin.addUsrInfo(ds);
	admin.addUsrInfo(ds);
	admin.addUsrInfo(ds);

	Employee u;
	while (1)
	{
		u.input(ds);
		ds.work();
	}
}

int main(void)
{
	//testGuest();
	testEmployee();

	return 0;
}
