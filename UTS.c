#include <stdio.h>
#include <math.h>

double fungsi(double x){
	return pow(x, 3) - 4 * x - 9;
}
//------------------TABEL------------------
void tableMethod(){
	double bawah, atas, step;
	double x = bawah;
	int found = 0;
	
	printf("Masukkan batas bawah: ");
    scanf("%lf", &bawah);
    printf("Masukkan batas atas: ");
    scanf("%lf", &atas);
    printf("Masukkan step: ");
    scanf("%lf", &step);
	
	
    printf("x\tf(x)\n");
    printf("-----------------\n");

	while(x <= atas){
		double fx = fungsi(x);
		printf("%.4f\t%.4f\n", x, fx);
		
		if(fabs(fx) < 1e-6 ){
			//printf("Akar ditemukan pada x = %.4f\n", x);
			found = 1;
		}
		
		double fx_next = fungsi(x+step);
		if (fx * fx_next < 0){
			//printf("Akar berada diantara x = %.4f dan x = %.4f\n", x, x+step);
			found = 2;
		}
		
		 x += step;
	}
	
	if(!found){
		printf("Akar tidak ditemukan pada range yang diberikan\n");
	}else if(found == 1){
		printf("Akar ditemukan pada x = %.4f\n", x);
	}else if(found == 2){
		printf("Akar berada diantara x = %.4f dan x = %.4f\n", x, x+step);
	}
	
}
//------------------BISECTION------------------
void bisectionMethod(){
    int found = 0;
    double bawah, tengah, atas, tolerance;
    
    printf("Masukkan batas bawah: ");
    scanf("%lf", &bawah);
    printf("Masukkan batas atas: ");
    scanf("%lf", &atas);
    printf("Masukkan toleransi kesalahan (contoh: 0.0001): ");
    scanf("%lf", &tolerance);
    
    if(fungsi(bawah) * fungsi(atas) >= 0) {
        printf("Error, tidak ada perubahan tanda pada range yang diberikan.\n");
        return;
    }
    
    printf("a\tb\tc\tf(c)\tf(a)\n");
    printf("--------------------------------------------\n");

    while(found == 0) {
        tengah = (bawah + atas) / 2.0;
        printf("%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.6lf\n", bawah, atas, tengah, fungsi(tengah), fungsi(bawah));
        
        if(fabs(fungsi(tengah)) < tolerance) {
            found = 1;
            break;
        }
        
        if(fungsi(bawah) * fungsi(tengah) < 0) {
            atas = tengah;
        } else {
            bawah = tengah;
        }
    }
    
        printf("\nAkar ditemukan pada x = %.6lf\n", tengah);
}
//------------------REGULA FALSI------------------
void regulaFalsiMethod() {
    int found = 0;
    double bawah, atas, x, tolerance;
    
    printf("Masukkan batas bawah: ");
    scanf("%lf", &bawah);
    printf("Masukkan batas atas: ");
    scanf("%lf", &atas);
    printf("Masukkan toleransi kesalahan (contoh: 0.0001): ");
    scanf("%lf", &tolerance);
    
    if(fungsi(bawah) * fungsi(atas) >= 0) {
        printf("Error, tidak ada perubahan tanda pada range yang diberikan.\n");
        return;
    }
    
    printf("a\tb\tx\tf(x)\tf(a)\n");
    printf("--------------------------------------------\n");

    while(found == 0) {
        x = (fungsi(atas) * bawah - fungsi(bawah) * atas) / (fungsi(atas) - fungsi(bawah));
		printf("%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.6lf\n", bawah, atas, x, fungsi(x), fungsi(bawah));
        
        if(fabs(fungsi(x)) < tolerance) {
            found = 1;
            break;
        }
        
        if(fungsi(bawah) * fungsi(x) < 0) {
            atas = x;
        } else {
            bawah = x;
        }
    }
    
        printf("\nx ditemukan pada x = %.6lf\n", x);
}

void start(){
	int pilihan = 0;
	
	printf("1.Metode Tabel\n2.Metode Bisection\n3.Metode Regula Falsi\nMasukkan salah satu metode(0 untuk exit): ");
	scanf("%d", &pilihan);
	
	if(pilihan == 1){
		tableMethod();
	}else if(pilihan == 2){
		bisectionMethod();
	}else if(pilihan == 3){
		regulaFalsiMethod();
	}else if(pilihan == 0){
		return 0;
	}else{
		printf("\nMasukkan pilihan dengan benar!\n\n");
		system("pause");
		system("cls");
		start();
	}
}

int main(){
	
	start();
	
	return 0;
}
