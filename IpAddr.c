
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
char *strk;
char s[2]=" ";
FILE *fp;

char returnData[64];

fp = popen("/sbin/ifconfig | awk '/^eth/{s=$1;getline;print $1,$2}'", "r");

while (fgets(returnData, 64, fp) != NULL)
{
  strk=strtok (returnData,s);
	while(strk!=NULL)
	{
	  printf ("%s\n",strk); 
	  strk=strtok (NULL,s);
	
	}
 }
pclose(fp);

}
