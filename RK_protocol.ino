//compatible con Arduino uno R3 y Mega R3

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>

DS3231  rtc;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

boolean z,y,sw,r,x;
String tiempo,h,m,s;

const int buttonPin = 2;
const int r1 = 3;

byte time[7];   // Temp buffer used to hold BCD time/date values
char buf[12];   // Buffer used to convert time[] values to ASCII strings

uint32_t  time_now=0;
uint32_t  time_new=0;
uint32_t  temp1;



void setup(){
	// initialize the LCD
	pinMode(buttonPin, INPUT);
	pinMode(r1, OUTPUT);
	
	lcd.init();

	// Turn on the blacklight and print a message.
	lcd.backlight();
	lcd.print("Arduino Chile");
	delay(2000);
  	
}


void loop(){
	uint16_t h;
	uint8_t m,s;
	
	rtc.getDateTime(time);

	if(z==1&&digitalRead(buttonPin)==1){while(digitalRead(buttonPin)==1){delay(25);}z=0;y=0;}
	if(y==0){lcd.clear();lcd.print("Pulse for start");y=1;sw=0;}
	if(digitalRead(buttonPin)==1&&sw==0){while(digitalRead(buttonPin)==1){delay(25);} time_now = rtc.timeToSeconds(time);x=0; lcd.clear();lcd.print("Wait R1");sw=1;r=1;}

	time_new = rtc.timeToSeconds(time);
	
	if(x==0&&sw==1){
		if(time_new == time_now + 1200)		{digitalWrite(r1,HIGH);	lcd.setCursor(0,0); lcd.print("              ");	lcd.setCursor(8,0);lcd.print("rele ON ");}
		if(time_new == time_now + 1210)		{digitalWrite(r1,LOW);	lcd.setCursor(0,0); lcd.print("Wait R2");			lcd.setCursor(8,0);lcd.print("rele OFF");}
		if(time_new == time_now + 3600)		{digitalWrite(r1,HIGH);	lcd.setCursor(0,0); lcd.print("              ");	lcd.setCursor(8,0);lcd.print("rele ON ");}
		if(time_new == time_now + 3610)		{digitalWrite(r1,LOW);	lcd.setCursor(0,0); lcd.print("Wait R3");			lcd.setCursor(8,0);lcd.print("rele OFF");}
		if(time_new == time_now + 6000)		{digitalWrite(r1,HIGH);	lcd.setCursor(0,0); lcd.print("              ");	lcd.setCursor(8,0);lcd.print("rele ON ");}
		if(time_new == time_now + 6010)		{digitalWrite(r1,LOW);	lcd.setCursor(0,0); lcd.print("Wait R4");			lcd.setCursor(8,0);lcd.print("rele OFF");}
		if(time_new == time_now + 8400)		{digitalWrite(r1,HIGH);	lcd.setCursor(0,0); lcd.print("              ");	lcd.setCursor(8,0);lcd.print("rele ON ");}
		if(time_new == time_now + 8410)		{digitalWrite(r1,LOW);	lcd.setCursor(0,0); lcd.print("Wait R5");			lcd.setCursor(8,0);lcd.print("rele OFF");}
		if(time_new == time_now + 10800)	{digitalWrite(r1,HIGH);	lcd.setCursor(0,0); lcd.print("              ");	lcd.setCursor(8,0);lcd.print("rele ON ");}
		if(time_new == time_now + 10810)	{digitalWrite(r1,LOW);	lcd.setCursor(0,0); lcd.print("Wait R6");			lcd.setCursor(8,0);lcd.print("rele OFF");}
		if(time_new == time_now + 13200)	{digitalWrite(r1,HIGH);	lcd.setCursor(0,0); lcd.print("              ");	lcd.setCursor(8,0);lcd.print("rele ON ");}
		if(time_new == time_now + 13210)	{digitalWrite(r1,LOW);	lcd.setCursor(0,0); lcd.print("Fin de protocolo");	z=1;}
	}

	lcd.setCursor(0, 1);
	lcd.print(rtc.timeToString(time, buf));

	lcd.setCursor(9, 1);
	temp1 = time_new-time_now;
	secondsToHMS(temp1, h,m,s);
	lcd.print(h,DEC);
	lcd.print(":");
	lcd.print(m,DEC);
	lcd.print(":");
	lcd.print(s,DEC);
	
	if(digitalRead(buttonPin)==1&&r==1){
		r=0;
		lcd.clear();lcd.print("cancelado");
		while(digitalRead(buttonPin)==1){delay(25);}
		digitalWrite(r1,LOW);y=0;
	}
}

void secondsToHMS( const uint32_t seconds, uint16_t &h, uint8_t &m, uint8_t &s )
{
	uint32_t t = seconds;
	s = t % 60;
	t = (t - s)/60;
	m = t % 60;
	t = (t - m)/60;
	h = t;
}
