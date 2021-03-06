//
//  SettingsScene.h
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

#ifndef AticBoom_SettingsScene_h
#define AticBoom_SettingsScene_h

#include <vector>
#include <string>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "CCTouchDispatcher.h"
#include "MenuScene.h"
#include "AticBoomObjC.h"
#include "Border.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

class SettingsScene : public cocos2d::CCLayer {
    
public:
    SettingsScene();
    ~SettingsScene();
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    static SettingsScene* node()
    {
        SettingsScene *pRet = new SettingsScene();
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
    
    int soundstate;
    int fxstate;
    bool confirmationMode;
    
    bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    void onEnter();
    void onExit();
    void backToTitle(CCObject* pSender);
    void toggleMusic(CCObject* pSender);
    void toggleFx(CCObject* pSender);
    void saveSettings();
    void showConfirmation();
    void eraseData(CCObject* pSender);
    void hideConfirmation();
    void keyBackClicked();
    void reloopCloud(CCNode* cloud);
    
};

#endif
