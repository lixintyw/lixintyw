#ifndef TECPARTMANA_H_
#define TECPARTMANA_H_
#include"tecpart.h"
#include"datatable.h"
//#include"companny.h"
class TecPartMana:public TecPart
{
		public:
				TecPartMana(string name="NewPartTecMana",uint salary=1000);
				~TecPartMana();
				void info();

				void addTecPart();
				void delTecPart();
				void lookTecPart();
				void changeTecPart();
				
				uint getSalary();
				void work(uint uiId);
				void work();
		private:
			uint m_uiSalary;
			DataTable db1;
//			Companny c;
};
#endif
