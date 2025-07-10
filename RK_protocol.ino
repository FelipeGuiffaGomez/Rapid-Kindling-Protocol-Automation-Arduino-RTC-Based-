//compatible con Arduino uno R3 y Mega R3

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <FlexiTimer2.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int hora,minu,seg;
boolean r,x,y,z,sw;
String tiempo,h,m,s;

const int buttonPin = 2;
const int r1 = 3;


void flash()
{
x=0;
}


void setup()
{
  // initialize the LCD
  pinMode(buttonPin, INPUT);
  pinMode(r1, OUTPUT);

  
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Kindking Machine");lcd.setCursor(1,1);lcd.print("Neuron Effects");
  delay(3000);
  
  FlexiTimer2::set(1000, flash); // MsTimer2 style is also supported
  
}

void loop()
{
  if(z==1&&digitalRead(buttonPin)==1){while(digitalRead(buttonPin)==1){delay(25);}z=0;y=0;}
  if(y==0){lcd.clear();lcd.print("   Pulse para");lcd.setCursor(4,1);lcd.print("iniciar");y=1;sw=0;}
  if(digitalRead(buttonPin)==1&&sw==0){while(digitalRead(buttonPin)==1){delay(25);}hora=0;minu=0;seg=0;FlexiTimer2::start();lcd.clear();lcd.print("Esperando EST 1");sw=1;r=1;}
  
  
  if(x==0&&sw==1){
    
    if(hora==0&&minu==20&&seg==0){digitalWrite(r1,HIGH);lcd.setCursor(0,0);lcd.print("              ");lcd.setCursor(0,0);lcd.print("ESTIMULANDO!");}
    if(hora==0&&minu==20&&seg==10){digitalWrite(r1,LOW);lcd.setCursor(0,0);lcd.print("Esperando EST 2");}
    if(hora==1&&minu==0&&seg==0){digitalWrite(r1,HIGH);lcd.setCursor(0,0);lcd.print("              ");lcd.setCursor(0,0);lcd.print("ESTIMULANDO!");}
    if(hora==1&&minu==0&&seg==10){digitalWrite(r1,LOW);lcd.setCursor(0,0);lcd.print("Esperando EST 3");}
    if(hora==1&&minu==40&&seg==0){digitalWrite(r1,HIGH);lcd.setCursor(0,0);lcd.print("              ");lcd.setCursor(0,0);lcd.print("ESTIMULANDO!");}
    if(hora==1&&minu==40&&seg==10){digitalWrite(r1,LOW);lcd.setCursor(0,0);lcd.print("Esperando EST 4");}
    if(hora==2&&minu==20&&seg==0){digitalWrite(r1,HIGH);lcd.setCursor(0,0);lcd.print("              ");lcd.setCursor(0,0);lcd.print("ESTIMULANDO!");}
    if(hora==2&&minu==20&&seg==10){digitalWrite(r1,LOW);lcd.setCursor(0,0);lcd.print("Esperando EST 5");}
    if(hora==3&&minu==00&&seg==0){digitalWrite(r1,HIGH);lcd.setCursor(0,0);lcd.print("              ");lcd.setCursor(0,0);lcd.print("ESTIMULANDO!");}
    if(hora==3&&minu==00&&seg==10){digitalWrite(r1,LOW);lcd.setCursor(0,0);lcd.print("Esperando EST 6");}
    if(hora==3&&minu==40&&seg==00){digitalWrite(r1,HIGH);lcd.setCursor(0,0);lcd.print("              ");lcd.setCursor(0,0);lcd.print("ESTIMULANDO!");}
    if(hora==3&&minu==40&&seg==10){digitalWrite(r1,LOW);lcd.setCursor(0,0);lcd.print("Fin de protocolo");FlexiTimer2::stop();z=1;}
    
  x=1;h=hora;m=minu;s=seg;
  tiempo=h+":"+m+":"+s;
  lcd.setCursor(0, 1);lcd.print("        ");lcd.setCursor(0, 1);lcd.print(tiempo);
  seg++;
  if(seg==60){seg=0;minu++;if(minu==59){minu=0;hora++;}}
  }

  if(digitalRead(buttonPin)==1&&r==1){
    r=0;FlexiTimer2::stop();
    lcd.clear();lcd.print("Cancelado");
    while(digitalRead(buttonPin)==1){delay(25);}
    digitalWrite(r1,LOW);y=0;
    
    }
  
  
}
