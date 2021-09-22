#include <iostream>

union Var {

int varInt;
float varFloat;
char varChar;
int *varPoint;

};


int main()
{
	Var v;
	
	int num = 64;

 	v.varInt = 12;
 	v.varFloat = 7;
	v.varChar = 'b';
	v.varPoint = &num;

 	std::cout << "int: " << v.varInt << std::endl;
 	std::cout << "float: " << v.varFloat << std::endl;
	std::cout << "char: " << v.varChar << std::endl;
	std::cout << "Pointer: " << *v.varPoint << std::endl;
	return 0;

}
