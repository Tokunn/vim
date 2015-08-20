#include "libspi.h"
#include <iostream>
#include <stdio.h>

#define MCP320X_PACKET_SIZE	1
#define MCP320X_DIFF		0
#define MCP320X_SINGLE		1
#define MCP320X_RESOLUTION	4095
#define MCP3204_CHANNELS	4
#define MCP3208_CHANNELS	8

#define SIZE 1

int main() {
    int bus=0, cs=1;
    uint8_t mode = 0;
    //mode = SPI_CPOL | SPI_CPHA;
    mode = SPI_CPOL | SPI_CPHA;
    uint8_t packet[MCP320X_PACKET_SIZE];
    packet[0] = 0x6;
    packet[0] = 0x18;
    packet[1] = 0x40;
    double ref = 3.30;
    uint8_t *rxbuf;
    SPI *spi = new SPI(bus, cs, mode);
    rxbuf = spi->transfer(MCP320X_PACKET_SIZE, packet);
    //printf("Send:0x%x 0x%x \t Recive:0x%x 0x%x\n", packet[0], packet[1], rxbuf[1], rxbuf[2]);
    printf("Send:0x%x \t Recive:0x%x\n", packet[0], rxbuf[0]);
    int d = (rxbuf[1] & 0x0F) << 8;
    d |= rxbuf[2];
    printf("%fV\n", (double)((d * ref)/MCP320X_RESOLUTION));
    delete(rxbuf);
    delete(spi);
    return 0;
}
