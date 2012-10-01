#include <iostream>
#include <pcap.h>
#include <stdint.h>
#include <map>

#define MAX_DEV 10


class arp_table
{
   /*define data structure*/
   typedef std::map<uint32_t, uint64_t> ipaddr_mac_map;
   ipaddr_mac_map ipaddrMacMap;

public:
   arp_table();
   uint64_t lookup_ip(uint32_t ipAddr);
};

class routing_table
{
    typedef enum
    {
       LAST_HOP,
       NO_ENTRY,
       ENTRY_FOUND
    } rt_ret_val;
    /*define data structure*/

public:
    routing_table();
    
    rt_ret_val lookup_ip( uint32_t  destIp,
                          uint32_t &nextHop,
                          char     *device);
    rt_ret_val insert_ip( uint32_t destIp,
                          uint32_t nextHop,
                          char*    *device);
};

class router
{
    int noDev;
    pcap_t* pcapDevHandle;

    arp_table arpTable;
    routing_table routingTable;

    void handle_icmp();
    void handle_arp();
    void handle_ip();

public:
    router(int noDev,
           pcap_t* pcapDevHandle[MAX_DEV]);

    void start();
};

