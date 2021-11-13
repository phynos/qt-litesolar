
#include <stdio.h>
#include <stdlib.h>
#include "modbus.h"
#include <memory.h>

#include <windows.h>

int main(void)
{
    modbus_t *mb;
    uint16_t tab_reg[64]={0};

    //1-打开端口
    mb = modbus_new_tcp("127.0.0.1",502);

    //2-设置从地址
    modbus_set_slave(mb,1);

    //3-建立连接
    if (modbus_connect(mb) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(mb);
        return -1;
    }

    //4-设置应答延时
    struct timeval t;
    t.tv_sec=0;
    t.tv_usec=1000000;//1000ms
    modbus_set_response_timeout(mb,0,1000000);

    //5-循环读
    int num = 0;
    while(1)
    {   
        memset(tab_reg,0,64*2);

        //6-读寄存器设置：寄存器地址、数量、数据缓冲
        int regs=modbus_read_registers(mb, 0, 20, tab_reg); 
       
        printf("-------------------------------------------\n");
        printf("[%4d][read num = %d]",num,regs);
        num++;
        
        int i;
        for(i=0; i<20; i++)
        {
            printf("<%#x>",tab_reg[i]);
        }
        printf("\n");
        printf("-------------------------------------------\n");
        sleep(1);
    }

    //7-关闭modbus端口
    modbus_close(mb); 

    //8-释放modbus资源
    modbus_free(mb);
    return 0;
}
