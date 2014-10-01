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

Horizontal line
========
ctx.beginPath();ctx.lineWidth = 2;ctx.moveTo(0,230);ctx.lineTo(canvas.width,230);ctx.strokeStyle = '#ff0000';ctx.stroke();

Credits
========
me<br />
deroad<br />
Andreas Hartl<br />
Bresenham's line algorithm
