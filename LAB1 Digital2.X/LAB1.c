// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
// Configuración del PIC
#pragma config FOSC = INTRC_CLKOUT// Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic16f887.h>
int on; // Variable de enable
int a = 0; // Variable de cremcimiento
int b = 0; // Variable de crecimiento 2
//int pull =0;
/*
 * Llamado de todas las funciones antes de empezar el programa para que se inicie la jerarquia
 */
void segment (void); 
void configp (void);
void crecimiento1p (void);
void crecimiento2p (void);
void sevenseg (void);
void ciclocheck (void);
void Start (void);
void delay_ms (unsigned int dms);
//*************************************************************************************************
//PROGRAMA inicio donde empieza la configuración
//*************************************************************************************************
void main(void) {
    configp (); //llamado de la configuración del puertos
    ciclocheck();//chequeo del push para iniciar
    return;
}
//*************************************************************************************************
//Chekeados de boton de inciio para empezar el programa
//*************************************************************************************************
void ciclocheck (void){
    while (on == 0){// Ciclo para revisar el boton
        if (PORTDbits.RD1 == 1){//revisión del boton
            on = 0;
        } else {
            on = 1;
        }
    }
    Start();//inicio del juego
}
/*
//Cuenta regresiva 7segmentos
*/ 
/*void segment (void) {
  unsigned char valores[4] = {0
 * x6D,0xCD,0x14,0xFE};
  unsigned char contador1 = 0;
  TRISC = 0x00; 
  PORTC = 0x00; 
  while(contador1 < 4){
    PORTC = valores [contador1];
    __delay_ms(500);
    contador1++;
    if(contador1==4)

Inicio de carrera

       contador1=0;
  }
  return;
}*/
/*
 Funcion de juego
 */
void Start (void){
    /*while (Win==0){
        * if (PORTDbits.RD3 && player1 ==0){
         * delay_ms(5);
         * player1++;
         * }
         * if (PORTDbits.RD2 && player2 ==0){
         * delay_ms(5);
         * player2++;
         * }
         * if (PORTDbits.RD3 == 1 && player 1 ==0){
         * delay_ms(5);
         * player1 =0;
         * verificador1++;
         * if (verificador >=
         * PORTA = 0x00;
         * PORTB = 0x00;
         * PORTD.
         * }
         
    ]     */
    if (PORTDbits.RD0==0){//reivisión del boton para llamar el retroceso del 7segmentos
    sevenseg();//función del 7segmentos    
    } 
    void crecimiento1p ();//función de crecimiento p1
    void crecimiento2p ();//funcion de crecimiento p2
    /*while (pull == 1){ 
     if (PORTDbits.RD1 == 0 || PORTDbits.RD2 == 0 ){
         void crecimiento1p ();
         void crecimiento2p ();
     }
     
 }  */
}
/*
FUNCIÓN DE INICIALIZACIÓN DE PUERTOS
*/
void configp (void){
    
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x0D;
    
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    
    ANSEL = 0;
    ANSELH =0;
    
}
/*
 Crecimiento del contador de el player 1
 */
void crecimiento1p (void){
    if (a == 0){//chequeo de variable
      a = 1;  
    } else if (0<a && a<128){//chequo si el puerto si ya esta al maximo
        a = a * 2;// aumento del valor
        PORTA = a;// valor pasado al puerto a
     } else {
        if (PORTA == 128){
            PORTA = 0x00;//reinicio del puerto a
        }
     }
}
/*
 Crecimiento del contador de el player 2
 */
void crecimiento2p (void){
    if (b == 0){
      b = 1;  
    } else if (0<b && b<128){
        b = b * 2;
        PORTB = b;
     } else {
        if (PORTB == 128){
            PORTB = 0x00;
        }
     }
}
/*
 * Funcion de retroceso del siete segmentos y los led del semaforo.
 */
void sevenseg (void){
    //leds encendidos y 7sietes con valores
    PORTDbits.RD4 = 1; 
    PORTDbits.RD5 = 1; 
    PORTDbits.RD6 = 1; 
    PORTC = 0x6D; 
    delay_ms(250);// delay de cada ciclo de luz 
    //2 leds encendidos y 7sietes con valores
    PORTDbits.RD4 = 0; 
    PORTDbits.RD5 = 1; 
    PORTDbits.RD6 = 1; 
    PORTC = 0xCD; 
    delay_ms(250);
    //led encendido y 7sietes con valores
    PORTDbits.RD4 = 0; 
    PORTDbits.RD5 = 0; 
    PORTDbits.RD6 = 1; 
    PORTC = 0x28; 
    delay_ms(250);
    //todo apagado
    PORTDbits.RD4 = 0; 
    PORTDbits.RD5 = 0; 
    PORTDbits.RD6 = 0; 
    PORTC = 0xFE; 
    delay_ms(250);
    
}
/*
 * Delay auto
 *  
 */
void delay_ms(unsigned int dms){
    for(int i = 0; i<dms; i++){// ciclo para el aumento en miisegundos.
        for(int j = 0; j<255; j++);
    }
}