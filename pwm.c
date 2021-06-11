#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define enable  1
#define disable 0
#define chip 0
        // We are using PWMchip0 beacause there is only a single hardware PWM pin in Raspb$
//unsigned int period = 0 ;
char duty_cycle_path[] = "/sys/class/pwm/pwmchip0/pwm0/duty_cycle";     //duty cycle file $
char enable_path[] = "/sys/class/pwm/pwmchip0/pwm0/enable";             // Enable File lac$
char period_path[] = "/sys/class/pwm/pwmchip0/pwm0/period";             // Time Period loc$
char export_path[] = "/sys/class/pwm/pwmchip0/export";                  // Path to notify $
char unexport_path[] = "/sys/class/pwm/pwmchip0/unexport";              // disable pwm Set$

unsigned int period = 0;

int file_write(char file_name[] , unsigned int value);
void pwm_init()
{
        if (file_write (export_path , 0))
                return 1;
        if(file_write(duty_cycle_path , 0));
                return 1;
        if(file_write(
int file_write(char location[], unsigned int value){                            // functio$
        FILE *fptr;                                                     //file pointer dec$
        fptr = fopen(file_name,"w");
        if(fptr == NULL)                                                //checking for NUL$
        {       printf("Error! Writing to file");
                return 1;
        }
        fprintf(fptr, "%d", value);
        fclose(fptr);
        return 0;
}
