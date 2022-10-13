#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int cat_file(char *filename);

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		//printf("usage: wcat FILE...\n");
		exit(0);
	}

	for(int i = 1; i < argc; i++) 
	{
		int rc = cat_file(argv[i]);
		if(rc != 0)
		{
			printf("wcat: cannot open file\n"); 
			exit(1);

		}
	}
	
	return 0;
}

int cat_file(char *filename)
{
	FILE *fp = fopen(filename, "r");

	if(fp == NULL)
	{
		return 1;
	}

	char buffer[BUFFER_SIZE];
	while(fgets(buffer, 512, fp) != NULL)
	{
		printf("%s", buffer);
	}

	return 0;
}
