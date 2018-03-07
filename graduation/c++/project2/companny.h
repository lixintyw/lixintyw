#ifndef COMPANNY_H_
#define COMPANNY_H_
#include<iostream>
#include"datatable.h"
#include"boss.h"
#include"tecpart.h"
#include"tecpartmana.h"
#include"salepart.h"
#include"salepartmana.h"
using namespace std;
class Companny
{
	public:
			Companny();
			~Companny();
			void CreateBoss();
			void work();
	private:
			DataTable dt;
			Boss boss;
			TecPart tp;
			TecPartMana tpma;
			SalePart sp;
			SalePartMana spma;
};
#endif
