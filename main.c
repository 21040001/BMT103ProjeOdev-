#include <stdio.h>

void ekle();
void guncelle();
void gorevler();
void silme();
int main(){
    int a;
    while (1){
    printf("*Isleminizi Seciniz*\n" );
    printf("1 - Plan Ekle\n");
    printf("2 - Plan Guncelle\n");
    printf("3 - Plani Sil\n");
    printf("4 - Plani Goruntule\n");
    printf("5 - Programi bitir\n");//burada fonksiyonlara sayı atadım
    scanf("%d", &a);

    switch (a) {
        case 1:
            ekle();
            break;
        case 2:
            guncelle();
            break;
        case 3:
            silme();
            break;
        case 4:
            gorevler();
            break;
        case 5:
            return 0;
        default:
            printf("Gecersiz deger girdiniz !!!!!\n");
            break;//burada girdiğimiz sayıya karşılık gelen fonksiyonu çağırdık
    }
    }

}
