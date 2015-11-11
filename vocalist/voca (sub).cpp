#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "korean");
	FILE *ppfile = NULL;
	srand(time(NULL) + (unsigned)getpid());
	
	char voca[60];
	char mean[60];
	char bound[3];

	memset(voca,0x00,sizeof(voca));
	memset(mean,0x00,sizeof(mean));

	ppfile = fopen("eng.txt","r");
	
	fseek(ppfile,rand()%20000+1,SEEK_SET);
	while(1)
	{
		if(fgetc(ppfile)=='\n')
		{
			break;
		}
	}
	//fseek(ppfile,1,SEEK_CUR);
	/*while(fscanf(ppfile,"%s %s %s",voca,bound,mean) > 0)
	{
		cout << "추출된 영단어는 " << voca << endl;
		cout << "뜻은 " << mean << endl;
		break;
	}*/

	int idx=0;
	char a;

	while((a=fgetc(ppfile)) != '-')
	{
		voca[idx++] = a;
	}
	fgetc(ppfile);
	idx=0;
	while((a=fgetc(ppfile)) != '\n')
	{
		mean[idx++] = a;
	}

	cout << "추출된 영단어는 " << voca << endl;
	cout << "뜻은 " << mean << endl;
}
