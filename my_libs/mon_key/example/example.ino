/*
  mon_key
*/

#include <avr/io.h>
#include <util/delay.h>
#include "C:\Users\alex\Documents\Cursos\sist_embarcados\arduino\mon_key\mon_key.h"

// Pin definitions
#define LED_PIN PB3
#define BUTTON_PIN PB0
#define BUTTON_PORT PINB
#define LED_PORT PORTB
#define LED_DDR DDRB

// State variables
int PS1 = 0;
int ES1 = 0;
int res;

// Function to read pin state
int read_pin(uint8_t port, uint8_t pin){
  // Read the button state: if pressed, return 1; otherwise, return 0
  return (port & (1 << pin)) ? 0 : 1;
}

int main(void) {
    // Initialize serial communication
    Serial.begin(9600);

    uint8_t buttonState;

    // Configure pins
    // Set LED_PIN (port 11) as output
    LED_DDR |= (1 << LED_PIN);
    // Set BUTTON_PIN (port 8) as input
    LED_DDR &= ~(1 << BUTTON_PIN);

    // Enable internal pull-up on BUTTON_PIN
    LED_PORT |= (1 << BUTTON_PIN);

    while(1){
      // Read button state
      buttonState = read_pin(BUTTON_PORT, BUTTON_PIN);

      // Call m_key::mn_key function to process button state
      res = m_key::mn_key(buttonState, &PS1, &ES1);

      // If the function returns true (res == 1), toggle LED state
      if (res){
          LED_PORT ^= (1 << LED_PIN);
          ES1 = 0;
      }
    }

    return 0;
}
