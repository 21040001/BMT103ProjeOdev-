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
