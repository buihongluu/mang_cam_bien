#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Chọn chân GPIO đọc dữ liệu từ DHT11
#define DHTPIN 2        // GPIO2 (D4)
#define DHTTYPE DHT11   // Chọn loại cảm biến DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);  // Khởi động Serial Monitor
    Serial.println("Khởi động cảm biến DHT11...");
    dht.begin();           // Khởi động cảm biến
}

void loop() {
    // Đọc giá trị nhiệt độ và độ ẩm
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature(); // Mặc định là độ C
    float tempF = dht.readTemperature(true);   // Đọc nhiệt độ °F (không bắt buộc)

    // Kiểm tra lỗi khi đọc dữ liệu từ cảm biến
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("⚠️ Lỗi đọc cảm biến! Kiểm tra lại kết nối.");
        return;
    }

    // Hiển thị dữ liệu lên Serial Monitor
    Serial.print("🌡️ Nhiệt độ: ");
    Serial.print(temperature);
    Serial.print(" °C (");
    Serial.print(tempF);
    Serial.print(" °F), 💧 Độ ẩm: ");
    Serial.print(humidity);
    Serial.println(" %");

    delay(2000); // Đọc dữ liệu mỗi 2 giây
}