/* gcc -ansi -pedantic -std=c11 aoc_2023_1_2.c -o aoc_2023_1_2.out */

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

char what_num(char* _str)
{
	char ret = '.';

	char* zero = "zero";
	char* one = "one";
	char* two = "two";
	char* three = "three";
	char* four = "four";
	char* five = "five";
	char* six = "six";
	char* seven = "seven";
	char* eight = "eight";
	char* nine = "nine";

	if(prefix(zero, _str))
		ret =  '0';
	if(prefix(one, _str))
		ret =  '1';
	if(prefix(two, _str))
		ret =  '2';
	if(prefix(three, _str))
		ret =  '3';	
	if(prefix(four, _str))
		ret =  '4';
	if(prefix(five, _str))
		ret =  '5';
	if(prefix(six, _str))
		ret =  '6';
	if(prefix(seven, _str))
		ret =  '7';
	if(prefix(eight, _str))
		ret =  '8';
	if(prefix(nine, _str))
		ret =  '9';

	return ret;
}


bool is_ascii_num(char _c)
{
	if(ZERO_IN_ASCII <= _c && _c <= NINE_IN_ASCII)
	{
		return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	size_t sum = 0;
	
	if(argc != 2)
	{
		printf("no file attached\n");
		return 0;
	}

	char* filename = argv[1];
	
	FILE* file = fopen(filename, "r");
	if(file == NULL)
	{
		printf("error opening file\n");
		return 0;
	}

    char * line = NULL;
    size_t line_len = 0;
	size_t line_num = 1;
	char left_digit;
	char right_digit;
	char temp_digit;
	
	while (getline(&line, &line_len, file) != -1)
	{
		left_digit = '/';
		right_digit = '/';
		temp_digit = '/';
		
		printf("%ld - ", line_num);
		for(int i=0; i<line_len; i++)
		{
			if(is_ascii_num(line[i]) && left_digit == '/')
			{
				left_digit = line[i];
				continue;
			}
			temp_digit = what_num(&line[i]);
			if( temp_digit >= ZERO_IN_ASCII &&
				temp_digit <= NINE_IN_ASCII && 
				left_digit == '/')
			{
				left_digit = temp_digit;
				continue;
			}
			if(is_ascii_num(line[i]) &&
				left_digit >= ZERO_IN_ASCII &&
				left_digit <= NINE_IN_ASCII)
			{
				right_digit = line[i];
				continue;
			}
			if( temp_digit >= ZERO_IN_ASCII &&
				temp_digit <= NINE_IN_ASCII && 
				left_digit >= ZERO_IN_ASCII &&
				left_digit <= NINE_IN_ASCII)
			{
				right_digit = temp_digit;
				continue;
			}
		}

		printf("%c",left_digit);
		if(right_digit == '/')
		{
			right_digit=left_digit;
		}
		printf("%c",right_digit);
	
		printf("\n"); 
		line_num++;
		line = NULL;

		sum = sum + (left_digit - ZERO_IN_ASCII)*10 + (right_digit - ZERO_IN_ASCII);
    }
	
	printf("\nsum is %ld\n", sum); 
	
	if (line)
	{
		free(line);
	}
	fclose(file);
}