#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Input
{
public:
	Input()
	{
		m_strData.clear();
	}
	~Input(){}
	//清空输入设备的数据
	void clearData()
	{
		m_strData.clear();
	}

	void inputData()
	{
		cout << "请输入数据:";
		cin >> m_strData;
	}
	const string &getData()
	{
		return m_strData;
	}
	string dataType()
	{
		string strType = "";
		//m_strData.c_str():返回值为char *，即数据地址
		if (0 == strncmp("ca", m_strData.c_str(), 2))
		{
			strType = "ca";
		}
		else if (0 == strncmp("pa", m_strData.c_str(), 2))
		{
			strType = "pa";
		}
		else if (0 == strncmp("fi", m_strData.c_str(), 2))
		{
			strType = "fi";
		}
		return strType;
	}
private:
	string m_strData;
};


#endif
