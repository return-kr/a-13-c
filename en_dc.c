// If u are in Linux then ignore the WARNING against gets() :





#include<stdio.h>

#include<stdlib.h>

#include<string.h>



void encryption (void);

void decryption (void);



FILE *wfile,*rfile;



int main(){

    int n;

xy:

    printf("enter choice\n\n");

    printf("1. encryption\n2. decryption\n");

    scanf("%d", &n);

    if(n==1)

        encryption();

    else if(n==2)

        decryption();

    else{

        printf("Wrong case \ntry again\n");

        goto xy;

    }

return 0;

}



void encryption (void){

    char temp[200],pass[200],ch[50];

    int i=0,fk,sk;

    int plen;

    printf("enter the file name\n");

    scanf("%s",ch);

    printf("enter first key (1 - 9)\n");

    scanf("%d", &fk);

    printf("enter the second key (1 - 9)\n");

    scanf("%d", &sk);

    wfile=fopen(ch,"w");

    printf("enter your password\n");

    fflush(stdin);

    gets(temp);

    fflush(stdin);

    plen=strlen(temp);

    for(i=0;i < plen;i++)

        pass[i]=temp[i]+(2*(fk-i)-2*(sk-i));

    for(i=0;i < plen;i++)

        putc(pass[i],wfile);

    fclose(wfile);

    printf("successfully encrypted\n");

}



void decryption (void){

    char ch[50],temp[200],pass[200];

    int plen;

    int i=0,fk,sk;

    printf("enter the file name\n");

    scanf("%s", ch);

    fflush(stdin);

    printf("enter the first key (1 - 9)\n");

    scanf("%d", &fk);

    printf("enter the second key (1 - 9)\n");

    scanf("%d", &sk);

    rfile=fopen(ch,"r");

    fgets(temp,200,rfile);

    plen=strlen(temp);

    for(i=0;i < plen;i++){

        pass[i]=temp[i]-(2*(fk-i)-2*(sk-i));

        if(pass[i]=='\n' || '\0')

         continue;

        else

         printf("%c",pass[i]);

    }

    printf("\nsuccessfully decrypted\n");

    fclose(rfile);

    fflush(stdin);

}



                                                                                                                          // algorithm by A 13 C 
