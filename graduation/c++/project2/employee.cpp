#include"employee.h"
Employee::Employee(string name,uint level)
{
	m_strName=name;
	m_uiLevel=level;
//	m_uiId=m_baseId;
	m_strPwd="123456";
	m_strNote="表现良好!";
}
Employee::~Employee(){}
void Employee::info()
{
}
void Employee::modifyPwd()
{

}
//void Employee::setBaseId()
//{}
uint Employee::getId()
{
	return m_uiId;
}
uint Employee::getLevel()
{}
string &Employee::getName()
{}
string &Employee::getPwd()
{}
string &Employee::getNote()
{}

void Employee::work()
	
{
	cout<<"welcome to sys C\n";
	cout<<"1.打印信息\t2.修改密码\n";
}
//uint Employee::m_baseId=1000; 
