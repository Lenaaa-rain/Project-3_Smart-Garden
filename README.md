 Smart Garden IoT Project (ESP32-Based)

Overview

Smart Garden merupakan sebuah sistem berbasis Internet of Things (IoT) yang dirancang untuk otomatisasi penyiraman tanaman menggunakan mikrokontroler ESP32. Sistem ini memantau kondisi lingkungan seperti kelembaban tanah, suhu, dan kelembaban udara secara real-time, serta dapat mengontrol pompa air secara otomatis maupun manual melalui aplikasi Blynk.

Proyek ini merupakan bagian dari tugas akhir mata kuliah IoT Lanjutan yang bertujuan memberikan pemahaman teknis dalam membangun solusi pertanian cerdas (smart farming).



Project Objectives

- Mengembangkan sistem monitoring dan penyiraman tanaman otomatis berbasis ESP32.
- Mengintegrasikan berbagai sensor dan aktuator dalam satu sistem IoT.
- Menyediakan antarmuka pemantauan melalui LCD dan platform Blynk secara real-time.




 Komponen Utama

| Komponen               | Deskripsi                                                                 |

| ESP32 WROOM-32         | Mikrokontroler utama dengan WiFi & Bluetooth                             |
| Expansion Board        | Mempermudah koneksi antarmuka ESP32                                      |
| Soil Moisture Sensor   | Mengukur kelembaban tanah (kapasitif)                                    |
| DHT11                  | Sensor suhu dan kelembaban udara digital                                 |
| DS18B20                | Sensor suhu digital presisi tinggi                                       |
| Relay 1-Channel        | Mengontrol pompa air mini                                                 |
| Pompa Air Mini DC      | Menyiram tanaman berdasarkan kondisi kelembaban tanah                    |
| LCD 16x2 I2C           | Menampilkan data suhu, kelembaban, dan status sistem                     |
| Breadboard & Jumper    | Media uji coba dan koneksi sementara antar komponen                      |
| Power Supply (5V)      | Sumber daya sistem dan pompa                                             |


 Circuit Design & Wiring

- LCD 16x2 I2C:  
  - SCL: D22  
  - SDA: D21  
  - VCC: 5V  
  - GND: GND  

- Relay:  
  - IN: D14  
  - VCC: 5V  
  - GND: GND  

- DHT11:  
  - OUT: D5  
  - VCC: 5V  
  - GND: GND  

- DS18B20:  
  - DATA: D4  
  - VCC: 5V  
  - GND: GND  

- Soil Moisture:  
  - AOUT: D34  
  - VCC: 5V  
  - GND: GND  


 Blynk Integration
 Langkah Setup:

1. Buat template baru:  
   - Name: Smart Garden  
   - Hardware: ESP32  
   - Connection type: WiFi  
   - Description: (isi bebas)

2. Tambahkan Datastreams:
   - `V0`: Temperature (°C)
   - `V1`: Soil Moisture (%)
   - `V2`: Humidity (%)
   - `V3`: Mode Button (Auto/Manual)
   - `V4`: Pump Button

3. Tambahkan widget di Web Dashboard:
   - 3 x Gauge (Temperature, Soil Moisture, Humidity)
   - 2 x Switch (Mode & Pump)

4. Masukkan data berikut ke dalam kode Arduino:
   - `BLYNK_TEMPLATE_ID`
   - `BLYNK_DEVICE_NAME`
   - `BLYNK_AUTH_TOKEN`

5. Juga sesuaikan dengan koneksi jaringan internet/WIFI/Hotspot yang anda pakai
ssid[ ]
Pass[ ]

6. Upload sketch ke ESP32 melalui Arduino IDE atau PlatformIO.

