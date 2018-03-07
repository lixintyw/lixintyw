#ifndef BICYCLE_H_
#define BICYCLE_H_

#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;

enum ENUM_BICYCLE_STATE
{
	ENUM_BICYCLE_STATE_MIN = 0,
	ENUM_BICYCLE_STATE_INIT,
	ENUM_BICYCLE_STATE_BORROWED,
	ENUM_BICYCLE_STATE_DAMAGED,
	ENUM_BICYCLE_STATE_MAX = 0x00ffffff
};

class Bicycle
{
	public:
		Bicycle();
		virtual ~Bicycle();

		uint getBicyeleId();
		uint getBicycleState();//����״̬
		string &getBicycleBorrowedInfo();//����ʻ��¼
		string &getBicycleRepairedInfo();//ά�޼�¼
		
	private:
		uint BicycleId;
		uint BicycleState;
		string BicycleBorrowedInfo;
		string BicycleRepairedInfo；
};

#endif
