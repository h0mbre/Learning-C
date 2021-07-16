#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	int filedescriptor;

	filedescriptor = open("testfile.txt", O_WRONLY | O_CREAT, S_IRWXU);

	if (filedescriptor < 0)
	{
		printf("The open operation failed...");
		return -1;
	}
	else 
	{
		printf("The open operation succeeded!\n");
		
	}

	char buf[] = "Writing test data to the file";
	int writertn;
	
	writertn = write(filedescriptor, buf, sizeof(buf)/sizeof(char));

	if (writertn != sizeof(buf)/sizeof(char))
	{
		printf("The write operation failed...");
		return -1;
	}
	else
	{
		printf("The write operation succeeded!");
	}

	if (close(filedescriptor) != 0)
	{
		printf("The close operation failed...");
		return -1;
	}

	return 0;

}


