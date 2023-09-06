#include "mbed.h"
#include "BNO055.h"

BNO055 bno(D14,D15);
DigitalOut led(LED1);

int main() {
    printf("BNO055 Hello World\r\n\r\n");
    led = 1;
    bno.reset();
    if (!bno.check())
        while (true){
            led = !led;
            ThisThread::sleep_for(1ms);
            }
    printf("BNO055 found\r\n\r\n");
    printf("\r\n");
    while (true) {
        bno.setmode(OPERATION_MODE_NDOF);
        bno.get_calib();
        bno.get_angles();
        bno.get_quat();
        printf("%c ",bno.calib);
        printf("%f ",bno.euler.roll);
        printf("%f ",bno.euler.pitch);
        printf("%f ",bno.euler.yaw);
        
        printf("\n");
        ThisThread::sleep_for(1ms);
    }
}
