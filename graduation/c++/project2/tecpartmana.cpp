#include"tecpartmana.h"
TecPartMana::TecPartMana(string name,uint salary):TecPart(name,ENUM_EMPLOYEE_LEVEL_TECPARTMANA),Employee(name,ENUM_EMPLOYEE_LEVEL_TECPARTMANA)
{
	m_uiSalary=salary;
}
TecPartMana::~TecPartMana(){}
void TecPartMana::info()
{}
void TecPartMana::addTecPart()
{}
void TecPartMana::delTecPart()
{}
void TecPartMana::lookTecPart()
{}
void TecPartMana::changeTecPart()
{}
uint TecPartMana::getSalary()
{
	return m_uiSalary;
}
void TecPartMana::work(uint uiId)
{
	while(1)
	{
//	db1.time();
	cout<<"\t			  welcome!           "<<endl;
	cout<<"\t********************************"<<endl;
	cout<<"\t*1.查看信息    \t2.修改密码    *"<<endl;
	cout<<"\t*3.添加技术人员\t4.删除技术人员*"<<endl;
	cout<<"\t*5.查找技术人员\t6.修改技术人员*"<<endl;
	cout<<"\t*0.退出        \t7.打印技术人员*"<<endl;
	cout<<"\t********************************"<<endl;
	char num='\0';
	cout<<"输入选项:";
	cin>>num;
	switch(num)
	{
		case '1':
				db1.lookTPMA(uiId);
				break;
		case '2':
				db1.changePwdTp();
				break;
		case '3':
				db1.addTP(uiId);
				break;
		case '4':
				db1.delTP();
				break;
		case '5':
				db1.lookTP();
				break;
		case '6':
				db1.changeTP();
				break;
		case '7':
				db1.PTP();
				break;
		case '0':
				return;
				//exit(1);
		default:
			cout<<"error!"<<endl;
			break;
	}
	}
}
void TecPartMana::work()
{
	while(1)
	{
//	db1.time();
	cout<<"\t			  welcome!"<<endl;
	cout<<"\t********************************"<<endl;
	cout<<"\t*1.添加技术人员\t2.删除技术人员*"<<endl;
	cout<<"\t*3.查找技术人员\t4.修改技术人员*"<<endl;
	cout<<"\t*0.退出                        *"<<endl;
	cout<<"\t********************************"<<endl;
	char num='\0';
	cout<<"输入选项:";
	cin>>num;
	switch(num)
	{
		case '1':
				db1.addTP();
				break;
		case '2':
				db1.delTP();
				break;
		case '3':
				db1.lookTP();
				break;
		case '4':
				db1.changeTP();
				break;
		case '0':
				return;
		default:
			cout<<"error!"<<endl;
			break;
	}
	}
}
