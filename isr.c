/*
 * File:   isr.c
 * Author: ameen
 *
 * Created on 11 March, 2024, 8:16 PM
 */


#include <xc.h>
#include "main.h"
extern unsigned char sec, min;
void __interrupt() isr(void)
{
    static unsigned int count = 0;
    
    if (TMR2IF == 1)
    {
        if (++count == 1250)
        {
            count = 0;
            if(sec > 0)
            {
                sec--;
            }
            else if(sec == 0 && min > 0)
            {
                min--;
                sec = 59;
        }
        }        
        TMR2IF = 0;
    }
}
