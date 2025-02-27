#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

void setup() {
    Serial.begin(115200);
    Wire.begin(D2, D1);  // SDA = D2 (GPIO4), SCL = D1 (GPIO5)
    
    if (!lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
        Serial.println("Không tìm thấy cảm biến BH1750!");
        while (1);
    }
    Serial.println("Cảm biến BH1750 đã sẵn sàng!");
}

void loop() {
    float lux = lightMeter.readLightLevel();
    Serial.print("Cường độ ánh sáng: ");
    Serial.print(lux);
    Serial.println(" lux");

    delay(1000);  // Đọc mỗi giây
}
