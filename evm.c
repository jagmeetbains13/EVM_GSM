#include<LiquidCrystal.h>
#include<EEPROM.h>
#include <Keypad.h>

const byte ROWS = 4;         // Four rows
const byte COLS = 4;         // Three columns
                             // Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 18, 17, 16, 15 };
byte colPins[COLS] = { 9, 10, 11, 12 };

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal lcd(8, 7, 5, 4, 3, 2);


#define sw5 19   //result
#define ldg 6    //green led
#define sup 14
#define buzzer 13  //buzzer
int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;
int tvote=0;
int k=0;
int j,i;
int p=0;
int q=0;
int a[4];    //supervisor password
int b[4];    //password input
int voterid1[4];
int voterid2[4];
int voterid[4];
int otp[4];
int otpm[4];


void setup()
{
 a[0] = 1; a[1] = 1 ; a[2] = 1 ; a[3] = 1;  
 voterid1[0] = 4; voterid1[1] = 4; voterid1[2] = 4; voterid1[3] = 4;
 voterid2[0] = 5; voterid2[1] = 5; voterid2[2] = 5; voterid2[3] = 5;

  pinMode(sw5,INPUT);
  pinMode(sup,INPUT);
   Serial.begin(9600);//gsm interfacing
   delay(5000);       
   
 
  pinMode(ldg,OUTPUT);
 
  pinMode(buzzer,OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Voting Machine");
  lcd.setCursor(0,1);
  lcd.print("IISER");
  delay(1000);
 
  lcd.clear();
  
 digitalWrite(sw5, HIGH);
 digitalWrite(sup, HIGH);
  vote1 = EEPROM.read(1);
  vote2 = EEPROM.read(2);
  vote3 = EEPROM.read(3);
  vote4 = EEPROM.read(4);
   lcd.clear(); 
}
void loop()
{
  tvote = vote1 + vote2 + vote3 + vote4 ;  
  
   lcd.setCursor(0,0);
   lcd.print("Total Votes");
    lcd.setCursor(0,1);
   lcd.print(tvote);

 digitalWrite(ldg, LOW);
 while(digitalRead(sup)==0){ 
   lcd.clear(); 
   lcd.setCursor(0,0);
   lcd.print("Enter Voter ID");
   
   
   i=0;
while(1){   
    char key = kpd.getKey();
  q=0;  //change
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '0':  { lcd.setCursor(i,1);   lcd.print("*");  voterid[i] = 0;  i++; break; }
      case '1':  { lcd.setCursor(i,1);   lcd.print("*");  voterid[i] = 1;  i++; break; }
      case '2':  { lcd.setCursor(i,1);   lcd.print("*");  voterid[i] = 2;  i++; break; }
      case '3':  { lcd.setCursor(i,1);   lcd.print("*");  voterid[i] = 3;  i++; break; }
      case '4':  { lcd.setCursor(i,1);   lcd.print("*");  voterid[i] = 4;  i++; break; }
      case '5':  { lcd.setCursor(i,1);   lcd.print("*");  voterid[i] = 5;  i++; break; }
      case '6':  { lcd.setCursor(i,1);   lcd.print("*");  voterid[i] = 6;  i++; break; }
      case '7':  { lcd.setCursor(i,1);   lcd.print("*");  voterid[i] = 7;  i++; break; }
      case '8':  { lcd.setCursor(i,1);   lcd.print("*");  voterid[i] = 8;  i++; break; }
      case '9':  { lcd.setCursor(i,1);   lcd.print("*");  voterid[i] = 9;  i++; break; }
     
    }
  } if(i==4) break; }
  
   


    otp[0] = random(0,9) ; otp[1] = random(0,9); otp[2] = random(0,9); otp[3] = random(0,9);
    if(voterid[0]==voterid1[0] && voterid[1]==voterid1[1] && voterid[2]==voterid1[2] && voterid[3]==voterid1[3]){
    q=1; 
    lcd.clear();    lcd.setCursor(0,0);    lcd.print("Welcome Sanjay"); delay(1000); lcd.clear();    lcd.setCursor(0,0); lcd.print("Enter OTP");   
Serial.println("AT");
delay(1000);
Serial.println("AT+CMGF=1");
delay(1000);
Serial.println("AT+CMGS=\"86993990\""); //CHANGE TO DESTINATION NUMBER
delay(1000);
Serial.print("OTP For Voting is: ");
Serial.print(otp[0]);
Serial.print(otp[1]); 
Serial.print(otp[2]); 
Serial.print(otp[3]); 
Serial.write(26);
delay(1000);

    }
    
    if(voterid[0]==voterid2[0] && voterid[1]==voterid2[1] && voterid[2]==voterid2[2] && voterid[3]==voterid2[3]){
    q=1; 
    lcd.clear();    lcd.setCursor(0,0);    lcd.print("Welcome Raman"); delay(1000); lcd.clear();    lcd.setCursor(0,0);   
Serial.println("AT");
delay(1000);
Serial.println("AT+CMGF=1");
delay(1000);
Serial.println("AT+CMGS=\"76968915\""); //CHANGE TO DESTINATION NUMBER
delay(1000);
Serial.print("OTP For Voting");
Serial.print(otp[0]);
Serial.print(otp[1]); 
Serial.print(otp[2]); 
Serial.print(otp[3]); 
Serial.write(26);
delay(1000);
lcd.print("Enter OTP");
    }
    if(q==0) { lcd.clear();    lcd.setCursor(0,0);    lcd.print("Wrong ID"); delay(1000);break;}

    if(q==1)
    
    {i=0; 
    while(1)
   {
   char key = kpd.getKey();
  
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '0':  { lcd.setCursor(i,1);   lcd.print("*");  otpm[i] = 0;  i++; break; }
      case '1':  { lcd.setCursor(i,1);   lcd.print("*");  otpm[i] = 1;  i++; break; }
      case '2':  { lcd.setCursor(i,1);   lcd.print("*");  otpm[i] = 2;  i++; break; }
      case '3':  { lcd.setCursor(i,1);   lcd.print("*");  otpm[i] = 3;  i++; break; }
      case '4':  { lcd.setCursor(i,1);   lcd.print("*");  otpm[i] = 4;  i++; break; }
      case '5':  { lcd.setCursor(i,1);   lcd.print("*");  otpm[i] = 5;  i++; break; }
      case '6':  { lcd.setCursor(i,1);   lcd.print("*");  otpm[i] = 6;  i++; break; }
      case '7':  { lcd.setCursor(i,1);   lcd.print("*");  otpm[i] = 7;  i++; break; }
      case '8':  { lcd.setCursor(i,1);   lcd.print("*");  otpm[i] = 8;  i++; break; }
      case '9':  { lcd.setCursor(i,1);   lcd.print("*");  otpm[i] = 9;  i++; break; }
     
    }
  } if(i==4)break;
      
    }
    if(otpm[0]==otp[0] && otpm[1]==otp[1] &&otpm[2]==otp[2] &&otpm[3]==otp[3])
    {
      k=1;
      lcd.clear();    lcd.setCursor(0,0);    lcd.print("Cast Vote");
    }
    }
    if(k==0) { lcd.clear();    lcd.setCursor(0,0);    lcd.print("Wrong OTP"); delay(1000);break;}

 i=0; 
  while(k){
  digitalWrite(ldg, HIGH);
   char key = kpd.getKey();
   
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case 'A':  { lcd.setCursor(0,1);   lcd.print("A");  tone(buzzer, 500); delay(1000); noTone(buzzer); vote1++; EEPROM.write(1, vote1); i++;   break; }
      case 'B':  { lcd.setCursor(0,1);   lcd.print("B");  tone(buzzer, 500); delay(1000); noTone(buzzer);  vote2++; EEPROM.write(2, vote2); i++;  break; }
      case 'C':  { lcd.setCursor(0,1);   lcd.print("C");  tone(buzzer, 500); delay(1000); noTone(buzzer);  vote3++; EEPROM.write(3, vote3); i++;   break; }
      case 'D':  { lcd.setCursor(0,1);   lcd.print("D");  tone(buzzer, 500); delay(1000); noTone(buzzer);  vote4++; EEPROM.write(4, vote4); i++;  break; }
    }
  }if(i==1)break;
  }}


