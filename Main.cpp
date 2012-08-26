#include <iostream>
#include <functional>
#include <string>

int main()
{
	char* basePassword = new char[128];
	char* siteName = new char[128];
	char* dobYear = new char[128];

	std::cout << "Enter base password:" << std::endl;
	std::cin.getline(basePassword,128);

	std::cout << "Enter site name:" << std::endl;
	std::cin.getline(siteName,128);

	std::cout << "Enter the year you were born in:" << std::endl;
	std::cin.getline(dobYear,128);

	std::cout << "Calculating hash based on " << basePassword << " and " << siteName << " and " << dobYear << std::endl;

	std::string toHash = basePassword;
	toHash.append(siteName);

	std::hash<std::string> hashFunction;
	size_t hashed = hashFunction(toHash);

	//Make the password longer with bit manip
	int lA = dobYear[0] - '0';
	int rA = dobYear[1] - '0';
	int lB = dobYear[2] - '0';
	int rB = dobYear[3] - '0';

	size_t leftShiftA = hashed << lA;
	size_t rightShiftA = hashed >> rA;
	size_t leftShiftB = hashed << lB;
	size_t rightShiftB = hashed >> rB;

	std::cout << "Unique password: " << std::hex << hashed << 
									    std::hex << leftShiftA << 
										std::hex << rightShiftA <<
										std::hex << leftShiftB << 
										std::hex << rightShiftB << std::endl;

	return 0;
}