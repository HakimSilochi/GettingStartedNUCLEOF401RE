#include "stm32f410rx.h"
//Una vez incluidas las librerias de cmsis procedemos a activar el reloj del led que queremos utilizar.
void delayMs (int n);
int  main (){
//Led esta en PA5 y el boton se encuentra en el PC13 con una resistencia pull uo que garantiza un nivel alto si no se pulsa el boton.
RCC->AHB1ENR |= (1<<0)|(1<<2); //ACTIVACION DE CLOCKS
GPIOA->MODER &=~(1<<11);
GPIOA->MODER |=(1<<10); //LED COMO SALIDA.
GPIOA->MODER &=~(1<<5);
	while (1){
		//El led se enciende con una signal positiva.
		GPIOA->BSRR =(1<<5);
		delayMs(50);
		GPIOA->BSRR =(1<<21);
		delayMs(50);
    }

return 0;

}
void delayMs(int n) {
int i;
for (; n > 0; n--)
for (i = 0; i < 3195; i++) ; }
