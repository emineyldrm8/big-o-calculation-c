#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1000
#define MAX_LINE_LENGTH 80
#include <time.h>
#include <unistd.h>

// return 0'ý katýyorum hesaba tn icin +1 ekliyorum
char *suslu="{";
char *suslu2="}";
const char *whilevarmi = "while";
int parantez;
char artiarti[3]="++";
char artiesit[3]="+=";
char eksieksi[3]="--";
char eksiesit[3]="-=";
char carpiesit[3]="*=";
char boluesit[3]="/=";
char carpi[3]="*";
char bolu[3]="/";
int artiartisayaci = 0;
int artiesitsayaci = 0;
int eksieksisayaci = 0;
int eksiesitsayaci = 0;
int carpisayaci = 0;
int bolusayaci = 0;
const char *forvarmi = "for";
const char *n2varmi = "n";
int lineer=0;
int logaritmik=0;
int on=0;
int dongusayisi=0;
const char *koselivarmi = "[";
const char *matrisvarmi="][";
int parantez=0;
const char *nvarmi="[]";
int mainkonum,returnkonum,parantezkonum,mesafe1,mesafe2,mesafe3,mesafe4;
int tn(char wrd[256]);
int artiskontrolu(char dizi[], FILE*fptr);
int kontrol(char dizi[], FILE*fptr);
int tngenelhesap(char dizi[],FILE* fptr);
 const char *dovarmi = "do{";
