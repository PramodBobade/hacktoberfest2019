/*
CircuitMagic.com
*/
 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{
    B00000000, B11000000,
    B00000001, B11000000,
    B00000001, B11000000,
    B00000011, B11100000,
    B11110011, B11100000,
    B11111110, B11111000,
    B01111110, B11111111,
    B00110011, B10011111,
    B00011111, B11111100,
    B00001101, B01110000,
    B00011011, B10100000,
    B00111111, B11100000,
    B00111111, B11110000,
    B01111100, B11110000,
    B01110000, B01110000,
    B00000000, B00110000
}
;

Serial.println("hello world");
 
 
 
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
 
// defines variables
long duration;
int distance;
 
//------code for RPM----------------
int encoder_pin = 2;
// The pin the encoder is connected
unsigned int rpm;
// rpm reading
volatile byte pulses;
// number of pulses
unsigned long timeold;
// The number of pulses per revolution
// depends on your index disc!!
unsigned int pulsesperturn = 1;
void counter()
{
    //Update count
    pulses++;
}
//-----------------------------------
void setup()   {
    Serial.begin(9600);
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    // initialize with the I2C addr 0x3D (for the 128x64)
    // init done
    // Show image buffer on the display hardware.
    // Since the buffer is intialized with an Adafruit splashscreen
    // internally, this will display the splashscreen.
    //display.display();
    //delay(2000);
    // Clear the buffer.
    //display.clearDisplay();
    // draw a single pixel
    //display.drawPixel(10, 10, WHITE);
    // Show the display buffer on the hardware.
    // NOTE: You _must_ call display after making any drawing commands
    // to make them visible on the display hardware!
    //display.display();
    //delay(2000);
     
 
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
void loop()
{
      // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
     
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
     
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
     
    // Calculating the distance
    distance= duration*0.034/2;
 
     
   if (millis() - timeold >= 500){
        /*Uptade every one second, this will be equal to reading frecuency (Hz).*/
        //Don't process interrupts during calculations
        detachInterrupt(0);
        //Note that this would be 60*1000/(millis() - timeold)*pulses if the interrupt
        //happened once per revolution
        //rpm = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses;
        timeold = millis();
        pulses = 0;
        //Write it out to serial port
        //Serial.print("Distance = ");
       // Serial.println(rpm,DEC);
        updateDisplay(distance);
        //Restart the interrupt processing
        attachInterrupt(0, counter, FALLING);
    }
 
     
     
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
}
int valLen;
int displayWidth = 128;
int letterWidth = 19;
void updateDisplay(int distance){
  if(distance > 9999)
    valLen = 5;
  else if(distance > 999)
    valLen = 4;
  else if(distance > 99)
    valLen = 3;
  else if(distance > 9)
    valLen = 2;
  else
    valLen = 1;
   
 
 
        display.clearDisplay();
        // text display tests
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(30,0);
        display.println("CircuitMagic");
        display.setTextColor(BLACK, WHITE);
        // 'inverted' text
        //display.println(3.141592);
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(20,20);
        display.println("Distance");
        display.setCursor((displayWidth/2)-(letterWidth/2*valLen),42);
        display.setTextSize(2);
        String distanceS = String(distance) + "cm";
        display.println(distanceS);
        // display.println(0xDEADBEEF, HEX);
        display.display();
       
}
