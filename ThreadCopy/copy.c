#include <threadcopy.h>


void copy(const char*sfile,const char*dfile,int block_size,int offset)
{
	char buffer[block_size];
	bzero(buffer,sizeof(buffer));
	ssize_t readlen;
	int sfd=open(sfile,O_RDONLY);
	int dfd=open(dfile,O_RDWR|O_CREAT,0664);


	lseek(sfd,offset,SEEK_SET);
	lseek(dfd,offset,SEEK_SET);
	readlen=read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,readlen);
	close(sfd);
	close(dfd);
	return 0;
}
