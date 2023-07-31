#include<stdio.h>
/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc,char** argv)
{
	puts("2023 Developed by Soham Mane\nLispy Version 0.0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1)
	{
		fputs("lispy>>",stdout);
		fgets(input,2048,stdin);
		printf("No your are a %s\n",input);
	}
	return 0;
}