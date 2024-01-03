void silme(){
   fileAdres = fopen("eylemler.txt", "w");  // dosyayı yazma komutuyla açtım
    if(fileAdres != NULL){
        fclose(fileAdres); // dosyayı kapattığımda dosya içeriği silinir
        printf("Gorevler silindi \n");
    }
    else
        printf("Dosya acilamadi\n"); // dosya açılmazsa bu mesaj ekrana yazılacak
}
