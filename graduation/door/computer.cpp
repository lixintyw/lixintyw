#include "computer.h"

CComputer::CComputer()
{}
CComputer::~CComputer()
{}
void CComputer::addData(string data, string sign)
{
	if ("pa" == sign)  //密码
	{
		m_pwdList.push_back(data);
	}
	else if ("ca" == sign)  //门卡
	{
		m_cardList.push_back(data);
	}
	else if ("fi" == sign)  //指纹
	{
		m_fingerList.push_back(data);
	}
}

const LIST & CComputer::getPwdList()
{
	return m_pwdList;
}
const LIST & CComputer::getCardList()
{
	return m_cardList;
}
const LIST & CComputer::getFingerList()
{
	return m_fingerList;
}




