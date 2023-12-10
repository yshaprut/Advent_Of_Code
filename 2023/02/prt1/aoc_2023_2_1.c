/* gcc -ansi -pedantic -std=c11 aoc_2023_2_1.c -o aoc_2023_2_1.out */

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define ZERO_IN_ASCII 48
#define NINE_IN_ASCII 57

#define IS_GREEN 0
#define IS_RED 1
#define IS_BLUE 2
#define NOT_COLOR 3

#define CUBES_GREEN 13
#define CUBES_RED 12
#define CUBES_BLUE 14

#define YES 1
#define NO 0

bool prefix(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

int what_color(char* _str)
{
	char* green = "green";
	char* red = "red";
	char* blue = "blue";

	if(prefix(green, _str))
		return IS_GREEN;
	if(prefix(red, _str))
		return IS_RED;
	if(prefix(blue, _str))
		return IS_BLUE;
	
	return NOT_COLOR;
}


size_t get_ascii_num(char _a, char _b)
{
	if(ZERO_IN_ASCII <= _a && _b <= NINE_IN_ASCII)
	{
		return  (_a - ZERO_IN_ASCII)*10 +
				(_b - ZERO_IN_ASCII);	
	}

	return  (_b - ZERO_IN_ASCII);
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
	
	size_t blue_num;
	size_t red_num;
	size_t green_num;

	int is_possible_game;

	while (getline(&line, &line_len, file) != -1)
	{
		blue_num = 0;
		red_num = 0;
		green_num = 0;
		is_possible_game = YES;

		printf("%ld - ", line_num);
		for(int i=0; i<line_len; i++)
		{
			switch (what_color(&line[i]))
			{
			case IS_BLUE:
				blue_num = get_ascii_num(line[i-3],line[i-2]);
				printf("%ld, ", blue_num);
				if(CUBES_BLUE < blue_num)
					is_possible_game = NO;
				break;
			
			case IS_RED:
				red_num = get_ascii_num(line[i-3],line[i-2]);
				printf("%ld, ", red_num);
				if(CUBES_RED < red_num)
					is_possible_game = NO;
				break;
			case IS_GREEN:
				green_num = get_ascii_num(line[i-3],line[i-2]);
				printf("%ld, ", green_num);
				if(CUBES_GREEN < green_num)
					is_possible_game = NO;
				break;
			
			default:
				break;
			}

			if(is_possible_game == NO)
				break;
		}

		if(is_possible_game == YES)
				printf("YES"); 

		if(is_possible_game == NO)
				printf("NO"); 
		
		if(is_possible_game == YES)
			sum += line_num;

		printf("\n"); 

		line_num++;
		line = NULL;
    }

	printf("sum is %ld\n", sum); 
	
	if (line)
		free(line);
	
	fclose(file);
}