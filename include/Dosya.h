//PDP 2.Odev
//MHD NOUR ALKHALAF
//B201210566
//1C

#ifndef DOSYA_H
#define DOSYA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

struct DOSYA{
    
    int (*Count)(struct DOSYA*,char*);
    char* (*kisiOku)(struct DOSYA*);
    char* (*sayiOku)(struct DOSYA*);
    void (*yikici)(struct DOSYA*);
};
typedef struct DOSYA* Dosya;

Dosya new_dosya();
int Count(const Dosya,char*);
char* kisiOku(const Dosya);
char* sayiOku(const Dosya);
void yikici(const Dosya);

#endif