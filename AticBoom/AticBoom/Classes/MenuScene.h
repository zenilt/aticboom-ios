//
//  MenuScene.h
//  AticBoom
//
//  Created by Claudio Alvial on 1/6/12.
//

/*
 * Copyright (C) 2015 Juan Francisco Rodríguez
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef AticBoom_MenuScene_h
#define AticBoom_MenuScene_h

#include <vector>
#include <string>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "CCTouchDispatcher.h"
#include "GameScene.h"
#include "SettingsScene.h"
#include "HelpScene.h"
#include "CreditsScene.h"
#include "WorldSelectScene.h"
#include "Music.h"
#include "Geometry.h"
#include "AticBoomObjC.h"
#include "Border.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

class MenuScene : public cocos2d::CCLayer {
    
public:
    MenuScene();
    ~MenuScene();
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    static MenuScene* node()
    {
        MenuScene *pRet = new MenuScene();
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    };
    
    bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    void startAticGame(CCObject* pSender);
    void goToSettings(CCObject* pSender);
    void goToCredits(CCObject* pSender);
    void reloopCloud(CCNode* cloud);
    void moveAnchor(CCNode* pSender);
    void onEnter();
    void onExit();
    void keyBackClicked();
    
};

#endif