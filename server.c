/*
 * by usmaks
 * #How to use this
 *      1. Edit your signal [*name, *data]
 *      2. Make this
 *      3. Generate executable file
 *      4. Execute & Open index.html file
 *      5. You can see your original graph! 
 *
 *      Signal Data Format:
 *      e.g.)
 *          ["Coffee", 10,9,21,10,22,3,11],\n
 *           --name--  -------data-------    ↑LineFeedCode
 *
 *      NOTE:
 *          Must align the number of data
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "html_head.h"

#define bufsize 256
#define datasize 40
#define namesize 30
#define repsize (datasize + namesize + 1)

void generateSignal(char name[], char cdata[]);

int main(){
    
    FILE *fp;
    FILE *fo;
    FILE *fs0;
    FILE *flog;

    char *fnameo = "public/index.html";
    char *fnamep = "public/preindex.html";
    char *fnames0 = "signal";
    char *flogname = "logfile";
    char buff[bufsize];
    
    char *find = "_addData_";

    fo = fopen(fnameo, "w");
    fp = fopen(fnamep, "r");
    fs0 = fopen(fnames0, "r");
    flog = fopen(flogname, "a");
    
    char buff0[bufsize];
    if(fgets(buff0, sizeof(buff0), fs0) == NULL){
        
        char repName0[namesize] = "[ \"Month\", ";
        char repData0[datasize] = "1,2,3,4,5,6,7,8,9,10,11,12"; 
    
        char repName1[namesize] = "[ \"Coffee\", ";
        char repData1[datasize] = "50,50,50,50,50,50,50,50,50,50,50,50";
    
        char repName2[namesize] = "[ \"Cafe\", ";
        char repData2[datasize] = "20,32,10,49,31,20,33,41,66,11,4,44";

        if(fo == NULL || fp == NULL){
            printf("%s または %s ファイルが開けません。\n", fnameo, fnamep);
            return -1;
        }

        fclose(fs0);
    
        generateSignal(repName0, repData0);
        generateSignal(repName1, repData1);
        generateSignal(repName2, repData2);
        
    }


    FILE *fs2;
    char *fnames2 = "signal";
    char buff2[bufsize];
    
    fs2 = fopen(fnames2, "r");
    
    while(fgets(buff, sizeof(buff), fp) != NULL){
        
        if(strstr(buff, find) != NULL){                             //if match, return without NULL
        
            while(fgets(buff2, sizeof(buff2), fs2) != NULL){
                fputs(buff2, fo);
                fputs(buff2, flog);                                 // Take a log
            }
                        
        }else{
            fputs(buff, fo);
        }
    }
    
    
    fclose(fp);
    fclose(fo);
    fclose(fs2);
    fclose(flog);
    
    printf("%s ファイルへの書き込みが終わりました。\n", fnameo);

//  Initialize "signal"
    FILE *fs3;
    char *fnames3 = "signal";
    fs3 = fopen(fnames3, "w");
    fclose(fs3);
   
    
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
        exit (-1);
    }
    
    strcat(cdata, "],\n");
    fputs(strcat(name, cdata), fp);
    printf(name);
    fclose(fp);
    
    printf("%s ファイルへの信号生成が終わりました。\n", fname);
}