#include "Wifi.h"

Wifi::Wifi(char* ssid, char* pass, uint8_t channel, uint8_t max_connection, uint8_t* local_ip, uint8_t* gateway, uint8_t* subnet){
    WifiRun(ssid, pass, channel, max_connection, local_ip, gateway, subnet);
}

void Wifi::WifiRun(char* ssid, char* pass, uint8_t channel, uint8_t max_connection, uint8_t* local_ip, uint8_t* gateway, uint8_t* subnet){
    WifiConfig(local_ip, gateway, subnet);
    WifiSetup(ssid, pass, channel, max_connection);
}

void Wifi::WifiConfig(uint8_t* local_ip, uint8_t* gateway, uint8_t* subnet){
    uint8_t filtered_local_ip[4];
    uint8_t filtered_gateway[4];
    uint8_t filtered_subnet[4];

    LocalIpSet(local_ip);
    GatewaySet(gateway);
    SubnetSet(subnet);
    filtered_local_ip = LocalIpGet();
    filtered_gateway = GatewayGet();
    filtered_subnet = SubnetGet();
    IPAddress aux_local_ip( filtered_local_ip[0],
                            filtered_local_ip[1],
                            filtered_local_ip[2],
                            filtered_local_ip[3]);
    IPAddress aux_gateway( filtered_gateway[0],
                            filtered_gateway[1],
                            filtered_gateway[2],
                            filtered_gateway[3]);
    IPAddress aux_subnet( filtered_subnet[0],
                            filtered_subnet[1],
                            filtered_subnet[2],
                            filtered_subnet[3]);

    WiFi.softAPConfig(aux_local_ip, aux_gateway, aux_subnet);
}

void Wifi::WifiSetup(char* ssid, char* pass, uint8_t channel, uint8_t max_connection){
    // Set variables
    SsidSet(ssid);
    PassSet(pass);
    ChannelSet(channel);
    MaxConnectionSet(max_connection);
    // Do not hide SSID
    uint8_t aux_hidden = 0x00;

    WiFi.softAP(SsidGet(), PassGet(), ChannelGet(), aux_hidden, MaxConnectionGet());
}

void Wifi::WifiRunDefault(){
    WifiConfig(LocalIpDefaultGet(), GatewayDefaultGet(), SubnetDefaultGet());
    WifiSetup(SsidDefaultGet(), PassDefaultGet(), ChannelDefaultGet(), MaxConnectionDefaultGet());
}

uint8_t Wifi::StationNumGet(){
    return WiFi.softAPgetStationNum();
}

uint8_t* Wifi::CurrentIpGet(){
    return WiFi.softAPIP();
}

uint8_t* Wifi::MacAddressGet(){
    uint8_t mac_addr[6];
    WiFi.softAPmacAddress(mac_addr);
    return mac_addr;
}

char* Wifi::SsidDefaultGet(){ return i_ssid_default;}
char* Wifi::PassDefaultGet(){ return i_pass_default;}
uint8_t Wifi::ChannelDefaultGet(){ return i_channel_default;}
uint8_t Wifi::MaxConnectionDefaultGet(){ return i_max_connection_default;}
uint8_t* Wifi::LocalIpDefaultGet(){ return i_local_ip_default;}
uint8_t* Wifi::GatewayDefaultGet(){ return i_gateway_default;}
uint8_t* Wifi::SubnetDefaultGet(){ return i_subnet_default;}

char* Wifi::SsidGet(){ return i_ssid;}
char* Wifi::PassGet(){ return i_pass;}
uint8_t Wifi::ChannelGet(){ return i_channel;}
uint8_t Wifi::MaxConnectionGet(){ return i_max_connection;}
uint8_t* Wifi::LocalIpGet(){ return i_local_ip;}
uint8_t* Wifi::GatewayGet(){ return i_gateway;}
uint8_t* Wifi::SubnetGet(){ return i_subnet;}

// Private

void Wifi::SsidSet(char* ssid){i_ssid = ssid;}
void Wifi::PassSet(char* pass){i_pass = pass;}
void Wifi::ChannelSet(uint8_t channel){i_channel = channel;}
void Wifi::MaxConnectionSet(uint8_t max_connection){i_max_connection = max_connection;}
void Wifi::LocalIpSet(uint8_t* local_ip){i_local_ip = local_ip;}
void Wifi::GatewaySet(uint8_t* gateway){i_gateway = gateway;}
void Wifi::SubnetSet(uint8_t* subnet){i_subnet = subnet;}
