
//http://cpp0x.pl/forum/temat/?id=2909

//author marcin matysek rewertynPL
/source code beta version

  //  WIN32 aplikacion  !!!!!!!!!!!!!!!!!!!


#include <windows.h>
#include<wingdi.h>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iostream>

#include <Shellapi.h>
#include <fstream>
#include <time.h>
#include <sys/timeb.h> // pomiar czasu
#include <tchar.h>

#pragma comment(lib, "libgdi32.a")

using namespace std;
LPSTR NazwaKlasy = "Klasa Okienka";
MSG Komunikat;

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );



//http://januszg.hg.pl/teksty/budowa_pliku_bmp.html
//http://msdn.microsoft.com/en-us/library/aa383751%28VS.85%29.aspx
//http://guidecpp.cal.pl/docs,stdlibs,stdio,fread
//http://support.microsoft.com/kb/158898
//http://msdn.microsoft.com/en-us/library/dd183402%28v=VS.85%29.aspx
#define BITMAP_width11	0
#define BITMAP_height11	0
int szerokosc_1;
int wysokosc_1;
int szerokosc_2;
int wysokosc_2;
int szerokosc_3;
int wysokosc_3;
    // TWORZENIE OKNA
    HWND hwnd;
#pragma pack(push, 1)			// zeby nie dodawal sobie niepotrzebnych bitow (rozmiar nie podzielny przez 4) //
///////////////////




HWND g_hPrzycisk;

void fun_1( HWND hwnd);

//http://januszg.hg.pl/teksty/budowa_pliku_bmp.html
//http://msdn.microsoft.com/en-us/library/aa383751%28VS.85%29.aspx
//http://guidecpp.cal.pl/docs,stdlibs,stdio,fread
//http://support.microsoft.com/kb/158898
//http://msdn.microsoft.com/en-us/library/dd183402%28v=VS.85%29.aspx

class cPixel11klasa
{
public:
	char red11;
	char green11;
	char blue11;
	//~cPixel11klasa();
};

class cdata1111klasa
{
public:
 cPixel11klasa **pixel;
 int szerokosc_0, wysokosc_0;
 cdata1111klasa(){};
 cdata1111klasa(int wysokosc_0,int szerokosc_0);
 ~cdata1111klasa();
 int getx() {return szerokosc_0;}
 int gety() {return wysokosc_0;}
};

cdata1111klasa::cdata1111klasa(int wysokosc_0,int szerokosc_0)
 {
  this->szerokosc_0 = szerokosc_0;
  this->wysokosc_0 = wysokosc_0;
  pixel = new cPixel11klasa*[wysokosc_0];
  for ( int i = 0; i < wysokosc_0; ++i )
  {
   pixel[i] = new cPixel11klasa[szerokosc_0];
  }
 }

cdata1111klasa::~cdata1111klasa()
 {

	 for(int i = 0; i < wysokosc_0; i++)
	 {
	    //delete pixel[i];
	    delete[] pixel[i];
     }
	 delete[] pixel;
 };


class cBMP11klasa
{
public:
	void loadBMP11(int,int,unsigned char ***tablica_bitmapy1,std::string);
} bmp11;
///////////////////////////////////////////////////////////////////////////////
    int table_size1=2;
    int table_size2=5;
    int table_size3=3;
    int table_size4=2;
    int table_size5=9;

    cdata1111klasa *data11 =  new cdata1111klasa[table_size1];;
	cdata1111klasa *data12 =  new cdata1111klasa[table_size2];;
	cdata1111klasa *actual_bitmap11 =  new cdata1111klasa[table_size3];;
	cdata1111klasa *actual_bitmap12 =  new cdata1111klasa[table_size4];;
	cdata1111klasa *actual_bitmap13 =  new cdata1111klasa[table_size5];;
////////////////////////////////////////////////////////////////////////////////
#pragma pack(pop)

int *table11;
POINT po1;
int width11;
int height11;
FILE *control_file11;
///////////////////////
void cBMP11klasa::loadBMP11(int wys,int szer,unsigned char ***tablica_bitmapy1,std::string path)
{
	FILE *bmpfile;

	if ( (bmpfile = fopen (path.c_str(), "rb")) == NULL )
	{
	    MessageBox( hwnd, "nieprawid³owa sciezka:", "Ha3!", MB_ICONINFORMATION );
		//std::cout << "nieprawid³owa sciezka: "<<path.c_str()<< std::endl;
		return;
	}
				   // _TCHAR szBuffer[ 20 ];
                  //  _stprintf( szBuffer, _T( "Bitmapy sa sobie rowne counter %i" ), counter );
                  //  MessageBox( NULL, szBuffer, _T( "Liczba w oknie" ), MB_OK );
	//MessageBox( hwnd, "odnaleziono plik:", "Ha3!", MB_ICONINFORMATION );
	//std::cout << "odnaleziono plik: "<<path.c_str() << std::endl;

	// ladowanie danych //
	//fseek (bmpfile, 54, SEEK_SET);
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, bmpfile); // read the 54-byte header
    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

	for ( int y = 0; y < wys; ++y )
	{
		for ( int x = 0; x < szer; ++x )
		{
			//cout<<"wysokosc= "<<y<<" szerokosc= "<<x<<endl;
			tablica_bitmapy1[x][y][0]= fgetc(bmpfile);
			tablica_bitmapy1[x][y][1]= fgetc(bmpfile);
			tablica_bitmapy1[x][y][2] = fgetc(bmpfile);
			//fgetc(bmpfile);	   // pobieranie wartosci 0
		}
	}
	fclose (bmpfile);
}

