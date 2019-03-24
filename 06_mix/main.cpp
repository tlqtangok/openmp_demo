#include <iostream>
#include <omp.h>
#include <vector>
#include <cstdio> 
#include <cmath>
#include <algorithm>
#include <time.h>
#include <sys/time.h>



using namespace std; 

#define DEFINE_idx auto idx = omp_get_thread_num();
#define _ROWS (omp_get_num_threads())


int main()
{

	auto diff_in_seconds_jd = [](timeval *end, timeval *start)
	{
		double sec;
		sec=(end->tv_sec - start->tv_sec);
		sec+=(end->tv_usec - start->tv_usec)/1e6;
		return sec;
	};

	struct timeval start, end;

	vector<int> v_i{}; 

	int len = int(1e7); 
	v_i.resize(len); 
	vector<int> v_ans {}; 
	v_ans.resize(len); 
	

	for(int i=0;i<len;i++)
	{
		v_i[i] = i; 	
	}

	int cnt_ans = 0; 

	v_i[len - 1] = 2; 

	gettimeofday (&start, NULL);  // time start
	
#pragma omp parallel for reduction(+:cnt_ans) default(shared)  num_threads(10)
        for(int i=0; i<len; i++)
	{
		auto &e = v_i[i]; 
		int t = 0; 

		if ( i < len / 2)
		{
			t = pow(e, 2); 
		}	
		else 
		{
			t = (int)sqrt(e); 
		}
		if ( t % 2 == 1)
		{
			cnt_ans += 1;
		}
	}
	
	gettimeofday (&end, NULL); // time end
	auto time_used = diff_in_seconds_jd(&end, &start); 
	printf("- time used:\t%f seconds\n", time_used); 

	cout << "- size of v_ans:\t" << cnt_ans << endl; 


	for(auto &e : v_ans)
	{
		//cout << e << endl; 
	}



	return 0; 
}

