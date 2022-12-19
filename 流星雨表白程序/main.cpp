#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<easyx.h>	//简单的图形图，会C语言就可以用的飞起
#include<mmsystem.h>	//多媒体头文件
#pragma comment(lib,"winmm.lib")

#define NUM 100	//流星雨数量

//背景图
IMAGE img_bk[2];
//流星图片
IMAGE img_meteor[2];

//结构体封装属性
struct Meteor	//流星
{
	int x;
	int y;
	int speed;	//速度
};
struct Meteor meteor[NUM];

void welcome()
{
	//播放背景音乐 mci media device interface 
	mciSendString(_T("open ./images/浪漫空气.mp3 alias bgm"), NULL, 0, NULL);
	//mciSendString(_T("play bgm"), NULL, 0, NULL);

	//设置文字样式
	settextstyle(40, 0, _T("华文行楷"));
	//设置背景模式为透明
	setbkmode(TRANSPARENT);

	//按任意键退出循环
	while (!_kbhit())
	{
		//清除屏幕
		cleardevice();
		//贴背景图
		putimage(0, 0, img_bk);
		//设置文字颜色
		settextcolor(RGB(rand()%256, rand() % 256, rand() % 256));

		//输出文字
		outtextxy(450, 20, _T("鞠婧祎,我喜欢你"));
		outtextxy(200, 100, _T("爱意随风起，风止意难平。"));
		outtextxy(200, 150, _T("我还是很喜欢你，像风吹过几万里"));
		outtextxy(200, 200, _T("春风十里不如你，我喜欢你"));
		outtextxy(200, 250, _T("曾经有份真挚的感情摆在我面前，我却没有珍惜"));
		outtextxy(200, 300, _T("春风十里，不及你嫣然一笑。"));
		outtextxy(200, 350, _T("天青等烟雨，而我在等你"));
		outtextxy(200, 400, _T("因为我爱你，所以纵容你"));
		outtextxy(200, 450, _T("情书是抄的，爱你是真的。"));
		outtextxy(200, 500, _T("----------------------------爱你的顿开学员"));
		//随机坐标 x（0 1200） y(0,800)
		for (size_t i = 0; i < 10; i++)
		{
			settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
			outtextxy(rand()%1200, rand() % 800, _T("♥"));
			outtextxy(rand() % 1200, rand() % 800, _T("🌺"));
		}
		Sleep(1000);
	}
}

//初始化流星
void initMeteor(int i)
{
	meteor[i].x = rand() % (1200*2) - 1200;	//（0-1200，1200）
	meteor[i].y = rand() %20 - 200;		//(-78,-200)
	meteor[i].speed = rand() % 15 + 1;
}
//绘制流星
void drawMeteor()
{
	for (int i = 0; i < NUM; i++)
	{
		putimage(meteor[i].x, meteor[i].y, img_meteor + rand() % 2,SRCPAINT);
	}
}
//移动流星
void moveMeteor()
{
	//改变坐标就可以实现移动了，斜向x,y都要变化
	for (int i = 0; i < NUM; i++)
	{
		meteor[i].x += meteor[i].speed;
		meteor[i].y += meteor[i].speed;
		if (meteor[i].y > getheight() || meteor[i].x>getwidth())
		{
			initMeteor(i);
		}
	}
}

int main()
{
	//创建图形窗口
	initgraph(1200, 800,1000);
	//加载图片
	loadimage(img_bk, _T("./images/welcome.png"),1200,800);
	loadimage(img_bk + 1, _T("./images/bk.png"),1200,800);
	loadimage(img_meteor, _T("./images/1.jpg"), 50, 50);
	loadimage(img_meteor+1, _T("./images/2.jpg"), 50, 50);

	welcome();

	for (size_t i = 0; i < NUM; i++)
	{
		initMeteor(i);
	}

	//防止闪屏，双缓冲
	BeginBatchDraw();	//开启双缓冲绘图
	while (true)
	{
		//控制画面的帧率 26帧 60
		int begin = clock();	//获取程序运行时间（毫秒数）

		putimage(0, 0, img_bk + 1);
		drawMeteor();
		moveMeteor();
		//Sleep(50);	//让程序休眠
		FlushBatchDraw();//刷新

		//获取程序总共的执行时间
		int timeRemaining = clock() - begin;
		//计算每帧需要的时间
		int timeFrame = 1000.0 / 60;
		//获取程序执行时间有没有超过，每帧执行的最大时间
		int delay = timeFrame - timeRemaining;
		if (delay > 0)
		{
			printf("%d\n", delay);	
			Sleep(delay);		//动态变化
		}
		//知识的运用。。。
		//1,什么都不会做。。。			
		//2,不仅自己会做，还帮别人做 
		/*
			学习方法：把自己的知识交给别人

			直播+录播，指导... 20：00 - 22：00
			10个月，VIP
			学费：7280 - 1024 = 6256

			为什么学习：兴趣  工作




		*/
	}
	EndBatchDraw();

	getchar();
	return 0;
}
