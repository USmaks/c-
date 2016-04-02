/*
 * by usmaks
 * #How to this
 *      1. Make this
 *      2. Edit your signal [*name, *data]
 *      3. Generate executable file
 *      4. Execute & Open index.html file
 *      5. You can see your original graph! 
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "html_head.h"

#define bufsize 256
#define datasize 40
#define reposize 20

void generateSignal(char name[], char cdata[]);

int main(){
    
    FILE *fp;
    FILE *fo;

    char *fnameo = "public/index.html";
    char *fnamep = "public/preindex.html";
    char buff[bufsize];
    
    char *find = "コーヒー";
    
    char repName[datasize + reposize + 1] = "\"Coffee\" ,";
    char repData[datasize] = "50,50,50,50,50,50,50,50,50,50,50,50\n";
    
    char repNameNext[datasize + reposize + 1] = "\"Cafe\",";
    char repDataNext[datasize] = "20,32,10,49,31,20,33,41,66,11,4,44\n";
    
    fo = fopen(fnameo, "w");
    fp = fopen(fnamep, "r");
    
    if(fo == NULL || fp == NULL){
        printf("%s または %s ファイルが開けません。\n", fnameo, fnamep);
        return -1;
    }
    
    generateSignal(repName, repData);
    generateSignal(repNameNext, repDataNext);

    
    while(fgets(buff, sizeof(buff), fp) != NULL){
        if(strstr(buff, find) != NULL){                             //if match, return without NULL
            fputs(repName, fo);
        }else{
            fputs(buff, fo);
        }
    }
    
    
    fclose(fp);
    fclose(fo);
    
    printf("%s ファイルへの書き込みが終わりました。\n", fnameo);

//  Initialize "signal"
    FILE *fs;
    char *fnames = "signal";
    fs = fopen(fnames, "w");
    fclose(fs);
   
    
    return 0;
    
}

void generateSignal(char name[], char cdata[]){
    // *name = \"coffee\"," ; *cdata = 50,29,48,... 
    FILE *fp;
    char *fname = "signal";
    char buff[bufsize];
    
    fp = fopen(fname, "a");
    
    if(fp == NULL){
        printf("%s ファイルが開けません。\n", fname);
        return -1;
    }
    
    fputs(strcat(name, cdata), fp);
    printf(name);
    fclose(fp);
    
    printf("%s ファイルへの信号生成が終わりました。\n", fname);
}