int icicebigoicinkarar(char dizi[], FILE*fptr);
int whileicinbigo(char dizi[],FILE* fptr);
int main()
{
    double harcanan_zaman = 0.0;
    clock_t baslangic = clock();


    char dizi[50];

    FILE *fptr = fopen("input1.txt","r");
    char kelimeKontrol[5] = "main";//verilen dosya icerisinde arayacagim kelime.
     DosyaIcerikKontrolu(fptr,kelimeKontrol);
     const char *forvarmi = "for";
    while(fgets(dizi,200,fptr))
    {
       printf("%s",dizi);
        if(strstr(dizi,forvarmi))
        {

            artiskontrolu(dizi,fptr);
            kontrol(dizi, fptr);

        }
        else
        {

        }


    }
    whileicinbigo(dizi,fptr);
    icicebigoicinkarar(dizi,fptr);
       dohesap(dizi,fptr);
       sleep(3);

    clock_t son = clock();

    harcanan_zaman += (double)(son - baslangic) / CLOCKS_PER_SEC;

    printf("\n\nKodun calistirilmasinda gecen sure saniye cinsinden : %f saniyedir.\n",harcanan_zaman);

    fclose(fptr);
      char dizi2[50];

    FILE *fptr2=fopen("input1.txt","r");
       yerhesabinicagir(dizi2,fptr2);
    fclose(fptr2);

    return 0;
}
int DosyaIcerikKontrolu(FILE *fptr, char arananKelime[])
{
    FILE *proje = fopen("input1.txt", "r");

    if(proje == NULL)
    {
        printf("\nDosya acma hatasi!\n");
        exit(1);
    }

    char KodDizisi[250];//Kodu atacagim dizi
    int kontrol;//aradigim kelime bulunursa 1 degerini yoksa 0 degerini alacak.

    while(!feof(proje))
    {
        fgets(KodDizisi,249,proje);//satir satir dosyayi okuyorum.

        char *str = strstr(KodDizisi,arananKelime); //main kelimesini kod icerisinde ariyorum.

        if(str == NULL)
        {
            kontrol = 0;
        }
        else
        {
            kontrol = 1;
            break;
        }
    }

    if(kontrol)
    {
        printf("\n\n\nBU TEXT DOSYASI BIR KOD ICERMEKTEDIR.\n");
    }
    else
    {
        printf("\n\n\nBU TEXT DOSYASI BIR KOD ICERMEMEKTEDIR.\n");
    }
    fclose(proje);
}
int whileicinbigo(char dizi[], FILE *fptr)
{
    char diziw[50];

    FILE *fptrw = fopen("input1.txt","r");
    int artiartisayaci = 0;
    int artiesitsayaci = 0;
    int eksieksisayaci = 0;
    int eksiesitsayaci = 0;
    int carpiesitsayaci = 0;
    int boluesitsayaci = 0;
    int whileicinsayac=0;

    const char *whilevarmi = "while";
    int wlineer=0;
    int wlogaritmik=0;
    while(fgets(diziw,80,fptrw))
    {


        if(strstr(diziw,whilevarmi))
        {
            whileicinsayac++;
        }

        if(strstr(diziw,artiarti))
        {
            artiartisayaci = artiartisayaci+1;
        }
        if(strstr(diziw,artiesit))
        {
            artiesitsayaci = artiesitsayaci+1;
        }
        if(strstr(diziw,eksieksi))
        {
            eksieksisayaci = eksieksisayaci+1;
        }
        if(strstr(diziw,eksiesit))
        {
            eksiesitsayaci = eksiesitsayaci+1;
        }
        if(strstr(diziw,carpiesit))
        {
            carpiesitsayaci = carpiesitsayaci+1;
        }
        if(strstr(diziw,boluesit))
        {
            boluesitsayaci = boluesitsayaci+1;
        }

         if(artiartisayaci!=0 || artiesitsayaci!=0 || eksieksisayaci!=0 || eksiesitsayaci!=0)
    {
        wlineer++;
    }
    else if(carpiesitsayaci!=0 || boluesitsayaci!=0)
    {
        wlogaritmik++;
    }

    }
    if(whileicinsayac== 1 && (wlineer>=1))
    {
        printf("TEK WHILE VEYA TEK DO WHILE ICEREN DONGUNUZUN BIG O'SU O(N)");
    }
    else if(whileicinsayac== 1 && (wlogaritmik>=1))
    {
        printf("TEK WHILE VEYA TEK DO WHILE ICEREN DONGUNUZUN BIG O'SU O(LOG(N))");
    }
    else if(whileicinsayac== 1 && (wlogaritmik==0) &&(wlineer==0))
    {
        printf("TEKLI WHILE VEYA TEK DO WHILE ICEREN DONGUNUZUN  BIG O'SU O(LOG(N))");
    }
     else if((whileicinsayac== 2) && (wlineer>=2))
    {
        printf("ICICE WHILE VEYA ICICE DO WHILE ICEREN DONGUNUZUN BIG O'SU=O(N^2)");
    }
    else if((whileicinsayac== 2) && (wlogaritmik>=2))
    {
        printf("ICICE WHILE VEYA ICICE DO WHILE ICEREN DONGUNUZUN BIG O'SU=O(LOG^2(N)");
    }
    else if((whileicinsayac== 2) && (wlineer>=1) || (wlogaritmik>=1))
    {
        printf("ICICE WHILE VEYA ICICE DO WHILE ICEREN DONGUNUZUN BIG O'SU O(LOG(N)*N)");
    }
   fclose(fptrw);
    return 0;
}
int kontrol(char dizi[], FILE*fptr)
{

    if(strstr(dizi, suslu))
    {
        parantez++;
        fgets(dizi,100,fptr);
        printf("%s",dizi);
        if(strstr(dizi, forvarmi))
        {
            artiskontrolu(dizi,fptr);
        }
        kontrol(dizi,fptr);
    }
    else if(strstr(dizi, suslu2))
    {
        parantez--;
        if(parantez==1)
        {
            printf("ICICE FOR VAR\n");
           dongusayisi=2;

        }else if(parantez==0)
        {

            printf("tek for var.\n");
            if(lineer>0)
            {
                printf("TEK FOR DONGUNUZUN BIG O'SU=O(N)'DIR.\n");

            }
            else if(logaritmik>0)
            {
                 printf("TEK FOR DONGUNUZUN BIG O'SU=O(LOGN)'DIR.\n");
            }
            else if(on>0)
            {
                 printf("TEK FOR DONGUNUZUN BIG O'SU=O(1)'DIR.\n");
            }
             dongusayisi=1;

        }

    }
    else
    {

        fgets(dizi,100,fptr);
        printf("%s",dizi);
        if(strstr(dizi, forvarmi))
        {
            artiskontrolu(dizi,fptr);
        }

        kontrol(dizi,fptr);
    }

}



