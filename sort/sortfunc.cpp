#define _CRT_SECURE_NO_WARNINGS

#include "sortheader.h"
#include "sortfunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int temp[100000] = { 0, };
int radixtemp[10][100000] = { 0, };
int radixmark = 1;

void mysortfunc(sortparameter ss, int* arr, int SelectSortMethod)
{
	if (SelectSortMethod == BasicSort) // bubble
	{
		bubble(ss, arr);
	}
	if (SelectSortMethod == AdvancedSort)
	{
		ss.mymergey.right = ss.Asccnt - 1;
		Mergesort(0, ss.mymergey.right, arr, Ascending);
		debuggingmsg(arr, ss.arraysize, Ascending);
		ss.mymergey.right = ss.Descnt - 1;
		Mergesort(0, ss.mymergey.right, arr, Descending);
	}
	if (SelectSortMethod == RadixSort)
	{
		Radixsort2(ss, arr);
	}
}

// bubble
void bubble(sortparameter ss, int* arr)
{
	int temp = 0;
	for (int i = ss.Asccnt - 1; i > 0; i--)
	{
		for (int j = 0; j < ss.Asccnt - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	debuggingmsg(arr, ss.arraysize, Ascending);

	for (int i = ss.Descnt - 1; i > 0; i--)
	{
		for (int j = 0; j < ss.Descnt - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}		
}

// Merge
void Mergesort(int left, int right, int* arr, int AscDes) 
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		Mergesort(left, mid, arr, AscDes);
		Mergesort(mid + 1, right, arr, AscDes);
		merge(arr, left, mid, right, AscDes);
	}
}
void merge(int* arr, int left, int mid, int right, int AscDes)
{
	int i = 0, j = 0, k = 0, l = 0;
	if (AscDes == Ascending)
	{
		i = left; j = mid + 1; k = left;
		while (i <= mid && j <= right)
		{
			if (arr[i] <= arr[j])
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		if (i > mid)
		{
			for (l = j; l <= right; l++)
			{
				temp[k++] = arr[l];
			}
		}
		else
		{
			for (l = i; l <= mid; l++)
			{
				temp[k++] = arr[l];
			}
		}
		for (l = left; l <= right; l++)
		{
			arr[l] = temp[l];
		}
	}
	l = 0;
	if (AscDes == Descending)
	{
		i = left; j = mid + 1; k = left;
		while (i <= mid && j <= right)
		{
			if (arr[i] <= arr[j])
				temp[k++] = arr[j++];
			else
				temp[k++] = arr[i++];
		}
		if (i > mid)
		{
			for (l = i; l <= mid; l++)
			{
				temp[k++] = arr[l];
			}
		}
		else
		{
			for (l = i; l <= mid; l++)
			{
				temp[k++] = arr[l];
			}
		}
		for (l = left; l <= right; l++)
		{
			arr[l] = temp[l];
		}
	}
}

// Radix
void radixtemp_input(int x, int y, int i, int* arr)
{
	int check = 0, count = 0;
	while (radixtemp[x][y++] != NULL)
	{
		count++;
	}
	radixtemp[x][count] = arr[i];
}

void Radixsort2(sortparameter ss, int* arr)
{
	int checknumber = 0;
	int AscDes = 0;
	AscDes = ss.Asccnt;
	int x = 0, y = 0;
	ss.RadixBig = checkdigit(ss, arr, ss.Asccnt);

	for (int j = 0; j < ss.RadixBig; j++)
	{
		for (int i = 0; i < AscDes; i++)
		{
			x = (arr[i] / radixmark) % 10;
			radixtemp_input(x, y, i, arr);
		}
		radixmark *= 10;
		Radixsort3(ss, arr, Ascending);
	}
	debuggingmsg(arr, ss.arraysize, Ascending);

	radixmark = 1;
	AscDes = ss.Descnt; ss.direction = Descending;
	x = 0, y = 0;
	ss.RadixBig = checkdigit(ss, arr, ss.Descnt);
	
	for (int j = 0; j < ss.RadixBig; j++)
	{
		for (int i = 0; i < AscDes; i++)
		{
			x = (arr[i] / radixmark) % 10;
			radixtemp_input(x, y, i, arr);
		}
		radixmark *= 10;
		Radixsort3(ss, arr, Descending);
	}
	
}

void Radixsort3(sortparameter ss, int* arr, int direction)
{
	int x = 0, y = 0, i = 0;
	if (direction == Ascending)
	{
		while (i != ss.Asccnt)
		{
			while (radixtemp[x][y] != NULL)
			{
				arr[i] = radixtemp[x][y];
				radixtemp[x][y] = NULL;
				i++; y++;
			}
			x++;
			y = 0;
		}
	}
	
	x = 9, y = 0, i = 0;
	if (direction == Descending)
	{
		while (i != ss.Descnt)
		{
			while (radixtemp[x][y] != NULL)
			{
				arr[i] = radixtemp[x][y];
				radixtemp[x][y] = NULL;
				i++; y++;
			}
			x--;
			y = 0;
		}
	}
	
}

void debugging_init(sortparameter* ss, int* arr)
{
	arr[0] = 4, arr[1] = 300, arr[2] = 10, arr[3] = 100;

	ss->arraysize = 4; ss->set = 1; ss->Asccnt = 3; ss->Descnt = 3;
	ss->direction = Ascending;

	ss->mymergey.left = 0;
	ss->mymergey.right = ss->Asccnt - 1;
}

int checkdigit(sortparameter ss, int* arr, int direction)
{
	int count = 1, check = 10;
	int AscDes = 0;
	AscDes = direction;
	ss.RadixBig = arr[0];

	for (int i = 1; i < AscDes; i++)
	{
		if (ss.RadixBig < arr[i])
		{
			ss.RadixBig = arr[i];
		}
	}
	while (ss.RadixBig / check)
	{
		count++;
		check *= 10;
	}
	return count;
}

void sort_init(sortparameter* ss, int* arr)
{
	int num = 0;
	srand(time(NULL));

	ss->arraysize = 10;//rand() % ArrayIndex + 2; // 2 ~ 100,000 
	printf("배열의 크기 : %d\n", ss->arraysize);
//	printf("원하는 배열의 크기를 입력하세요: ");
//	scanf("%d", &ss->arraysize);
	
// second : parameter
	for (int i = 0; i < ss->arraysize; i++)
	{
		arr[i] = rand() % 100000 + 1; // 1 ~ 100000
	}
	// thrid : set amount
	ss->set = 1;
//	printf("반복 횟수 입력: ");
//	scanf("%d", &ss->set);

	// fourth : [2] = [ascending, descending]
	ss->Asccnt = rand() % ss->arraysize + 2;
	ss->Descnt = rand() % ss->arraysize + 2;
	
	printf("오름차순 index = %d \n", ss->Asccnt);
	printf("내림차순 index = %d \n", ss->Descnt);

//	printf("up down");
//	scanf("%d", &ss->Asccnt); scanf("%d", &ss->Descnt);
}

void debuggingmsg(int* arr, int size, int AsDs)
{
	printf("SORT : ");
	for (int j = 0; j < size; j++)
	{
		printf("%d  ", arr[j]);
	}
	printf("\n");
}