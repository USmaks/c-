#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "html_head.h"

#define bufsize 256
#define datasize 40
#define reposize 20

int main(){
    
    FILE *fp;
    FILE *fo;
    char *fnameo = "public/index.html";
    char *fnamep = "public/preindex.html";
    char buff[bufsize];
    char *find = "ジュース";
    char data[datasize] = "50,50,50,50,50,50,50,50,50,50,50,50";
    char rep[datasize + reposize + 1] = "[\"Coffee\" ,";
    fo = fopen(fnameo, "w");
    fp = fopen(fnamep, "r");
    
    if(fo == NULL || fp == NULL){
        printf("%s または %s ファイルが開けません。\n", fnameo, fnamep);
        return -1;
    }
    
    while(fgets(buff, sizeof(buff), fp) != NULL){
        if(strstr(buff, find) != NULL){
            fputs(strcat(rep, data), fo);
        }else{
            fputs(buff, fo);
        }
    }

    fclose(fp);
    fclose(fo);
    
    printf("%s ファイルへの書き込みが終わりました。\n", fnameo);
    
    return 0;
    
}