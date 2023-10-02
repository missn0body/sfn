// let's make 8.3 filenames!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *VERSION = "1.0.0";
void usage(void)
{
	fprintf(stderr, "\"sfn\" (Short FileName) by anson: version %s\nusage: sfn.exe <string>\n", VERSION);
}

// remember to free the return value of this function!
char *sfn(char *input)
{
	char *returnValue = malloc(9), *ext = malloc(5), *read, *write;
	if(!returnValue || !ext) { perror("sfn"); exit(EXIT_FAILURE); }

	strncpy(returnValue, input, (strcspn(input, ".") <= 8) ? strcspn(input, ".") : 6);

	read = returnValue, write = returnValue;
	while(*read)
	{
		*write = toupper((unsigned char)*read++);
		write += isalnum((int)*write);
	}

	*write = '\0';
	if(strcspn(input, ".") > 8) strcat(returnValue, "~1");

	if(strrchr(input, '.'))
	{
		sprintf(ext, ".%-.3s", strrchr(input, '.') + 1);
		ext[strcspn(ext, " ")] = '\0';

		for(int i = 1; isalpha((int)ext[i]) || i < 5; i++) { ext[i] = toupper(ext[i]); }
	}
	else strncpy(ext, ".TMP", 5);

	strcat(returnValue, ext);
	free(ext);

	return returnValue;
}

int main(int argc, char *argv[])
{
	if(argc < 2 || !*argv[1]) { atexit(usage); exit(EXIT_FAILURE); }

	char *prev = malloc((sizeof(char) * strlen(argv[1])) + 1);
	strncpy(prev, argv[1], strlen(argv[1]));
	char *buffer = sfn(argv[1]);

	if(buffer == NULL) { perror("sfn"); exit(EXIT_FAILURE); }
	printf("\"%s\" is now \"%s\".\n", prev, buffer);
	free(buffer);

	exit(EXIT_SUCCESS);
}
