/*Lab 8 ECE 422
 * filename: main.c
 * Summary: This program makes 3 leds connected to the pic processor blink in succession with time-period 1s and 0.5s,
 * the time period changes whenever a button is pressed.
 * Author: Aquib Al Ahmed Immanuel
 * Date: 11/6/20128
 */

/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system intialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.75.1
        Device            :  PIC24FJ256GA702
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.35
        MPLAB 	          :  MPLAB X v5.05
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/ext_int.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/traps.h"

/*
                         Main application
 */
int delayval=1637;
int ctr=0;
int exctr=0;
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    LED1_SetHigh() ;
    LED2_SetHigh() ;
    LED3_SetHigh() ;

    while (1)
    {
        delay();
        ctr++;
        if (ctr==1){
            LED1_SetHigh() ;
            LED2_SetLow() ;
            LED3_SetLow() ;
        }
        else if(ctr==2){
            LED1_SetLow() ;
            LED2_SetHigh() ;
            LED3_SetLow() ;
        }
        else if(ctr==3){
            LED1_SetLow() ;
            LED2_SetLow() ;
            LED3_SetHigh() ;
            ctr=0;
        }
        
    }

    return 1;
}

void delay(void)// this function also polls the button
{
    unsigned int i,j;

    for (i = 0; i < delayval; i++)
    {
        for (j = 0; j < 100; j++){
           
         
        };
    }
}
void __attribute__ ( ( interrupt, no_auto_psv ) ) _INT0Interrupt(void)
{
    //***User Area Begin->code: INT0 - External Interrupt 0***

    //***User Area End->code: INT0 - External Interrupt 0***
     unsigned int i,j;

    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < 100; j++){
           
         
        };
    }
    
    EX_INT0_InterruptFlagClear();
    if(exctr){
    delayval=1637;
    exctr++;
    }
    else{
        delayval=819;
    exctr--;
    }
}

/**
 End of File
*/

