FILE * fileAdres;
void ekle(){
    struct gorev gorev1;
    fileAdres = fopen("eylemler.txt","a+");//eylemler dosyasını açtım

    printf("Lutfen gorev saati giriniz!! \n");
    scanf("%d", &gorev1.saat);
    printf("Lutfen gorev dakikasini giriniz!! \n");
    scanf("%d", &gorev1.dakika);
    printf("Lutfen gorevi giriniz!!  \n");

    scanf("%s",gorev1.eylem);//değişkenlere değer atadım

    if (fileAdres == NULL){
        printf("Dosya olusturulamadi, uzgunuz !!");
        exit(1);
    }//dosya boş ise bildiriyor
    fprintf(fileAdres," %d:%d => %s \n ",gorev1.saat,gorev1.dakika,gorev1.eylem);//değişkenleri eylemler dosyasının içine yazdırdım
    fclose(fileAdres);//dosyayı kapattım

}
