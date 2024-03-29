/*
 * Copyright 2024 TheJat, All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		DarkWyrm, manishkl543@gmail.com
 */

#ifndef WIN11_DECORATOR_H
#define WIN11_DECORATOR_H


#include "DecorManager.h"
#include "SATDecorator.h"


struct rgb_color;


class BRect;

class Win11DecorAddOn : public DecorAddOn {
public:
								Win11DecorAddOn(image_id id, const char* name);

protected:
	virtual Decorator*			_AllocateDecorator(DesktopSettings& settings,
									BRect rect,	Desktop* desktop);
};


class Win11Decorator: public SATDecorator {
public:
								Win11Decorator(DesktopSettings& settings,
									BRect frame, Desktop* desktop);
								~Win11Decorator(void);

	virtual	void				Draw(BRect updateRect);
	virtual	void				Draw();

	virtual	Region				RegionAt(BPoint where, int32& tab) const;

	virtual	bool				SetRegionHighlight(Region region,
									uint8 highlight, BRegion* dirty,
									int32 tab = -1);

protected:
			void				_DoLayout();

	virtual	void				_DrawFrame(BRect rect);

	virtual	void				_DrawButtons(Decorator::Tab* tab,
									const BRect& invalid);
	virtual	void				_DrawTab(Decorator::Tab* tab, BRect rect);
	virtual	void				_DrawTitle(Decorator::Tab* tab, BRect rect);

	virtual	void				_DrawMinimize(Decorator::Tab* tab, bool direct,
									BRect rect);
	virtual	void				_DrawZoom(Decorator::Tab* tab, bool direct,
									BRect rect);
	virtual	void				_DrawClose(Decorator::Tab* tab, bool direct,
									BRect rect);

	virtual	void				_SetTitle(Decorator::Tab* tab, const char* string,
									BRegion* updateRegion = NULL);

			void				_MoveBy(BPoint offset);
			void				_ResizeBy(BPoint offset, BRegion* dirty);

			Decorator::Tab*		_AllocateNewTab();

	virtual	bool				_AddTab(DesktopSettings& settings,
									int32 index = -1,
									BRegion* updateRegion = NULL);
	virtual	bool				_RemoveTab(int32 index,
									BRegion* updateRegion = NULL);
	virtual	bool				_MoveTab(int32 from, int32 to, bool isMoving,
									BRegion* updateRegion = NULL);

			void				_GetFootprint(BRegion *region);
	virtual	void				_SetFocus(Decorator::Tab* tab);

private:
			void				_UpdateFont(DesktopSettings& settings);
			void				_DrawBeveledRect(BRect r, bool down);

private:
			rgb_color			fFrameHighColor;
			rgb_color			fFrameMidColor;
			rgb_color			fFrameLowColor;
			rgb_color			fFrameLowerColor;
			
			

			rgb_color			fFocusTabColor;
			rgb_color			fFocusTextColor;
			rgb_color			fNonFocusTabColor;
			rgb_color			fNonFocusTextColor;
			
			
			

			rgb_color			fTabColor;
			rgb_color			fTextColor;
			
			rgb_color			fFrameHighColorInactive;
			rgb_color			fFrameMidColorInactive;
		
};


#endif	// WIN11_DECORATOR_H