int artiskontrolu(char dizi[], FILE*fptr)
{
    if(parantez==0)
    {lineer=0;
        logaritmik=0;
        on=0;
    }
    int artiartisayaci=0;
    int artiesitsayaci=0;
    int eksieksisayaci=0;
    int eksiesitsayaci=0;
    int carpisayaci=0;
    int bolusayaci=0;
    int nsayaci=0;
    if(strstr(dizi,artiarti))
    {
        artiartisayaci=artiartisayaci+1;
    }
    if(strstr(dizi,artiesit))
    {
        artiesitsayaci=artiesitsayaci+1;
    }
    if(strstr(dizi,eksieksi))
    {
        eksieksisayaci=eksieksisayaci+1;
    }
    if(strstr(dizi,eksiesit))
    {
        eksiesitsayaci=eksiesitsayaci+1;
    }
    if(strstr(dizi,carpi))
    {
        carpisayaci=carpisayaci+1;
    }
    if(strstr(dizi,bolu))
    {
        bolusayaci=bolusayaci+1;
    }
     if(strstr(dizi,n2varmi))
    {
        nsayaci=nsayaci+1;
    }

    if(nsayaci>0 && artiartisayaci>=1)
    {
        printf("big o=o(N)\n");
        lineer++;
    }
    else if(nsayaci>0 && artiesitsayaci>=1)
    {
        printf("big o=o(N)\n");
        lineer++;
    }
    else  if(nsayaci>0 && eksieksisayaci>=1)
    {
        printf("big o=o(N)\n");
        lineer++;
    }
    else  if(nsayaci>0 && eksiesitsayaci>=1)
    {
        printf("big o=o(N)\n");
        lineer++;
    }
    else if(nsayaci>0 && carpisayaci>0)
    {
        printf("big o=o(logN)\n\n");
        logaritmik++;
    }
    else if(nsayaci>0 && bolusayaci>0)
    {
        printf("big o=o(logN)\n\n");
        logaritmik++;
    }
    else if(nsayaci==0 && (carpisayaci>0 || bolusayaci>0 || eksiesitsayaci>0 || eksieksisayaci>0 || artiesitsayaci>0 || artiartisayaci>0))
    {
        printf("big o=o(1)\n\n");
        on++;
    }
}
int icicebigoicinkarar(char dizi[], FILE*fptr)
{

    if((dongusayisi==2) && (logaritmik==1 && lineer==1) )
    {
         printf("ICICE FOR ICIN O(N*LOGN)\n");
    }else if((dongusayisi==2) && (lineer==2) )
    {
          printf("ICICE FOR ICIN O(N^2)\n");
    }
    else if((dongusayisi==2) && (logaritmik==2) )
    {
          printf("ICICE FOR ICIN O(LOGN*LOGN)\n");
    }
     else if((dongusayisi==2) && (logaritmik==1 && on==1) )
    {
           printf("ICICE FOR ICIN O(LOGN)\n");
    }
     else if((dongusayisi==2) && (lineer==1 && on==1) )
    {
           printf("ICICE FOR ICIN O(N)\n");
    }
    else if((dongusayisi==2) && (on==2) )
    {
           printf("ICICE FOR ICIN O(1)\n");
    }
    return 0;
}


 int dohesap(char dizi[],FILE* fptr)
 {     char dizido[200];
    FILE *fptrdo= fopen("input1.txt","r");

    int dosayac=0;
    while(fgets(dizido,80,fptrdo))
    {

        if(strstr(dizido,dovarmi))
        {
            dosayac++;
        }
    }
if(dosayac==0)
{
   whileicinsurehesabi(dizido,fptr);
   foricinsurehesabi(dizido,fptr);
}
 else if(dosayac==1)
{
    dowhileicinsurehesabi(dizido,fptr);
}
return 0;
}
int tn(char wrd[256])
{
    char  buffer[256];
    int n, m, i, j, line;

    FILE* fp;
    fp = fopen("input1.txt", "r");


    m = strlen(wrd);

    line = 0;
    while (fgets(buffer, 256, fp) != NULL)
    {

        i = 0;
        n = strlen(buffer);
        while (i < n)
        {
            j = 0;
            while (i < n && j < m && buffer[i] == wrd[j])
            {
                ++i, ++j;
            }

            if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m)
            {
                return line;

            }

            while (i < n && buffer[i] != ' ')
            {
                ++i;
            }
            ++i;

        }

        ++line;

    }

}

