#include <stdio.h>
#include <math.h>

int main(){
    int total = 450;
    int CS = 0;
    int law = 0;
    int mkt = 0;
    int CStotal = 14;
    int lawtotal = 23;
    int mkttotal = 24;
    int years = 0;

    while (total < 1500){
    
        total = total+CStotal+lawtotal+mkttotal;
        years++;
        printf("%d \n", total);
    }

    printf("It will take %d years to reach 1,500 students", years);
    

}