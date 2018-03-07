#include "system.h"

void DoorSystem::work()
{
	const string &str = m_input.getData();
	if (!str.empty())
	{
		string strType = m_input.dataType();
		if (m_computer.check(str, strType))
		{
			m_door.open();
		}
		else
		{
			cout << "密码/门卡/指纹不对...\n";
		}
		m_input.clearData();
	}

	if (m_open)  //大爷按了开门按钮
	{
		m_door.open();
		m_open = false;
	}
}




