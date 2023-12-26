#include <stdio.h>

#include <process.h>
#include <stdlib.h>

struct gorev{
    int saat;
    int dakika;
    char eylem[30];
};
FILE * fileAdres;
void ekle(){
    struct gorev gorev1;
    char get_ss[30];
    fileAdres = fopen("eylemler.txt","a+");

    printf("Lutfen Eylem saati giriniz!! \n");
    scanf("%d", &gorev1.saat);
    printf("Lutfen Eylem dakikasini giriniz!! \n");
    scanf("%d", &gorev1.dakika);
    printf("Lutfen Eylemi giriniz!!  \n");

    scanf("%s",gorev1.eylem);

    if (fileAdres == NULL){
        printf("Dosya olusturulamadi, uzgunuz !!");
        exit(EXIT_FAILURE);
    }
    fprintf(fileAdres," %d:%d => %s \n ",gorev1.saat,gorev1.dakika,gorev1.eylem);
    fclose(fileAdres);

}
void guncelle(){
    FILE *dosya;
    int saat,dakika;
    struct gorev gorev1;
    dosya = fopen("eylemler.txt", "r");
    if (dosya == NULL)
    {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    printf("Lutfen guncellemek istediginiz Eylem saati giriniz!! \n");
    scanf("%d", &saat);
    printf("Lutfen guncellemek istediginiz Eylem dakikasini giriniz!! \n");
    scanf("%d", &dakika);
    fscanf(dosya, "%d %d",saat, dakika);
    fclose(dosya);
}
void gorevler(){
    char c;
    fileAdres = fopen("eylemler.txt", "r");
    if (fileAdres == NULL)
    {
        printf("Dosya açılamadı!\n");
        exit(EXIT_FAILURE);
    }
    c = fgetc(fileAdres);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fileAdres);
    }
    fclose(fileAdres);

}
