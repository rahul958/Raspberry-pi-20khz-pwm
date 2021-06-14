#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define enable  1
#define disable 0
#define chip 0
        // We are using PWMchip0 beacause there is only a single hardware PWM pin in Raspberry pi
//unsigned int period = 0 ;
char duty_cycle_path[] = "/sys/class/pwm/pwmchip0/pwm0/duty_cycle";     //duty cycle file location
char enable_path[] = "/sys/class/pwm/pwmchip0/pwm0/enable";             // Enable File lacation
char period_path[] = "/sys/class/pwm/pwmchip0/pwm0/period";             // Time Period location( T= $
char export_path[] = "/sys/class/pwm/pwmchip0/export";                  // Path to notify system tha$
char unexport_path[] = "/sys/class/pwm/pwmchip0/unexport";              // disable pwm Setup
unsigned int period = 50000;

int file_write(char location[] , unsigned int value);
int pwm_init(void);
int chnage_dutycycle(int rxd_duty_cycle);
int pwm_disable(void);
int change_pwm_freq(unsigned int freq);


int pwm_init(void)
{
        if (file_write (export_path , 0))
                return 1;
        if(file_write(duty_cycle_path , 0))
                return 1;
        if(file_write(period_path , period))
                return 1;
	if(file_write(enable_path , enable))
		return 1;
        return 0 ;
}

int file_write(char location[], unsigned int value){                            // function to write$
        FILE *fptr;                                                     //file pointer declaration
        fptr = fopen(location,"w");
        if(fptr == NULL)                                                //checking for NULL condition
        {       printf("Error! Writing to file");
                return 1;
        }
        fprintf(fptr, "%d", value);
        fclose(fptr);
        return 0;
}
int chnage_dutycycle(int rxd_duty_cycle){
	if(rxd_duty_cycle <= 100){
		unsigned int duty_period = rxd_duty_cycle * period/100;
		if(file_write(duty_cycle_path ,duty_period))
			return 1 ;
		return 0;
	}
	else
	return 1;
}

int pwm_disable(void){
//	if (file_write (export_path , 0))
//                return 1;
//      if(file_write(duty_cycle_path , 0))
//                return 1;
//      if(file_write(period_path , period))
//                return 1;
        if(file_write(enable_path , disable)) 
		 return 1;
        return 0;

}
int change_pwm_freq(unsigned int freq){
	period = 100000000/freq;
	if(file_write(period_path , period))
		return 1;
	return 0;
}
