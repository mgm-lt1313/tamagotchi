#include <M5StickCPlus.h>

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(LIGHTGREY); // 背景をLIGHTGRAYに設定

  uint16_t centerX = 67;  // 中央X座標
  uint16_t centerY = 120; // 中央Y座標
  uint16_t size = 10;      // 1ドットのサイズ

  // ドットパターン (0: 白, 1: 黒)
  uint8_t tama[12][12] = {
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };

  // ドット絵の左上基準座標
  uint16_t startX = centerX - (12 * size) / 2;
  uint16_t startY = centerY - (12 * size) / 2;

  // 描画
  for (uint16_t i = 0; i < 12; i++) {
    for (uint16_t j = 0; j < 12; j++) {
      uint16_t color = (tama[i][j] == 1) ? BLACK : LIGHTGREY;
      M5.Lcd.fillRect(startX + j * size, startY + i * size, size, size, color);
    }
  }
}

void loop() {
  // 静止画なのでループ処理なし
}
