#include <iostream>
#include <omp.h>

using namespace std; 

int main()
{

#if 0
// TODO : this is incorrect way to reduce !!!
	int sum = 0;
	#pragma omp parallel for num_threads(33)
	for(int i=0; i<100; i++)
	{
		sum +=  i; 
	}

	cout << sum << endl; 

#endif 

#if 1 

	int sum = 0;
	#pragma omp parallel for num_threads(32) reduction(+:sum)
	for(int i=0; i<100; i++)
	{
		sum +=  i; 
	}

	cout << sum << endl; 

#endif 
	
	return 0; 
}

