#include "esphome.h"
#include <cstdio>

class LittleFSTest : public Component {
 public:
  void setup() override {
    ESP_LOGI("littlefs_test", "Testing LittleFS...");

    FILE *f = fopen("/littlefs/test.txt", "w");
    if (!f) {
      ESP_LOGE("littlefs_test", "Failed to open file for writing on LittleFS");
      return;
    }
    const char *msg = "LittleFS OK\n";
    fwrite(msg, 1, strlen(msg), f);
    fclose(f);
    ESP_LOGI("littlefs_test", "Wrote test file on LittleFS");
  }

  void loop() override {}
};
