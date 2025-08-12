#ifndef fontLabel_h
#define fontLabel_h

#include "label.h"


class fontLabel : public label {

	public:
				fontLabel(void);
				fontLabel(rect* inRect);
				fontLabel(int inX, int inY, int inW,int inH);
	virtual	~fontLabel(void);
				
				void	setFont(GFXfont* font,int yOffset);
				void	setFont(GFXfont* font,int inHeight,int yOffset);
	virtual	void  drawSelf(void);
	
				GFXfont*	ourFont;		// Our font.
				int		fontOffset;
};


#endif
