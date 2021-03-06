#include "tcp_demo.h"
#include "uip.h"
#include <string.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "led.h"
#include "rm3100.h"
#include "24cxx.h"
#include "modbus.h"




u8   mac_address[6];//registers: 100 101 102 103 104 105
u8   ip_mode = 0;//register: 106, 0 = static, 1 = DHCP
u8   ip_address[4] = {192, 168, 0, 3};//registers: 107 108 109 110
u8   subnet_mask_address[4] = {255, 255, 255, 0};//registers: 111 112 113 114
u8   gateway_address[4] = {192, 168, 0, 4};//registers: 115 116 117 118
u8   tcp_server_enable = 0;//registers 119
u8   listen_port_at_tcp_server_mode[2] = {0x17, 0x71};//register 120 121

u8   ip_mode_ghost = 0;//register: 106, 0 = static, 1 = DHCP
u8   ip_address_ghost[4] = {0, 0, 0, 0};//registers: 107 108 109 110
u8   subnet_mask_address_ghost[4] = {0, 0, 0, 0};//registers: 111 112 113 114
u8   gateway_address_ghost[4] = {0, 0, 0, 0};//registers: 115 116 117 118
u8   tcp_server_enable_ghost = 0;//registers 119
u8   listen_port_at_tcp_server_mode_ghost[2] = {0, 0};//register 120 121
u8   enable_ghost = 0;


static u8 send_flag = 0; 
static u8 tcp_server_databuf[1024];   	//发送数据缓存	  
static u16 tcp_buf_len;
static u8 tcp_server_sta;				//服务端状态
u16 uart_buf_len;
u8 tcp_buf_ready;
 
static void tcp_para_read(void)
{
	ip_mode_ghost = AT24CXX_ReadOneByte(EEP_IP_MODE);
	AT24CXX_Read(EEP_MAC_ADDRESS,mac_address,6); 
	AT24CXX_Read(EEP_IP_ADDRESS ,ip_address_ghost,4); 
	AT24CXX_Read(EEP_SUBNET_MASK_ADDRESS,subnet_mask_address_ghost,4); 
	AT24CXX_Read(EEP_GATEWAY_ADDRESS,gateway_address_ghost,4);
	AT24CXX_Read(EEP_TCP_PORT,listen_port_at_tcp_server_mode_ghost,2);  							
}
static void tcp_para_set(void)
{
	AT24CXX_WriteOneByte(EEP_IP_MODE,ip_mode_ghost);
	AT24CXX_Write(EEP_MAC_ADDRESS,mac_address,6); 
	AT24CXX_Write(EEP_IP_ADDRESS ,ip_address_ghost,4); 
	AT24CXX_Write(EEP_SUBNET_MASK_ADDRESS,subnet_mask_address_ghost,4); 
	AT24CXX_Write(EEP_GATEWAY_ADDRESS,gateway_address_ghost,4);
	AT24CXX_Write(EEP_TCP_PORT,listen_port_at_tcp_server_mode_ghost,2);  							
}
void tcp_server_initial(void)
{
	tcp_para_read();
	ip_mode = ip_mode_ghost;
	memcpy(ip_address,ip_address_ghost,4);
	memcpy(subnet_mask_address,subnet_mask_address_ghost,4);
	memcpy(gateway_address,gateway_address_ghost,4);
	memcpy(listen_port_at_tcp_server_mode,listen_port_at_tcp_server_mode_ghost,2);
	enable_ghost = DISABLE;
}
void tcp_server_config(void)
{
	ip_mode = ip_mode_ghost;
	memcpy(ip_address,ip_address_ghost,4);
	memcpy(subnet_mask_address,subnet_mask_address_ghost,4); 
	memcpy(gateway_address,gateway_address_ghost,4);
	memcpy(listen_port_at_tcp_server_mode,listen_port_at_tcp_server_mode_ghost,2);
	tcp_para_set();
}

