void guncelle() {
    FILE *geciciDosya = fopen("dosya.txt", "w");//dosya adlı dosya açtı
    FILE *dosya = fopen("eylemler.txt", "r");//eylemler dosyasını okudu
    if (dosya == NULL) {
        printf("Dosya acilamadi!");
        exit(1);
    }//dosya boş ise bunu bildiriyor
    int dsaat, ddakika;
    char deylem[100];
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
        sscanf(satir, "%d:%d => %s\n]", &dsaat, &ddakika, deylem);
        if (saat == dsaat && dakika == ddakika) {
           fprintf(geciciDosya, "%d:%d => %s\n", saat, dakika, yeni_eylem);
        } else {
           fprintf(geciciDosya, "%d:%d => %s\n", dsaat, ddakika, deylem);
        }
    }     //burada değişiklerle birlikte verileri geçici dosyaya kaydettim

    fclose(geciciDosya);
    fclose(dosya);//dosyaları kapattım

    remove("eylemler.txt");
    rename("dosya.txt", "eylemler.txt");// dasya adındaki dosyadaki  verileri eylemler adındaki dosyaya attım

    printf("gorev basariyla degistirildi!\n");
}