if(digitalRead(sw5)==0)
        {  lcd.clear();  lcd.setCursor(0,0);  lcd.print("Enter Password");
           i=0; 
         while(1)
            {
                char key = kpd.getKey();
                if(key) 
                 {
    switch (key)
    {
      case '0':  { lcd.setCursor(i,1);   lcd.print("*");  b[i] = 0;  i++; break; }
      case '1':  { lcd.setCursor(i,1);   lcd.print("*");  b[i] = 1;  i++; break; }
      case '2':  { lcd.setCursor(i,1);   lcd.print("*");  b[i] = 2;  i++; break; }
      case '3':  { lcd.setCursor(i,1);   lcd.print("*");  b[i] = 3;  i++; break; }
      case '4':  { lcd.setCursor(i,1);   lcd.print("*");  b[i] = 4;  i++; break; }
      case '5':  { lcd.setCursor(i,1);   lcd.print("*");  b[i] = 5;  i++; break; }
      case '6':  { lcd.setCursor(i,1);   lcd.print("*");  b[i] = 6;  i++; break; }
      case '7':  { lcd.setCursor(i,1);   lcd.print("*");  b[i] = 7;  i++; break; }
      case '8':  { lcd.setCursor(i,1);   lcd.print("*");  b[i] = 8;  i++; break; }
      case '9':  { lcd.setCursor(i,1);   lcd.print("*");  b[i] = 9;  i++; break; }
     
    }
  } 
  
  if(i==4)break;}
  if(a[0]==b[0] && a[1] == b[1] && a[2] == b[2] && a[3] ==b[3]){
  p=1;
}
else {
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("Wrong password"); q=0;
  delay(1000);
  lcd.clear();
  }
 if(p==1)  
   {
     int vote=vote1+vote2+vote3+vote4;
      lcd.clear();
      lcd.setCursor(0,0);
  lcd.print("JB");
  lcd.setCursor(1,1);
  lcd.print(vote1);
  lcd.setCursor(4,0);
  lcd.print("PS");
  lcd.setCursor(5,1);
  lcd.print(vote2);
  lcd.setCursor(8,0);
  lcd.print("SK");
   lcd.setCursor(9,1);
  lcd.print(vote3);
  lcd.setCursor(12,0);
  lcd.print("NOTA"); 
  lcd.setCursor(13,1);
  lcd.print(vote4);
  delay(5000);
  lcd.clear();
  Serial.println("AT");
delay(1000);
Serial.println("AT+CMGF=1");
delay(1000);
Serial.println("AT+CMGS=\"8699173\""); //CHANGE TO DESTINATION NUMBER
delay(1000);
Serial.print("JB-");  Serial.print(vote1);
Serial.print("\nPS-");  Serial.print(vote2); 
Serial.print("\nSK-");  Serial.print(vote3);
Serial.print("\nNOTA-");  Serial.print(vote4);
Serial.write(26);
delay(1000);
     if(vote)
     {
      if((vote1 > vote2 && vote1 > vote3 && vote1 > vote4))
      {
       lcd.clear();
       lcd.print("JB Wins");
       delay(2000);
       lcd.clear();
      }
      else if((vote2 > vote1 && vote2 > vote3 && vote2 > vote4))
      {
       lcd.clear();
       lcd.print("PS Wins");
       delay(2000);
       lcd.clear();
      }
      else if((vote3 > vote1 && vote3 > vote2 && vote3 > vote4))
      {
       lcd.clear();
       lcd.print("SK Wins");
       delay(2000);
       lcd.clear();
      }
     else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
     {
       lcd.setCursor(0,0);
       lcd.clear();
       lcd.print("NOT Wins");
       delay(2000);
       lcd.clear();
     }
     
      else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
     {
       lcd.setCursor(0,0);
       lcd.clear();
       lcd.print("NOT Wins");
       delay(2000);
       lcd.clear();
     }
     
     else
     {
       lcd.clear();
       lcd.print("   Tie Up Or   ");
       lcd.setCursor(0,1);
       lcd.print("   No Result   ");
       delay(1000);
       lcd.clear();
     }
     
    }      
     else 
     {
       lcd.clear();
       lcd.print("No Voting....");
       delay(1000);
       lcd.clear();
     }
     vote1=0;vote2=0;vote3=0;vote4=0,vote=0;
     for (int i = 1 ; i < 5 ; i++) {
    EEPROM.write(i, 0);
    }
     lcd.clear();
   }
   }  
  

}