//这是一个TCP 服务器应用回调函数。
//该函数通过UIP_APPCALL(tcp_demo_appcall)调用,实现Web Server的功能.
//当uip事件发生时，UIP_APPCALL函数会被调用,根据所属端口(1200),确定是否执行该函数。
//例如 : 当一个TCP连接被创建时、有新的数据到达、数据已经被应答、数据需要重发等事件
void tcp_server_demo_appcall(void)
{
 	u16 temp;
	struct tcp_demo_appstate *s = (struct tcp_demo_appstate *)&uip_conn->appstate;
	if(uip_aborted())tcp_server_aborted();		//连接终止
 	if(uip_timedout())tcp_server_timedout();	//连接超时   
	if(uip_closed())tcp_server_closed();		//连接关闭	   
 	if(uip_connected())tcp_server_connected();	//连接成功	    
	if(uip_acked())tcp_server_acked();			//发送的数据成功送达 
	//接收到一个新的TCP数据包 
	if(uip_newdata())//收到客户端发过来的数据
	{
//		if((tcp_server_sta & (1 << 6)) == 0)	//还未收到数据
//		{
//			if(uip_len > 499)
//			{		   
//				((u8*)uip_appdata)[499] = 0;
//			}
//		    
//	    	strcpy((char*)tcp_server_databuf, uip_appdata);				   	  		  
//			tcp_server_sta |= 1 << 6;			//表示收到客户端数据
//		}
		if(strcmp(uip_appdata,"send") == 0)
			{
				send_flag =1;
			} 
	}
//	else if(tcp_server_sta & (1 << 5))			//有数据需要发送
//	{
//		s->textptr = tcp_server_databuf;
//		s->textlen = strlen((const char*)tcp_server_databuf);
//		tcp_server_sta &= ~(1 << 5);			//清除标记
//	}
	
	//当需要重发、新数据到达、数据包送达、连接建立时，通知uip发送数据 
	if(uip_rexmit() || uip_newdata() || uip_acked() || uip_connected() || uip_poll())
	{
		if(send_flag == 1)
		{
			if(tcp_buf_ready == 1)
			{	
				if(uart_buf_len > BUF_LEN)
				{	
					temp = BUF_LEN;
				}
				else
					temp = uart_buf_len;
				
				tcp_buf_len = temp*PNI_BUF_SIZE; 
				memcpy(tcp_server_databuf,(u8*)TCP_Buffer,tcp_buf_len);	
				
				uart_buf_len -=temp;
				if(uart_buf_len == 0)
				{
					tcp_buf_ready =0;
					send_flag = 0;
				}
				memcpy(TCP_Buffer,&TCP_Buffer[temp],uart_buf_len*PNI_BUF_SIZE);
				
				s->textptr = tcp_server_databuf;
				s->textlen =tcp_buf_len;//strlen((const char*)tcp_server_databuf);
			}
			else
			{
				//memcpy(tcp_server_databuf,"over",4);
				s->textptr = tcp_server_databuf;
				s->textlen =0;//strlen((const char*)tcp_server_databuf);
				send_flag = 0;
			}
		}
		tcp_server_senddata();
	}
}

//终止连接				    
void tcp_server_aborted(void)
{
	tcp_server_sta &= ~(1 << 7);				//标志没有连接
	uip_log("tcp_server aborted!\r\n");			//打印log
}

//连接超时
void tcp_server_timedout(void)
{
	tcp_server_sta &= ~(1 << 7);				//标志没有连接
	uip_log("tcp_server timeout!\r\n");			//打印log
}

//连接关闭
void tcp_server_closed(void)
{
	tcp_server_sta &= ~(1 << 7);				//标志没有连接
	uip_log("tcp_server closed!\r\n");			//打印log
}

//连接建立
void tcp_server_connected(void)
{								  
	struct tcp_demo_appstate *s = (struct tcp_demo_appstate *)&uip_conn->appstate;
	//uip_conn结构体有一个"appstate"字段指向应用程序自定义的结构体。
	//声明一个s指针，是为了便于使用。
 	//不需要再单独为每个uip_conn分配内存，这个已经在uip中分配好了。
	//在uip.c 中 的相关代码如下：
	//		struct uip_conn *uip_conn;
	//		struct uip_conn uip_conns[UIP_CONNS]; //UIP_CONNS缺省=10
	//定义了1个连接的数组，支持同时创建几个连接。
	//uip_conn是一个全局的指针，指向当前的tcp或udp连接。
	tcp_server_sta |= 1 << 7;					//标志连接成功
  	uip_log("tcp_server connected!\r\n");		//打印log
	s->state = STATE_CMD; 						//指令状态
	s->textlen = 0;
	s->textptr = "Connect to STM32 Board Successfully!\r\n";
	s->textlen = strlen((char *)s->textptr);
}

//发送的数据成功送达
void tcp_server_acked(void)
{						    	 
	struct tcp_demo_appstate *s = (struct tcp_demo_appstate *)&uip_conn->appstate;
	s->textlen = 0;								//发送清零
	uip_log("tcp_server acked!\r\n");			//表示成功发送		 
}

//发送数据给客户端
void tcp_server_senddata(void)
{
	struct tcp_demo_appstate *s = (struct tcp_demo_appstate *)&uip_conn->appstate;
	//s->textptr : 发送的数据包缓冲区指针
	//s->textlen ：数据包的大小（单位字节）		   
	if(s->textlen > 0)
		uip_send(s->textptr, s->textlen);//发送TCP数据包	 
}
