//PDP 2.Odev
//MHD NOUR ALKHALAF
//B201210566
//1C

#include <Dosya.h>

FILE *fp;
long lSize;
char *buffer;
int i=0,count = 1; 




Dosya new_dosya()
{
    Dosya this;
    this =(Dosya)malloc(sizeof(struct DOSYA));

    this->kisiOku=&kisiOku;
    this->sayiOku=&sayiOku;
    this->Count=&Count;
    this->yikici=&yikici;

    return this;
}

int Count(const Dosya this,char* filename)
{
    char c;
    int count=1;
    fp = fopen ( filename , "r" );
        if( !fp ) perror(filename),exit(1);

        for (c = getc(fp); c != EOF; c = getc(fp))
            if (c == '\n') 
                count = count + 1;

    fclose(fp);    
    return count;
}

char* kisiOku(const Dosya this)
{
    fp = fopen ( "Kisiler.txt" , "rb" );
    if( !fp ) perror("Kisiler.txt"),exit(1);

    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );

    buffer = calloc( 1, lSize+1 );
    if( !buffer ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

    if( 1!=fread( buffer , lSize, 1 , fp) )
    fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);

    fclose(fp);
    return buffer;
}


char* sayiOku(const Dosya this )
{
    free(buffer);
    fp = fopen ( "Sayilar.txt" , "rb" );
    if( !fp ) perror("Sayilar.txt"),exit(1);
    
    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );

    buffer = calloc( 1, lSize+1 );
    if( !buffer ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

    if( 1!=fread( buffer , lSize, 1 , fp) )
    fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);

    fclose(fp);
    return buffer;
}

void yikici(const Dosya this){
    if(this==NULL) return;
    free(buffer);
    free(this);
}