
#include <EEPROM.h>

#ifndef DataStore_h
#define DataStore_h

#define MAX_BYTES_EEPROM 4096

class DataStore: public EEPROM {
    public:
        typedef struct {
            // Stations: devices that connect to wifi networks
            char sta_ssid[32];
            char sta_pass[64];
            uint8_t sta_dhcp_enable;
            uint8_t sta_local_ip[4];
            uint8_t sta_gateway[4];
            uint8_t sta_subnet[4];
            // Access Points: devices that provide wifi networks
            char ap_ssid[32];
            char ap_pass[64];
            uint8_t ap_local_ip[4];
            uint8_t ap_gateway[4];
            uint8_t ap_subnet[4];
        } Data;
        
        // TODO: instantiate Data typedef struct
        // Data loaded_data = Data;

        // Loads Data variable with Flash data
        DataStore();

        uint StoreRead(uint16_t init_byte, uint16_t size);
        uint StoreWrite(uint16_t init_byte, uint8_t values[]);

};

#endif