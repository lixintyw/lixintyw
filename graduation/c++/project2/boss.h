#ifndef BOSS_H_
#define BOSS_H_
#include"tecpartmana.h"
#include"salepartmana.h"
#include"datatable.h"
class Boss:public TecPartMana,public SalePartMana
{
	public:
			Boss(string name="Boss");
			virtual ~Boss();
   
			void work();
			DataTable db;
			TecPartMana tpm;

};
void work1();
void work2();
#endif
