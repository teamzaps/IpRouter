#include <stdio.h>
#include <pcap.h>
#include <router.h>

char errbuf[PCAP_ERRBUF_SIZE];
router *routerObj;

int main( int argc, char* argv[])
{
    char *dev = NULL;
    pcap_t *pcapDevHandle[MAX_DEV];


    for( int i = 1; i < argc; i++)
    {
        pcapDevHandle[i-1] = 
            pcap_open_live(argv[i], 
                           BUFSIZ, 
                           1, 
                           1000, 
                           errbuf);
        if ( pcapDevHandle[i-1] == NULL)
        {
            fprintf(stderr, 
                    "Cound't open device %s: %s\n",
                    argv[i],
                    errbuf);
                    
        }
    }
    routerObj = new router(argc-1, 
                           pcapDevHandle);

    routerObj->start();
}
