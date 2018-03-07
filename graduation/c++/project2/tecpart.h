#ifndef TECPART_H_
#define TECPART_H_
#include<iostream>
#include"employee.h"
#include"datatable.h"
using namespace std;

class TecPart:virtual public Employee
{
		public:
				TecPart(string name="NewPartTec",uint level=ENUM_EMPLOYEE_LEVEL_TECPART,uint payhour=50,uint leaderId=1000);
				~TecPart();
				void info();
				void setWorkHour();
				uint getWorkHour();
				uint getPerHourPay();
				uint getLeaderId();
				void work(uint id);
		private:
		uint m_WorkHour;
		uint m_PerHourPay;
		uint m_uiLeaderId;
		DataTable db3;
};

#endif
