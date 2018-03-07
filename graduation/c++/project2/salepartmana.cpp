#include"salepartmana.h"
SalePartMana::SalePartMana(string name,uint normalsalary):SalePart(name,ENUM_EMPLOYEE_LEVEL_SALEPARTMANA),Employee(name,ENUM_EMPLOYEE_LEVEL_SALEPARTMANA)
{
	m_uiNormalSalary=normalsalary;
}
SalePartMana::~SalePartMana(){}
void SalePartMana::info()
{}
void SalePartMana::setNormalSalary()
{}
void SalePartMana::setSaleSalary()
{}
void SalePartMana::setTotalSaled()
{}

uint SalePartMana::getNormalSalary()
{
	return m_uiNormalSalary;
}
uint SalePartMana::getSaleSalary()
{
	return m_uiSaleSalary;
}
uint SalePartMana::getTotalSaled()
{
	return m_uiTotalSaled;
}
void SalePartMana::addSalePart()
{}
void SalePartMana::delSalePart()
{}
void SalePartMana::lookSalePart()
{}
void SalePartMana::changeSalePart()
{}

void SalePartMana::work(uint id)
{
	char num='\0';
	while(1)
	{
	//db2.time();
	//			db2.myfree();
	//			db2.myfree();
	cout<<"\t         welcome!"<<endl;
	cout<<"\t********************************"<<endl;
	cout<<"\t*1.查看信息    \t2.修改密码    *"<<endl;
	cout<<"\t*3.添加销售人员\t4.删除销售人员*"<<endl;
	cout<<"\t*5.查找销售人员\t6.修改销售人员*"<<endl;
	cout<<"\t*0.退出        \t7.打印销售人员*"<<endl;
	cout<<"\t********************************"<<endl;
	cout<<"输入选项:";
	//getchar();
	cin>>num;
	switch(num)
	{
		case '1':
				db2.lookSPMA(id);
				break;
		case '2':
				db2.changePwdTp();
				break;
		case '3':
				db2.addSP(id);
				break;
		case '4':
				db2.delSP();
				break;
		case '5':
				db2.lookSP();
				break;
		case '6':
				db2.changeSP();
				break;
		case '7':
				db2.PSP();
				break;
		case '0':
				//exit(1);
				return;
		default:
				cout<<"error"<<endl;
				break;
	}
	}
}

