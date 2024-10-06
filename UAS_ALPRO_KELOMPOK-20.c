//_____PROGRAM ENKRIPSI MENGGUNAKAN 3 CIPHER METHODE______

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void caesarEncrypt(char text[], int shift){
    char ch;
    int i;
    
    for (i = 0; i <= strlen(text); ++i) {  
        ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a'; //abc 
            text[i] = ch;
        }else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
            text[i] = ch;
        }
    }
}

void caesarDecrypt(char text[], int shift) {
    char ch;
    int i;
    
    for(i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a'; // abc 24 + 97
            text[i] = ch;
        }else if(ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
            text[i] = ch;
        }
    }
}

void atbash(char text[]) {
    char ch;
    int i;
    
    for(i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if(ch >= 'a' && ch <= 'z') {
            text[i] = 'z' - (ch - 'a');
        }else if(ch >= 'A' && ch <= 'Z') {
            text[i] = 'Z' - (ch - 'A');
        }
    }
}

void rot13(char text[]){
	char ch;
	int i;
	
	for (i = 0; text[i] != '\0'; ++i){
		ch = text[i];
		
		if(ch >= 'a' && ch <= 'z'){
			if(ch >= 'a' && ch <= 'm'){
				text[i] = ch + 13;
			}else{
				text[i] = ch - 13;
			}
		}else if(ch >= 'A' && ch <= 'Z'){
			if(ch >= 'A' && ch <= 'M'){
				text[i] = ch + 13;
			}else{
				text[i] = ch - 13;
			}
		}
	}
}


int main() {
    char text[100];
    int shift;
    
    int option, option2;
    char restart = 'y';
    
    while(restart == 'y'){
    	
    	system("cls");
    	printf("1.Caesar Cipher\n");
    	printf("2.Atbash Cipher\n");
    	printf("3.ROT13 Cipher\n\n");
    	printf("Pilih salah satu cipher: ");
    	scanf("%d", &option);
    
    	if(option == 1){
		
		system("cls");
    	printf("1.Encrypt\n");
    	printf("2.Decrypt\n");
    	printf("\nPilih proses yang ingin dilakukan: ");
    	scanf("%d", &option2);
    	
    		if(option2 == 1){
    		
    			system("cls");
    	    	printf("Masukkan teks: ");
    	    	fflush(stdin);
    			gets(text);
    			printf("Masukkan shift: ");
    			scanf("%d", &shift);
    			caesarEncrypt(text, shift);
    			printf("\nEncrypted text: %s\n", text);
    			printf("===============================\nApakah anda ingin menggunakan program lagi?(y/n)");
    			fflush(stdin);
				scanf("%c", &restart);
				
			}else if(option2 == 2){
			
				system("cls");
    	    	printf("Masukkan teks: ");
    	    	fflush(stdin);
    			gets(text);
    			printf("Masukkan shift: ");
    			scanf("%d", &shift);
    			caesarDecrypt(text, shift);
    			printf("\nDecrypted text: %s\n", text);
    			printf("===============================\nApakah anda ingin menggunakan program lagi?(y/n)");
    			fflush(stdin);
				scanf("%c", &restart);
    		
			}
		}else if(option == 2){
		
		system("cls");
		printf("1.Encrypt\n");
    	printf("2.Decrypt\n");
    	printf("\nPilih proses yang ingin dilakukan: ");
    	scanf("%d", &option2);
    	
    		if(option2 == 1){
    		
    			system("cls");
    	    	printf("Masukkan teks: ");
    	    	fflush(stdin);
    			gets(text);
    			atbash(text);
    			printf("\nEncrypted text: %s\n", text);
    			printf("===============================\nApakah anda ingin menggunakan program lagi?(y/n)");
    			fflush(stdin);
				scanf("%c", &restart);
				
			}else if(option2 == 2){
			
				system("cls");
    	    	printf("Masukkan teks: ");
    	    	fflush(stdin);
    			gets(text);
    			atbash(text);
    			printf("\nDecrypted text: %s\n", text);
        		printf("===============================\nApakah anda ingin menggunakan program lagi?(y/n)");
    			fflush(stdin);
				scanf("%c", &restart);
    		
			}
		}else if(option == 3){
		
		system("cls");
		printf("1.Encrypt\n");
    	printf("2.Decrypt\n");
    	printf("\nPilih proses yang ingin dilakukan: ");
    	scanf("%d", &option2);
    	
    		if(option2 == 1){
    		
    			system("cls");
    	    	printf("Masukkan teks: ");
    	    	fflush(stdin);
    			gets(text);
    			rot13(text);
    			printf("\nEncrypted text: %s\n", text);
    			printf("===============================\nApakah anda ingin menggunakan program lagi?(y/n)");
    			fflush(stdin);
				scanf("%c", &restart);
				
			}else if(option2 == 2){
				
				system("cls");
	    	    printf("Masukkan teks: ");
	    	    fflush(stdin);
	    		gets(text);
	    		rot13(text);
	    		printf("\nDecrypted text: %s\n", text);
    			printf("===============================\nApakah anda ingin menggunakan program lagi?(y/n)");
    			fflush(stdin);
				scanf("%c", &restart);
	    		
			}
    	
		}	
	}
    
    return 0;
}

