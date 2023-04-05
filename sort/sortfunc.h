#pragma once

void debugging_init(sortparameter* ss, int* arr);
void sort_init(sortparameter* ss, int* arr);

int checkdigit(sortparameter ss, int* arr, int direction);

void mysortfunc(sortparameter ss, int* arr, int SelectSortMethod);
void bubble(sortparameter ss, int* arr);

void Mergesort(int p, int r, int* arr, int AscDes);
void merge(int* arr, int left, int mid, int right, int AscDes);

void radixtemp_input(int x, int y, int i, int* arr);
void Radixsort2(sortparameter ss, int* arr);
void Radixsort3(sortparameter ss, int* arr, int direction);

void debuggingmsg(int* arr, int size, int AsDs);