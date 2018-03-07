#ifndef SALEPARTMANA_H_
#define SALEPARTMANA_H_
#include"salepart.h"
#include"datatable.h"
class SalePartMana:public SalePart
{
		public:
				SalePartMana(string name="NEWSalePartMana",uint normalsalary=10000);
				~SalePartMana();
				void info();
				void setNormalSalary();
				void setSaleSalary();
				void setTotalSaled();
				uint getNormalSalary();
				uint getSaleSalary();
				uint getTotalSaled();
				
				void addSalePart();
				void delSalePart();
				void lookSalePart();
				void changeSalePart();

				void work(uint id);
		private:
			uint m_uiNormalSalary;
			uint m_uiSaleSalary;
			uint m_uiTotalSaled;
			DataTable db2;
};
#endif
