//PDP 2.Odev
//MHD NOUR ALKHALAF
//B201210566
//1C

#include <Kisi.h>

int count,i;
char* buffer;




Kisi new_Kisi()
{
    Kisi this;
    this = (Kisi)malloc(sizeof(struct KISI));

    this->d=new_dosya();

    this->KisiAdi=malloc(sizeof(char*)*this->d->Count(this->d,"Kisiler.txt"));

    for(i=0;i<this->d->Count(this->d,"Kisiler.txt");i++)
        this->KisiAdi[i]=malloc((50)*sizeof(char));

    this->Para=malloc(sizeof(double)*this->d->Count(this->d,"Kisiler.txt"));
    this->YatirmaMiktari=malloc(sizeof(double)*this->d->Count(this->d,"Kisiler.txt"));
    this->YatirmaSayi=malloc(sizeof(int)*this->d->Count(this->d,"Kisiler.txt"));

    
    this->SanliSayi=malloc(sizeof(int)*this->d->Count(this->d,"Sayilar.txt")); 

    this->enZenginHesapla=&enZenginHesapla;
    this->bilgilerGetir=&bilgilerGetir;
    this->yoket=&yoket;

    return this;
}

void enZenginHesapla(const Kisi this)
{   
    this->maxPara=this->Para[0];
    this->index=0;
    count = this->d->Count(this->d,"Kisiler.txt");
    for(i=0;i<count;i++)
    {
        if(this->maxPara < this->Para[i])
        {
            this->maxPara=this->Para[i];
            this->index=i;
        }
    }
}

void bilgilerGetir(const Kisi this)
{
    buffer=this->d->kisiOku(this->d);
    char* token = strtok(buffer, "#");
    i=0;

    while (token != NULL) {

        strcpy(this->KisiAdi[i],token);

        token = strtok(NULL, "#");
        this->Para[i] = atof(token);

        token = strtok(NULL, "#");
        this->YatirmaMiktari[i]=atof(token);

        token = strtok(NULL, "\n");
        this->YatirmaSayi[i]=atoi(token);

        token = strtok(NULL, "#");
        i=i+1;
    } 

    buffer=this->d->sayiOku(this->d);
    i=0;

    token = strtok(buffer, "\n");
    while (token != NULL) 
    {
        this->SanliSayi[i]=atoi(token);
        token = strtok(NULL, "\n");
        i=i+1;
    }
    this->enZenginHesapla(this);
}


void yoket(const Kisi this)
{
    if(this==NULL) return;
    this->d->yikici(this->d);
    free(this->KisiAdi);
    free(this->Para);
    free(this->YatirmaMiktari);
    free(this->YatirmaSayi);
    free(this->SanliSayi);
    free(this);
}
