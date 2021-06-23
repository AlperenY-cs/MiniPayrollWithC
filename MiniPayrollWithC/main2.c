#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
    /*
        İşyeri Maaş Bilgileri 
        
        -----------------------------------------------
        Meslek ID: 1 / Yazılım Ekibi Günlük Ücret: 300 ₺
        -----------------------------------------------
        Meslek ID: 2 / İdari Ekip Günlük Ücret: 500 ₺
        -----------------------------------------------
        Meslek ID: 3 / Muhasebe Ekibi Günlük Ücret: 200₺
        -----------------------------------------------

    */
    int personelNetMaas, sayac, secim, calistigiGun, meslekID;
    int yazilimEkibiGunluk, idariEkipGunluk, muhEkipGunluk;
    char personelAdiSoyadi[20], gorev[20]; 

    //Günlük Maaş Sabitleri
    yazilimEkibiGunluk = 300;
    idariEkipGunluk = 500;
    muhEkipGunluk = 200;   
    
    /* --- Txt Dosya Açma ---*/
    FILE *fp;


    //Başlık
    printf("%s\n","--- PERSONEL MAAS HESAPLAMA ---");
    
    
    sayac = 1;
    while (sayac == 1)
    {
        
        fp = fopen("personelDB.txt","a");
        printf("\n%s\n","1) Personel Maas Hesapla");
        printf("%s\n","2) Personelleri Listele");
        printf("%s\n","3) Cikis");

        printf("Lutfen Seciminizi Giriniz: ");
        scanf("%d", &secim);
        if (secim == 1)
        {
            // UYARI !
            printf("\n\n%s\n", "Personel adini ve soyadini bitisik yaziniz!");
            printf("Personel Adi Soyadi: ");
            scanf(" %s", &personelAdiSoyadi);

            printf("Calistigi gun sayisi: ");
            scanf(" %d", &calistigiGun);

            printf("%s\n","Meslek ID Giriniz:  ---1) Yazilim Ekibi---2) Idari Ekip---3) Muhasebe Ekibi--- ");
            scanf(" %d", &meslekID);

                if (meslekID == 1)
                {
                    personelNetMaas = yazilimEkibiGunluk * calistigiGun;
                    printf("Maas Bilgisi: %d\n",personelNetMaas);
                    fprintf(fp, "Ad:%s,Gorev:%s,Maas:%d\n\n", personelAdiSoyadi,"YazilimEkibi", personelNetMaas);         
                };
                if (meslekID == 2)
                {
                    personelNetMaas = idariEkipGunluk * calistigiGun;
                    printf("Maas Bilgisi: %d\n", personelNetMaas);
                    fprintf(fp, "Ad:%s,Gorev:%s,Maas:%d\n\n", personelAdiSoyadi,"IdariEkip", personelNetMaas);                    
                };
                if (meslekID == 3)
                {
                    personelNetMaas = muhEkipGunluk * calistigiGun;
                    printf("Maas Bilgisi: %d\n", personelNetMaas);
                    fprintf(fp, "Ad:%s,Gorev:%s,Maas:%d\n\n", personelAdiSoyadi,"MuhasebeEkibi", personelNetMaas);
                };

        };
        fclose(fp);

        if (secim == 2)
        {   
            fp = fopen("personelDB.txt","r");
            if (fp)
            {
                
                while (!feof(fp))
                {
                    fputchar(fgetc(fp));
                }
                fclose(fp);
                
                
            };            
        };

        if (secim == 3)
        {
            printf("Programdan cikis yapildi!");
            break;
        };
             

    }//While Bitişi
    sayac= sayac+1; 

    //Dosya Bağlantısı Kesme
    fclose(fp); 
    return 0;
}