void load_templates11(int wys,int szer,unsigned char ***tablica_bitmapy1)
{

	bmp11.loadBMP11(wys,szer,&tablica_bitmapy1[0],"nr1.bmp");

/*
	bmp11.loadBMP11(wys,szer,&data12[1],"d://18/szablony/1.bmp");
	bmp11.loadBMP11(wys,szer,&data12[2],"d://18/szablony/2.bmp");
	bmp11.loadBMP11(wys,szer,&data12[3],"d://18/szablony/3.bmp");
	bmp11.loadBMP11(wys,szer,&data12[4],"d://18/szablony/4.bmp");
*/
}
void load_templates12(int wys,int szer,unsigned char ***tablica_bitmapy1)
{

	bmp11.loadBMP11(wys,szer,&tablica_bitmapy1[0],"nr1.bmp");;
/*
	bmp11.loadBMP11(wys,szer,&data11[2], "d://18/szablony/102.bmp");
	bmp11.loadBMP11(wys,szer,&data11[3], "d://18/szablony/103.bmp");
	bmp11.loadBMP11(wys,szer,&data11[4], "d://18/szablony/104.bmp");
	bmp11.loadBMP11(wys,szer,&data11[5], "d://18/szablony/105.bmp");
	bmp11.loadBMP11(wys,szer,&data11[6], "d://18/szablony/106.bmp");
	bmp11.loadBMP11(wys,szer,&data11[7], "d://18/szablony/107.bmp");
	bmp11.loadBMP11(wys,szer,&data11[8], "d://18/szablony/108.bmp");
	bmp11.loadBMP11(wys,szer,&data11[9], "d://18/szablony/109.bmp");
	bmp11.loadBMP11(wys,szer,&data11[10], "d://18/szablony/110.bmp");
	bmp11.loadBMP11(wys,szer,&data11[11], "d://18/szablony/111.bmp");
	bmp11.loadBMP11(wys,szer,&data11[12], "d://18/szablony/112.bmp");
	bmp11.loadBMP11(wys,szer,&data11[13], "d://18/szablony/113.bmp");
	bmp11.loadBMP11(wys,szer,&data11[14], "d://18/szablony/114.bmp");
	bmp11.loadBMP11(wys,szer,&data11[15], "d://18/szablony/202.bmp");
	bmp11.loadBMP11(wys,szer,&data11[16], "d://18/szablony/203.bmp");
	bmp11.loadBMP11(wys,szer,&data11[17], "d://18/szablony/204.bmp");
	bmp11.loadBMP11(wys,szer,&data11[18], "d://18/szablony/205.bmp");
	bmp11.loadBMP11(wys,szer,&data11[19], "d://18/szablony/206.bmp");
	bmp11.loadBMP11(wys,szer,&data11[20], "d://18/szablony/207.bmp");
	bmp11.loadBMP11(wys,szer,&data11[21], "d://18/szablony/208.bmp");
	bmp11.loadBMP11(wys,szer,&data11[22], "d://18/szablony/209.bmp");
	bmp11.loadBMP11(wys,szer,&data11[23], "d://18/szablony/210.bmp");
	bmp11.loadBMP11(wys,szer,&data11[24], "d://18/szablony/211.bmp");
	bmp11.loadBMP11(wys,szer,&data11[25], "d://18/szablony/212.bmp");
	bmp11.loadBMP11(wys,szer,&data11[26], "d://18/szablony/213.bmp");
	bmp11.loadBMP11(wys,szer,&data11[27], "d://18/szablony/214.bmp");
	bmp11.loadBMP11(wys,szer,&data11[28], "d://18/szablony/302.bmp");
	bmp11.loadBMP11(wys,szer,&data11[29], "d://18/szablony/303.bmp");
	bmp11.loadBMP11(wys,szer,&data11[30], "d://18/szablony/304.bmp");
	bmp11.loadBMP11(wys,szer,&data11[31], "d://18/szablony/305.bmp");
	bmp11.loadBMP11(wys,szer,&data11[32], "d://18/szablony/306.bmp");
	bmp11.loadBMP11(wys,szer,&data11[33], "d://18/szablony/307.bmp");
	bmp11.loadBMP11(wys,szer,&data11[34], "d://18/szablony/308.bmp");
	bmp11.loadBMP11(wys,szer,&data11[35], "d://18/szablony/309.bmp");
	bmp11.loadBMP11(wys,szer,&data11[36], "d://18/szablony/310.bmp");
	bmp11.loadBMP11(wys,szer,&data11[37], "d://18/szablony/311.bmp");
	bmp11.loadBMP11(wys,szer,&data11[38], "d://18/szablony/312.bmp");
	bmp11.loadBMP11(wys,szer,&data11[39], "d://18/szablony/313.bmp");
	bmp11.loadBMP11(wys,szer,&data11[40], "d://18/szablony/314.bmp");
	bmp11.loadBMP11(wys,szer,&data11[41], "d://18/szablony/402.bmp");
	bmp11.loadBMP11(wys,szer,&data11[42], "d://18/szablony/403.bmp");
	bmp11.loadBMP11(wys,szer,&data11[43], "d://18/szablony/404.bmp");
	bmp11.loadBMP11(wys,szer,&data11[44], "d://18/szablony/405.bmp");
	bmp11.loadBMP11(wys,szer,&data11[45], "d://18/szablony/406.bmp");
	bmp11.loadBMP11(wys,szer,&data11[46], "d://18/szablony/407.bmp");
	bmp11.loadBMP11(wys,szer,&data11[47], "d://18/szablony/408.bmp");
	bmp11.loadBMP11(wys,szer,&data11[48], "d://18/szablony/409.bmp");
	bmp11.loadBMP11(wys,szer,&data11[49], "d://18/szablony/410.bmp");
	bmp11.loadBMP11(wys,szer,&data11[50], "d://18/szablony/411.bmp");
	bmp11.loadBMP11(wys,szer,&data11[51], "d://18/szablony/412.bmp");
	bmp11.loadBMP11(wys,szer,&data11[52], "d://18/szablony/413.bmp");
	bmp11.loadBMP11(wys,szer,&data11[53], "d://18/szablony/414.bmp");

	bmp11.loadBMP11(wys,szer,&data11[54], "d://18/szablony/1102.bmp");
	bmp11.loadBMP11(wys,szer,&data11[55], "d://18/szablony/1103.bmp");
	bmp11.loadBMP11(wys,szer,&data11[56], "d://18/szablony/1104.bmp");
	bmp11.loadBMP11(wys,szer,&data11[57], "d://18/szablony/1105.bmp");
	bmp11.loadBMP11(wys,szer,&data11[58], "d://18/szablony/1106.bmp");
	bmp11.loadBMP11(wys,szer,&data11[59], "d://18/szablony/1107.bmp");
	bmp11.loadBMP11(wys,szer,&data11[60], "d://18/szablony/1108.bmp");
	bmp11.loadBMP11(wys,szer,&data11[61], "d://18/szablony/1109.bmp");
	bmp11.loadBMP11(wys,szer,&data11[62], "d://18/szablony/1110.bmp");
	bmp11.loadBMP11(wys,szer,&data11[63], "d://18/szablony/1111.bmp");
	bmp11.loadBMP11(wys,szer,&data11[64], "d://18/szablony/1112.bmp");
	bmp11.loadBMP11(wys,szer,&data11[65], "d://18/szablony/1113.bmp");
	bmp11.loadBMP11(wys,szer,&data11[66], "d://18/szablony/1114.bmp");
	bmp11.loadBMP11(wys,szer,&data11[67], "d://18/szablony/1202.bmp");
	bmp11.loadBMP11(wys,szer,&data11[68], "d://18/szablony/1203.bmp");
	bmp11.loadBMP11(wys,szer,&data11[69], "d://18/szablony/1204.bmp");
	bmp11.loadBMP11(wys,szer,&data11[70], "d://18/szablony/1205.bmp");
	bmp11.loadBMP11(wys,szer,&data11[71], "d://18/szablony/1206.bmp");
	bmp11.loadBMP11(wys,szer,&data11[72], "d://18/szablony/1207.bmp");
	bmp11.loadBMP11(wys,szer,&data11[73], "d://18/szablony/1208.bmp");
	bmp11.loadBMP11(wys,szer,&data11[74], "d://18/szablony/1209.bmp");
	bmp11.loadBMP11(wys,szer,&data11[75], "d://18/szablony/1210.bmp");
	bmp11.loadBMP11(wys,szer,&data11[76], "d://18/szablony/1211.bmp");
	bmp11.loadBMP11(wys,szer,&data11[77], "d://18/szablony/1212.bmp");
	bmp11.loadBMP11(wys,szer,&data11[78], "d://18/szablony/1213.bmp");
	bmp11.loadBMP11(wys,szer,&data11[79], "d://18/szablony/1214.bmp");
	bmp11.loadBMP11(wys,szer,&data11[80], "d://18/szablony/1302.bmp");
	bmp11.loadBMP11(wys,szer,&data11[81], "d://18/szablony/1303.bmp");
	bmp11.loadBMP11(wys,szer,&data11[82], "d://18/szablony/1304.bmp");
	bmp11.loadBMP11(wys,szer,&data11[83], "d://18/szablony/1305.bmp");
	bmp11.loadBMP11(wys,szer,&data11[84], "d://18/szablony/1306.bmp");
	bmp11.loadBMP11(wys,szer,&data11[85], "d://18/szablony/1307.bmp");
	bmp11.loadBMP11(wys,szer,&data11[86], "d://18/szablony/1308.bmp");
	bmp11.loadBMP11(wys,szer,&data11[87], "d://18/szablony/1309.bmp");
	bmp11.loadBMP11(wys,szer,&data11[88], "d://18/szablony/1310.bmp");
	bmp11.loadBMP11(wys,szer,&data11[89], "d://18/szablony/1311.bmp");
	bmp11.loadBMP11(wys,szer,&data11[90], "d://18/szablony/1312.bmp");
	bmp11.loadBMP11(wys,szer,&data11[91], "d://18/szablony/1313.bmp");
	bmp11.loadBMP11(wys,szer,&data11[92], "d://18/szablony/1314.bmp");
	bmp11.loadBMP11(wys,szer,&data11[93], "d://18/szablony/1402.bmp");
	bmp11.loadBMP11(wys,szer,&data11[94], "d://18/szablony/1403.bmp");
	bmp11.loadBMP11(wys,szer,&data11[95], "d://18/szablony/1404.bmp");
	bmp11.loadBMP11(wys,szer,&data11[96], "d://18/szablony/1405.bmp");
	bmp11.loadBMP11(wys,szer,&data11[97], "d://18/szablony/1406.bmp");
	bmp11.loadBMP11(wys,szer,&data11[98], "d://18/szablony/1407.bmp");
	bmp11.loadBMP11(wys,szer,&data11[99], "d://18/szablony/1408.bmp");
	bmp11.loadBMP11(wys,szer,&data11[100], "d://18/szablony/1409.bmp");
	bmp11.loadBMP11(wys,szer,&data11[101], "d://18/szablony/1410.bmp");
	bmp11.loadBMP11(wys,szer,&data11[102], "d://18/szablony/1411.bmp");
	bmp11.loadBMP11(wys,szer,&data11[103], "d://18/szablony/1412.bmp");
	bmp11.loadBMP11(wys,szer,&data11[104], "d://18/szablony/1413.bmp");
	bmp11.loadBMP11(wys,szer,&data11[105], "d://18/szablony/1414.bmp");
*/
}
int create_new_bitmap111(HWND hwnd,int wys,int szer, HWND window,_TCHAR* str,int od_wsp_x,int od_wsp_y,int flaga1,int wymiar_obrazka_x,int wymiar_obrazka_y)
{
 //MessageBox(hwnd, "w create_new_bitmap111", "Ha5!", MB_ICONINFORMATION);
	HANDLE hFile;//plik
	HDC hdcScreen;
    HDC hdcWindow;
    HDC hdcMemDC = NULL;
    HBITMAP hbmScreen = NULL;
    BITMAP bmpScreen;
	/*
	lub:
	BYTE *bits1; //<-- tu zapisane s¹ piksele
	HBITMAP hbm1 = CreateDIBSection(sdc1,bi1,DIB_RGB_COLORS,(void**)&bits1,NULL,0);
	HDC hdc1 = CreateCompatibleDC(sdc1);
	HGDIOBJ hold = SelectObject(hdc1,hbm1);
	*/
	//Retrieve the handle to a display device context for the client area of the window.
    hdcScreen = GetDC(NULL);
    hdcWindow = GetDC(window);
    //Create a compatible DC which is used in a BitBlt from the window DC
    hdcMemDC = CreateCompatibleDC(hdcWindow);

    if(!hdcMemDC)
    {
        MessageBox(hwnd, "CreateCompatibleDC has failed Failed", "Ha5!", MB_ICONINFORMATION);
       //cout<<"CreateCompatibleDC has failed Failed"<<endl;
       return 0;
    }
	//////////
	//Get the client area for size calculation
    //RECT rcClient; //pobieranie x i y okna
    //GetClientRect(hWnd, &rcClient); //pobieranie x i y okna
	//////////
	//Create a compatible bitmap from the Window DC
    //hbmScreen = CreateCompatibleBitmap(hdcWindow, rcClient.right-rcClient.left, rcClient.bottom-rcClient.top);
    hbmScreen = CreateCompatibleBitmap(hdcWindow,szer,wys);

	if(!hbmScreen)
    {
        MessageBox(hwnd, "CreateCompatibleBitmap Failed Failed", "Ha5!", MB_ICONINFORMATION);
        //cout<<"CreateCompatibleBitmap Failed Failed"<<endl;
        return 0;
    }
	//Select the compatible bitmap into the compatible memory DC.
    SelectObject(hdcMemDC,hbmScreen);


	//////
	CURSORINFO cursorInfo1 = { 0 };
    cursorInfo1.cbSize = sizeof(cursorInfo1);
	GetCursorInfo(&cursorInfo1);
	ICONINFO moja_ikona = {0};
    GetIconInfo(cursorInfo1.hCursor, &moja_ikona);
	HBITMAP h_mouse_bitmap1;
	BITMAP mouse_bitmap1;
	BITMAPINFO bmi1;
	h_mouse_bitmap1 = moja_ikona.hbmColor;
	HDC hdcScreen1 = GetDC(NULL);
	//HDC hdc_mouse_cursor = CreateCompatibleDC(hdcScreen1);
	//HDC hdcWindow;
    //hdcWindow = GetDC(window);
	HDC hdc_mouse_cursor = CreateCompatibleDC(hdcWindow);
	GetObject(h_mouse_bitmap1, sizeof(BITMAP), &mouse_bitmap1);
	GetDIBits(hdc_mouse_cursor, h_mouse_bitmap1, 0, 32, NULL, &bmi1, DIB_RGB_COLORS);
    SelectObject(hdc_mouse_cursor,h_mouse_bitmap1);//przypisanie kontekstowi bitmapy
	///////
    int PunktX=moja_ikona.xHotspot;
    int PunktY=moja_ikona.yHotspot;
	POINT pozycja_myszki;
    GetCursorPos(&pozycja_myszki); //pozycja_myszki.x //pozycja_myszki.y

	///////////////////////////////////////////////////////////////////////////////
    //Bit block transfer into our compatible memory DC.							///
	if(flaga1==1)																///
    {																			///
		//nr1
		if(!BitBlt(hdcMemDC,0,0,wymiar_obrazka_x,wymiar_obrazka_y,hdcWindow,od_wsp_x,od_wsp_y,SRCCOPY))		///
		{
        MessageBox( hwnd, "BitBlt has failed Failed", "Ha5!", MB_ICONINFORMATION);																	///
        //cout<<"BitBlt has failed Failed"<<endl;									///
        return 0;																///
		}

		//nr2 //kursor
		if(!BitBlt(hdcMemDC,0,0,wymiar_obrazka_x,wymiar_obrazka_y,hdc_mouse_cursor,pozycja_myszki.x,pozycja_myszki.y,SRCCOPY))		///
		{
        MessageBox( hwnd, "BitBlt has failed Failed", "Ha5!", MB_ICONINFORMATION);																			///
        //cout<<"BitBlt has failed Failed"<<endl;									///
        return 0;																///
		}
		  ///
	}																			///
	if(flaga1==2)																///
    {																			///
		if(!BitBlt(hdcMemDC,0,0,wymiar_obrazka_x,wymiar_obrazka_y,hdcWindow,od_wsp_x,od_wsp_y,SRCCOPY))		///
		{
        MessageBox( hwnd, "BitBlt has failed Failed", "Ha5!", MB_ICONINFORMATION);																		///
        //cout<<"BitBlt has failed Failed"<<endl;									///
        return 0;																///
		}																		///
	}																			///
	///////////////////////////////////////////////////////////////////////////////
	if(flaga1==3)	//screen samego kursora myszki															///
    {																			///
		if(!BitBlt(hdcMemDC,0,0,wymiar_obrazka_x,wymiar_obrazka_y,hdc_mouse_cursor,pozycja_myszki.x,pozycja_myszki.y,SRCCOPY))		///
		{
        MessageBox( hwnd, "BitBlt has failed Failed", "Ha5!", MB_ICONINFORMATION);																		///
        //cout<<"BitBlt has failed Failed"<<endl;									///
        return 0;																///
		}																		///
	}																			///
	///////////////////////////////////////////////////////////////////////////////

    //Get the BITMAP from the HBITMAP
    GetObject(hbmScreen,sizeof(BITMAP),&bmpScreen);

	BITMAPFILEHEADER   bmfHeader;  //file
    BITMAPINFOHEADER   bi;//info

    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = bmpScreen.bmWidth;
    bi.biHeight = bmpScreen.bmHeight;
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;


	DWORD dwBmpSize = ((bmpScreen.bmWidth * bi.biBitCount + 31) / 32) * 4 * bmpScreen.bmHeight;

	HANDLE hDIB = GlobalAlloc(GHND,dwBmpSize);
    char *lpbitmap = (char *)GlobalLock(hDIB);

    //Gets the "bits" from the bitmap and copies them into a buffer
    //which is pointed to by lpbitmap.
    GetDIBits(hdcWindow, hbmScreen, 0,(UINT)bmpScreen.bmHeight,lpbitmap,(BITMAPINFO *)&bi, DIB_RGB_COLORS);

	//A file is created, this is where we will save the screen capture.
	hFile=CreateFile((LPTSTR) str,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);

	//Add the size of the headers to the size of the bitmap to get the total file size
    DWORD dwSizeofDIB = dwBmpSize + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	//Offset to where the actual bitmap bits start.
    bmfHeader.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER);
    //Size of the file
    bmfHeader.bfSize = dwSizeofDIB;
	//bfType must always be BM for Bitmaps
    bmfHeader.bfType = 0x4D42; //BM

	DWORD dwBytesWritten = 0;
	WriteFile(hFile, (LPSTR)&bmfHeader, sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
    WriteFile(hFile, (LPSTR)&bi, sizeof(BITMAPINFOHEADER), &dwBytesWritten, NULL);
    WriteFile(hFile, (LPSTR)lpbitmap, dwBmpSize, &dwBytesWritten, NULL);

	//Unlock and Free the DIB from the heap
    GlobalUnlock(hDIB);
    GlobalFree(hDIB);

    //Close the handle for the file that was created
    CloseHandle(hFile);

    //Clean up
    DeleteObject(hbmScreen);
    DeleteObject(hdcMemDC);
    ReleaseDC(NULL,hdcScreen);
//    ReleaseDC(hWnd,hdcWindow);
}
////////////////////////////////////////////////////////////////
/*
int find_bitmap11(HWND hwnd,int m,int wys,int szer)
{
	bool _break = false;
	int counter = 0;
	int actual_number = -1;
	for ( int i = 0; i < 1; ++i )
	{
		for ( int y = 0; y < wys; ++y )
		{
			for ( int x = 0; x < szer; ++x )
			{
				int a1=actual_bitmap11[m].pixel[y][x].blue11;
				int a2=data12[i].pixel[y][x].blue11;
				int b1=actual_bitmap11[m].pixel[y][x].green11;
				int b2=data12[i].pixel[y][x].green11;
				int c1=actual_bitmap11[m].pixel[y][x].red11;
				int c2=data12[i].pixel[y][x].red11;

				if(((a1<=a2-4 )||(a1>=a2+4 ))&&((b1<=b2-4 )||(b1>=b2+4 ))&&((c1<=c2-10)||(c1>=c2+10))
				 ||((a1<=a2-4 )||(a1>=a2+10 ))&&((b1<=b2-10)||(b1>=b2+10))&&((c1<=c2-4 )||(c1>=c2+4 ))
				 ||((a1<=a2-10)||(a1>=a2+10))&&((b1<=b2-4 )||(b1>=b2+4 ))&&((c1<=c2-4 )||(c1>=c2+4 )))
				{
					//cout<<"wysokosc= "<<j<<"  szerokosc=  "<<k<<endl;
					//cout<<"1.  "<<actual_bitmap11[m].pixel[y][x].blue11<<" = "<<data11[i].pixel[y][x].blue11<<"    "<<actual_bitmap11[m].pixel[y][x].green11<<" = "<<data11[i].pixel[y][x].green11<<"    "<<actual_bitmap11[m].pixel[y][x].red11<<" = "<<data11[i].pixel[y][x].red11<<endl;
					//_break = true;
					//counter = 0;
					//break;
				}
				else
				{
					++counter;
					//std::cout << counter << ".. " << std::endl;
				}

				if ( (counter >= szer*wys-4))
				{
					actual_number = i;
                    //_stprintf( szBuffer, _T( "counter %i" ), counter );
                    //MessageBox( NULL, szBuffer, _T( "Liczba w oknie" ), MB_OK );
					//MessageBox( hwnd, "Bitmapy sa sobie rowne", "Ha5!", MB_ICONINFORMATION);
			    //  std::cout << "Bitmapy sa sobie rowne_1 i= "<<i<< " ,2. counter= "<< counter<< "  .m= "<<m+1<< std::endl;
				//	system("pause");
					counter = 0;
					_break = true;
					break;
				}
				else if(y>=wys-1&&x>=szer-1&&i>=1)
				{
                    //_stprintf( szBuffer, _T( "counter %i" ), counter );
                    //MessageBox( NULL, szBuffer, _T( "Liczba w oknie" ), MB_OK );
					//MessageBox( hwnd, "Bitmapy sa nierowne", "Ha5!", MB_ICONINFORMATION);
					//std::cout << "Bitmapy sa nierowne_1 i= "<<i<< " ,2. counter= "<< counter<< "  .m= "<<m+1<< std::endl;
					//goto spr;
					//system("pause");
					_break = true;
					counter = 0;
					break;
				}
			}
			if ( _break == true )
			{
				_break = false;
				break;
			}
		}
		//if(counter>35){std::cout << "i= "<<i<< " . counter= "<< counter<< "  .m= "<<m+1<< std::endl;}
		counter = 0;
		if ( actual_number != -1 )
			break;
	}
	return actual_number;

}
*/
//////////////////////////////////////////////////////////////
int find_bitmap12(HWND hwnd,int m,int wys,int szer,unsigned char ***tablica_bitmapy1,unsigned char ***tablica_bitmapy2)
{
    MessageBox( hwnd, "w find_bitmap12", "Ha5!", MB_ICONINFORMATION);
	bool _break = false;
	int counter = 0;
	int actual_number = -1;
	for ( int i = 0; i < 1; ++i )
	{
		for ( int y = 0; y < wys; ++y )
		{
			for ( int x = 0; x < szer; ++x )
			{
				int a1=tablica_bitmapy1[x][y][0];
				int a2=tablica_bitmapy2[x][y][0];
				int b1=tablica_bitmapy1[x][y][1];
				int b2=tablica_bitmapy2[x][y][1];
				int c1=tablica_bitmapy1[x][y][2];
				int c2=tablica_bitmapy2[x][y][2];

				if(((a1<=a2-10 )||(a1>=a2+10 ))&&((b1<=b2-10 )||(b1>=b2+10 ))&&((c1<=c2-100)||(c1>=c2+100))
				 ||((a1<=a2-10 )||(a1>=a2+10 ))&&((b1<=b2-100)||(b1>=b2+100))&&((c1<=c2-10 )||(c1>=c2+10 ))
				 ||((a1<=a2-100)||(a1>=a2+100))&&((b1<=b2-10 )||(b1>=b2+10 ))&&((c1<=c2-10 )||(c1>=c2+10 )))
				{
					//if(i==15){cout<<"wysokosc= "<<y<<"  szerokosc=  "<<x<<endl;}
					//cout<<"1.  "<<actual_bitmap11[m].pixel[y][x].blue11<<" = "<<data11[i].pixel[y][x].blue11<<"    "<<actual_bitmap11[m].pixel[y][x].green11<<" = "<<data11[i].pixel[y][x].green11<<"    "<<actual_bitmap11[m].pixel[y][x].red11<<" = "<<data11[i].pixel[y][x].red11<<endl;
					//_break = true;
					//counter = 0;
					//break;
					//cout<<y<<endl;
				}
				else
				{
					++counter;
					//std::cout << counter << ".. " << std::endl;
				}
			}
			if ( _break == true )
			{
				_break = false;
				break;
			}
		}
                if ( (counter >= szer*wys-5))
				{
				    _TCHAR szBuffer[ 40 ];
                    _stprintf( szBuffer, _T( "Bitmapy sa sobie rowne counter %i" ), counter );
                    MessageBox( NULL, szBuffer, _T( "Liczba w oknie" ), MB_OK );
				    //MessageBox( hwnd, "Bitmapy sa sobie rowne", "Ha5!", MB_ICONINFORMATION);
					actual_number = i;
			      //std::cout << "Bitmapy sa sobie rowne_1 i= "<<i<< " ,2. counter= "<< counter<< "  .m= "<<m+1<< std::endl;
				//	system("pause");
					counter = 0;
					_break = true;
					break;
				}
				else
				{
				    //MessageBox( hwnd, "Bitmapy sa nierowne_1", "Ha5!", MB_ICONINFORMATION);
                        _TCHAR szBuffer[ 20 ];
                        _stprintf( szBuffer, _T( "Bitmapy sa nierowne_1 counter %i" ), counter );
                        MessageBox( NULL, szBuffer, _T( "Liczba w oknie" ), MB_OK );

					//std::cout << "Bitmapy sa nierowne_1 i= "<<i<< " ,2. counter= "<< counter<< "  .m= "<<m+1<< std::endl;
					//goto spr;
					//system("pause");
					_break = true;
					counter = 0;
					break;
				}
		if(counter>1100){
                //std::cout << "i= "<<i<< " . counter= "<< counter<< "  .m= "<<m+1<< std::endl;
		}
		counter = 0;
		if ( actual_number != -1 )
			break;
	}
	return actual_number;

}
//////////////////////////////////////////////////////////////




