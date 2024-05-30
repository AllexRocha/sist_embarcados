#include <avr/io.h>
#include <util/delay.h>
#include "mon_key.h"

#define LED_PIN PB3
#define BUTTON_PIN_1 PB1
#define BUTTON_PIN_2 PB0
#define BUTTON_PORT PINB
#define LED_PORT PORTB
#define LED_DDR DDRB

int PS1 = 0;
int PS2 = 0;
int ES1 = 0;
int ES2 = 0;
int res1,res2;
int count = 0;
int limit = 9;

int read_pin(uint8_t port, uint8_t pin){
  // lê o estado do botão, se estiver pressionado retorna 1 se não retorna 0
  return (port & (1 << pin)) ? 0 : 1;
}

int main(void){

  Serial.begin(9600);
  uint8_t buttonState1,buttonState2;
  //setando porta 11 para saída
  LED_DDR |= (1 << LED_PIN);

  //setando porta 9 como entrada do botão 1
  LED_DDR &= ~(1 << BUTTON_PIN_1);
  //setando porta 8 como entrada do botão 2
  LED_DDR &= ~(1 << BUTTON_PIN_2);

  //adicionando pull up nas entradas
  LED_PORT |= (1 << BUTTON_PIN_1);
  LED_PORT |= (1 << BUTTON_PIN_2);


  while(1){
    Serial.println(count);
    buttonState1 = read_pin(BUTTON_PORT, BUTTON_PIN_1);
    buttonState2 = read_pin(BUTTON_PORT, BUTTON_PIN_2);
    res1 = m_key::mn_key(buttonState1, &PS1, &ES1);
    res2 = m_key::mn_key(buttonState2, &PS2, &ES2);
    if (res1) {
      if(count > 0){
        count--;
      }
        
        ES1 = 0;
    }
    else if(res2){
      if(count<limit){
        count++;
      }

      ES2 = 0;
    }

    if(count == limit){
      LED_PORT |= (1 << LED_PIN);
    } else{
      LED_PORT &= ~(1 << LED_PIN);
    }

  }

  return 0;
}