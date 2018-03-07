#include <iostream>
using namespace std;

class StaticTest 
{
	public:
		StaticTest()
		{
			test++;
		}
		
		void print()
		{
			cout << "test number is :" << test << endl;
		}
	private:
		static int test;
};

int StaticTest::test = 10000;

int main()
{
	StaticTest a;
	a.print();

	StaticTest b;
	b.print();
	StaticTest c;
	c.print();
	return 0;
}


