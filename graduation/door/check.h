#ifndef CHECK_H
#define CHECK_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Check
{
public:
	virtual bool check(const string &str
				       , const list<string> &l) = 0;
private:
};
//密码验证类
class PwdCheck: public Check
{
public:
	static PwdCheck &getInstance()
	{
		static PwdCheck pwdCheck;
		return pwdCheck;
	}

	bool check(const string &str, const list<string> &l)
	{
		cout << "pwd check" << endl;
		bool bOk = false;
		list<string>::const_iterator iter;
		iter = l.begin();
		for (; iter != l.end(); iter++)
		{
			if (str == *iter)
			{
				bOk = true;
				break;
			}
		}
		return bOk;
	}
private:
};
//门卡验证类
class CardCheck: public Check
{
public:
	static CardCheck &getInstance()
	{
		static CardCheck cardCheck;
		return cardCheck;
	}
	bool check(const string &str, const list<string> &l)
	{
		cout << "card check" << endl;
		bool bOk = false;
		list<string>::const_iterator iter;
		iter = l.begin();
		for (; iter != l.end(); iter++)
		{
			if (str == *iter)
			{
				bOk = true;
				break;
			}
		}
		return bOk;
	}
private:
};
//指纹验证类
class FingerCheck: public Check
{
public:
	static FingerCheck &getInstance()
	{
		static FingerCheck fingerCheck;
		return fingerCheck;
	}
	bool check(const string &str, const list<string> &l)
	{
		cout << "finger check" << endl;
		bool bOk = false;
		list<string>::const_iterator iter;
		iter = l.begin();
		for (; iter != l.end(); iter++)
		{
			if (str == *iter)
			{
				bOk = true;
				break;
			}
		}
		return bOk;
	}
private:
};

#endif
