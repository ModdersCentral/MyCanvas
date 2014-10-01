#ifndef MYCANVAS_TEST_VERSION_H
#define MYCANVAS_TEST_VERSION_H
#include "MyCanvas.h"
#else
#error MyCanvas.cpp has been included previously
#endif
#define ROUND(a) ((int) (a + 0.5))
int horizontal = 0;int vertical = 0;unsigned char *pixels;
/*
i thought this was going good then it fkd up..
*/
		 //we get the width+height of the screen then we set the pixel container large enough to store it
	MyCanvas::MyCanvas(){
		GetDesktopResolution(horizontal, vertical);
		pixels = new unsigned char[horizontal * vertical * 3];
		clear(255,255,255);
	}
		 //we get the width+height by reffernce
	void MyCanvas::GetDesktopResolution(int& horizontal, int& vertical){
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);
		horizontal = desktop.right;
		vertical = desktop.bottom;
	}
		 //we delete the pixel container/pointer
	MyCanvas::~MyCanvas(){
		delete[] pixels;
	}
		 //subroutine to clear the pixels to white
	void MyCanvas::clear(){
			clear(255, 255,255);
	}
	int MyCanvas::GetWidth(){
		return horizontal;
	}
	int MyCanvas::GetHeight(){
		return vertical;
	}
		 //set all the pixels a certain colour
	void MyCanvas::clear(unsigned char r, unsigned char g, unsigned char b){
			for (int i = 0; i < GetWidth() * GetHeight(); i++) {
				pixels[i * 3 + 0] = r;
				pixels[i * 3 + 1] = g;
				pixels[i * 3 + 2] = b;
			}
	}
	void MyCanvas::setsPixel(int x, int y,unsigned char r,unsigned char g,unsigned char b){
		int idx = ((x*GetWidth())+y)*3;
		pixels[idx + 0] = r;
		pixels[idx + 1] = g;
		pixels[idx + 2] = b;
	}
	 void MyCanvas::RectangleToBitmap(int X, int Y, int width, int height, unsigned char r, unsigned char g, unsigned char b){
	for(int i = Y; i < (height+Y); i++) {for(int j = X; j < (width+X); j++) { setsPixel(i,j,r,g,b);}}
	}



	 
	  













	 
