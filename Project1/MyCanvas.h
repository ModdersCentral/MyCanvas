#ifndef MYCANVAS_TEST2_VERSION_H
#define MYCANVAS_TEST2_VERSION_H
#include <string>
#include "wtypes.h"
#include <sstream> 
#include <fstream>
#include <iostream> 
class MyCanvas {
public:
	MyCanvas(); 
	std::string DebugScreen();
	void beginPath();
		//shapes
	void arc(int x,int y,int radius, int start_angle, int end_angle,bool clockwise = FALSE);
	void arcTo(int x1,int y1,int x2,int y2,int r);
	void quadraticCurveTo(int cpx,int cpy,int x,int y);
	void rect(int x,int y,int width,int height);
	void roundRect(int x,int y,int width,int height,int radius);
		//fonts
	void font(std::string value);
		//colouring
	void fillStyle(std::string color);
	void strokeStyle(std::string color);
		//drawing
	void stroke();
	void fill();
		//text functions
	void fillText(std::string text,int x,int y);void strokeText(std::string text,int x,int y);
		//lines
	void moveTo(int x,int y);void lineTo(int x,int y);
	void clear();
	void setsPixel (int x, int y,  unsigned char r, unsigned char g, unsigned char b);
	void lineTo(int xa, int ya, int xb, int yb);
	void drawRect(int x, int y,  int w, int h, unsigned char r,unsigned char g,unsigned char b);
	void  Draw();
void getpixel(int x, int y, int &r, int &g, int &b); 
void clear(unsigned char r, unsigned char g, unsigned char b); 
void RectangleToBitmap(int X, int Y, int width, int height, unsigned char r, unsigned char g, unsigned char b); 
protected:
	void GetDesktopResolution(int& horizontal, int& vertical); 
	void DrawLine( const float x1, const float y1, const float x2, const float y2, unsigned char r, unsigned char g, unsigned char b); 
	void drawFastVLine(int x, int y,  int h, unsigned char r, unsigned char g, unsigned char b);
	void drawFastHLine(int x, int y, int w, unsigned char r, unsigned char g, unsigned char b);
	BYTE* ConvertRGBToBMPBuffer ( BYTE* Buffer, int width, int height, long* newsize );
	bool SaveBMP ( BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile );
};
#else
#error MyCanvas.h has been included previously
#endif