/*
* 计算机系统 第七章作业
* 学号：1190200526
* 姓名：沈城有
* 题目：7.7, 7.9, 7.11 （7.13不要求）
*/

#include <stdio.h>
#include <stdlib.h>

//7.7题：
/* bar5.c */
//只需将x声明为static，链接会成为内部链接
static double x;

void f()
{
    x = -0.0;
}

/*7.9题：
答：在Linux环境下，我的输出是"0xfffffff3\n"。
在foo6.c中，main是函数，属于强符号；而在bar6.c中，main为未初始化全局变量，是弱符号。
链接器选择了foo6.c中的强符号，其指向main函数的起始位置，
而main函数第一条机器指令为f3 0f 1e fa，即endbr64，
故被printf输出时会默认输出开头的一个字节内容，0xf3被符号扩展故得到0xfffffff3。
若在Windows环境下运行输出则为"0x55\n"，对应main函数第一条机器指令push %rbp。
*/

/*7.11题：
答：书P484页有相关说明：该段中剩余的8个字节对应于运行时将被初始化为0的.bss数据。
*/

/*7.13题：
A.
【使用命令】
------------------------------------------------------
ar -t /usr/lib/x86_64-linux-gnu/libc.a | wc -l
ar -t /usr/lib/x86_64-linux-gnu/libm.a | wc -l （报错）
ar -t /usr/lib/x86_64-linux-gnu/libm-2.31.a | wc -l
------------------------------------------------------
【结果】
libc.a : 1740
libm.a : 802
【说明】
终端命令 ar -t libm.a | wc -l 报错，输出如下：
------------------------------------------------------
ar: libm.a: file format not recognized
0
------------------------------------------------------
查看文件发现libm.a仅有132字节，libm-2.31.a大小为3.3MB，猜测有效的libm文件可能是这个，命令输出为802。
*/