//incomplete
	void MyCanvas::beginPath(){}
	void MyCanvas::arcTo(int x1,int y1,int x2,int y2,int r){}
	void MyCanvas::quadraticCurveTo(int cpx,int cpy,int x,int y){}
	void MyCanvas::font(std::string value){/*has values like: //bold  10px Arial //      10px Arial*/}
	void MyCanvas::fillStyle(std::string color){/*use regex to parse: //argb //rgb //rgba //hex color //color*/}
	void MyCanvas::fillText(std::string text,int x,int y){}
	void MyCanvas::strokeText(std::string text,int x,int y){}
	void MyCanvas::strokeStyle(std::string color){/*use regex to parse: //argb //rgb //rgba //hex color //color*/}
	void MyCanvas::fill(){}
	void MyCanvas::stroke(){}
	void MyCanvas::moveTo(int x,int y){ }
	void MyCanvas::lineTo(int x,int y){}

	void MyCanvas::drawRect(int x, int y,  int w, int h, unsigned char r,unsigned char g,unsigned char b) {
 drawFastHLine(x, y, h, r,g,b);



 drawFastHLine(x, y+w-1, h, r,g,b);


  drawFastVLine(x, y, w, r,g,b);



  drawFastVLine(x+h-1, y, w, r,g,b);


}


	void MyCanvas::lineTo(int xa, int ya, int xb, int yb){//i think this works
		/*int dx = xb - xa, dy = yb - ya, steps;

    float xIncrement, yIncrement, x = xa, y = ya;

   if(abs(dx) > abs(dy)) steps = abs(dx);

   else steps = abs(dy);

   xIncrement = dx / (float) steps;

   yIncrement = dy / (float) steps;

   setPixel(ROUND(x), ROUND(y),0,0,0);
   for(int k = 0; k < steps; k++){

    x += xIncrement;

    y += yIncrement;

   setPixel(ROUND(x), ROUND(y),0,0,0);

 }
   */
	}
	

	//completed or kinda completed
	void MyCanvas::getpixel(int x, int y, int &r, int &g, int &b){int idx = ((x*vertical)+y)*3;r = pixels[idx+0];g = pixels[idx+1];b = pixels[idx+2];}
	void MyCanvas::rect(int x,int y,int width,int height){beginPath();moveTo(x, y);lineTo(x + width, y);lineTo(x + width, y + height);lineTo(x,y + height);lineTo(x,y);}
	void MyCanvas::roundRect(int x,int y,int width,int height,int radius){if (width < 2 * radius){ radius = width / 2;}if (height < 2 * radius){ radius = height / 2;}beginPath();moveTo(x+radius, y);arcTo(x+width, y,   x+width, y+height, radius);arcTo(x+width, y+height, x,   y+height, radius);arcTo(x,   y+height, x,   y,   radius);arcTo(x,   y,   x+width, y,   radius);}
	void MyCanvas::Draw(){
			 long s;
		BYTE* b = ConvertRGBToBMPBuffer ( pixels,  1366, 768, &s );
	SaveBMP ( b, 1366, 768, s,  "image.bmp" );
	 delete [] b;
		for (int i = 0; i < horizontal * vertical; i++){/*cant find any cross platform function to draw the pixels to screen pixels[i * 3 + 0];pixels[i * 3 + 1];pixels[i * 3 + 2]*/}}
	void MyCanvas::drawFastVLine(int x, int y, int h, unsigned char r, unsigned char g, unsigned char b) {DrawLine(x, y, x, y+h-1, r,g,b);}
	void MyCanvas::drawFastHLine(int x, int y, int w, unsigned char r, unsigned char g, unsigned char b) {DrawLine(x, y, x+w-1, y, r,g,b);}
	std::string MyCanvas::DebugScreen(){int r, g, b;getpixel(1,1,r,g,b);std::ostringstream os;os << "Debug Info: (" << vertical << " Height x " << horizontal << " Width)(" << r << g << b << ")";return  os.str();}
	//this is just tempory we will be using the lineto and moveto...// Bresenham's line algorithm
	 void MyCanvas::DrawLine(  float x1, float y1,  float x2,  float y2, unsigned char r, unsigned char g, unsigned char b){
		int delta_x(x2 - x1);
    // if x1 == x2, then it does not matter what we set here
    signed char const ix((delta_x > 0) - (delta_x < 0));
    delta_x = std::abs(delta_x) << 1;
 
    int delta_y(y2 - y1);
    // if y1 == y2, then it does not matter what we set here
    signed char const iy((delta_y > 0) - (delta_y < 0));
    delta_y = std::abs(delta_y) << 1;
  setsPixel(x1,y1,r,g,b);
 
    if (delta_x >= delta_y)
    {
        // error may go below zero
        int error(delta_y - (delta_x >> 1));
 
        while (x1 != x2)
        {
            if ((error >= 0) && (error || (ix > 0)))
            {
                error -= delta_x;
                y1 += iy;
            }
            // else do nothing
 
            error += delta_y;
            x1 += ix;
 
            setsPixel(x1,y1,r,g,b);
        }
    }
    else
    {
        // error may go below zero
        int error(delta_x - (delta_y >> 1));
 
        while (y1 != y2)
        {
            if ((error >= 0) && (error || (iy > 0)))
            {
                error -= delta_y;
                x1 += ix;
            }
            // else do nothing
 
            error += delta_x;
            y1 += iy;
 
            setsPixel(x1,y1,r,g,b);
        }
    }
}

	






















	 
BYTE* MyCanvas::ConvertRGBToBMPBuffer ( BYTE* Buffer, int width, int height, long* newsize ){

	// first make sure the parameters are valid
	if ( ( NULL == Buffer ) || ( width == 0 ) || ( height == 0 ) )
		return NULL;

	// now we have to find with how many bytes
	// we have to pad for the next DWORD boundary	

	int padding = 0;
	int scanlinebytes = width * 3;
	while ( ( scanlinebytes + padding ) % 4 != 0 )     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;
	
	// we can already store the size of the new padded buffer
	*newsize = height * psw;

	// and create new buffer
	BYTE* newbuf = new BYTE[*newsize];
	
	// fill the buffer with zero bytes then we dont have to add
	// extra padding zero bytes later on
	memset ( newbuf, 0, *newsize );

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;   
	long newpos = 0;
	for ( int y = 0; y < height; y++ )
		for ( int x = 0; x < 3 * width; x+=3 )
		{
			bufpos = y * 3 * width + x;     // position in original buffer
			newpos = ( height - y - 1 ) * psw + x;           // position in padded buffer

			newbuf[newpos] = Buffer[bufpos+2];       // swap r and b
			newbuf[newpos + 1] = Buffer[bufpos + 1]; // g stays
			newbuf[newpos + 2] = Buffer[bufpos];     // swap b and r
		}

	return newbuf;
}
bool MyCanvas::SaveBMP ( BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile )
{
	// declare bmp structures 
	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER info;
	
	// andinitialize them to zero
	memset ( &bmfh, 0, sizeof (BITMAPFILEHEADER ) );
	memset ( &info, 0, sizeof (BITMAPINFOHEADER ) );
	
	// fill the fileheader with data
	bmfh.bfType = 0x4d42;       // 0x4d42 = 'BM'
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + paddedsize;
	bmfh.bfOffBits = 0x36;		// number of bytes to start of bitmap bits
	
	// fill the infoheader

	info.biSize = sizeof(BITMAPINFOHEADER);
	info.biWidth = width;
	info.biHeight = height;
	info.biPlanes = 1;			// we only have one bitplane
	info.biBitCount = 24;		// RGB mode is 24 bits
	info.biCompression = BI_RGB;	
	info.biSizeImage = 0;		// can be 0 for 24 bit images
	info.biXPelsPerMeter = 0x0ec4;     // paint and PSP use this values
	info.biYPelsPerMeter = 0x0ec4;     
	info.biClrUsed = 0;			// we are in RGB mode and have no palette
	info.biClrImportant = 0;    // all colors are important

	// now we open the file to write to
	HANDLE file = CreateFile ( bmpfile , GENERIC_WRITE, FILE_SHARE_READ,
		 NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
	if ( file == NULL )
	{
		CloseHandle ( file );
		return false;
	}
	
	// write file header
	unsigned long bwritten;
	if ( WriteFile ( file, &bmfh, sizeof ( BITMAPFILEHEADER ), &bwritten, NULL ) == false )
	{	
		CloseHandle ( file );
		return false;
	}
	// write infoheader
	if ( WriteFile ( file, &info, sizeof ( BITMAPINFOHEADER ), &bwritten, NULL ) == false )
	{	
		CloseHandle ( file );
		return false;
	}
	// write image data
	if ( WriteFile ( file, Buffer, paddedsize, &bwritten, NULL ) == false )
	{	
		CloseHandle ( file );
		return false;
	}
	
	// and close file
	CloseHandle ( file );

	return true;
}
 


