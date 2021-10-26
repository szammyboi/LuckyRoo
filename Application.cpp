#include "LuckyRoo.h"
#include <iostream>

void test()
{
	std::cout << "TEST BINDING" << std::endl;
}

int main()
{
	LCKYROO::Controller::Bind<DIGITAL_A>(test);
	LCKYROO::Controller::Update();
	LCKYROO::Controller::Retrieve(DIGITAL_A)->Update();
}