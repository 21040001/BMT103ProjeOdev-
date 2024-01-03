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
    FILE *geciciDosya = fopen("dosya.txt", "w");//dosya adlı dosya açtı
    FILE *dosya = fopen("eylemler.txt", "r");//eylemler dosyasını okudu
    if (dosya == NULL) {
        printf("Dosya acilamadi!");
        exit(1);
    }//dosya boş ise bunu bildiriyor
    int yenisaat, yenidakika;
    char yenieylem[100];
    char satir[100];
    int saat, dakika;
    char yeni_eylem[50];//değişkenleri ve dizileri tanımladık

    printf("Lutfen degistirmek istediginiz gorevin saatini girin:\n ");
    scanf("%d", &saat);
    printf("Lutfen degistirmek istediginiz gorevin dakikasini girin:\n ");
    scanf("%d", &dakika);

    printf("Lutfen yeni gorev girin:\n ");
    scanf("%s", yeni_eylem);//değişkenlere değer atadık

    while (fgets(satir, sizeof(satir), dosya) != NULL) {//eylemler dosyasındaki değerleri satır adındaki diziye girdik
        sscanf(satir, "%d:%d => %s\n]", &yenisaat, &yenidakika, yenieylem);
        if (saat == yenisaat && dakika == yenidakika) {
           fprintf(geciciDosya, "%d:%d => %s\n", saat, dakika, yeni_eylem);
        } else {
           fprintf(geciciDosya, "%d:%d => %s\n", yenisaat, yenidakika, yenieylem);
        }
    }     //burada değişiklerle birlikte verileri geçici dosyaya kaydettim

    fclose(geciciDosya);
    fclose(dosya);//dosyaları kapattım

    remove("eylemler.txt");
    rename("dosya.txt", "eylemler.txt");// dasya adındaki dosyadaki  verileri eylemler adındaki dosyaya attım

    printf("gorev basariyla degistirildi!\n");
}
void gorevler(){
    char c;
    fileAdres = fopen("eylemler.txt", "r");//eylemler dosyasını açtım
    if (fileAdres == NULL)
    {
        printf("Dosya açılamadı!\n");
        exit(1);
    }//dosya boşsa bunu bize bildiriyor
    c = fgetc(fileAdres);//eylemler dosyasındaki verileri değişkene atadım
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fileAdres);
    }//değikendeki verileri döngü yardımı ile ekrana yazdırdım
    fclose(fileAdres);//dosyayı kapattım
}

void silme(){
   fileAdres = fopen("eylemler.txt", "w");  // dosyayı yazma momutuyla açtım
    if(fileAdres != NULL){
        fclose(fileAdres); // dosyayı kapattığımda dosya içeriği silinir
        printf("Gorevler silindi \n");
    }
    else
        printf("Dosya acilamadi\n"); // dosya açılmazsa bu hatra mesaj ekrana yazılacak
}
