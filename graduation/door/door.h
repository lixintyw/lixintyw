#ifndef DOOR_H
#define DOOR_H

#include <iostream>
#include <unistd.h>

using namespace std;

class Door
{
public:
	void open()
	{
		cout << "door is openning..." << endl;
		sleep(3);
		cout << "door is closing..." << endl;
	}
};


#endif
