#include <reg51.h>
#include <intrins.h>
#define PORT P0 //I/O端口
#define uchar unsigned char 
sbit RS = P2 ^ 2;
sbit RW = P2 ^ 3;
sbit E = P2 ^ 4;

void delayms(uchar ms)
// 延时子程序
{
    unsigned char i;
    while (ms--)
    {
        for (i = 0; i < 120; i++)
            ;
    }
}
void writeCommand(uchar command)
{
    E = 0;
    RS = 0; //RS=0 表示写命令
    delayms(50);
    RW = 0;
    delayms(50);
    PORT = command;
    delayms(50);
    E = 1;
    delayms(50);
    E = 0;
    //按照时序图依次设置各个信号以及延时
}
void writeData(uchar byte)
{
    E = 0;
    RS = 1; //RS=0 表示写数据
    delayms(10);
    RW = 0;
    delayms(10);
    PORT = byte;
    delayms(10);
    E = 1;
    delayms(10);
    E = 0;
    //按照时序图依次设置各个信号以及延时
}
void writeAChar( uchar x, uchar y, uchar word)
{
    x &= 0x0f;     //取低四位
    y &= 0x01;     //取第0位
    if (y)         //如果y=1即第二行
        x |= 0x40; //根据DDRAM地址格式,第二行应设置为0x4X
    x |= 0x80;     //设置指令字为写DDRAM地址
    writeCommand(x);
    writeData(word);
}
void writeStr(uchar addr,uchar length,uchar* str,uchar shift)
{
    writeCommand(addr);
	uchar i=0;
    for(i=0;i<length;i++)
    {
		writeData(str[i]);
	}
    if(shift)
    {
        for(i=0;i<length;i++)
         {
		     writeCommand(0x1c);
             delayms(1000);
	     }
        
    }
}
void checkBusy()
{
    uchar temp = 0;
    RS = 0; //命令
    RW = 1; //读
    E = 0;
    while (1)
    {
        PORT = 0xFF;
        E = 1;
        temp = PORT;
        E = 0;
        if ((temp & 0x80) == 0) //检查BF位是否为0
        {
            break;
        }
    }
}
main()
{
    uchar WorkStyle = 0x38; //按照指令字格式设置为8为数据接口，两行显示，5*8点阵
                            //即command=(001111000)2
    uchar Control = 0x0F;   //显示开，光标显示，光标闪烁 即00001111
    uchar Mode = 0x06;      //写入数据后光标右移，显示不移动
    uchar Clear = 0x01;     //清屏
    uchar str[]="I Love You ! ZQS"; //变量声明需要在函数最前面
    /*初始化开始*/
    writeCommand(WorkStyle);     //设置工作模式
    delayms(500);                //延时等待设置完成
    writeCommand(Control);       //设置光标
    delayms(500);                //延时等待设置完成
    writeCommand(Mode);          //设置光标移动
    delayms(500);                //延时等待设置完成
    writeCommand(Clear);         //设置光标移动
    delayms(500);                //延时等待设置完成
    /*初始化结束*/
    /*writeAChar(0x00, 0x00, 'A'); //左上角写A
    writeAChar(0x01, 0x00, 'B'); //左上角写A
    writeAChar(0x00, 0x01, 'C'); //左上角写A
    writeAChar(0x01, 0x01, 'D'); //左上角写A*/
	writeStr(0x80,strlen(str),str,1);
}