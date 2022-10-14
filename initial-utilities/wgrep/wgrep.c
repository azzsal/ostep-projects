#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_file(char *searchterm, FILE *fp);

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}

	if(argc == 2)
	{
		search_file(argv[1], stdin);
		exit(0);
	}

	for(int i = 2; i < argc; i++)
	{
		FILE *fp = fopen(argv[i], "r");
		if(!fp)
		{
			printf("wgrep: cannot open file\n");
			exit(1);
		}
		search_file(argv[1], fp);
	}

	return 0;

}

void search_file(char *searchterm, FILE *fp)
{
	char *lineptr = NULL;
	size_t len = 0;
	while(getline(&lineptr, &len, fp) != -1)
	{
		if(strstr(lineptr, searchterm) != NULL)
		{
			printf("%s", lineptr);
		}
	}

	free(lineptr);
	fclose(fp);
}
