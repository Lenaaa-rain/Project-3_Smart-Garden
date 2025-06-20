#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
const char* ssid = "Alf4"; //nama WiFi
const char* password = "00000000"; //password
int Col = 16; //jumlah kolom LCD
int Row = 2; //jumlah baris LCD
LiquidCrystal_I2C lcd(0x27, Col, Row);  //Set LCD pada alamat 0x27
//====================================
void setup() {
  lcd.init();      //inisialisasi LCD                        
  lcd.backlight(); //backlight ON
  lcd.setCursor(0, 0); //set posisi baris 1 kolom 1  
  lcd.print("Tes Koneksi WiFi"); //Tulis baris 1
  lcd.setCursor(0,1);   //Set posisi baris 2 kolom 1
  lcd.print("   ..........");  //Tulis baris 2
  delay(2000); //tunggu 2 s
  lcd.clear(); //hapus tampilan
  lcd.print("Coba Koneksi ke"); 
  lcd.setCursor(0,1);
  lcd.print(ssid);  //tulis nama WiFi
  WiFi.begin(ssid, password); //koneksi ke WiFi
  while (WiFi.status() != WL_CONNECTED) { //tunggu sampai sukses
    delay(500);    
  }  
  lcd.clear(); //hapus tampilan
  lcd.print("WiFi Terhubung !"); //WiFi terhubung
  lcd.setCursor(0,1); //set di baris 2 LCD
  lcd.print(WiFi.localIP()); //tampilan IP Address
}
void loop() {  
}
