//#include <xc.h>
//
//#pragma config FOSC = HS
//#pragma config WDTE = OFF
//#pragma config PWRTE = ON
//#pragma config BOREN = ON
//#pragma config LVP = OFF
//#pragma config CPD = OFF
//#pragma config WRT = OFF
//#pragma config CP = OFF
//
//#define _XTAL_FREQ 20000000UL
//void buzz();
//
//void Delay_Ms(unsigned int ms)
//{
//    int i, count;
//
//    for(i = 1; i <= ms; i++)
//    {
//        count = 1000;
//
//        while(count != 1)
//        {
//            count--;
//        }
//    }
//}
//
//
//void send(unsigned char value, unsigned char rs)
//{
//    PORTD = value;
//
//    RC1 = rs;       // RS
//    RC0 = 0;        // RW
//    RC2 = 1;        // EN
//
//    __delay_ms(1);
//
//    RC2 = 0;
//
//    __delay_ms(5);
//}
//
//
//int main()
//{
//    TRISC = 0x00;
//    TRISD = 0x00;
//
//    PORTC = 0x00;
//    PORTD = 0x00;
//
//    __delay_ms(200);
//
//    // LCD initialization
//    send(0x30, 0);
//    __delay_ms(10);
//
//    send(0x30, 0);
//    __delay_ms(10);
//
//    send(0x30, 0);
//    __delay_ms(10);
//
//    send(0x38, 0);      // 8-bit, 2-line
//    send(0x0C, 0);      // Display ON, cursor OFF
//    send(0x01, 0);      // Clear display
//    __delay_ms(10);
//    send(0x06, 0);      // Increment cursor
//
//
//    // Keypad configuration
//    // RB0-RB4 = inputs
//    // RB5-RB7 = outputs
//
//    TRISB = 0x1F;
//
//    OPTION_REG &= 0x7F;     // Enable PORTB pull-ups
//
//    ADCON1 = 0x0F;          // Digital I/O
//
//    TRISD = 0x00;
//    
//   
//
//
//    while(1)
//    {
//        RB5 = 0;RB6 = 1;RB7 = 1;
//        send(0xC0, 0);
//        if(RB1 == 0)
//        {
//            // send(0x80, 0);
//            send('A', 1);
//          
//           
//        }
//
//        else if(RB2 == 0)
//        {    
//            //send(0x80, 0);
//            send('B', 1);
//           
//        }
//
//        else if(RB3 == 0)
//        {
//            //send(0x80, 0);
//            send('C', 1);
//      
//        }
//
//        else if(RB4 == 0)
//        {
//            //send(0x80, 0);
//            send('D', 1);
//            
//        }
//        RB5=1;RB6=0;RB7=1;
//        
//        if(RB1==0){
//            send(0x80, 0);
//            send('1', 1);
//        }
//        else if(RB2==0){
//            send(0x80, 0);
//            send('2', 1);
//        } 
//        else if(RB3==0){
//            send(0x80, 0);
//            send('3', 1);
//        } 
//        else if(RB4==0){
//            send(0x80, 0);
//            send('4', 1);
//        }
//        RB5=1;RB6=1;RB7=0;
//        if(RB1==0){
//           buzz();
//            send(0x80, 0);
//            send('5', 1);
//        } 
//        else if(RB2==0){
//            send(0x80, 0);
//            send('6', 1);
//            buzz();
//        } 
//        else if(RB3==0){
//            send(0x80, 0);
//            send('7', 1);
//        } 
//        else if(RB4==0){
//            send(0x80, 0);
//            send('8', 1);
//        }
//    }
//}
//
//void buzz(){
//    TRISE=0x00;
//    RE0=0;
//    Delay_Ms(500);
//    RE0=1;
//    Delay_Ms(500);
//}
//


