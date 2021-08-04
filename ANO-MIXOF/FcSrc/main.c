/******************** (C) COPYRIGHT 2017 ANO Tech ********************************
 * 作者    ：匿名科创
 * 官网    ：www.anotc.com
 * 淘宝    ：anotc.taobao.com
 * 技术Q群 ：190169595
 * 描述    ：主循环
**********************************************************************************/
#include "SysConfig.h"
#include "Ano_Scheduler.h"
#include "WaypointControl.h"

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
	while (1)
	{
		//当系统出错后，会进入这个死循环
	}
}
#endif
//=======================================================================================
//=======================================================================================
int main(void)
{
	//进行所有设备的初始化，并将初始化结果保存
	All_Init();
	//调度器初始化，系统为裸奔，这里人工做了一个时分调度器
	Scheduler_Setup();
	//calibrate base yaw
	MyDelayMs(5000);
	t265_yaw_base = anof_yaw;
	set_x_position = t265_x_position;
	set_y_position = t265_y_position;
	set_z_position = t265_z_position;
	while (1)
	{
		//运行任务调度器，所有系统功能，除了中断服务函数，都在任务调度器内完成
		Scheduler_Run();
	}
}
/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/
