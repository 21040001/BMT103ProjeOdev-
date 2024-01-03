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
    FILE *geciciDosya = fopen("gecici.txt", "w");//buarada yeni bir dosya açtı
    FILE *dosya = fopen("eylemler.txt", "r");//burda eylemler dosyasını okudu
    if (dosya == NULL) {//dosya açılmasa bunu bize bildiriyor
        printf("Dosya acilamadi!");
        exit(1);
    }
    int yenisaat, yenidakika;
    char yenieylem[100];
    char satir[100];
    int saat, dakika;
    char yeni_eylem[50];//kulancağımız diziler ve değişkenleri tanımladım

    printf("Lutfen degistirmek istediginiz eylemin saatini girin: ");
    scanf("%d", &saat);
    printf("Lutfen degistirmek istediginiz eylemin dakikasini girin: ");
    scanf("%d", &dakika);

    printf("Lutfen yeni eylem girin: ");
    scanf("%s", yeni_eylem);//burada değişkenlere değer atadım

    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        sscanf(satir, "%d:%d => %[^\n]", &yenisaat, &yenidakika, yenieylem);//buarada eylemler dosyasındaki değerleri satır dizisine aktardık
        if (saat == yenisaat && dakika == yenidakika) {
            fprintf(geciciDosya, "%d:%d => %s\n", saat, dakika, yeni_eylem);
        } else {
            fprintf(geciciDosya, "%d:%d => %s\n", yenisaat, yenidakika, yenieylem);
            break;//burada değişiklerle birlikte verileri geçici dosyaya kaydettim
        }
    }

    fclose(geciciDosya);
    fclose(dosya);//dosyaları kapatttım

    remove("eylemler.txt");
    rename("gecici.txt", "eylemler.txt");//eylemler isimli dosya ile gecici isimli dosyayanın içeriğini değiştirir

    printf("Eylem basariyla degistirildi!");
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
