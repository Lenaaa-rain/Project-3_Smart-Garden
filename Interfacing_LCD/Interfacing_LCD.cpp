#include <LiquidCrystal_I2C.h>
int Col = 16;//jumlah kolom LCD
int Row = 2; //jumlah baris LCD
LiquidCrystal_I2C lcd(0x27, Col, Row);  //Set LCD pada alamat 0x27
//===============================
void setup(){  
  lcd.init();      //inisialisasi LCD                        
  lcd.backlight(); //backlight ON
  lcd.setCursor(0, 0); //set posisi baris 1 kolom 1  
  lcd.print("  ESP32 Smart  "); //Tulis baris 1
  lcd.setCursor(0,1);   //Set posisi baris 2 kolom 1
  lcd.print("Garden ARDUTECH");  //Tulis baris 2
}
//===============================
void loop(){  
}
