   //PDP 2.Odev
//MHD NOUR ALKHALAF
//B201210566
//1C

#include <Oyun.h>

int tur,m,n,count,index1;
double masa;


void delay(double number_of_seconds)
{
    double milli_seconds = 1000 * number_of_seconds;
  
    clock_t start_time = clock();
  
    while (clock() < start_time + milli_seconds);
}
void clrscr()
{
    system("@cls||clear");
}

Oyun new_Oyun()
{
    Oyun this;
    this=(Oyun)malloc(sizeof(struct OYUN));
    this->k=new_Kisi();


    masa=0;
    tur=0;
    this->oyunBasla=&oyunBasla;
    this->oyunYoket=&oyunYoket;
    return this;
}
void oyunBasla(const Oyun this)
{
    
    this->k->bilgilerGetir(this->k);

    count=this->k->d->Count(this->k->d,"Kisiler.txt");
    
    while(this->k->maxPara>=1000)
    {   
        
        clrscr();
        tur++;
        printf("\n\n\n\n\t\t\t##########################################################\n");
        printf("\t\t\t##\t\t\tSanli Sayi: %-2d\t\t\t##\n",this->k->SanliSayi[m]);
        printf("\t\t\t##########################################################\n");
        printf("\t\t\t##########################################################\n");
        printf("\t\t\t##\t\t\t\t\t\t\t##\n");
        printf("\t\t\t##\t\t\t  TUR: %-3d       \t\t##\n",tur);
        for(n=0;n<count;n++)
        {
            if((this->k->YatirmaSayi[n]==this->k->SanliSayi[m])&&(this->k->Para[n]>1000))
            {
                masa=masa-this->k->Para[n]*this->k->YatirmaMiktari[n]*9;
                this->k->Para[n]=this->k->Para[n]*this->k->YatirmaMiktari[n]*9+this->k->Para[n];
            }
            else if(this->k->Para[n] > 1000)
            {
                masa=masa+this->k->Para[n]*this->k->YatirmaMiktari[n];
                this->k->Para[n]=this->k->Para[n]-this->k->Para[n]*this->k->YatirmaMiktari[n];
            }
        }
        m++;
        printf("\t\t\t##\t\tMasa Bakiyesi: %.0lf TL    \t\t##\n",masa);
        printf("\t\t\t##\t\t\t\t\t\t\t##\n");
        printf("\t\t\t##------------------------------------------------------##\n");

        this->k->enZenginHesapla(this->k);
        
        if(this->k->maxPara<1000)
        {
            printf("\t\t\t##\t\t\t\t\t\t\t##\n");    
            printf("\t\t\t##\t\tEn Zengin Kisi: %-24s##\n",this->k->KisiAdi[index1]);
            printf("\t\t\t##\t\t     Bakiyesi: %-10d           \t##\n",(int)round(this->k->Para[index1]));
            printf("\t\t\t##\t\t\t\t\t\t\t##\n");
            printf("\t\t\t##########################################################\n\n\n\n");
        }
        else
        {
            printf("\t\t\t##\t\t\t\t\t\t\t##\n");    
            printf("\t\t\t##\t\tEn Zengin Kisi: %-24s##\n",this->k->KisiAdi[this->k->index]);
            printf("\t\t\t##\t\t      Bakiyesi: %-10d          \t##\n",(int)round(this->k->maxPara));
            printf("\t\t\t##\t\t\t\t\t\t\t##\n");
            printf("\t\t\t##########################################################\n\n\n\n");
            index1=this->k->index;
        }
        delay(0.09);
    }
    clrscr();
    printf("\n\n\n\n\t\t\t##########################################################\n");
    printf("\t\t\t##\t\t\t  TUR: %-3d       \t\t##\n",tur);
    printf("\t\t\t##\t\tMasa Bakiyesi: %.0lf TL    \t##\n",masa);
    printf("\t\t\t##------------------------------------------------------##\n");
    printf("\t\t\t##\t\t\t\t\t\t\t##\n");
    printf("\t\t\t##\t\t\tOYUN BITTI\t\t\t##\n");
    printf("\t\t\t##\t\t\t\t\t\t\t##\n");
    printf("\t\t\t##########################################################\n\n\n\n");
}
void oyunYoket(const Oyun this)
{
    if(this==NULL) return;
    this->k->yoket(this->k);
    free(this);
}