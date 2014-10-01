MyCanvas
========

C++ Canvas meant to look like the HTML5 canvas

Installation
========
1)Download<br />
2)Open Project1.sln<br />
3) Edit to your needs<br />

Creating an instance
========
MyCanvas *ctx = new MyCanvas; 

Filling a Rectangle
========
ctx->beginPath();
			ctx->rect(1,2, 3,4);
			ctx->fillStyle("rgba(0,0,0,0.255)");
			ctx->fill();
Drawing Text
========

ctx->beginPath();
			ctx->font("bold 3px Arial"); 
			ctx->fillStyle("white");
			ctx->fillText("Recently Watched",5 , 10);  

Credits
========
me<br />
deroad<br />
Andreas Hartl<br />
Bresenham's line algorithm
