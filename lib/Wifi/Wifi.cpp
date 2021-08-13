#include "Wifi.h"

Wifi::Wifi(){
    WifiSoftAPRunDefault();
}

// TODO
Wifi::Wifi(Wifi::WifiConf wifi_conf, Wifi::Network network){
    // WifiRun(ssid, pass, channel, max_connection, local_ip, gateway, subnet);
}

void Wifi::WifiSoftAPRunDefault(){
    WifiConf def_wifi_conf = {
        I_SSID_DEFAULT,
        I_PASS_DEFAULT,
        I_CHANNEL_DEFAULT,
        I_MAX_CONNECTION_DEFAULT
    };

    Network def_network = {
        I_LOCAL_IP_DEFAULT,
        I_GATEWAY_DEFAULT,
        I_SUBNET_DEFAULT
    };

    WifiSoftAPRun(def_wifi_conf, def_network);
}

void Wifi::WifiSoftAPRun(Wifi::WifiConf wifi_conf, Wifi::Network network){
    WifiSoftAPConfig(network);
    WifiSoftAPSetup(wifi_conf);
}

void Wifi::WifiSoftAPConfig(Wifi::Network network){
    // TODO
    // NetworkSet(network)
    IPAddress aux_local_ip( network.local_ip[0],
                            network.local_ip[1],
                            network.local_ip[2],
                            network.local_ip[3]);
    IPAddress aux_gateway(  network.gateway[0],
                            network.gateway[1],
                            network.gateway[2],
                            network.gateway[3]);
    IPAddress aux_subnet(   network.subnet[0],
                            network.subnet[1],
                            network.subnet[2],
                            network.subnet[3]);

    softAPConfig(aux_local_ip, aux_gateway, aux_subnet);
}

void Wifi::WifiSoftAPSetup(Wifi::WifiConf wifi_conf){
    // TODO
    // WifiConfSet(wifi_conf);
    
    // Do not hide SSID
    uint8_t aux_hidden = 0x00;

    softAP(wifi_conf.ssid, wifi_conf.pass, wifi_conf.channel, aux_hidden, wifi_conf.max_connection);
}


// uint8_t Wifi::StationNumGet(){
//     return ESP8266WiFiClass.softAPgetStationNum();
// }

// uint8_t* Wifi::CurrentIpGet(){
//     return ESP8266WiFiClass.softAPIP();
// }

// uint8_t* Wifi::MacAddressGet(){
//     uint8_t mac_addr[6];
//     ESP8266WiFiClass.softAPmacAddress(mac_addr);
//     return mac_addr;
// }

// char* Wifi::SsidDefaultGet(){ return i_ssid_default;}
// char* Wifi::PassDefaultGet(){ return i_pass_default;}
// uint8_t Wifi::ChannelDefaultGet(){ return i_channel_default;}
// uint8_t Wifi::MaxConnectionDefaultGet(){ return i_max_connection_default;}
// uint8_t* Wifi::LocalIpDefaultGet(){ return i_local_ip_default;}
// uint8_t* Wifi::GatewayDefaultGet(){ return i_gateway_default;}
// uint8_t* Wifi::SubnetDefaultGet(){ return i_subnet_default;}

// char* Wifi::SsidGet(){ return i_ssid;}
// char* Wifi::PassGet(){ return i_pass;}
// uint8_t Wifi::ChannelGet(){ return i_channel;}
// uint8_t Wifi::MaxConnectionGet(){ return i_max_connection;}

// uint8_t* Wifi::LocalIpGet(){ return i_local_ip;}
// uint8_t* Wifi::GatewayGet(){ return i_gateway;}
// uint8_t* Wifi::SubnetGet(){ return i_subnet;}
Wifi::Network Wifi::NetworkGet(){return i_network;}

// Private

// void Wifi::SsidSet(char ssid[32]){i_ssid = ssid;}
// void Wifi::PassSet(char pass[64]){i_pass = pass;}
// void Wifi::ChannelSet(uint8_t channel){i_channel = channel;}
// void Wifi::MaxConnectionSet(uint8_t max_connection){i_max_connection = max_connection;}

// void Wifi::LocalIpSet(uint8_t local_ip[4]){i_local_ip = local_ip;}
// void Wifi::GatewaySet(uint8_t gateway[4]){i_gateway = gateway;}
// void Wifi::SubnetSet(uint8_t subnet[4]){i_subnet = subnet;}

void Wifi::NetworkSet(Network net){}
