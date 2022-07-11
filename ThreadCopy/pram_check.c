#include <threadcopy.h>


void pram_check(int argc,const char*sfile,int thrno)
{
	if(argc<3)
	{
		printf("too few pram\n");	
		exit(0);
	}
	if((access(sfile,F_OK))!=0)
	{
		printf("bad source file\n");
		exit(0);
	}
	if(thrno<=0||thrno>100)
	{
		printf("bad thread number\n");
		exit(0);
	}
}
