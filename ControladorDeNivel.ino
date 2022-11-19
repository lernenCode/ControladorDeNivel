// LCD 
#include <LiquidCrystal.h>
const int rs = 12, en = 11,d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// Potenciometro 
const int potenciometro = 1;
float nivel;

// Leds
const int led1 =1; 
const int led2 =2;
const int led3 =3; 
const int led4 =4;
const int led5 =5;


/* toll to right*/  void rollRight()    {for (int positionCounter = 0; positionCounter < 16; positionCounter++) { lcd.scrollDisplayRight(); delay(100);}}
/*Start*/           void start()        {lcd.begin(16,2);lcd.setCursor(4,0);lcd.print("LERN-DEV");lcd.setCursor(2,1);lcd.print("LuizVinicius"); delay(1000); rollRight(); delay(500);lcd.clear();}

void led1On(){digitalWrite(led1, HIGH);}  void led1Of(){digitalWrite(led1, LOW);}
void led2On(){digitalWrite(led2, HIGH);}  void led2Of(){digitalWrite(led2, LOW);}
void led3On(){digitalWrite(led3, HIGH);}  void led3Of(){digitalWrite(led3, LOW);}
void led4On(){digitalWrite(led4, HIGH);}  void led4Of(){digitalWrite(led4, LOW);}
void led5On(){digitalWrite(led5, HIGH);}  void led5Of(){digitalWrite(led5, LOW);}

// Sprites
//https://maxpromer.github.io/LCD-Character-Creator/
byte level1[] = { B00000, B00100, B01010, B01010, B10001, B10001, B10001, B01110 };
byte level2[] = { B00000, B00100, B01010, B01010, B10001, B10001, B11111, B01110 };
byte level3[] = { B00000, B00100, B01010, B01010, B10001, B11111, B11111, B01110 };
byte level4[] = { B00000, B00100, B01010, B01010, B11111, B11111, B11111, B01110 };
byte level5[] = { B00000, B00100, B01110, B01110, B11111, B11111, B11111, B01110 };

void setup()
{
  //Sprites
  lcd.createChar(1, level1); lcd.createChar(2, level2); lcd.createChar(3, level3); lcd.createChar(4, level4); lcd.createChar(5, level5);
  
  // Start
  start();
  
  // Saidas
  pinMode(led1,OUTPUT);pinMode(led2,OUTPUT);pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);pinMode(led5,OUTPUT);
}


void loop()
{
 nivel = analogRead(potenciometro) * 0.09775635;
 lcd.setCursor(0,0); lcd.print("Controle d nivel");
 lcd.setCursor(0,1); lcd.print("Nivel: "); lcd.print(nivel); lcd.print("%");
 
 if(nivel <25){led1On(); led2Of(); led3Of(); led4Of(); led5Of(); lcd.setCursor(15,1);  lcd.write(1);}
 if(nivel >25 && nivel < 50){led2On(); led1Of(); led3Of(); led4Of(); led5Of(); lcd.setCursor(15,1);  lcd.write(2);}
 if(nivel >50 && nivel < 75){led3On(); led2Of(); led1Of(); led4Of(); led5Of(); lcd.setCursor(15,1);  lcd.write(3);}
 if(nivel >75 && nivel < 98){led4On(); led2Of(); led3Of(); led1Of(); led5Of(); lcd.setCursor(15,1);  lcd.write(4);}
 if(nivel >98){led5On(); led2Of(); led3Of(); led4Of(); led1Of();lcd.setCursor(15,1);  lcd.write(5);}
 
}
