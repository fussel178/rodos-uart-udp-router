#include "rodos.h"

#define DEFAULT_DOWNLINK_PORT 8670
#define DEFAULT_UPLINK_PORT 8669
#define DEFAULT_REMOTE_HOSTNAME "0.0.0.0"

RODOS::UDPInOut udp{DEFAULT_DOWNLINK_PORT, DEFAULT_UPLINK_PORT, DEFAULT_REMOTE_HOSTNAME};
RODOS::LinkinterfaceUDP link_interface_udp{&udp};
RODOS::Gateway udp_gateway{&link_interface_udp, true};

RODOS::HAL_UART local_uart{RODOS::UART_IDX0}; //  /dev/ttyUSB0
RODOS::LinkinterfaceUART link_interface_uart{&local_uart, 115200};
RODOS::Gateway uart_gateway{&link_interface_uart, true};

//RODOS::Router router{false, &udp_gateway, &uart_gateway};

RODOS::Topic<int> myTopic{0x411, "myTopic"};

class TestSubscriber : SubscriberReceiver<int> {

public:
    TestSubscriber() : SubscriberReceiver<int>(myTopic, "testSubscriber") {}

    uint32_t put(const uint32_t topicId, const size_t len, void *data, const RODOS::NetMsgInfo &netMsgInfo) override {
        PRINTF("length: %d", len);
        return 0;
    }
} testSubscriber;
