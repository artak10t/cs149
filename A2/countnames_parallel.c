/**
* Description: Count repeating names from the file in parallel
* Author Names: Spartak Gevorgyan, Shadi Abd El Majid
* Author Emails: spartak.gevorgyan@sjsu.edu, shadi.abdelmajid@sjsu.edu
* Last Modified Date: 3/5/2023
* Creation Date: 3/5/2023
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define NAME_LENGTH 30
#define NAMES 100

int pipedir[2];
char names[NAMES][NAME_LENGTH];
int names_count[NAMES];
int line = 0;

/**
* Compute the names and pass through pipe
* Assumption: File exists
* Input Parameters: Filename
* Returns: None
**/
void processFile(char* filename)
{
	//Open file, if doesn't exist
	//Print error and exit process
	FILE *f = fopen(filename, "r");
	if(f == NULL)
	{
		fprintf(stderr, "Error - File %s doesn't exist\n", filename);
		close(pipedir[0]);
		fclose(f);
		exit(1);
	}

	//Go over file line by line
	char current_name[NAME_LENGTH];
	while(fgets(current_name, NAME_LENGTH, f))
	{
		//If new line character at the end
		//Replace with null character
		char* ptr = strchr(current_name, '\n');

		if(ptr)
			*ptr = '\0';

		//In case of empty line print warning
		if(strlen(current_name) == 0)
		{
			fprintf(stderr, "Warning - File %s line %i is empty\n", filename, line);
			continue;
		}

		strcpy(names[line], current_name);
		line++;
	}

	fclose(f);

	//Pipe names and lines into main process
	close(pipedir[0]);
	write(pipedir[1], &line, sizeof(line));
	write(pipedir[1], names, sizeof(names));

	//Terminate process
	exit(0);
}

/**
* Creates separate processes for each file and output names count
* Assumption: File exists and is provided as an argument
* Input Parameters: Filenames
* Returns: List of individual names and repetitions
**/
int main(int argc, char **argv)
{
	//Verify if argument with filename is given
	//Else output error
	if(argc == 1)
	{
		fprintf(stderr, "Error - Enter filename as an argument\n");
		exit(1);
	}

	//Open the pipe
	if(pipe(pipedir) == -1)
	{
		fprintf(stderr, "Error - Pipe failed");
		exit(1);
	}

	//Fork processes for each file
	for(int i = 1; i < argc; i++)
	{
		int k = fork();

		if(k < 0)
		{
			fprintf(stderr, "Error - Unable to fork");
			exit(1);
		}
		else if(k == 0)
		{
			//In case of successful fork
			//Call processFile in child
			processFile(argv[i]);
			break;
		}
	}

	int status;
	//Wait until all processes are done
	while(wait(&status) > 0)
	{
		if(status != 0)
			continue;

		int line_r;
		char names_r[NAMES][NAME_LENGTH];

		//Read pipe from childs
		close(pipedir[1]);
		read(pipedir[0], &line_r, sizeof(line_r));
		read(pipedir[0], names_r, sizeof(names));

		for(int i = 0; i < line_r; i++)
		{
			if(strlen(names[line]) == 0)
			{
				strcpy(names[line], names_r[i]);
			}
			else
			{
				i--;
			}
			line++;
		}
	}

	for(int i = 0; i < NAMES; i++)
		names_count[i] = -1;

	//Goes over names and finds the count
	for(int i = 0; i < line; i++)
	{
		int count = 1;
		for(int j = i + 1; j < line; j++)
		{
			if(strcmp(names[i], names[j]) == 0)
			{
				count++;
				names_count[j] = 0;
			}
		}
		if(names_count[i] != 0)
			names_count[i] = count;
	}

	//Print names
	for(int i = 0; i < line; i++)
		if(names_count[i] != 0)
			fprintf(stdout, "%s: %d\n", names[i], names_count[i]);

	return 0;
}
