#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"
#include "Card.h"

//移动方向
enum class ENUM_DIR
{
	UP,
	DOWM,
	LEFT,
	RIGHT
};

class GameScene : public cocos2d::Layer
{
private:
	int m_startmove;	//记录触摸是否移动
	int m_sound_clear;	//是否播放消除音效
	int m_score;		//记录分数
	int m_x, m_y;		//记录触摸歧视位置
	int map[4][4];		//网格数组，记录数字块的编号
	ENUM_DIR dir;		//记录移动方向
	bool isMove;		//数字块是否移动
	cocos2d::LayerColor * GameColor;	//网格背景
	cocos2d::Vector<Card *> allCard;	//记录所有卡片

	void newTile();		//产生新块
	void moveAllTile();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void showGameOver();

public:
	static cocos2d::Scene * createScene();
	virtual bool init();
	void menuCallBack(cocos2d::Ref* obj);
	CREATE_FUNC(GameScene);
};

#endif