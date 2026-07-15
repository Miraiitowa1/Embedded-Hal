## 1.1 Cortex-M3
![alt text](image-10.png)
### CM3Core是Cortex-M3的中央处理器 采用哈弗结构
![alt text](image-11.png)
### NVIC 中断控制器 采用向量中断机制
### SYSTICK 系统定时器 24位倒计时计数器
### MPU（存储保护单元）
### Bus Matrix (总线矩阵) 32位AHB总线互连网络
### 调试接口
#### Cortex-M3处理器的调试系统主要由 SW-DP/SWJ-DP(Serial Wire-Debug Port / Serial Wire JTAG-Debug Port，串⾏线调试端⼝/串⾏线JTAG调试端⼝)、AHB-AF(Advanced High Performance Bus-Access Port，AHB 访问端⼝)
### 跟踪输出接口
#### Cortex-M3处理器具有指令跟踪(由 ETM 产⽣)、数据跟踪(由 DWT产⽣)和调试信息跟踪(由ITM 产⽣)3 种跟踪源,并⽀持各种跟踪机制
---

## 1.2 Cortex-M3编程模型
### 工作状态
#### 在 Thumb 状态下处理器执⾏ 16 位和32 位半字对⻬的 Thumb-2 指令的状态
#### 在调试状态下，处理器停⽌执⾏并进⾏调试时进⼊该状态
### 数据类型
#### 字节(B)⻓为 8位
#### 半字(halfword)⻓为16位，必须以 2字节对⻬的⽅式存取
#### 字(word)⻓为 32位，必须以4字节对⻬的⽅式存取
### 寄存器
#### R0~R12 通用寄存器
#### R13（SP） 
##### 堆栈指针寄存器 由一块连续的内存和一个堆栈指针组成 常用于临时保存将要或易于被修改的数据，以便将来能够恢复 同一时间，只能有一个SP
##### 1.**主堆栈指针（MSP）** 复位后默认的堆指针 由操作系统内核、异常服务程序以及特权访问的用户使用
##### 2.**进程堆栈指针（PSP）** 由常规用户程序使用
#### R14（LR）链接寄存器 常用于调用子程序时保存返回地址
#### R15（PC）程序计数器 用于存放下一条执行的指令的地址
#### 特殊功能寄存器组
##### 程序状态寄存器组xPSR
#### 中断屏蔽寄存器组（FAULMASK/PRMASK/BASEPRI
![alt text](image-12.png)
#### 控制寄存器 CONTROL 2位寄存器
![alt text](image-13.png)
---

## 1.3 指令集
### CISC/RISC Cortex-M3（RISC）
### 指令格式 操作码字段和操作数字段
#### Thumb-2指令集 16/32混合指令集
---

## 1.4 操作模式与特权分级
### 特权分级
![alt text](image-14.png)
### 操作模式
#### 线程模式。当复位或异常返回时，Cortex-M3 进⼊该模式。通常情况下，线程模式是⽤⼾应⽤程序的运⾏模式。在该模式下,可以执⾏特权级和⽤⼾(⾮特权)级代码
#### 处理者模式。当发⽣异常时，Cortex-M3 进⼊该模式 通常情况下，Handler 模式是异常或中断服务程序或操作系统内核代码的运⾏模式。在该模式下,所有代码都是特权访问的
### 模式间的切换
![alt text](image-15.png)
---

## 1.5 异常和中断
###  ARM 中凡是发⽣了打断程序正常执⾏流程的事件，都被称为异常(exception) 中断(interrupt)是⼀种特殊的异常
---

## 1.6 Cortex-M3存储器系统 存储器映射
![alt text](image-16.png)
---

## 1.7 Cortex-M3低功耗模式
### 睡眠模式
#### Cortex-M3内核可以通过WFI/WFE指令进入睡眠，停止执行指令，只有NVIC的小部分保持唤醒
### 深度睡眠模式
#### Cortex-M3在微控制器的配合驱动下实现深度睡眠模式
---

## 2.1 复位与时钟控制
### 复位（RESET）
#### 将CPU的所有内部寄存器、状态和程序计数器等重置为预定值，以便系统能够从指定的程序入口重新启动
#### **上电复位（POR）**
#### **掉电复位**
#### **复位引脚复位**
#### **看门狗复位**
#### **软件复位**
---

## 2.2 STM32F103启动过程
### 初始化异常向量表、初始化时钟系统、初始化存储器系统、初始化堆栈、跳转到main函数等
---

## 2.3 ARM汇报语言
### [LABEL] OPERATION [OPERAND] [:COMMENT]
#### LABEL ：标号。是指令、变量或数据的地址或者常量。此项为可选项，如果有区必须顶格书写，后⾯不能加冒号
#### OPERATION ：指令、宏指令、伪指令或伪操作 此项为必选项，但不能在⼀⾏开头顶格书写，⽽且前后必须有空格。特别注意，在ARM 汇编程序中，⼀条指令伪指令、寄存器名可以全部为⼤写字⺟,也可以全部为⼩写字⺟，但不要⼤⼩写混合使⽤。
#### OPERAND ：操作的对象(即操作数)。可以是常量、变量，标号、寄存器或表达式。此项为可选项，若有多个操作数,操作数之间⽤逗号隔开。
#### COMMENT：程序注释，增强代码的可读性。此项为可选项，由分号开始，可以顶格写

#### 指令
##### **B（）**
###### B{<code>} Rm/label label或 Rm 是跳转的⽬标地址，跳转范围在 +/- 32MB 之间 例如，“B.”表⽰跳转到当前地址(“.”表⽰当前指令地址)，即进⼊死循环，等价于C语⾔的while(1)
##### **BX（跳转并切换指令集）**
##### **BLX（带返回地址的跳转并切换指令集）**

### 伪指令

### 伪操作
#### 数据定义伪操作 EQU(常量定义和赋值，与 C语⾔中#define 有异曲同⼯之妙) SPACE(分配⼀⽚连续的存储区域。等价于C语⾔的malloc) DCD(分配⼀⽚连续的字（4字节）存储区域并初始化)
---

## GPIO
### GPIO工作模式
#### #define GPIO_MODE_INPUT 0x00000000u /*!< Input Floating Mode */
#### #define GPIO_MODE_OUTPUT_PP 0x00000001u /*!< Output Push Pull Mode */
#### #define GPIO_MODE_OUTPUT_OD 0x00000011u /*!< Output Open Drain Mode */
#### #define GPIO_MODE_AF_PP 0x00000002u /*!< Alternate Function Push Pull Mode */
#### #define GPIO_MODE_AF_OD 0x00000012u /*!< Alternate Function Open Drain Mode */
#### #define GPIO_MODE_AF_INPUT GPIO_MODE_INPUT /*!< Alternate Function Input Mode */
#### #define GPIO_MODE_ANALOG 0x00000003u /*!< Analog Mode */





## 20.1 FreeRTOS
### 20.2 任务管理task
#### 任务创建与启动 osThreadld
