#ifdef WIN32
#include<bits/stdc++.h> 
#include <shlobj.h>
#include<windows.h>
#endif
using namespace std;
HWND hwnd=GetForegroundWindow();
//BOOL CBaseWebPage::PreTranslateMessage(MSG* pMsg)
//{
////如果是web窗口的消息，不需要处理
//if (pMsg->hwnd == webHwnd)
//{ 
//if (pMsg->message == WM_KEYDOWN ||
//pMsg->message == WM_KEYUP ||
//pMsg->message == WM_CHAR)
//{
//unsigned int flags = 0;
//if (HIWORD(pMsg->lParam) & KF_REPEAT)
//flags |= WKE_REPEAT;
//if (HIWORD(pMsg->lParam) & KF_EXTENDED)
//flags |= WKE_EXTENDED;
//if (pMsg->message == WM_KEYDOWN)
//{
//wkeFireKeyDownEvent(window, pMsg->wParam, flags, false);
//}
//else if (pMsg->message == WM_KEYUP)
//{
//wkeFireKeyUpEvent(window, pMsg->wParam, flags, false);
//}
//else if (pMsg->message == WM_CHAR)
//{ //如果firekey会导致中文输入法乱码
////wkeFireKeyPressEvent(window, pMsg->wParam, flags, false);
//return FALSE;
//}
//}
//}
//return CBCGPDockingControlBar::PreTranslateMessage(pMsg);
//}
int miniblink()
{
//	wkeCreateWebWindow(WKE_WINDOW_TYPE_TRANSPARENT,NULL,0,0,640,480);  
//	wkeLoadURLW(,L"miniblink.net");
//wkeSetWkeDllPath(reinterpret_cast<const wchar_t *>(dllpath.utf16()));
//    // 初始化miniblink
//    wkeInitialize();
//    // 创建miniblink窗口
//    m_wkeView =  wkeCreateWebWindow(WKE_WINDOW_TYPE_CONTROL, NULL, 0, 0, 
//    // 设置网址
//    wkeLoadFile(m_wkeView, "http://www.baidu.com");
//    // 显示
//    wkeShowWindow(m_wkeView, TRUE);
//wkeSetWkeDllPath(L"D:\\miniblink49\\trunk\\out\\Release_vc6\\node.dll");
//wkeInitialize();
//wkeWebView window = wkeCreateWebWindow(WKE_WINDOW_TYPE_POPUP, NULL, 0, 0, 1080, 680);
//wkeLoadURL(window, "qq.com");
//wkeShowWindow(window, TRUE);
}
void wj_Custom()
{
	BROWSEINFO  bi;
	bi.hwndOwner = NULL;
	bi.pidlRoot = CSIDL_DESKTOP;//文件夹的根目录，此处为桌面
	bi.pszDisplayName = NULL;
	bi.lpszTitle = NULL;//显示位于对话框左上部的提示信息
	bi.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;//有新建文件夹按钮
	bi.lpfn = NULL;
	bi.iImage = 0;
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);//调用选择对话框
	if (pidl == NULL)
	{
		std::cout << "没有选择目录" << std::endl;
		return;
	}
	TCHAR strFolder[MAX_PATH];
	SHGetPathFromIDList(pidl, strFolder);
	std::string sFolder;
}
//////////int main()
//////////{
//////////	Custom();
//////////}
////////#include <windows.h>
////////int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
////////{
//////// OPENFILENAME ofn;
//////// TCHAR szOpenFileNames[80*MAX_PATH];
//////// TCHAR szPath[MAX_PATH];
//////// TCHAR szFileName[80*MAX_PATH];
//////// TCHAR* p;
//////// int nLen = 0;
//////// ZeroMemory( &ofn, sizeof(ofn) );
//////// ofn.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT;
//////// ofn.lStructSize = sizeof(ofn);
//////// ofn.lpstrFile = szOpenFileNames;
//////// ofn.nMaxFile = sizeof(szOpenFileNames);
//////// ofn.lpstrFile[0]=="/0";
//////// ofn.lpstrFilter = TEXT("All Files(*.*)/0*.*/0");
//////// if( GetOpenFileName( &ofn ) )
//////// {  
////////  //把第一个文件名前的复制到szPath,即:
////////  //如果只选了一个文件,就复制到最后一个'/'
////////  //如果选了多个文件,就复制到第一个NULL字符
////////  lstrcpyn(szPath, szOpenFileNames, ofn.nFileOffset );
////////  //当只选了一个文件时,下面这个NULL字符是必需的.
////////  //这里不区别对待选了一个和多个文件的情况
////////  szPath[ ofn.nFileOffset ]=="/0";
////////  nLen = lstrlen(szPath);
////////  
////////  if( szPath[nLen-1]!="//")   //如果选了多个文件,则必须加上'//'
////////  {
////////   lstrcat(szPath, TEXT("//"));
////////  }
////////  
////////  p = szOpenFileNames + ofn.nFileOffset; //把指针移到第一个文件
////////  
////////  ZeroMemory(szFileName, sizeof(szFileName));
////////  while( *p )
////////  {   
////////   lstrcat(szFileName, szPath);  //给文件名加上路径  
////////   lstrcat(szFileName, p);    //加上文件名  
////////   lstrcat(szFileName, TEXT("/n")); //换行   
////////   p += lstrlen(p) +1;     //移至下一个文件
////////  }
////////  MessageBox(NULL, szFileName, TEXT("MultiSelect"), MB_OK);
//////// }
////////} 
//////#include <fstream> // ifstream, ifstream::in
//////using namespace std;
//////
//////int main(){
//////	// 1. 打开图片文件
//////	ifstream is("test.jpg", ifstream::in);
//////	// 2. 计算图片长度
//////	is.seekg(0, is.end);
//////	int length = is.tellg();
//////	is.seekg(0, is.beg);
//////	// 3. 创建内存缓存区
//////	char * buffer = new char[length];
//////	// 4. 读取图片
//////	is.read(buffer, length);
//////	// 到此，图片已经成功的被读取到内存（buffer）中
//////	delete [] buffer;
//////	return 0;
//////}
////#include<windows.h>
////#include<bits/stdc++.h>
////
////using namespace std;
////
////int main()
////{
////    //保存输入图像文件名和输出图像文件名
////    char InImgName[10];
////    char OutImgName[10];
////    //图像数据长度
////    int length;
////    //文件指针
////    FILE* fp;
////    //输入要读取的图像名
////    cout << "Enter Image name:";
////    cin >> InImgName;
////    //以二进制方式打开图像
////    if ((fp = fopen(InImgName, "rb")) == NULL)
////    {
////        cout << "Open image failed!" << endl;
////        exit(0);
////    }
////    //获取图像数据总长度
////    fseek(fp, 0, SEEK_END);
////    length = ftell(fp);
////    rewind(fp);
////    //根据图像数据长度分配内存buffer
////    char* ImgBuffer = (char*)malloc(length* sizeof(char));
////    //将图像数据读入buffer
////    fread(ImgBuffer, length, 1, fp);
////    fclose(fp);
////    //输入要保存的文件名
////    cout << "Enter the name you wanna to save:";
////    cin >> OutImgName;
////    //以二进制写入方式
////    if ((fp = fopen(OutImgName, "wb")) == NULL)
////    {
////        cout << "Open File failed!" << endl;
////        exit(0);
////    }
////    //从buffer中写数据到fp指向的文件中
////    fwrite(ImgBuffer, length, 1, fp);
////    cout << "Done!" << endl;
////    //关闭文件指针，释放buffer内存
////    fclose(fp);
////    free(ImgBuffer);
////}
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<cmath>
//#include<cctype>
//using namespace std;
//const int mod = 1000000000;
//const int N = 1000000;
//long long f[N + 2];
//int main()
//{
//    int n;
//    f[1] = 1; f[2] = 2;
//    for (int i = 3; i <= N; i++)
//    {
//        if (i % 2 != 0)f[i] = f[i - 1];
//        else f[i] = (f[i / 2]%mod + f[i - 2]%mod)%mod;
//    }
//    while (cin>>n)
//    {
//        printf("%lld\n", f[n] % mod);
//    }
//}
bool unshutdown=1;
char xs_outer[1000][1000]={'0'};
int xs_xlong=100,xs_ylong=100,num_jc;
string xs_jc[1000]="   ";
int first_hello(int re)
{
	num_jc++;
	xs_jc[num_jc]="[hello]";
	xs_outer[20][5]='H',xs_outer[20][6]='e',xs_outer[20][7]='l',xs_outer[20][8]='l',xs_outer[20][9]='o',xs_outer[20][10]='!',xs_outer[20][11]=':',xs_outer[20][12]=')';
	
	
	if(re==1) return 0;
}
COORD get_font_size()
{
    COORD font_size;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    /* 字体信息 */
    struct CONSOLE_FONT
    {
        DWORD index;
        COORD dim;
    } cfi;
    typedef COORD (WINAPI *PROCGETCONSOLEFONTSIZE)(HANDLE, DWORD);
    typedef BOOL (WINAPI *PROCGETCURRENTCONSOLEFONT)(HANDLE, BOOL, struct CONSOLE_FONT*);

    HMODULE hKernel32 = GetModuleHandle("kernel32");
    PROCGETCONSOLEFONTSIZE GetConsoleFontSize = (PROCGETCONSOLEFONTSIZE)GetProcAddress(hKernel32,"GetConsoleFontSize");
    PROCGETCURRENTCONSOLEFONT GetCurrentConsoleFont = (PROCGETCURRENTCONSOLEFONT)GetProcAddress(hKernel32,"GetCurrentConsoleFont");

    GetCurrentConsoleFont(handle, FALSE, &cfi);             /* 获取当前字体索引信息 */
    font_size = GetConsoleFontSize(handle, cfi.index);      /* 获取当前字体宽高信息[字符宽度及高度所占像素数] */

    return font_size;
}
void full_screen(){
    HWND hwnd = GetForegroundWindow();
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);   /* 标准输出缓冲区句柄 */
    xs_xlong= GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 */
    xs_ylong= GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 */
    COORD size = get_font_size();
    char cmd[32] = { 0 };
    sprintf(cmd, "MODE CON: COLS=%d LINES=%d", xs_xlong/ size.X,xs_ylong/ size.Y);
    system(cmd);
    SetWindowPos(hwnd, HWND_TOP, 0, 0,xs_xlong,xs_ylong, 0);
	ShowWindow(hwnd,SW_MINIMIZE);
}
void color(int a){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);}
int windows_cmd(int sum)
{
	COORD size = get_font_size();
	for(int i=6;i<xs_xlong/size.X;i++)
	{
		xs_outer[1][i]=' ';
	}
}
int print(){
	windows_cmd(1);
	system("cls");
	COORD size = get_font_size();
	for(int i=9;i<xs_ylong/size.Y+2;i++)
	{
		for(int j=2;j<xs_xlong/size.X-1;j++)
		{
			cout<<xs_outer[i-7][j-1];//<<' '<<i<<' '<<j<<' '<<xs_ylong/size.Y<<' '<<xs_xlong/size.X<<endl;
		}
		cout<<'\n';
	}
	color(3);
	cout<<"(@)";
	for(int i=2;i<xs_xlong/size.X-1;i+=3)
	{
		cout<<" ";
		cout<<xs_jc[i];
	}
	
	color(7);
	COORD pos;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int xs_go(int x,int y)
{
    COORD coord;
    coord.X=y;
    coord.Y=x;
    HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,coord);
}
int main(){
	cout<<"\n\n\n\n\n\n                                      启动ing";
	full_screen();
	int input;
	while(unshutdown)
	{
		first_hello(1);
		print();
	}
	
	
	
	
	return 0;
}
