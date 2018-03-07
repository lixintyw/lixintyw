#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include<iostream>
#include<string>
using namespace std;

typedef unsigned int uint;

enum ENUM_EMPLOYEE_LEVEL
{
	ENUM_EMPLOYEE_LEVEL_MIN=0,
	ENUM_EMPLOYEE_LEVEL_TECPART,
	ENUM_EMPLOYEE_LEVEL_TECPARTMANA,
	ENUM_EMPLOYEE_LEVEL_SALEPART,
	ENUM_EMPLOYEE_LEVEL_SALEPARTMANA,
	ENUM_EMPLOYEE_LEVEL_BOSS,
	ENUM_EMPLOYEE_LEVEL_MAX=0x00ffffff
};
class Employee
{
	public:
		Employee(string name="NewEmployee",uint level=ENUM_EMPLOYEE_LEVEL_MIN);
		virtual ~Employee();
		void info();
		void modifyPwd();
//		void setBaseId();
		uint getId();
		uint getLevel();
		string &getName();
		string &getPwd();
		string &getNote();
		void work();
//	public:
//		static uint m_baseId;
	private:
		uint m_uiId;
		uint m_uiLevel;
		string m_strName;
		string m_strPwd;
		string m_strNote;
};
#endif
