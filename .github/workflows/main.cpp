#ifdef WIN32
#include<bits/stdc++.h> 
#include <shlobj.h>
#include<windows.h>
#endif
using namespace std;
HWND hwnd=GetForegroundWindow();
//BOOL CBaseWebPage::PreTranslateMessage(MSG* pMsg)
//{
////�����web���ڵ���Ϣ������Ҫ����
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
//{ //���firekey�ᵼ���������뷨����
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
//    // ��ʼ��miniblink
//    wkeInitialize();
//    // ����miniblink����
//    m_wkeView =  wkeCreateWebWindow(WKE_WINDOW_TYPE_CONTROL, NULL, 0, 0, 
//    // ������ַ
//    wkeLoadFile(m_wkeView, "http://www.baidu.com");
//    // ��ʾ
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
	bi.pidlRoot = CSIDL_DESKTOP;//�ļ��еĸ�Ŀ¼���˴�Ϊ����
	bi.pszDisplayName = NULL;
	bi.lpszTitle = NULL;//��ʾλ�ڶԻ������ϲ�����ʾ��Ϣ
	bi.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;//���½��ļ��а�ť
	bi.lpfn = NULL;
	bi.iImage = 0;
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);//����ѡ��Ի���
	if (pidl == NULL)
	{
		std::cout << "û��ѡ��Ŀ¼" << std::endl;
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
////////  //�ѵ�һ���ļ���ǰ�ĸ��Ƶ�szPath,��:
////////  //���ֻѡ��һ���ļ�,�͸��Ƶ����һ��'/'
////////  //���ѡ�˶���ļ�,�͸��Ƶ���һ��NULL�ַ�
////////  lstrcpyn(szPath, szOpenFileNames, ofn.nFileOffset );
////////  //��ֻѡ��һ���ļ�ʱ,�������NULL�ַ��Ǳ����.
////////  //���ﲻ����Դ�ѡ��һ���Ͷ���ļ������
////////  szPath[ ofn.nFileOffset ]=="/0";
////////  nLen = lstrlen(szPath);
////////  
////////  if( szPath[nLen-1]!="//")   //���ѡ�˶���ļ�,��������'//'
////////  {
////////   lstrcat(szPath, TEXT("//"));
////////  }
////////  
////////  p = szOpenFileNames + ofn.nFileOffset; //��ָ���Ƶ���һ���ļ�
////////  
////////  ZeroMemory(szFileName, sizeof(szFileName));
////////  while( *p )
////////  {   
////////   lstrcat(szFileName, szPath);  //���ļ�������·��  
////////   lstrcat(szFileName, p);    //�����ļ���  
////////   lstrcat(szFileName, TEXT("/n")); //����   
////////   p += lstrlen(p) +1;     //������һ���ļ�
////////  }
////////  MessageBox(NULL, szFileName, TEXT("MultiSelect"), MB_OK);
//////// }
////////} 
//////#include <fstream> // ifstream, ifstream::in
//////using namespace std;
//////
//////int main(){
//////	// 1. ��ͼƬ�ļ�
//////	ifstream is("test.jpg", ifstream::in);
//////	// 2. ����ͼƬ����
//////	is.seekg(0, is.end);
//////	int length = is.tellg();
//////	is.seekg(0, is.beg);
//////	// 3. �����ڴ滺����
//////	char * buffer = new char[length];
//////	// 4. ��ȡͼƬ
//////	is.read(buffer, length);
//////	// ���ˣ�ͼƬ�Ѿ��ɹ��ı���ȡ���ڴ棨buffer����
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
////    //��������ͼ���ļ��������ͼ���ļ���
////    char InImgName[10];
////    char OutImgName[10];
////    //ͼ�����ݳ���
////    int length;
////    //�ļ�ָ��
////    FILE* fp;
////    //����Ҫ��ȡ��ͼ����
////    cout << "Enter Image name:";
////    cin >> InImgName;
////    //�Զ����Ʒ�ʽ��ͼ��
////    if ((fp = fopen(InImgName, "rb")) == NULL)
////    {
////        cout << "Open image failed!" << endl;
////        exit(0);
////    }
////    //��ȡͼ�������ܳ���
////    fseek(fp, 0, SEEK_END);
////    length = ftell(fp);
////    rewind(fp);
////    //����ͼ�����ݳ��ȷ����ڴ�buffer
////    char* ImgBuffer = (char*)malloc(length* sizeof(char));
////    //��ͼ�����ݶ���buffer
////    fread(ImgBuffer, length, 1, fp);
////    fclose(fp);
////    //����Ҫ������ļ���
////    cout << "Enter the name you wanna to save:";
////    cin >> OutImgName;
////    //�Զ�����д�뷽ʽ
////    if ((fp = fopen(OutImgName, "wb")) == NULL)
////    {
////        cout << "Open File failed!" << endl;
////        exit(0);
////    }
////    //��buffer��д���ݵ�fpָ����ļ���
////    fwrite(ImgBuffer, length, 1, fp);
////    cout << "Done!" << endl;
////    //�ر��ļ�ָ�룬�ͷ�buffer�ڴ�
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
    /* ������Ϣ */
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

    GetCurrentConsoleFont(handle, FALSE, &cfi);             /* ��ȡ��ǰ����������Ϣ */
    font_size = GetConsoleFontSize(handle, cfi.index);      /* ��ȡ��ǰ��������Ϣ[�ַ���ȼ��߶���ռ������] */

    return font_size;
}
void full_screen(){
    HWND hwnd = GetForegroundWindow();
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);   /* ��׼������������ */
    xs_xlong= GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� */
    xs_ylong= GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� */
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
	cout<<"\n\n\n\n\n\n                                      ����ing";
	full_screen();
	int input;
	while(unshutdown)
	{
		first_hello(1);
		print();
	}
	
	
	
	
	return 0;
}
