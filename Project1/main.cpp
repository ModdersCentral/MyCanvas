#include <iostream>
#include "MyCanvas.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
using namespace std;
/* TODO:
***to make it as portable as possible/low level as possible without relying on api's 
*/











































int main() { 
	MyCanvas *ctx = new MyCanvas; 
	int i=0;
	 //filling rectangle
			ctx->beginPath();
			ctx->rect(1,2, 3,4);
			ctx->fillStyle("rgba(0,0,0,0.255)");
			ctx->fill();
		//drawing text
			ctx->beginPath();
			ctx->font("bold 3px Arial"); 
			ctx->fillStyle("white");
			ctx->fillText("Recently Watched",5 , 10);  


			///working on these atm.. 
  ctx->drawRect(10,10,ctx->GetWidth() - 20,ctx->GetHeight() - 20,0,0,0);
		 //	ctx->RectangleToBitmap(10,10,ctx->GetWidth() - 20, ctx->GetHeight() - 20,30,12,255);
			  ctx->Draw();
			
			 std::this_thread::sleep_for (std::chrono::seconds(10)); 
	delete ctx;
    return 0;
}