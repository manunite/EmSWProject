#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>

using namespace std;


char* Voca_Mean(void)
{
	struct timeval t;
	gettimeofday(&t,NULL);
	//cout << "HEO" <<endl;
	static char resultProtocol[1000];
	memset(resultProtocol,0x00,sizeof(resultProtocol));
	//char *resultProtocol = (char *)malloc(100);	
	setlocale(LC_ALL, "korean");
	FILE *ppfile = NULL;
	//srand((unsigned)time(NULL) + (unsigned)getpid());
	srand(t.tv_usec);
	char voca[100];
	char mean[100];
	char bound[3];

	memset(resultProtocol,0x00,sizeof(resultProtocol));
	memset(voca,0x00,sizeof(voca));
	memset(mean,0x00,sizeof(mean));
	memset(bound,0x00,sizeof(bound));

	ppfile = fopen("eng.txt","r");
	
	fseek(ppfile,rand()%25000+1,SEEK_SET);
	while(1)
	{
		if(fgetc(ppfile)=='\n')
		{
			break;
		}
	}

	int idx=0;
	char a;

	while((a=fgetc(ppfile)) != '-')
	{
		voca[idx++] = a;
	}
	fgetc(ppfile);
	mean[0]='%';
	idx=1;
	while((a=fgetc(ppfile)) != '\n')
	{
		mean[idx++] = a;
	}

	strcat(resultProtocol,voca);
	strcat(resultProtocol,mean);
	fclose(ppfile);
	return resultProtocol;	
}
