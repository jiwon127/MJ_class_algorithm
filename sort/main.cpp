#include <stdio.h>
#include "sortheader.h"
#include "sortfunc.h"

#define ArrayNUM		100000

int arr[ArrayNUM];


sortparameter mysort;


int main(void)
{
#if (debugging == 0 )
	sort_init(&mysort, arr);
	debuggingmsg(arr, mysort.arraysize, Ascending);
#elif (debugging == 1)
	debugging_init(&mysort, arr);
#endif

	for (int i = 1; i <= mysort.set; i++)
	{
		mysortfunc(mysort, arr, SelectedSort);
		debuggingmsg(arr, mysort.arraysize, Ascending);
	}
	return 0;
}