#include <LiquidCrystal.h>
char input[12];
int count = 0;
char tag1[]="1D1111231C8D";
char tag2[]="091122505277";
char tag3[]="090111F45BDEE";
LiquidCrystal lcd(8,9,10,11,12,13);
void setup() {
  //serial monitor
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  }
  void loop() {
    boolean match = 1;
    digitalWrite(2, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Hi, WELCOME");
    lcd.setCursor(0,1);
    lcd.print("SCAN SDUDENT ID");
    delay(1000);
    if(Serial.available())// check serial data ( RFID reader)
    {
      count = 0; // Reset the counter to zero
      /* Keep reading Byte by Byte from the Buffer till the RFID Reader Buffer is
       *  empty or till 12 Bytes (the ID size of our Tag) is read */
       while(Serial.available() && count < 12) 
       {
        input[count] = Serial.read(); // Read 1 Byte of data and store it in the input[] variable
        count++; // increment counter
        delay(5);
        }
        Serial.println("I received: ");
        for(int i=0;i<12;i++)
        Serial.print(input[i]);
        Serial.println();
        Serial.println();
        int j= 0;
        while (match==1 && j<12){
          if((tag1[j]==input[j])||(tag2[j]==input[j])||(tag3[j]==input[j])){
            match=1;
            j++;
            }
            else
            match=0; 
            }
            if (match == 1){
              lcd.clear();
              lcd.setCursor(0,1);
              lcd.print("VALID STUDENT");
              lcd.setCursor(0,2);
              lcd.print("You May Enter ");
              delay(1000);
              digitalWrite(4, LOW);
              digitalWrite(6, HIGH);
              delay(2000);
              digitalWrite(6, LOW);
              digitalWrite(4, HIGH);
              delay(1000);
              digitalWrite(4, HIGH);
              digitalWrite(6, LOW);
              }
              else{
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Unauthorished");
                lcd.setCursor(0,1);
                lcd.print("STUDENT");
                digitalWrite(5, HIGH);
                delay(2000);
                digitalWrite(5, LOW);
                }
                }
                }
