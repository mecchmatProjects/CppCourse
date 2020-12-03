
#include "Array.h"
 
int main()
{
	Array<int> intArray(10);
	Array<double> doubleArray(10);
 
	for (int count = 0; count < intArray.getLength(); ++count)
	{
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
	}
 
	for (int count = intArray.getLength()-1; count >= 0; --count)
		std::cout << intArray[count] << "\t" << doubleArray[count] << '\n';
 
	return 0;
}

