#include<stdio.h>
/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc,char** argv)
{
	puts("2023 Developed by Soham Mane");
	puts("LispScript Version 0.0.1");
	puts("Press Ctrl+c to Exit");
	puts("############################\n");
	while(1)
	{
		fputs("LispScript>>",stdout);
		fgets(input,2048,stdin);
		printf("You entered %s\n",input);
	}
	return 0;
}