#pragma once

#define BasicSort			1
#define AdvancedSort		2
#define RadixSort			3

#define SelectedSort		AdvancedSort

#define smaller				1
#define bigger				2

#define Ascending			1
#define Descending			2

#define debugging			0

#define ArrayIndex			10

typedef struct
{
	int left;
	int right;
}Mergyparameter;

typedef struct
{
	int arraysize;
	int set;
	int Asccnt;
	int Descnt;
	int direction;
	int RadixBig;
	Mergyparameter mymergey;
}sortparameter;