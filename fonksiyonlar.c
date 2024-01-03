#include <stdio.h>

#include <process.h>
#include <stdlib.h>

typedef struct File File;
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

    printf("Lutfen gorev saati giriniz!! \n");
    scanf("%d", &gorev1.saat);
    printf("Lutfen gorev dakikasini giriniz!! \n");
    scanf("%d", &gorev1.dakika);
    printf("Lutfen gorevi giriniz!!  \n");

    scanf("%s",gorev1.eylem);

    if (fileAdres == NULL){
        printf("Dosya olusturulamadi, uzgunuz !!");
        exit(1);
    }
    fprintf(fileAdres," %d:%d => %s \n ",gorev1.saat,gorev1.dakika,gorev1.eylem);
    fclose(fileAdres);

}
void guncelle() {
    FILE *geciciDosya = fopen("dosya.txt", "w");
    FILE *dosya = fopen("eylemler.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi!");
        exit(1);
    }
    int yenisaat, yenidakika;
    char yenieylem[100];
    char satir[100];
    int saat, dakika;
    char yeni_eylem[50];

    printf("Lutfen degistirmek istediginiz gorevin saatini girin:\n ");
    scanf("%d", &saat);
    printf("Lutfen degistirmek istediginiz gorevin dakikasini girin:\n ");
    scanf("%d", &dakika);

    printf("Lutfen yeni gorev girin:\n ");
    scanf("%s", yeni_eylem);

    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        sscanf(satir, "%d:%d => %s\n]", &yenisaat, &yenidakika, yenieylem);
        if (saat == yenisaat && dakika == yenidakika) {
           fprintf(geciciDosya, "%d:%d => %s\n", saat, dakika, yeni_eylem);
        } else {
           fprintf(geciciDosya, "%d:%d => %s\n", yenisaat, yenidakika, yenieylem);
        }
    }

    fclose(geciciDosya);
    fclose(dosya);

    remove("eylemler.txt");
    rename("dosya.txt", "eylemler.txt");

    printf("gorev basariyla degistirildi!\n");
}
void gorevler(){
    char c;
    fileAdres = fopen("eylemler.txt", "r");
    if (fileAdres == NULL)
    {
        printf("Dosya açılamadı!\n");
        exit(1);
    }
    c = fgetc(fileAdres);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fileAdres);
    }
    fclose(fileAdres);
}

void silme(){
   fileAdres = fopen("eylemler.txt", "w");  // dosyayı yazma komutuyla açtım
    if(fileAdres != NULL){
        fclose(fileAdres); // dosyayı kapattığımda dosya içeriği silinir
        printf("Gorevler silindi \n");
    }
    else
        printf("Dosya acilamadi\n"); // dosya açılmazsa bu mesaj ekrana yazılacak
}
