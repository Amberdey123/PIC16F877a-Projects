#include <xc.h>

#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

#define _XTAL_FREQ 20000000UL

void send(unsigned char value, unsigned char rs);
void check_password(void);
void buzz();
char letter[5];
unsigned char letter_index = 0;

//LCD initialization 

void send(unsigned char value, unsigned char rs)
{
    PORTD = value;

    RC1 = rs;       // RS
    RC0 = 0;        // RW
    RC2 = 1;        // EN

    __delay_ms(1);

    RC2 = 0;

    __delay_ms(5);
}
//password checking
void check_password(void)
{
    // Check A123 manually
    if(letter[0] == 'A' &&
       letter[1] == '1' &&
       letter[2] == '2' &&
       letter[3] == '3')
    {
        // Clear LCD
        send(0x01, 0);
        __delay_ms(10);

        send(0x80, 0);

        send('W', 1);
        send('E', 1);
        send('L', 1);
        send('C', 1);
        send('O', 1);
        send('M', 1);
        send('E', 1);
    }
    else
    {
        send(0x01, 0);
        __delay_ms(10);

        send(0x80, 0);

        send('W', 1);
        send('R', 1);
        send('O', 1);
        send('N', 1);
        send('G', 1);
        send(' ',1);
        send('P',1);
        send('A',1);
        send('S',1);
        send('S',1);
        send('W',1);
        send('O',1);
        send('R',1);
        send('D',1);
        buzz();
    }

    // Reset password
    letter_index = 0;

    letter[0] = 0;
    letter[1] = 0;
    letter[2] = 0;
    letter[3] = 0;
    letter[4] = 0;

    // Keep result on screen
    __delay_ms(1500);

    // Clear LCD
    send(0x01, 0);
    __delay_ms(10);
}

int main(void)
{

    TRISC = 0x00;
    TRISD = 0x00;

    PORTC = 0x00;
    PORTD = 0x00;
    __delay_ms(200);
    send(0x30, 0);
    __delay_ms(10);
    send(0x30, 0);
    __delay_ms(10);
    send(0x30, 0);
    __delay_ms(10);
    send(0x38, 0);      // 8-bit, 2-line
    send(0x0C, 0);      // Display ON, cursor OFF
    send(0x01, 0);      // Clear display
    __delay_ms(10);
    send(0x06, 0);      // Cursor increment
    TRISB = 0x1F;
    // Enable PORTB pull-ups
    OPTION_REG &= 0x7F;
    // Digital I/O
    ADCON1 = 0x0F;
    // Empty password
    letter_index = 0;
    while(1)
    {
        RB5 = 0;RB6 = 1;RB7 = 1;
        if(RB1 == 0)
        {
            if(letter_index < 4)
            {
                send('A', 1);

                letter[letter_index] = 'A';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
        else if(RB2 == 0)
        {
            if(letter_index < 4)
            {
                send('B', 1);

                letter[letter_index] = 'B';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
        else if(RB3 == 0)
        {
            if(letter_index < 4)
            {
                send('C', 1);

                letter[letter_index] = 'C';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
        else if(RB4 == 0)
        {
            if(letter_index < 4)
            {
                send('D', 1);

                letter[letter_index] = 'D';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
        RB5 = 1;RB6 = 0;RB7 = 1;
        if(RB1 == 0)
        {
            if(letter_index < 4)
            {
                send('1', 1);

                letter[letter_index] = '1';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
        
        else if(RB2 == 0)
        {
            if(letter_index < 4)
            {
                send('2', 1);

                letter[letter_index] = '2';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
        else if(RB3 == 0)
        {
            if(letter_index < 4)
            {
                send('3', 1);

                letter[letter_index] = '3';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
        else if(RB4 == 0)
        {
            if(letter_index < 4)
            {
                send('4', 1);

                letter[letter_index] = '4';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }

        RB5 = 1;RB6 = 1;RB7 = 0;

       
        if(RB1 == 0)
        {
            if(letter_index < 4)
            {
                send('5', 1);

                letter[letter_index] = '5';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
        else if(RB2 == 0)
        {
            if(letter_index < 4)
            {
                send('6', 1);

                letter[letter_index] = '6';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
        else if(RB3 == 0)
        {
            if(letter_index < 4)
            {
                send('7', 1);

                letter[letter_index] = '7';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
        else if(RB4 == 0)
        {
            if(letter_index < 4)
            {
                send('8', 1);

                letter[letter_index] = '8';
                letter_index++;

                __delay_ms(250);
            }

            if(letter_index == 4)
            {
                check_password();
            }
        }
    }

    return 0;
}

void buzz(){
    TRISE=0x00;
    RE0=1;
    __delay_ms(2500);
    RE0=0;
    __delay_ms(2500);
}