int dowhileicinsurehesabi(char dizi[], FILE *fptr)
{

    const char *dovarmi = "do{";
     char dizid[200];
    FILE *fptrd = fopen("input1.txt","r");

    while(fgets(dizid,80,fptrd))
     {


        if(strstr(dizid,dovarmi))
        {

            int n;
            int mainkonum=tn("main()");
            int dokonum=tn("do{");
            int  whilekonum=tn("}while");
            int returnkonum=tn("return");
            int mesafe1=(dokonum-mainkonum-2);
            int mesafe2=(whilekonum-dokonum-1);
            int mesafe3=(returnkonum-whilekonum-1);
            int mesafe4=mesafe1+mesafe3;

            printf("\nDO WHILE ICEREN DONGUNUZUN KOD CALISTIGINDA GECEN SURESI=%dn+%d",mesafe2+1,mesafe4+2);
        }
        else
            {

        }
    }
    fclose(fptrd);
 return 0;
}

int foricinsurehesabi(char dizi[],FILE *fptr)
{
        char dizif[50];
    FILE *fptrf = fopen("input1.txt","r");

    const char *forvarmi = "for ";

    while(fgets(dizif,80,fptrf))
    {

        if(strstr(dizif,forvarmi))
        {    int n;
            int mainkonum=tn("main()");
            int forkonum=tn("for");
            int  parantezkonum=tn("}");
            int returnkonum=tn("return");
            int mesafe1=(forkonum-mainkonum-2);
            int mesafe2=(parantezkonum-forkonum-2);
            int mesafe3=(returnkonum-parantezkonum-1);
            int mesafe4=mesafe1+mesafe3;

            printf("\nFOR ICEREN DONGUNUZUN KOD CALISTIGINDA GECEN SURESI=%dn+%d",mesafe2+1,mesafe4+2);
    }
        else
        {

        }
    }
        fclose(fptrf);
    return 0;
}

