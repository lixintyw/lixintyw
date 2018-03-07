#include"boss.h"
#include"time.h"
Boss::Boss(string name):TecPartMana(name),SalePartMana(name),Employee(name,ENUM_EMPLOYEE_LEVEL_BOSS)
{}
Boss::~Boss(){}

void Boss::work()
{
	while(1)
	{
	db.time();
	cout<<"\t\tWelcome Boss\n"<<endl;
	cout<<"\t*********************************"<<endl;
	cout<<"\t*1.添加技术经理 * 2.删除技术经理*"<<endl;
	cout<<"\t*3.查找技术经理 * 4.修改技术经理*"<<endl;
	cout<<"\t*********************************"<<endl;
	cout<<"\t*5.更新技术人员 * 6.更新销售人员*"<<endl;
	cout<<"\t*********************************"<<endl;
	cout<<"\t*7.添加销售经理 * 8.删除销售经理*"<<endl;
	cout<<"\t*9.查找销售经理 * x.修改销售经理*"<<endl;
	cout<<"\t*0.退出         * y.显示所有员工*"<<endl;
	cout<<"\t*********************************"<<endl;
	cout<<"输入选项:";
	char num='\0';
	cin>>num;
	switch(num)
	{
		case '1':
				db.addTPMA();
				break;
		case '2':
				db.delTPMA();
				break;
		case '3':
				db.lookTPMA();
				break;
		case '4':
				db.changeTPMA();
				break;
		case '5':
				work1();
				break;
		case '6':
				work2();
				break;
		case '7':
				db.addSPMA();
				break;
		case '8':
				db.delSPMA();
				break;
		case '9':
				db.lookSPMA();
				break;
		case 'x':
				db.changeSPMA();
				break;
		case 'y':
				db.PALL();
				break;
		case '0':
				return;
				break;
		default:
				cout<<"请输入正确选项"<<endl;
	}
	}
}
void work1()
{
    Boss s;
	while(1)
	{
	s.db.time();
	cout<<"			   welcome!"<<endl;
	cout<<"\t*******************************"<<endl;
	cout<<"\t*1.添加技术人员\t2.删除技术人员*"<<endl;
	cout<<"\t*3.查找技术人员\t4.修改技术人员*"<<endl;
	cout<<"\t*0.退出                        *"<<endl;
	cout<<"\t*******************************"<<endl;
	char num='\0';
	cout<<"输入选项:";
	cin>>num;
	switch(num)
	{
		case '1':
				s.db.addTP();
				break;
		case '2':
				s.db.delTP();
				break;
		case '3':
				s.db.lookTP();
				break;
		case '4':
				s.db.changeTP();
				break;
		case '0':
				s.work();
		default:
			cout<<"error!"<<endl;
			break;
	}
	}
}
void work2()
{
	Boss s1;
	while(1)
	{
	s1.db.time();
	cout<<"\twelcome!"<<endl;
	cout<<"\t*********************************"<<endl;
	cout<<"\t*1.添加销售人员\t2.删除销售人员*"<<endl;
	cout<<"\t*3.查找销售人员\t4.修改销售人员*"<<endl;
	cout<<"\t*0.退出                        *"<<endl;
	cout<<"\t*********************************"<<endl;
	cout<<"输入选项:";
	char num='\0';
	cin>>num;
	switch(num)
	{
		case '1':
				s1.db.addSP();
				break;
		case '2':
				s1.db.delSP();
				break;
		case '3':
				s1.db.lookSP();
				break;
		case '4':
				s1.db.changeSP();
				break;
		case '0':
				return;	
		default:
				cout<<"error"<<endl;
				break;
	}
	}
}
