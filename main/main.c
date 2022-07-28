/* WiFi station Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "ili9488.h"

void app_main()
{
  setup_lcd_pins();
  delay_ms(100);

  printf("Iniciando LCD\n");
  
  init_lcd();

  gpio_set_level(LCD_CS, 0);

  printf("Escrevendo pixel\n");
  write_pixel(100, 100, 255, 0, 0);

  write_string("Hello world!", 0, 20, 255, 0, 0);
  write_string("Hello world!", 10, 34, 255, 255, 255);
  write_string("Hello world!", 20, 48, 0, 255, 0);
  write_string("Hello world!", 30, 62, 0, 0, 255);


  write_string("LUAN", 0, 180, 199, 67, 209);

  for (int i = 0; i < 320; i++) {
    for (int j = 201; j < 230; j++) {
      write_pixel(i, j, i, 0, 0);
    }
  }
  for (int i = 0; i < 320; i++) {
    for (int j = 231; j < 260; j++) {
      write_pixel(i, j, 0, i, 0);
    }
  }
  for (int i = 0; i < 320; i++) {
    for (int j = 261; j < 290; j++) {
      write_pixel(i, j, 0, 0, i);
    }
  }

  // while(1) {
  //   printf("Aguardando...\n");
  //   delay_ms(2000);
  // }
}
