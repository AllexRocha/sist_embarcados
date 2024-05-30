/*
  mon_key
*/

#include <avr/io.h>
#include <util/delay.h>
#include "mon_key.h"

//objeto

#define LED_PIN PB3
#define BUTTON_PIN PB0
#define BUTTON_PORT PINB
#define LED_PORT PORTB
#define LED_DDR DDRB


int PS1 = 0;
int ES1 = 0;
int res;


int read_pin(uint8_t port, uint8_t pin){
  // lê o estado do botão, se estiver pressionado retorna 1 se não retorna 0
  return (port & (1 << pin)) ? 0 : 1;
}

int main(void) {


    Serial.begin(9600);
    uint8_t buttonState;
    //setando porta 11 para saída
    LED_DDR |= (1 << LED_PIN);
    //setando porta 8 para entrada
    LED_DDR &= ~(1 << BUTTON_PIN);

    //adicionando pull up
    LED_PORT |= (1 << BUTTON_PIN);

    while(1){
      buttonState = read_pin(BUTTON_PORT, BUTTON_PIN);
      res = m_key::mn_key(buttonState, &PS1, &ES1);
       if (res){
          LED_PORT ^= (1 << LED_PIN);
          ES1 = 0;

      }
    }

    return 0;
  }


