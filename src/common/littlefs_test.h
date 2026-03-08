#include "esphome.h"
#include <stdio.h>
#include "esp_littlefs.h"

class LittleFSTest : public Component {
 public:
  void setup() override {
    ESP_LOGI("LittleFS", "=== Testing filesystem ===");
    
    // Simple write test
    FILE *f = fopen("/littlefs/test.txt", "w");
    if (f) {
      fprintf(f, "LittleFS OK %lu\n", millis());
      fclose(f);
      ESP_LOGI("LittleFS", "✅ Write OK");
      
      // Read back verify
      f = fopen("/littlefs/test.txt", "r");
      if (f) {
        char buf[64];
        fgets(buf, sizeof(buf), f);
        fclose(f);
        ESP_LOGI("LittleFS", "✅ Read OK: %s", buf);
      }
    } else {
      ESP_LOGE("LittleFS", "❌ Partition not mounted or inaccessible");
    }
  }
};