//#include <xc.h>
//#include <string.h>
//
//#pragma config FOSC = HS
//#pragma config WDTE = OFF
//#pragma config PWRTE = ON
//#pragma config BOREN = ON
//#pragma config LVP = OFF
//#pragma config CPD = OFF
//#pragma config WRT = OFF
//#pragma config CP = OFF
//
//#define _XTAL_FREQ 20000000UL
//
//void send(unsigned char value, unsigned char rs);
//void stay(void);
//void Delay_Ms(unsigned int ms);
//
//char letter[5];
//unsigned char letter_index = 0;
//
//
//void Delay_Ms(unsigned int ms)
//{
//    unsigned int i, count;
//
//    for(i = 1; i <= ms; i++)
//    {
//        count = 1000;
//
//        while(count != 1)
//        {
//            count--;
//        }
//    }
//}
//
//
//void stay(void)
//{
//    if(strlen(letter) == 4)
//    {
//        // Move cursor to first position
//        send(0x80, 0);
//
//        // Display 4 characters
//        send(letter[0], 1);
//        send(letter[1], 1);
//        send(letter[2], 1);
//        send(letter[3], 1);
//
//        // Reset for next entry
//        letter_index = 0;
//        letter[0] = '\0';
//    
//    }
//}
//
//
//void send(unsigned char value, unsigned char rs)
//{
//    PORTD = value;
//
//    RC1 = rs;       // RS
//    RC0 = 0;        // RW
//    RC2 = 1;        // EN
//
//    __delay_ms(1);
//
//    RC2 = 0;
//
//    __delay_ms(5);
//}
//
//
//int main(void)
//{
//    TRISC = 0x00;
//    TRISD = 0x00;
//
//    PORTC = 0x00;
//    PORTD = 0x00;
//
//    __delay_ms(200);
//
//
//    // =========================
//    // LCD INITIALIZATION
//    // =========================
//
//    send(0x30, 0);
//    __delay_ms(10);
//
//    send(0x30, 0);
//    __delay_ms(10);
//
//    send(0x30, 0);
//    __delay_ms(10);
//
//    send(0x38, 0);      // 8-bit, 2-line
//    send(0x0C, 0);      // Display ON, cursor OFF
//    send(0x01, 0);      // Clear display
//    __delay_ms(10);
//    send(0x06, 0);      // Increment cursor
//
//
//    // =========================
//    // KEYPAD CONFIGURATION
//    // =========================
//
//    TRISB = 0x1F;
//
//    OPTION_REG &= 0x7F;     // Enable PORTB pull-ups
//
//    ADCON1 = 0x0F;          // Digital I/O
//
//    letter[0] = '\0';
//
//
//    while(1)
//    {
//
//        // =========================
//        // ROW 1
//        // A B C D
//        // =========================
//
//        RB5 = 0;
//        RB6 = 1;
//        RB7 = 1;
//
//        if(RB1 == 0)
//        {
//            if(letter_index < 4)
//            {
//                send('A', 1);
//
//                letter[letter_index] = 'A';
//                letter_index++;
//                letter[letter_index] = '\0';
//            }
//
//            __delay_ms(200);
//            stay();
//        }
//
//        else if(RB2 == 0)
//        {
//            if(letter_index < 4)
//            {
//                send('B', 1);
//
//                letter[letter_index] = 'B';
//                letter_index++;
//                letter[letter_index] = '\0';
//            }
//
//            __delay_ms(200);
//            stay();
//        }
//
//        else if(RB3 == 0)
//        {
//            if(letter_index < 4)
//            {
//                send('C', 1);
//
//                letter[letter_index] = 'C';
//                letter_index++;
//                letter[letter_index] = '\0';
//            }
//
//            __delay_ms(200);
//            stay();
//        }
//
//        else if(RB4 == 0)
//        {
//            if(letter_index < 4)
//            {
//                send('D', 1);
//
//                letter[letter_index] = 'D';
//                letter_index++;
//                letter[letter_index] = '\0';
//            }
//
//            __delay_ms(200);
//            stay();
//        }
//
//
//        // =========================
//        // ROW 2
//        // 1 2 3 4
//        // =========================
//
//        RB5 = 1;
//        RB6 = 0;
//        RB7 = 1;
//
//        if(RB1 == 0)
//        {
//            send('1', 1);
//            __delay_ms(200);
//        }
//
//        else if(RB2 == 0)
//        {
//            send('2', 1);
//            __delay_ms(200);
//        }
//
//        else if(RB3 == 0)
//        {
//            send('3', 1);
//            __delay_ms(200);
//        }
//
//        else if(RB4 == 0)
//        {
//            send('4', 1);
//            __delay_ms(200);
//        }
//
//
//        // =========================
//        // ROW 3
//        // 5 6 7 8
//        // =========================
//
//        RB5 = 1;
//        RB6 = 1;
//        RB7 = 0;
//
//        if(RB1 == 0)
//        {
//            send('5', 1);
//            __delay_ms(200);
//        }
//
//        else if(RB2 == 0)
//        {
//            send('6', 1);
//            __delay_ms(200);
//        }
//
//        else if(RB3 == 0)
//        {
//            send('7', 1);
//            __delay_ms(200);
//        }
//
//        else if(RB4 == 0)
//        {
//            send('8', 1);
//            __delay_ms(200);
//        }
//    }
//}

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

char letter[5];
unsigned char letter_index = 0;


// ========================================
// LCD FUNCTION
// ========================================

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


// ========================================
// PASSWORD CHECK
// ========================================

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
        // Clear LCD
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


// ========================================
// MAIN
// ========================================

int main(void)
{
    // ====================================
    // PORT SETUP
    // ====================================

    TRISC = 0x00;
    TRISD = 0x00;

    PORTC = 0x00;
    PORTD = 0x00;


    // ====================================
    // LCD INITIALIZATION
    // ====================================

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


    // ====================================
    // KEYPAD
    // ====================================

    // RB0-RB4 = INPUT
    // RB5-RB7 = OUTPUT

    TRISB = 0x1F;

    // Enable PORTB pull-ups
    OPTION_REG &= 0x7F;

    // Digital I/O
    ADCON1 = 0x0F;


    // Empty password
    letter_index = 0;


    // ====================================
    // MAIN LOOP
    // ====================================

    while(1)
    {

        // =================================
        // ROW 1
        // A B C D
        // =================================

        RB5 = 0;
        RB6 = 1;
        RB7 = 1;

        // A
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

        // B
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

        // C
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

        // D
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


        // =================================
        // ROW 2
        // 1 2 3 4
        // =================================

        RB5 = 1;
        RB6 = 0;
        RB7 = 1;

        // 1
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

        // 2
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

        // 3
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

        // 4
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


        // =================================
        // ROW 3
        // 5 6 7 8
        // =================================

        RB5 = 1;
        RB6 = 1;
        RB7 = 0;

        // 5
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

        // 6
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

        // 7
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

        // 8
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