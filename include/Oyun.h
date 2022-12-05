//PDP 2.Odev
//MHD NOUR ALKHALAF
//B201210566
//1C

#ifndef OYUN_H
#define OYUN_H

#include <Kisi.h>

struct OYUN
{
    Kisi k;

    void (*oyunBasla)(struct OYUN*);
    void (*oyunYoket)(struct OYUN*);

};
typedef struct OYUN* Oyun;

Oyun new_Oyun();
void oyunBasla(const Oyun);
void oyunYoket(const Oyun);

#endif
