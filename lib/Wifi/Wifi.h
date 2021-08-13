
#include <ESP8266WiFi.h>
#include <Arduino.h>

#ifndef Wifi_h
#define Wifi_h

#define I_SSID_DEFAULT "ESP8266_SSID_Default_Name"
#define I_PASS_DEFAULT ""
#define I_CHANNEL_DEFAULT 1
#define I_MAX_CONNECTION_DEFAULT 1
#define I_LOCAL_IP_DEFAULT {192,168,1,1}
#define I_GATEWAY_DEFAULT {192,168,1,1}
#define I_SUBNET_DEFAULT {255,255,255,0}

class Wifi : public WiFi {
    public:
        Wifi(char* ssid, char* pass, uint8_t channel, uint8_t max_connection, uint8_t* local_ip, uint8_t* gateway, uint8_t* subnet);
        void WifiRun(char* ssid, char* pass, uint8_t channel, uint8_t max_connection, uint8_t* local_ip, uint8_t* gateway, uint8_t* subnet);
        void WifiConfig(uint8_t* local_ip, uint8_t* gateway, uint8_t* subnet);
        void WifiSetup(char* ssid, char* pass, uint8_t channel, uint8_t max_connection);
        void WifiRunDefault();
        
        uint8_t StationNumGet();
        uint8_t* CurrentIpGet();
        uint8_t* MacAddressGet();
        
        char* SsidDefaultGet();
        char* PassDefaultGet();
        uint8_t ChannelDefaultGet();
        uint8_t MaxConnectionDefaultGet();
        uint8_t* LocalIpDefaultGet();
        uint8_t* GatewayDefaultGet();
        uint8_t* SubnetDefaultGet();

        char* SsidGet();
        char* PassGet();
        uint8_t ChannelGet();
        uint8_t MaxConnectionGet();
        uint8_t* LocalIpGet();
        uint8_t* GatewayGet();
        uint8_t* SubnetGet();

    private:
        char i_ssid_default[32] = I_SSID_DEFAULT;
        char i_pass_default[64] = I_PASS_DEFAULT;
        uint8_t i_channel_default = I_CHANNEL_DEFAULT;
        uint8_t i_max_connection_default = I_MAX_CONNECTION_DEFAULT;
        uint8_t i_local_ip_default[4] = I_LOCAL_IP_DEFAULT;
        uint8_t i_gateway_default[4] = I_GATEWAY_DEFAULT;
        uint8_t i_subnet_default[4]= I_SUBNET_DEFAULT;

        char i_ssid[32] = I_SSID_DEFAULT;
        char i_pass[64] = I_PASS_DEFAULT;
        uint8_t i_channel = I_CHANNEL_DEFAULT;
        uint8_t i_max_connection = I_MAX_CONNECTION_DEFAULT;
        uint8_t i_local_ip[4] = I_LOCAL_IP_DEFAULT;
        uint8_t i_gateway[4] = I_GATEWAY_DEFAULT;
        uint8_t i_subnet[4] = I_SUBNET_DEFAULT;

        void SsidSet(char ssid[32]);
        void PassSet(char pass[64]);
        void ChannelSet(uint8_t channel);
        void MaxConnectionSet(uint8_t max_connection);
        void LocalIpSet(uint8_t local_ip[4]);
        void GatewaySet(uint8_t gateway[4]);
        void SubnetSet(uint8_t subnet[4]);

    // TODO When required. Secure communications with TLS

    // TODO When required. Implement Station Mode configuration: 
    // The ESP can operate in both soft-AP and Station mode so it can act as a node of a mesh network.
};

#endif