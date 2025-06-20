#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DallasTemperature.h>
#include <OneWire.h>

#define DHTPIN 5 
#define DHTTYPE DHT11
#define ONE_WIRE_BUS 4  
DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire); 

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int AirValue = 2620;   
const int WaterValue = 1180;  
int soilMoistureValue = 0;
int soilmoist=0;  
int humi, temp; 
//=============================
void read_DHT11(){
  humi = dht.readHumidity();   
  if (isnan(humi)) {
    Serial.println("DHT11 tidak terbaca... !");
    return;
  }
  else{   
  lcd.setCursor(4,1);
  lcd.print(humi);
  lcd.print("% ");
  }  
}
//===========
void read_SoilMoist(){
  soilMoistureValue = analogRead(A6);  
  soilmoist= map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilmoist >= 100)
    {
      soilmoist=100;
    }
  else if(soilmoist <=0)
    {
      soilmoist=0;
    }    
  Serial.print("Soil Moisture :");
  Serial.print(soilmoist);
  Serial.println("%");

  lcd.setCursor(11,0);
  lcd.print(soilmoist);   
  lcd.print("% "); 
}
//---------------------
void read_DS1820(){
  sensors.requestTemperatures();  
  temp=sensors.getTempCByIndex(0);  
  lcd.setCursor(13,1);
  lcd.print(temp);   
}
//===================================
void setup()
{  
  lcd.begin(16,2); 
  lcd.init();  
  lcd.backlight(); 
  lcd.setCursor(0, 0); 
  lcd.print("CEK ALL SENSOR");  
  dht.begin();  
  sensors.begin();
  delay(2000);  
  lcd.clear();
  lcd.print("Soil Moist=  % ");    
  lcd.setCursor(0, 1);
  lcd.print("Hum=  %  Tmp=  C");    
}
//=============================
void loop()
{
  read_DHT11();
  read_SoilMoist();
  read_DS1820();
  delay(1000);
}
