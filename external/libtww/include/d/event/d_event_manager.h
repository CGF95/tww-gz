#ifndef D_EVENT_D_EVENT_MANAGER_H
#define D_EVENT_D_EVENT_MANAGER_H

#include "d_event_data.h"

class dEvent_exception_c {
public:
    /* 0x0 */ s32 mEventInfoIdx;
    /* 0x4 */ u8 field_0x4;
    /* 0x5 */ u8 field_0x5;
    /* 0x6 */ u8 field_0x6;
    /* 0x7 */ u8 field_0x7;
    /* 0x8 */ s32 mState;
};
static_assert(sizeof(dEvent_exception_c) == 0xC);

class dEvent_manager_c {
public:
    /* 0x000 */ dEvDtBase_c mList;
    /* 0x020 */ u32 mCameraPlay;
    /* 0x024 */ dEvent_exception_c mException;
    /* 0x030 */ cXyz mGoal;
    /* 0x03C */ dEvDtFlag_c mFlag;
};
static_assert(sizeof(dEvent_manager_c) == 0x53C);

#endif /* D_EVENT_D_EVENT_MANAGER_H */
