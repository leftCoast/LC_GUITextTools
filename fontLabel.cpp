#include "fontLabel.h"
 
 
fontLabel::fontLabel(void) : label() {  }


fontLabel::fontLabel(int inX, int inY, int inWidth,int inHeight)
  : label(inX,inY,inWidth,inHeight) { }


fontLabel::fontLabel(rect* inRect)
  : label(inRect->x,inRect->y,inRect->width,inRect->height) { }
  
  
fontLabel::~fontLabel(void) {  }


void fontLabel::setFont(const GFXfont* font,int yOffset) {
	
	ourFont = font;
	fontOffset = yOffset;
	setNeedRefresh();
}


void fontLabel::setFont(const GFXfont* font,int inHeight,int yOffset) {
	
	height = inHeight;
	setFont(font,yOffset);
}


void fontLabel::drawSelf(void) {

	rect	bounds;
	int	yLoc;
	int	offset;
	
	screen->setTextWrap(false);
	screen->setTextColor(&textColor);
	screen->setFont(ourFont);
	screen->setTextSize(1);
	yLoc = y+height+fontOffset;
	bounds = screen->getTextRect(buff);
	switch(justify) {
		case TEXT_RIGHT	:
			offset = width-bounds.width;
		break;
		case TEXT_LEFT		:
			offset = 0;
		break;
		case TEXT_CENTER	:
			offset = width-bounds.width;
			offset = offset/2;
		break;
		default 				:
			offset = 0;
		break;
	}
	screen->setCursor(x+offset,yLoc);
	screen->drawText(buff);
	//screen->drawRect(this,&red);
	screen->setFont(NULL);
}
