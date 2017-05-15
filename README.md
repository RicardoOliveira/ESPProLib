# ESPProLib
## ESP8266 Promiscuous Library
The ESPProLib is a simple set of functions and strutures to help using the ESP8266 chip in promiscuous mode.

## Functions
#### void esppl_set_channel(int channel)
Changes the listening channel. Only one channel at a time can be used to receive frames.

**int channel** - should be a value between **ESPPL_CHANNEL_MIN** (1) and **ESPPL_CHANNEL_MAX** (14).

#### bool esppl_process_frames()
Allows some time to process the frames received. This function should be called if using a loop to scan through multiple channels.

The function returns true if there are still frames to be processed, false otherwise.

#### void esppl_init(ESPPL_CB_T cb)
Initializes the library and sets the ESP8266 in promiscuous mode.

**ESPPL_CB_T cb** - callback function to handle the parsed frame information. The function should have a structure similar to this:
```
void cb(esppl_frame_info *info)
```

#### void esppl_sniffing_start()
Starts the sniffing process.

#### void esppl_sniffing_stop()
Stops the sniffing process.
