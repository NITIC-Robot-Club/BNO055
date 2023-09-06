#include "mbed.h"
#include "BNO055.h"

BNO055 bno(D14,D15);
DigitalOut led(LED1);

int main() {
    printf("BNO055 Hello World\r\n\r\n");
    led = 1;
    bno.reset();
    while (!bno.check()){
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
        bno.get_angleee();
        printf("%f ",bno.euler.yaw); // <- 0~360 (初期位置0)
        // printf("   ");
        // printf("%f ",bno.quat.x);
        // printf("%f ",bno.quat.y);
        // printf("%f ",bno.quat.z);
        // printf("%f ",bno.quat.w);
        // printf("   ");
        // printf("%f ",bno.angleee.roll);
        // printf("%f ",bno.angleee.pitch);
        // printf("%f ",bno.angleee.yaw);
        printf("\n");
        ThisThread::sleep_for(1ms);
    }
}
