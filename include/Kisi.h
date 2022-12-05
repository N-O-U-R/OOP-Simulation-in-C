//PDP 2.Odev
//MHD NOUR ALKHALAF
//B201210566
//1C

#ifndef KISI_H
#define KISI_H

#include <Dosya.h>

struct KISI
{
    Dosya d;

    char** KisiAdi;
    double* Para;
    double* YatirmaMiktari;
    int* YatirmaSayi;
    int* SanliSayi;
    double maxPara;
    int index;

    void (*enZenginHesapla)(struct KISI*);
    void (*bilgilerGetir)(struct KISI*);
    void (*yoket)(struct KISI*);

};
typedef struct KISI* Kisi;

Kisi new_Kisi();
void enZenginHesapla(const Kisi);
void bilgilerGetir(const Kisi);
void yoket(const Kisi);


#endif