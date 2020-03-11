#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void bandingkanFile(FILE *fp1, FILE *fp2);

int main(){
    FILE *fp1 = fopen("file1.txt","r");
    FILE *fp2 = fopen("file2.txt","r");

    if(fp1 == NULL || fp2 == NULL){
        printf("File gagal diproses\n");
        printf("Tekan sembarangan untuk keluar!\n");
        getch();
    }

    bandingkanFile(fp1, fp2);

    fclose(fp1);
    fclose(fp2);

    printf("\n\n\n");
    return 0;
}

void bandingkanFile(FILE *fp1, FILE *fp2){

    char ch1, ch2;
    int error = 0;
    int posisi = 0;
    int baris = 1;

    while((ch1 = getc(fp1) != EOF) && (ch2 = getc(fp2) != EOF)) {
        posisi++;
        // jika sudah menemukan enter
        if(ch1 == '\n' && ch2 == '\n'){
            baris++;
            posisi = 0;
        }
        // jika karakter antar kedua file ada yang beda
        if(ch1 != ch2){
            error++;
            printf("Error pada baris ke %i, posisi ke %i\n", baris, posisi);
            printf("File 1: %c :: File 2: %c\n", ch1, ch2);
        }
    }

}
