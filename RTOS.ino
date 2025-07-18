#include <Arduino_FreeRTOS.h>

// Task function prototypes

void TaskBlinkLED(void *pvParameters);

void TaskPrintMessage(void *pvParameters);



// Priorities - you can tinker with these to see the effects to scheduling

uint32_t LEDPriority = 2;        //Higher Priority

uint32_t PrintPriority = 1;      // Lower Priority

void setup() {

  // Initialize serial communication

  Serial.begin(9600);

  while (!Serial);



  // Create tasks

  xTaskCreate(

    TaskBlinkLED,       // Task function

    "Blink",            // Task name

    128,                // Stack size

    NULL,               // Parameters

    LEDPriority,        // Priority

    NULL                // Task handle

  );



  xTaskCreate(

    TaskPrintMessage,

    "Print",

    128,

    NULL,

    PrintPriority,

    NULL

  );



  // Start the scheduler

  // After this, setup() and loop() won't be called anymore

  vTaskStartScheduler();

}



void loop() {

  // This will never run when using FreeRTOS

}

// Task 1: Blink an LED (if available)

void TaskBlinkLED(void *pvParameters) {

  pinMode(LED_BUILTIN, OUTPUT);

  while (1) {

    digitalWrite(LED_BUILTIN, HIGH);

    vTaskDelay(5000 / portTICK_PERIOD_MS); // Delay for 5000ms

    digitalWrite(LED_BUILTIN, LOW);

    vTaskDelay(5000 / portTICK_PERIOD_MS);

  }

}



// Task 2: Print a message

void TaskPrintMessage(void *pvParameters) {

  int x = 0;

  while (1) {

    x = x + 1;

    Serial.println(x);

    vTaskDelay(500 / portTICK_PERIOD_MS); // Delay for 500ms

  }

}

