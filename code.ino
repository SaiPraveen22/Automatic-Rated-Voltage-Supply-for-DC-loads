

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define buzz A5




unsigned int dc_current = 0,motor_current=0;  // variable to store the value coming from the sensor


int Relay_12 = 8;
int Relay_9 = 9;
int Relay_5 = 10;
int Relay_3 = 11;


unsigned int current_read()
{
    dc_current = analogRead(A0);delay(100);
    dc_current += analogRead(A0);delay(100);
    dc_current += analogRead(A0);delay(100);
    dc_current += analogRead(A0);delay(100);
    dc_current += analogRead(A0);delay(100);
    dc_current = dc_current/5;
    return dc_current;
}

void setup(void)
{
  
  pinMode(Relay_12,OUTPUT);
  pinMode(Relay_9,OUTPUT);
  pinMode(Relay_5,OUTPUT);
  pinMode(Relay_3,OUTPUT);
  digitalWrite(Relay_12,HIGH);
  digitalWrite(Relay_9,HIGH);
  digitalWrite(Relay_5,HIGH);
  digitalWrite(Relay_3,HIGH);

  lcd.begin(16, 2);
 
  lcd.clear(); lcd.setCursor(4, 0);        lcd.print("WELCOME");
  


}

/*--------------------------------------------------------------------------------------
  loop
  Arduino architecture main loop
  --------------------------------------------------------------------------------------*/
void loop(void)
{
  unsigned char e_count,cnt=0;
  unsigned int uc_i = 0;
  char s1[6], s2[6], s3[6], s4[6];
  unsigned int delaycount = 0;

  
 lcd.clear();
 lcd.setCursor(0,0); lcd.print("DC MOTOR FINDING");delay(2000);
 
 lcd.clear();
 lcd.setCursor(0,0); lcd.print("DC CURRENT:");
 digitalWrite(Relay_12,LOW);
  
  while (1)
  {
    cnt =0;
    while(cnt<10)
    {
      motor_current = current_read();
      lcd.setCursor(0,1); lcd.print("         ");
      lcd.setCursor(0,1);  lcd.print("MOTOR(mA) ");lcd.print(motor_current);
      delay(1000);
      cnt = cnt+1;
    }  

    // 5v supply
    if((motor_current>200)&&(motor_current<400))
    {
        lcd.setCursor(0,0); lcd.print("                    ");
        lcd.setCursor(0,0); lcd.print("DC MOTOR 5V  ");
        digitalWrite(Relay_12,HIGH); 
        delay(1000);
        digitalWrite(Relay_9,LOW);
        delay(2000);
        while(1)
        {
            motor_current = current_read();
            lcd.setCursor(0,1); lcd.print("                   ");
            lcd.setCursor(0,1); lcd.print("MOTOR(mA) ");lcd.print(motor_current);
            if (motor_current<10)
            {
               digitalWrite(Relay_9,HIGH);
               delay(2000);
               digitalWrite(Relay_12,LOW);
               lcd.clear();
               lcd.setCursor(0,0); lcd.print("DC MOTOR FINDING");delay(2000);
 
               break;
            }  
        }
      
    }
    //
    if((motor_current>700)&&(motor_current<800))
    {
        lcd.setCursor(0,0); lcd.print("                    ");
        lcd.setCursor(0,0); lcd.print("DC MOTOR 3V  ");
        digitalWrite(Relay_12,HIGH); 
        delay(1000);
        digitalWrite(Relay_3,LOW);
        delay(2000);
        while(1)
        {
            motor_current = current_read();
            lcd.setCursor(0,1); lcd.print("               ");
            lcd.setCursor(0,1);  lcd.print("MOTOR(mA) ");lcd.print(motor_current);
            if (motor_current<10)
            {
               digitalWrite(Relay_3,HIGH);
               delay(2000);
               digitalWrite(Relay_12,LOW);
               lcd.clear();
               lcd.setCursor(0,0); lcd.print("DC MOTOR FINDING");delay(2000);
 
               break;
            }  
        }
      
    }
    if((motor_current>500)&&(motor_current<600))
    {
        lcd.setCursor(0,0); lcd.print("                   ");
        lcd.setCursor(0,0); lcd.print("DC MOTOR 9V");
        digitalWrite(Relay_12,HIGH); 
        delay(1000);
        digitalWrite(Relay_5,LOW);
        while(1)
        {
            motor_current = current_read();
            lcd.setCursor(0,1); lcd.print("                  ");
            lcd.setCursor(0,1);  lcd.print("MOTOR(mA) ");lcd.print(motor_current);
            if (motor_current<10)
            {
               digitalWrite(Relay_5,HIGH);
               delay(2000);
               digitalWrite(Relay_12,LOW);
               lcd.clear();
               lcd.setCursor(0,0); lcd.print("DC MOTOR FINDING");delay(2000);
 
               break;
            }   
        }
      
    }
    if((motor_current>400)&&(motor_current<500))
    {
        lcd.setCursor(0,0); lcd.print("                   ");
        lcd.setCursor(0,0); lcd.print("DC MOTOR 12V");
       
       
        while(1)
        {
            motor_current = current_read();
            lcd.setCursor(0,1); lcd.print("                   ");
            lcd.setCursor(0,1);  lcd.print("MOTOR(mA) ");lcd.print(motor_current);
            if (motor_current<10)
            {
               lcd.clear();
               lcd.setCursor(0,0);  lcd.print("MOTOR(mA) ");lcd.print("DC MOTOR FINDING");delay(2000);
 
               digitalWrite(Relay_12,LOW);
               break;
            }   
        }
      
    } 
  }



}