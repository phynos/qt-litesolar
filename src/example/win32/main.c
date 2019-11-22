#include <windows.h>

//全局变量声明
HINSTANCE hInst;
HBITMAP dra,bg;
HDC     hdc,mdc,bufdc;
HWND    hWnd;
DWORD   tPre,tNow;
int     num,x,y;

//全局函数声明
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
void                MyPaint(HDC hdc);

//***WinMain函数，程序入口点函数**************************************   
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
    MSG msg;

    MyRegisterClass(hInstance);

    //初始化
    if (!InitInstance (hInstance, nCmdShow)) 
    {
        return FALSE;
    }

    //消息循环
    GetMessage(&msg,NULL,0,0);  //初始化msg
    while( msg.message!=WM_QUIT )
    {
        if( PeekMessage( &msg, NULL, 0,0 ,PM_REMOVE) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            tNow = GetTickCount();
            if(tNow-tPre >= 100)
                MyPaint(hdc);
            Sleep(1);//防止CPU100%
        }
    }

    return msg.wParam;
}

//****设计一个窗口类，类似填空题，使用窗口结构体*************************   
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX); 
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = (WNDPROC)WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = NULL;
    wcex.hCursor        = NULL;
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = "canvas";
    wcex.hIconSm        = NULL;

    return RegisterClassEx(&wcex);
}

//****初始化函数*************************************
// 加载位图并设定各对象的初始值
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    char filename[20] = "";
    HBITMAP bmp;
    hInst = hInstance;

    hWnd = CreateWindow("canvas", "动画演示" , WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

    if (!hWnd)
    {
        return FALSE;
    }

    MoveWindow(hWnd,10,10,640,480,TRUE);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    hdc = GetDC(hWnd);
    mdc = CreateCompatibleDC(hdc);
    bufdc = CreateCompatibleDC(hdc);
    bmp = CreateCompatibleBitmap(hdc,640,480);

    SelectObject(mdc,bmp);

    dra = (HBITMAP)LoadImage(NULL,"res/dra.bmp",IMAGE_BITMAP,760,198,LR_LOADFROMFILE);
    bg = (HBITMAP)LoadImage(NULL,"res/bg.bmp",IMAGE_BITMAP,640,480,LR_LOADFROMFILE);

    num = 0;    //显示图号
    x = 640;    //贴图起始X坐标
    y = 360;    //贴图起始Y坐标

    MyPaint(hdc);

    return TRUE;
}

//****自定义绘图函数*********************************
// 1.恐龙跑动图案的透明背景化
// 2.更新贴图坐标，实现动画效果
void MyPaint(HDC hdc)
{
    if(num == 8)
        num = 0;

    //在mdc中贴上背景图
    SelectObject(bufdc,bg);
    BitBlt(mdc,0,0,640,480,bufdc,0,0,SRCCOPY);

    //在mdc中进行透明处理
    SelectObject(bufdc,dra);
    BitBlt(mdc,x,y,95,99,bufdc,num*95,99,SRCAND);
    BitBlt(mdc,x,y,95,99,bufdc,num*95,0,SRCPAINT);

    //将最后的画面显示在窗口中
    BitBlt(hdc,0,0,640,480,mdc,0,0,SRCCOPY);

    tPre = GetTickCount();     //记录此次绘图时间
    num++;

    x-=20;                     //计算下次贴图的坐标
    if(x<=-95)
        x = 640;
}

//****消息处理函数***********************************
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:                    //窗口结束消息，撤销各种DC
            DeleteDC(mdc);
            DeleteDC(bufdc);
            DeleteObject(dra);
            DeleteObject(bg);
            ReleaseDC(hWnd,hdc);
            PostQuitMessage(0);
            break;
        default:                            //其他消息
            return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}