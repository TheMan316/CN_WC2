//
// Created by KK on 2021/9/11.
//
#ifndef WC2_EVENT_H
#define WC2_EVENT_H
#include "JNI_Fun.h"
#include "CLi.h"
extern CommonEvent g_commonEvent;
//在这里初始化所有事件和决议
void Init_eventsAndResolutions(int scriptNum);
void Init_events_inTheScript1();
//初始化征服1剧本中的德国事件和决议
void Init_events_de_conquest1();
void Init_resolutions_de_conquest1();
void Init_events_common_conquest1();
//管理在回合开始函数中 被触发的 所有事件
void Trigger_eventTurnBegin_theScript(CCountry* country);
//管理在移动函数中 被触发的 所有事件
void Trigger_eventMoveArmyTo_theScript(CCountry* country, CArea* area);
//管理所有 宣战 的决议
void Auto_creatResolutions_toTheForm(CCountry* country, JNIEnv* env, jclass* activity);

void Tirgger_eventTurnBegin_de(CCountry* theCountry, std::vector<EventTurnBegin*>& events) ;
void Tirgger_eventTurnBegin_common(std::vector<EventTurnBegin*>& events) ;

struct ResolutionDe: public EventResolution {
    CCountry* theCountry;

private:
    void Trigger_0002_2btn_resolution(int btnNUm);
    void Trigger_resolution(int eventNum, int btnNum, CCountry* theCounry);
};

#endif //WC2_EVENT_H
