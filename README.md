# BNO055
BNO055(9軸センサー)をMedOS6に対応させました。
※printfで%fを使いfloatを表示するには mbed_app.json をmain.cppと同じ階層においてください。

## サンプルコード
```cpp
#include "mbed.h"
#include "BNO055.h"
BNO055 bno(D14,D15); //I2C

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
        bno.setmode(OPERATION_MODE_NDOF); //魔法
        bno.get_calib(); // 補正取得
        bno.get_angles(); // 角度取得
        bno.get_quat();  // 4元数取得(詳しくは問題点LINKをチェック！)
        printf("%f\n",bno.euler.yaw); // <- 0~360 (初期位置0)
        ThisThread::sleep_for(1ms);
    }
}
```


[データシート](https://rokuen.work/dx/assets/020_images/BNO055_BME280/BST_BNO055.pdf)

[元link](https://os.mbed.com/users/StressedDave/code/BNO055/docs/tip/classBNO055.html)

[問題点link](http://l52secondary.blog.fc2.com/blog-entry-50.html)
