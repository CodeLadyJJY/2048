#ifndef __CARD_H__
#define __CARD_H__

#include "cocos2d.h"

class Card : public cocos2d::Node
{
private:
	int m_row, m_col;	//卡片所在行列

public:
	int m_num;			//卡片数字

	void show(int r, int c);	//显示块
	void move(int r, int c);	//移动块
	void doubleNum();
	virtual bool init();
	CREATE_FUNC(Card);
};

#endif