#include <iostream>
#include <string>
#include <string.h>
#include <Event.h>

using namespace std;

int main()
{
	Event e1("fcsb-dinamo", "29.01.2023", "20:30");
	e1.setType(handball_game);

	cout << e1.getName();
	cout << endl;
	cout << e1.getType();
	cout << e1.getTime();
	cout << endl;

	return 0;
}