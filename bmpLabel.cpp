
#include <bmpLabel.h>
#include <offscreen.h>

bmpLabel::bmpLabel(int inX,int inY,int width,int height,char* inText,char* bmpPath) 
  : label(inX,inY,width,height,inText) {
  
  backdrop = new bmpObj(inX,inY,width,height,bmpPath);	// Create a new bmpObj for our backdrop.
  setColors(&textColor);											// Cheaty trick to set transparent drawing.
}


bmpLabel::~bmpLabel(void) { if (backdrop) delete(backdrop); }


// We go through all this nonsense so we can redraw ourselves on every line.
// This actually hides the major flicker issue we would have otherwise.
// 

bool bmpLabel::offScreenDraw(void) {
  
	rect			temp;
	offscreen	vPort;
	bitmap		ourBMap;
	
	if (backdrop) {
		if (ourBMap.setSize(width,height)) {				// If we can allocate the RAM for the bitmap..
			temp = (rect) *this;									// Get our local rectangle.
			temp.x = screen->gX(temp.x);						// Convert to globals.
			temp.y = screen->gY(temp.y);						//
			backdrop->setLocation(x,y);						// Just in case we moved..
			backdrop->setSourceOffset(temp.x,temp.y);		// Point the bitmap to the bits in the file.
			vPort.beginDraw(&ourBMap,temp.x,temp.y);		// Start up offscreen drawing.
			backdrop->draw();										// Draw the background to it..
			label::drawSelf();									// Get the text in there.
			vPort.endDraw();										// Restore normal drawing.
			screen->blit(x,y,&ourBMap);						// Blast the bitmap out to the screen.
			return true;
		}
	}
	return false;
}


void bmpLabel::ezDraw(void) {
	
	rect 	temp;
			
	temp = (rect) *this;									// Get our local rectangle.
	temp.x = screen->gX(temp.x);						// Convert to global.
	temp.y = screen->gY(temp.y);
	backdrop->setLocation(x,y);						// Just in case we moved..
	backdrop->setSourceOffset(temp.x,temp.y);		// Point the bitmap to the bits in the file.
	backdrop->draw();										// Draw in local.
	label::drawSelf();									// Blast it out to the screen.
}


void bmpLabel::drawSelf(void){

	if (!offScreenDraw()) {
		ezDraw();
	}
}