#include <iostream>
#include "hasher/encryptor.h"
#include "hasher/decryptor.h"

int main()
{
	Encryptor e;

	e.setPassword("qwerty1");

	std::string hash = e.hash("Hello, World!");

	std::cout << hash << std::endl;

	Decryptor d;

	d.setPassword("qwerty1");

	std::cout << d.hash(hash) << std::endl;
	
	return 0;
}