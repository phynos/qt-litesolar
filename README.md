## 监控系统


### 编译说明
暂时只支持windows的mingw编译器，安装后设置环境变量后，运行bat脚本即可直接编译各种测试

### 脚本引擎

#### lua引擎
基于lua5.3版本构建，可以在test-3rd中找到测试和基本使用方法

#### javascript引擎
基于duktape构建，可以在test-3rd中找到测试和基本使用方法  
测试代码已经完成基本js绑定测试（js文件支持require调用）  

### 协议栈

#### modbus-slave
以libmodbus为基础

#### modbus-master
以freemodbus为基础

#### IEC104
暂缺