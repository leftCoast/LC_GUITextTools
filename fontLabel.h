#ifndef fontLabel_h
#define fontLabel_h

#include "label.h"


class fontLabel : public label {

	public:
				fontLabel(void);
				fontLabel(rect* inRect);
				fontLabel(int inX, int inY, int inW,int inH);
	virtual	~fontLabel(void);
				
				void	setFont(const GFXfont* font,int yOffset);
	virtual	void  drawSelf(void);
	
				GFXfont*	ourFont;		// Our font.
				int		fontOffset;
};


#endif
