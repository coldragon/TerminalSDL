﻿#include "hdr/Box.h"

Box::Box()
{
	x_ = 0; y_ = 0; w_ = 0; h_ = 0;
}

Box::Box(const int x = 0, const int y = 0, const int w = 0, const int h = 0) : x_(x), y_(y), w_(w), h_(h)
{
	
}

SDL_Rect Box::sdl() const
{
	return SDL_Rect{x_,y_,w_,h_};
}

int Box::GetPosX() const
{
	return x_;
}

int Box::GetPosY() const
{
	return y_;
}

int Box::GetPosW() const
{
	return w_;
}

int Box::GetPosH() const
{
	return h_;
}

void Box::SetPos(int x, int y)
{
	x_ = x; y_ = y;
}

void Box::ShiftPos(int x, int y)
{
	x_ += x; y_ += y;
}

void Box::SetSize(int w, int h)
{
	w_ = w; h_ = h;
}

bool Box::operator==(const Box& b) const
{
	if(x_ == b.x_ && y_ == b.y_ && w_ == b.w_ && b.h_)
	{
		return true;
	}
	return false;
}

bool Box::operator!=(const Box& b) const
{
	if (x_ == b.x_ && y_ == b.y_ && w_ == b.w_ && b.h_)
	{
		return false;
	}
	return true;
}

Box Box::operator*(const float& f) const
{
	return Box(x_, y_, w_*f, h_*f);
}

Box& Box::operator=(const SDL_Rect& r)
{
	x_ = r.x; y_ = r.y; w_ = r.w; 
	return *this;
}
