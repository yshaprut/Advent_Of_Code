/* gcc -ansi -pedantic -std=c11 aid_func.c -o aid_func.out */

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define ZERO_IN_ASCII 48
#define NINE_IN_ASCII 57

bool prefix(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

int what_num(char* _str)
{
	int ret = -1;

	char* one = "one";
	char* two = "two";
	char* three = "three";
	char* four = "four";
	char* five = "five";
	char* six = "six";
	char* seven = "seven";
	char* eight = "eight";
	char* nine = "nine";

	if(prefix(one, _str))
		ret =  1;
	if(prefix(two, _str))
		ret =  2;
	if(prefix(three, _str))
		ret =  3;	
	if(prefix(four, _str))
		ret =  4;
	if(prefix(five, _str))
		ret =  5;
	if(prefix(six, _str))
		ret =  6;
	if(prefix(seven, _str))
		ret =  7;
	if(prefix(eight, _str))
		ret =  8;
	if(prefix(nine, _str))
		ret =  9;

	return ret;
}

int main(int argc, char* argv[])
{
	char* str = "nine9one3";

	int num = what_num(str);

	printf("num -> %d\n", num);

	return 0;
}