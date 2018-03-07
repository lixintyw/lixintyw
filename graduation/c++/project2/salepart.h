#ifndef SALEPART_H_
#define SALEPART_H_
#include"employee.h"
#include"datatable.h"
class SalePart:virtual public Employee
{
	public:
			SalePart(string name="NewSalePart",uint level=ENUM_EMPLOYEE_LEVEL_SALEPART);
			~SalePart();
			void info();
			void setTotal();
			void setPay();
			uint getTotalSale();
			uint getPerSalePay();
			void work(uint id);
	private:
		uint m_uiTotalSale;
		uint m_PerSalePay;
		DataTable db4;
};
#endif
