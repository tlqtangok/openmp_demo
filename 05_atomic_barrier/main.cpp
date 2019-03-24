#include <iostream>
#include <omp.h>
#include <cstdio> 

using namespace std; 

#define DEFINE_idx auto idx = omp_get_thread_num();
#define _ROWS (omp_get_num_threads())


int main()
{


	int sum = 0; 
#pragma omp parallel  num_threads(3) 
	{
#pragma omp atomic 
		sum += 10; 
#pragma omp barrier  // TODO : disable this to see 
		cout << sum << endl; 
	}

	return 0; 
}

