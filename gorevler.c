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
