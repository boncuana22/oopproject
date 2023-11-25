#include<iostream>
#include<string>
#include<Event.h>

using namespace std;

int main()
{
	Event e1("fcsb-dinamo", "29.01.2023", "20:30");
	cout << e1.getName() << endl;

	
	return 0;
}