#include <threadcopy.h>

int file_block(const char*sfile,int thrno)
{
	int fd=open(sfile,O_RDONLY);
	int fsize=lseek(fd,0,SEEK_END);

	if(fsize % thrno==0)
	{
		return fsize/thrno;	
	}
	else
	{
		return fsize/thrno +1;	
	}
}
