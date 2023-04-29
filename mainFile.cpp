#include<iostream>
using namespace std;
typedef unsigned short int usi;
#include<conio.h>
#include"Header.h"

void main() {

	Teacher CA(new char[] {"Cavid"}, new char[] {"Atamoghlanov"}, Date(21, 8, 1998));
	Student JR(new char[] {"Jake"}, new char[] {"Robert"}, Date(30, 4, 1995),CA);
	JR.givePoint(CA);
}