int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    // WYPELNIANIE STRUKTURY
    WNDCLASSEX wc;

    wc.cbSize = sizeof( WNDCLASSEX );
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );
    // REJESTROWANIE KLASY OKNA
    if( !RegisterClassEx( & wc ) )
    {
        MessageBox( NULL, "Wysoka Komisja odmawia rejestracji tego okna!", "Niestety...",
        MB_ICONEXCLAMATION | MB_OK );
        return 1;
    }

    // TWORZENIE OKNA
   // HWND hwnd;

    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "Oto okienko", WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 440, 220, NULL, NULL, hInstance, NULL );

    if( hwnd == NULL )
    {
        MessageBox( NULL, "Okno odmówilo przyjscia na swiat!", "Ale kicha...", MB_ICONEXCLAMATION );
        return 1;
    }

    ShowWindow( hwnd, nCmdShow ); // Poka? okienko...
    UpdateWindow( hwnd );


g_hPrzycisk = CreateWindowEx( 0, "BUTTON", "Nasz przycisk1", WS_CHILD | WS_VISIBLE,
100, 100, 150, 30, hwnd, NULL, hInstance, NULL );




    // Petla komunikatów
    while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }
    return Komunikat.wParam;
}

// OBSLUGA ZDARZEN
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
    case WM_CLOSE:
        DestroyWindow( hwnd );
        break;
    case WM_COMMAND:
        if(( HWND ) lParam == g_hPrzycisk )
        {
        //MessageBox( hwnd, "Nacisnieto przycisk!", "Ha!", MB_ICONINFORMATION );
        fun_1(hwnd);
        }
    break;

    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;

        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }

    return 0;
}

