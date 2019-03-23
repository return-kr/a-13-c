#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encryption (void);
void decryption (void);

FILE *wfile, *rfile;

int main(){
	int n;
	printf("\n1. enryption\n2. decryption\n\n");
	scanf("%d", &n);
	if(n==1)
		encryption();
	else if(n==2)
		decryption();
	else
		exit(0);
	return 0;
}

void encryption (void){
	int i=0,asc,key;
	int plen,flen;
	char name[50],c,temp[200];
	printf("file name\n");
	scanf("%s", name);
	wfile=fopen(name,"w");
	fflush(stdin);
	printf("enter encryption key\n");
	scanf("%d", &key);
	printf("enter password\n");
	getchar();
	while((c=getchar())!='\n'){
		temp[i]=c;
		++i;
	}
	flen=strlen(name);
	plen=strlen(temp);
	for(i=0;i<plen;i++){
		asc=temp[i]+((plen+flen)+(i+1)+(2*(key/(i+1))));
		putc(asc,wfile);
	}
	fclose(wfile);
	fflush(stdin);
	printf("encryption done\n");
}

void decryption (void){
	int i,asc,key;
	int flen,plen;
	char temp[200],name[50];
	printf("file name\n");
	scanf("%s", name);
	printf("enter the key\n");
	scanf("%d", &key);
	fflush(stdin);
	rfile=fopen(name,"r");
	flen=strlen(name);
	fgets(temp,200,rfile);
	plen=strlen(temp);
	printf("the password is down below\n");
	for(i=0;i<plen;i++){
		asc=temp[i]-((plen+flen)+(i+1)+(2*(key/(i+1))));
		printf("%c",asc);
	}
	fclose(rfile);
	fflush(stdin);
	printf("\ndecryption done\n");
}
