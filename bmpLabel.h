#ifndef bmpLabel_h
#define bmpLabel_h

#include <label.h>
#include <bmpObj.h>

// This was written for the old vacuum gauge. It had a graphic "skin" and
// The text was colored to look like it was glowing under the glass. This
// made it so I could update the text without seeing a nasty flicker that
// would just destroy the effect.
//
// Oddly, it worked.
//
// Oct/2021 : bmpPipe is gone, offscreen drawing is here. The guts are all different now.

class bmpLabel : public label {

	public:
  				bmpLabel(int inX,int inY,int width,int height,char* inText,char* bmpPath);
	virtual	~bmpLabel(void);
	
	protected:
	
	virtual	void		drawSelf(void);
	 			bool		offScreenDraw(void);
  				void		ezDraw(void);

				bmpObj*	backdrop;
};

#endif