int whileicinsurehesabi(char dizi[],FILE *fptr)
{
     char diziw[50];
    FILE *fptrw = fopen("input1.txt","r");
    const char *whilevarmi = "while";

    while(fgets(diziw,80,fptrw))
    {

        if(strstr(diziw,whilevarmi) )
        {

            int n;
            int mainkonum=tn("main()");
            int whileilkkonum=tn("while");
            int  parantezkonum=tn("}");
            int returnkonum=tn("return");
            int mesafe1=(whileilkkonum-mainkonum-2);
            int mesafe2=(parantezkonum-whileilkkonum-2);
            int mesafe3=(returnkonum-parantezkonum-1);
            int mesafe4=mesafe1+mesafe3;
            printf("\nWHILE ICEREN DONGUNUZUN KOD CALISTIGINDA GECEN SURESI=%dn+%d",mesafe2+1,mesafe4+2);

         }
        else
        {
            printf("\n");
        }
    }
    fclose(fptrw);

    return 0;
}
int dizivematrislericinyerhesabi(FILE *fptr2,const char *wrd)
{

    char dizi[50];
    FILE *fptr=fopen("input1.txt","r");
    int sayac=0,toplamboyut=0,toplamboyutdizi=0;
    int sayacmatris=0;
    int i1, i2,i3;
    while(fgets(dizi,80,fptr))
    {


        if(strstr(dizi,wrd))
        {
            if(strstr(dizi,matrisvarmi))
            {
                sayacmatris++;


                if (2 == sscanf(dizi,"%*[^0123456789]%d%*[^0123456789]%d%",&i1,&i2))
                {
                    printf("\n\n%s MATRISLER ICIN BOYUT=%d %d \n",wrd, i1, i2);
                    toplamboyut=toplamboyut+(i1*i2);
                }

            }
            else if(strstr(dizi,koselivarmi))
            {
                sayac++;
                if (1 == sscanf(dizi,"%*[^0123456789]%d",&i3))
                {
                    printf("\n %s DIZILER ICIN BOYUT=%d \n\n",wrd, i3);
                    toplamboyutdizi=toplamboyutdizi+(i3);
                }

            }
        }
        else
        {

        }

    }



    printf("\n%d kadar %s dizisi var.\n",sayac,wrd);

    printf("\n%d kadar %s matris dizisi var.\n",sayacmatris,wrd);
    int toplam=toplamboyut+toplamboyutdizi;
    return toplam;
    fclose(fptr);
}

int nlericingenelhesap(FILE *fptr2,const char *wrd)
{

    char dizi[50];
    FILE *fptr=fopen("input1.txt","r");

    const char *n="[n]";
    int sayac=0;
    while(fgets(dizi,80,fptr))
    {


        if(strstr(dizi,wrd))
        {
            if(strstr(dizi,n))
            {
                sayac++;
            }

        }

        else
        {

        }

    }
    return sayac;
    fclose(fptr);
}
int nkarelericingenelhesap(FILE *fptr2,const char *wrd)
{

    char dizi[50];
    FILE *fptr=fopen("input1.txt","r");
    const char *nkare="[n][n]";
    int sayac=0;
    while(fgets(dizi,80,fptr))
    {


        if(strstr(dizi,wrd))
        {
            if(strstr(dizi,nkare))
            {
                sayac++;
            }

        }

        else
        {

        }

    }
    return sayac;
    fclose(fptr);
}

int dizisayisihesap(FILE *fptr2,const char *wrd)
{

    char dizi[50];
    FILE *fptr=fopen("input1.txt","r");
    int sayac=0;
    int sayacmatris=0;

    while(fgets(dizi,80,fptr))
    {


        if(strstr(dizi,wrd))
        {
            if(strstr(dizi,matrisvarmi))
            {
                sayacmatris++;

            }
            else if(strstr(dizi,koselivarmi))
            {
                sayac++;

            }
        }
        else
        {

        }

    }

    int toplam=sayacmatris+sayac;
    return toplam;
    fclose(fptr);
}
int kelimeicinyerhesabi(FILE *fptr2,const char *wrd)
{

    char dizi[50];
    FILE *fptr=fopen("input1.txt","r");
    int sayac=0;

    while(fgets(dizi,80,fptr))
    {
        if(strstr(dizi,wrd))
        {
            sayac++;
        }
        else
        {

        }

    }

    return sayac;


    fclose(fptr);


}

int virgulicinyerhesabi(FILE *fptr2,const char *wrd)
{

   char dizi[50];
    FILE *fptr=fopen("input1.txt","r");
    const char *virgul=",";
    int sayac=0;
    char *pos;
    int indeks,tekrar = 0;

    while(fgets(dizi,80,fptr))
    {


        if(strstr(dizi,wrd))
        { indeks = 0;
        while((pos = strstr(dizi + indeks,virgul)) != NULL){
            indeks = pos - dizi + 1;


                 sayac++;

            }

        }


    }

 return sayac;
 fclose(fptr);


}

