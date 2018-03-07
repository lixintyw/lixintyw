#include"tecpart.h"

TecPart::TecPart(string name,uint level,uint payhour,uint leaderId):Employee(name,level)
{
	m_WorkHour=0;
	m_PerHourPay=payhour;
	m_uiLeaderId=leaderId;
}
TecPart::~TecPart(){}
void TecPart::info()
{}
void TecPart::setWorkHour()
{}
uint TecPart::getWorkHour()
{
	return m_WorkHour;
}
uint TecPart::getPerHourPay()
{
	return m_PerHourPay;
}
uint TecPart::getLeaderId()
{
	return m_uiLeaderId;
}
void TecPart::work(uint id)
{
	while(1)
	{
//	db3.time();
	cout<<"\t           welcome!"<<endl;
	cout<<"\t******************************"<<endl;
	cout<<"\t*1.查看信息 2.修改密码 0.退出*"<<endl;
	cout<<"\t******************************"<<endl;
	cout<<"输入选项:";
	char num='\0';
	cin>>num;
	switch(num)
	{
		case '1':
				db3.lookTP(id);
				cout<<id<<endl;
				break;
		case '2':
				db3.changePwdTp();
				break;
		case '0':
				return;
		default:
				cout<<"请输入正确选项\n";
				break;
	}
	}

}
