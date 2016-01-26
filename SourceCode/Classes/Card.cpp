#include "Card.h"
#include "GameDefine.h"

USING_NS_CC;

//ÏÔÊ¾¿é
void Card::show(int r, int c)
{
	move(r, c);

	auto bk = getChildByTag(130);
	bk->runAction(Sequence::create(ScaleTo::create(0.2, 0.85),ScaleTo::create(0.2, 1.0),NULL));
}

//ÒÆ¶¯¿é
void Card::move(int r, int c)
{
	this->m_row = r;
	this->m_col = c;

	this->setPosition(Point(c*tileWidth + (c + 1)*tileBorderWidth,
		r*tileWidth + (r + 1)*tileBorderWidth));
}

//Êı×ÖË«±¶
void Card::doubleNum()
{
	this->m_num *= 2;
	auto bk = this->getChildByTag(130);
	auto label = (Label *)bk->getChildByTag(30);
	label->setString(StringUtils::format("%d", m_num));

	bk->runAction(Sequence::create(ScaleTo::create(0.2, 0.85),ScaleTo::create(0.2, 1.0),NULL));

	switch (this->m_num) 
	{
	case 2:
		bk->setColor(Color3B(230,220,210));
		label->setColor(Color3B(0, 0, 0));
		break;
	case 4:
		bk->setColor(Color3B(205, 190, 70));
		label->setColor(Color3B(0, 0, 0));
		break;
	case 8:
		bk->setColor(Color3B(230,150,100));
		label->setColor(Color3B(255,255,255));
		break;
	case 16:
		bk->setColor(Color3B(230,120,80));
		label->setColor(Color3B(255,255,255));
		break;
	case 32:
		bk->setColor(Color3B(230,100,90));
		label->setColor(Color3B(255,255,255));
		break;
	case 64:
		bk->setColor(Color3B(230,70,60));
		label->setColor(Color3B(255,255,255));
		break;
	case 128:
		bk->setColor(Color3B(230,190,60));
		label->setColor(Color3B(255,255,255));
		break;
	case 256:
		bk->setColor(Color3B(230,190,60));
		label->setColor(Color3B(255,255,255));
		break;
	case 512:
		bk->setColor(Color3B(230,190,60));
		label->setColor(Color3B(255,255,255));
		break;
	case 1024:
	case 2048:
		label->setScale(0.7);
		bk->setColor(Color3B(210,180,30));
		label->setColor(Color3B(255,255,255));
		break;
	}
}

bool Card::init()
{
	if(!Node::init())
		return false;

	//¿¨Æ¬Êı×Ö
	int r = rand()%100;
	this->m_num = r<60 ? 2:4;
	auto number = Label::createWithSystemFont(StringUtils::format("%d", m_num), "Consolas", 60);
	number->setColor(Color3B(0, 0, 0));
	number->setTag(30);

	//¿¨Æ¬±³¾°É«
	auto cardBGColor = LayerColor::create(Color4B(205, 190, 70, 255), tileWidth, tileWidth);
	cardBGColor->setTag(130);
	this->addChild(cardBGColor);

	switch (this->m_num) 
	{
	case 2:
		cardBGColor->setColor(Color3B(230,220,210));
		
		break;
	case 4:
		cardBGColor->setColor(Color3B(205, 190, 70));
		break;
	}

	number->setPosition(Vec2(tileWidth/2, tileWidth/2));
	cardBGColor->addChild(number);

	return true;
}