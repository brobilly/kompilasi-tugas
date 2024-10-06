//Billy Ramadhani
//23081010078

#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

struct journal{
    char judul[100];
    char penulis[200];
    char afiliasi[100];
    char email[50];
    char abstrak[2000];
    char kataKunci[100];
};

struct journal jrnl;

bool isChar(char c){
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void header(){
	printf("============WRITEJOURNAL v1.0============\n\n");
}

void getJudul(){
	fflush(stdin);
	printf("Masukkan judul journal(5-14 kata):\n");
	scanf("%[^\n]", jrnl.judul);
	
	int length, i;
	
	for(i=0; i<strlen(jrnl.judul); i++){
		if(jrnl.judul[i] == ' '){
			length++;
		}
	}
	
	if(length < 4 || length > 13){ //4 karena 5 kata terdiri dari 4 spasi, begitu juga 13 
		system("cls");
		header();
		printf("Masukkan antara 5-14 kata!\n\n");
		getJudul();
	}
	system("cls");
	header();
}

void getPenulis(){
	fflush(stdin);
	printf("Masukkan nama penulis, maksimal 3 penulis(contoh:Billy, Aril, Deva):\n");
	scanf("%[^\n]", jrnl.penulis);
	
	int j;
	int count = 0;
	for(j=0; j<strlen(jrnl.penulis); j++){
		if (jrnl.penulis[j] == ','){
			count++;			
		}
	}

	if(count > 2){
		system("cls");
		header();
		printf("Maksimal 3 penulis!\n");
		getPenulis();
	}
	system("cls");
	header();
}

void getAfiliasi(){
	fflush(stdin);
	printf("Masukkan lembaga afiliasi anda:\n");
	scanf("%[^\n]", jrnl.afiliasi);
	system("cls");
	header();
}

void getEmail(){
	fflush(stdin);
	printf("Masukkan email:\n");
	scanf("%[^\n]", jrnl.email);
	
	int startDomain = strlen(jrnl.email) - 6;
	char topDomain[6] = "";
	strncat(topDomain, jrnl.email + startDomain, 6);
	
	
	if(!strchr(jrnl.email, '@')){
		system("cls");
		header();
		printf("Masukkan email dengan benar!\n\n");
		getEmail();
	}
	
	if(!isChar(jrnl.email[0])){
		system("cls");
		header();
		printf("Masukkan email dengan benar!\n\n");
		getEmail();
	}
	
	if(strcmp(topDomain, ".ac.id") != 0){
		system("cls");
		header();
		printf("Masukkan email dengan benar!\n\n");
		getEmail();
	}
	system("cls");
	header();
}

void getAbstrak(){
	fflush(stdin);
	printf("Masukkan abstrak(maks. 200 kata):\n");
	scanf("%[^\n]", jrnl.abstrak);
	
	int length, i;
	
	for(i=0; i<strlen(jrnl.abstrak); i++){
		if(jrnl.abstrak[i] == ' '){
			length++;
		}
	}
	
	if(length > 199){
		system("cls");
		header();
		printf("Maksimal 200 kata!\n\n");
		getAbstrak();
	}
	system("cls");
	header();
}

void getKataKunci(){
	fflush(stdin);
	printf("Masukkan kata kunci(3-5 kata dipisahkan oleh koma)\n");
	scanf("%[^\n]", jrnl.kataKunci);
	
	int j;
	int count = 0;
	for(j=0; j<strlen(jrnl.kataKunci); j++){
		if (jrnl.kataKunci[j] == ','){
			count++;			
		}
	}

	if(count < 2 || count > 4){
		system("cls");
		header();
		printf("Masukkan antara 3-5 kata!\n");
		getKataKunci();
	}
	system("cls");
}

void printResult(){
	printf("%s\n\n%s\n%s\n%s\n\n%s\n\nKata Kunci: %s", jrnl.judul, jrnl.penulis, jrnl.afiliasi, jrnl.email, jrnl.abstrak, jrnl.kataKunci);
}

int main(){

	header();
	
	getJudul();
	getPenulis();
	getAfiliasi();
	getEmail();
	getAbstrak();
	getKataKunci();

	printResult();
    return 0;
}
