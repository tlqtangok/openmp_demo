#include <iostream>
using namespace std; 

int main()
{

#if _OPENMP
	cout << " support openmp " << endl; 
#else
	cout << " not support openmp" << endl; 
#endif
	return 0; 
}
