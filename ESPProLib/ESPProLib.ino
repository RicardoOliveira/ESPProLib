#include "./esppl_functions.h"

void cb(esppl_frame_info *info) {
  Serial.print("\n");
  Serial.print("FT: ");  
  Serial.print((int) info->frametype);
  Serial.print(" FST: ");  
  Serial.print((int) info->framesubtype);
  Serial.print(" SRC: ");
  for (int i = 0; i < 6; i++) Serial.printf("%02x", info->sourceaddr[i]);
  Serial.print(" DEST: ");
  for (int i = 0; i < 6; i++) Serial.printf("%02x", info->receiveraddr[i]);
  Serial.print(" RSSI: ");
  Serial.print(info->rssi);
  Serial.print(" SEQ: ");
  Serial.print(info->seq_num);
  Serial.print(" CHNL: ");
  Serial.print(info->channel);
  if (info->ssid_length > 0) {
    Serial.print(" SSID: ");
    for (int i = 0; i < info->ssid_length; i++) Serial.print((char) info->ssid[i]);    
  }
}

void setup() {
  delay(500);
  Serial.begin(115200);
  esppl_init(cb);
}

void loop() {
  esppl_sniffing_start();
  while (true) {
    for (int i = 1; i < 15; i++ ) {
      esppl_set_channel(i);
      while (esppl_process_frames()) {
        //
      }
    }
  }  
}
