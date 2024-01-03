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