int yerhesabinicagir(char dizi2[],FILE *fptr2)
{
     int sayac;
    int intdizimatris=dizivematrislericinyerhesabi(fptr2,"int ");
    int intn= nlericingenelhesap(fptr2,"int ");
    int intnkare=nkarelericingenelhesap(fptr2,"int ");
    int intdizi=dizisayisihesap(fptr2,"int ");
    int intkelime=kelimeicinyerhesabi(fptr2,"int ");
    int intvirgul=virgulicinyerhesabi(fptr2,"int ");
    int inticinyer=((intdizimatris)*4)+(((intkelime+intvirgul)-intdizi-1)*4);


    printf("INT TURUNDEKI DIZI SAYINIZ=%d\n",intdizi);
    printf("INT TURUNDEKI TOPLAM KELIME SAYINIZ=%d\n",((intkelime+intvirgul-intdizi-1)));



    int floatdizimatris=dizivematrislericinyerhesabi(fptr2,"float ");
    int floatn= nlericingenelhesap(fptr2,"float ");
    int floatnkare=nkarelericingenelhesap(fptr2,"float ");
    int floatdizi=dizisayisihesap(fptr2,"float ");
    int floatkelime=kelimeicinyerhesabi(fptr2,"float ");
    int floatvirgul=virgulicinyerhesabi(fptr2,"float ");
    int floaticinyer=((floatdizimatris)*4)+((floatkelime+floatvirgul-floatdizi)*4);

     printf("FLOAT TURUNDEKI DIZI SAYINIZ=%d\n",floatdizi);
    printf("FLOAT TURUNDEKI TOPLAM KELIME SAYINIZ=%d\n",((floatkelime+floatvirgul-floatdizi)));

    int doubledizimatris=dizivematrislericinyerhesabi(fptr2,"double ");
    int doublen= nlericingenelhesap(fptr2,"double ");
    int doublenkare=nkarelericingenelhesap(fptr2,"double ");
    int doubledizi=dizisayisihesap(fptr2,"double ");
    int doublekelime=kelimeicinyerhesabi(fptr2,"double ");
    int doublevirgul=virgulicinyerhesabi(fptr2,"double ");
    int doubleicinyer=((doubledizimatris)*8)+((doublekelime+doublevirgul-doubledizi)*8);

    printf("DOUBLE TURUNDEKI DIZI SAYINIZ=%d\n",doubledizi);
    printf("DOUBLE TURUNDEKI TOPLAM KELIME SAYINIZ=%d\n",((doublekelime+doublevirgul-doubledizi)));


    int chardizimatris=dizivematrislericinyerhesabi(fptr2,"char ");
    int charn= nlericingenelhesap(fptr2,"char ");
    int charnkare=nkarelericingenelhesap(fptr2,"char ");
    int chardizi=dizisayisihesap(fptr2,"char ");
    int charkelime=kelimeicinyerhesabi(fptr2,"char ");
    int charvirgul=virgulicinyerhesabi(fptr2,"char ");
    int charicinyer=((chardizimatris))+(((charkelime+charvirgul)-chardizi));

     printf("CHAR TURUNDEKI DIZI SAYINIZ=%d\n",chardizi);
    printf("CHAR TURUNDEKI TOPLAM KELIME SAYINIZ=%d\n",((charkelime+charvirgul-chardizi)));

    int toplamyer=inticinyer+floaticinyer+doubleicinyer+charicinyer;
    int nlericintoplamyer=(((-intnkare+intn)*4)+((-floatnkare+floatn)*4)+((-doublenkare+doublen)*8)+(-charnkare+charn));
     int nkarelericintoplamyer=((intnkare*4)+(floatnkare*4)+(doublenkare*8)+(charnkare));
     printf("YER KARMASIKLIGINIZ=\n");
     printf("%dn^2+%dn+%d",nkarelericintoplamyer,nlericintoplamyer,toplamyer);
     return 0;
}



