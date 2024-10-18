//KELOMPOK 15

#include <stdio.h>
#include <math.h>

double fungsi(double x){
	return pow(x, 3) - 4 * x - 9; // x^3 - 4x - 9
}

double turunan(double x){
	return 3 * pow(x, 2) - 4;
}

//------------------T A B E L------------------
void tableMethod(){
	double x, atas, step;
	double akar[2];
	int found = 0;
	
	printf("Masukkan batas bawah: ");
    scanf("%lf", &x);
    printf("Masukkan batas atas: ");
    scanf("%lf", &atas);
    printf("Masukkan step: ");
    scanf("%lf", &step);
	
	
    printf("x\tf(x)\n");
    printf("-----------------\n");

	while(x <= atas){
		double fx = fungsi(x);
		printf("%.4f\t%.4f\n", x, fx);
		
		if(fabs(fx) < 1e-5 ){
			found = 1;
			akar[0] = x;
		}
		
		double fx_next = fungsi(x+step);
		if(fx * fx_next < 0){
			found = 2;
			akar[0] = x;
			akar[1] = x+step;
		}
		
		 x += step;
	}
	
	if(!found){
		printf("Akar tidak ditemukan pada range yang diberikan\n");
	}else if(found == 1){
		printf("Akar ditemukan pada x = %.4f\n", akar[0]);
	}else if(found == 2){
		printf("Akar berada diantara x = %.4f dan x = %.4f\n", akar[0], akar[1]);
	}
	
}
//------------------B I S E C T I O N------------------
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
//------------------R E G U L A  F A L S I------------------
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

//------------------N E W T O N - R A P H S O N------------------
void newtonRaphsonMethod() {
    double x, tolerance;
    int maxIter, iter = 0;

    printf("Masukkan perkiraan awal untuk x: ");
    scanf("%lf", &x);
    printf("Masukkan toleransi kesalahan (contoh: 0.0001): ");
    scanf("%lf", &tolerance);
    printf("Masukkan maksimum iterasi: ");
    scanf("%d", &maxIter);
    
    printf("Iterasi\t\tx\t\t\tf(x)\n");
    printf("--------------------------------------------------------\n");
	
    while(iter < maxIter) {
		
        if(fabs(turunan(x)) < 1e-6) {
            printf("Error: Turunan mendekati nol, metode tidak dapat dilanjutkan.\n");
            return;
        }
        
		printf("%d\t\t%.6lf\t\t%.6lf\n", iter, x, fungsi(x));
		
        if(fabs(fungsi(x)) <= tolerance){
        	break;
		}
		
        x = x - (fungsi(x) / turunan(x));
        iter++;
    }

    if(fabs(fungsi(x)) <= tolerance) {
        printf("\nAkar ditemukan pada x = %.6lf setelah %d iterasi.\n", x, iter);
    }else {
        printf("\nAkar tidak ditemukan dalam jumlah iterasi maksimum.\n");
    }
}

void start(){
	int pilihan = 0;
	
	printf("1.Metode Tabel\n2.Metode Bisection\n3.Metode Regula Falsi\n4.Metode Newton-Raphson\nMasukkan salah satu metode(0 untuk exit): ");
	scanf("%d", &pilihan);
	
	if(pilihan == 1){
		tableMethod();
	}else if(pilihan == 2){
		bisectionMethod();
	}else if(pilihan == 3){
		regulaFalsiMethod();
	}else if(pilihan == 4){
		newtonRaphsonMethod();
	}else if(pilihan == 0){
		return;
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

//KELOMPOK 15
