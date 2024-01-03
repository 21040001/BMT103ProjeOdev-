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
