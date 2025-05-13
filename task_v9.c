#include <stdio.h>
#include <stdlib.h>

void scan_port(int port) {
    char command[128];
    snprintf(command, sizeof(command), "netstat -an | grep :%d", port);
    if (system(command) == 0) {
        printf("Port %d is active.\n", port);
    } else {
        printf("Port %d is closed or inactive.\n", port);
    }
}

int main() {
    int ports[] = {22, 80, 443, 3306};
    int size = sizeof(ports) / sizeof(ports[0]);

    for (int i = 0; i < size; i++) {
        scan_port(ports[i]);
    }

    return 0;
}