void fun_1( HWND hwnd)
{
    //MessageBox( hwnd, "w fun_1()", "Ha2!", MB_ICONINFORMATION );
	srand((int) time(0));
	szerokosc_1=80;//x
	wysokosc_1=30;//y
	szerokosc_2=60;
	wysokosc_2=20;
	szerokosc_3=15;
	wysokosc_3=40;
	//http://www.gamedev.pl/forum/tablica-obiektow-z-konstruktorem
	//https://4programmers.net/Forum/Java/135454-Tablica_Problem_z_wywolaniem_konstruktorow
	//http://edu.pjwstk.edu.pl/wyklady/pro/scb/PRG2CPP_files/node92.html

    //MessageBox( hwnd, "start tworzenia objektow dynamicznych", "Ha5!", MB_ICONINFORMATION );
///////////////////////////////////////////////////////////////////////
// Dynamically Allocate Memory for 3D Array in C++
   unsigned char *** tablica_bitmapy1 = new unsigned char **[szerokosc_1];

    for (int  i = 0; i < szerokosc_1; i++)
    {
        tablica_bitmapy1[i] = new unsigned char *[wysokosc_1];

        for (int  j = 0; j < wysokosc_1; j++)
            tablica_bitmapy1[i][j] = new unsigned char [3];
    }
   unsigned char *** tablica_bitmapy2 = new unsigned char **[szerokosc_1];

    for (int  i = 0; i < szerokosc_1; i++)
    {
        tablica_bitmapy2[i] = new unsigned char *[wysokosc_1];

        for (int  j = 0; j < wysokosc_1; j++)
            tablica_bitmapy2[i][j] = new unsigned char [3];
    }
    //MessageBox( hwnd, "koniec tworzenia objektow dynamicznych", "Ha5!", MB_ICONINFORMATION );
//////////////////////////////////////////////////////////////////////////





	//system("pause");
	int w11 = szerokosc_1, h11 = wysokosc_1;
	int bw1 = szerokosc_1, bh1 = wysokosc_1;
	int bw41=(bw1+3)&0xFFFFFFFC;
	//HANDLE hf;
	BITMAPINFO bi1;
	bi1.bmiHeader.biBitCount=24;
	bi1.bmiHeader.biClrImportant=0;
    bi1.bmiHeader.biClrUsed=0;
	bi1.bmiHeader.biCompression=BI_RGB;
	bi1.bmiHeader.biHeight=bh1;
    bi1.bmiHeader.biPlanes=1;
	bi1.bmiHeader.biSize=40;
	bi1.bmiHeader.biSizeImage=bw41*bh1*3;
	//bi1.bmiHeader.biSizeImage=bw*bh*3;
    bi1.bmiHeader.biWidth=bw1;
	bi1.bmiHeader.biXPelsPerMeter=3780;
	bi1.bmiHeader.biYPelsPerMeter=3780;
    bi1.bmiColors[0].rgbBlue=0;
	bi1.bmiColors[0].rgbGreen=0;
	bi1.bmiColors[0].rgbRed=0;
	bi1.bmiColors[0].rgbReserved=0;

	//Sleep(1000);
	po1.x = BITMAP_width11;
	po1.y = BITMAP_height11;
	POINT p1;
	HWND he1,hf1;
	GetCursorPos(&p1);
	//he = WindowFromPoint(p1);
	he1=GetDesktopWindow();
//he1=FindWindow(_T("IEFrame"),_T("WorldWinner Cash Competitions on GSN - Windows Internet Explorer"));
	//hf1 = WindowFromPoint(po1);
	//ClientToScreen(he,&po1);
	width11 = po1.x;
	height11 = po1.y;


////////////////////////////////////////
	_TCHAR str[70][15]={
		{_T("sample1.bmp")}};

char str2[70][15]={
		{"sample1.bmp"}};

	int actual_number1=-1;
	int tab[10][8]={0};
	int flaga1=0;
	int tmp1=0;
	//cout<<"zrzut ekranu:            ..........."<<endl;
	//system("pause");
	Sleep(1);
	int wymiar_obrazka_x;
	int wymiar_obrazka_y;
	wymiar_obrazka_x=szerokosc_1;
	wymiar_obrazka_y=wysokosc_1;

	tmp1=0;
	int szerokosc=0;
	int wysokosc=0;
	//MessageBox( hwnd, "przed create_new_bitmap111", "Ha5!", MB_ICONINFORMATION );
	create_new_bitmap111(hwnd,wysokosc_1,szerokosc_1,he1,str[0],0,50,1,wymiar_obrazka_x,wymiar_obrazka_y);
	//MessageBox( hwnd, "przed load_templates12", "Ha5!", MB_ICONINFORMATION );
	load_templates12(wysokosc_1,szerokosc_1,tablica_bitmapy1);


	//MessageBox( hwnd, "przed bmp11.loadBMP11", "Ha5!", MB_ICONINFORMATION );
   bmp11.loadBMP11(wysokosc_1,szerokosc_1,tablica_bitmapy2,str2[0]);
   // MessageBox( hwnd, "przed find_bitmap11", "Ha5!", MB_ICONINFORMATION );
    actual_number1 = find_bitmap12(hwnd,0,wysokosc_1,szerokosc_1,tablica_bitmapy1,tablica_bitmapy2);
    //MessageBox( hwnd, "po find_bitmap11", "Ha5!", MB_ICONINFORMATION );

    _TCHAR szBuffer[ 40 ];
    _stprintf( szBuffer, _T( "actual_number1 %i" ), actual_number1 );
    MessageBox( NULL, szBuffer, _T( "Liczba w oknie2" ), MB_OK );

//////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
	    MessageBox( hwnd, "przed 1 delete:", "Ha5!", MB_ICONINFORMATION);
  //https://www.techiedelight.com/dynamic-memory-allocation-in-c-for-2d-3d-array/
    // deallocate memory
    for (int i = 0; i < szerokosc_1; i++)
    {
        for (int j = 0; j < wysokosc_1; j++)
            delete[] tablica_bitmapy1[i][j];

        delete[] tablica_bitmapy1[i];
    }
    delete[] tablica_bitmapy1;

    for (int i = 0; i < szerokosc_1; i++)
    {
        for (int j = 0; j < wysokosc_1; j++)
            delete[] tablica_bitmapy2[i][j];

        delete[] tablica_bitmapy2[i];
    }
    delete[] tablica_bitmapy2;
//cout<<"po calym delete:"<<endl;
    MessageBox( hwnd, "w fun_1() koniec", "Ha3!", MB_ICONINFORMATION );
	//system("pause");
}
