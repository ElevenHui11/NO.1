#include <threadcopy.h>

#include <pthread.h>
typedef struct
{
	char*sfile;
	char*dfile;
	int blocksize;
	int offset;
}P,*PP;
void *jobs(void*pram)
{
		PP pr=(PP)pram;
		printf("tid=0x%x,offset=%d\n",(unsigned int)pthread_self(),pr->offset);
		copy(pr->sfile,pr->dfile,pr->blocksize,pr->offset);
}
void thread_create(pthread_attr_t* attr,const char*sfile,const char*dfile,int blocksize,int thrno)
{

	pthread_t tid;
	int flags=0;
	int err;
	printf("thrno=%d",thrno);
	for(flags;flags<thrno;flags++)
	{
		int offset;
		P pram;
		pram.sfile=sfile;
		pram.dfile=dfile;
		pram.blocksize=blocksize;
		offset=flags*blocksize;
		pram.offset=offset;
		printf("flags=%d,offset:%d\n",flags,pram.offset);
		if((err=pthread_create(&tid,attr,jobs,(void*)&pram)>0))
		{
			
			printf("thread create error:%s\n",strerror(err));
			exit(0);
		}
		sleep(1);
	}
}
