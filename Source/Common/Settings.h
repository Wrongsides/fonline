#pragma once

#include "Common.h"

struct Settings
{
    Settings();
    void Init( int argc, char** argv );

    string WorkDir;
    string CommandLine;

    uint   YearStartFTLo;
    uint   YearStartFTHi;
    uint   FullSecondStart;
    uint   FullSecond;
    uint   GameTimeTick;

    bool   DisableTcpNagle;
    bool   DisableZlibCompression;
    uint   FloodSize;
    bool   NoAnswerShuffle;
    bool   DialogDemandRecheck;
    uint   SneakDivider;
    uint   LookMinimum;
    int    DeadHitPoints;
    uint   Breaktime;
    uint   TimeoutTransfer;
    uint   TimeoutBattle;
    bool   RunOnCombat;
    bool   RunOnTransfer;
    uint   GlobalMapWidth;
    uint   GlobalMapHeight;
    uint   GlobalMapZoneLength;
    uint   BagRefreshTime;
    uint   WhisperDist;
    uint   ShoutDist;
    int    LookChecks;
    uint   LookDir[ 5 ];
    uint   LookSneakDir[ 5 ];
    uint   RegistrationTimeout;
    uint   AccountPlayTime;
    uint   ScriptRunSuspendTimeout;
    uint   ScriptRunMessageTimeout;
    uint   TalkDistance;
    uint   NpcMaxTalkers;
    uint   MinNameLength;
    uint   MaxNameLength;
    uint   DlgTalkMinTime;
    uint   DlgBarterMinTime;
    uint   MinimumOfflineTime;
    bool   ForceRebuildResources;

    bool   MapHexagonal;
    int    MapHexWidth;
    int    MapHexHeight;
    int    MapHexLineHeight;
    int    MapTileOffsX;
    int    MapTileOffsY;
    int    MapTileStep;
    int    MapRoofOffsX;
    int    MapRoofOffsY;
    int    MapRoofSkipSize;
    float  MapCameraAngle;
    bool   MapSmoothPath;
    string MapDataPrefix;

    bool   DesktopBuild;
    bool   TabletBuild;
    bool   WebBuild;
    bool   WindowsBuild;
    bool   LinuxBuild;
    bool   MacOsBuild;
    bool   AndroidBuild;
    bool   IOsBuild;

    // Client and Mapper
    bool   Quit;
    int    WaitPing;
    bool   OpenGLRendering;
    bool   OpenGLDebug;
    bool   AssimpLogging;
    int    MouseX;
    int    MouseY;
    int    LastMouseX;
    int    LastMouseY;
    int    ScrOx;
    int    ScrOy;
    bool   ShowTile;
    bool   ShowRoof;
    bool   ShowItem;
    bool   ShowScen;
    bool   ShowWall;
    bool   ShowCrit;
    bool   ShowFast;
    bool   ShowPlayerNames;
    bool   ShowNpcNames;
    bool   ShowCritId;
    bool   ScrollKeybLeft;
    bool   ScrollKeybRight;
    bool   ScrollKeybUp;
    bool   ScrollKeybDown;
    bool   ScrollMouseLeft;
    bool   ScrollMouseRight;
    bool   ScrollMouseUp;
    bool   ScrollMouseDown;
    bool   ShowGroups;
    bool   HelpInfo;
    bool   DebugInfo;
    bool   DebugNet;
    bool   Enable3dRendering;
    bool   FullScreen;
    bool   VSync;
    int    Light;
    string Host;
    uint   Port;
    uint   ProxyType;
    string ProxyHost;
    uint   ProxyPort;
    string ProxyUser;
    string ProxyPass;
    uint   ScrollDelay;
    int    ScrollStep;
    bool   ScrollCheck;
    int    FixedFPS;
    uint   FPS;
    uint   PingPeriod;
    uint   Ping;
    bool   MsgboxInvert;
    bool   MessNotify;
    bool   SoundNotify;
    bool   AlwaysOnTop;
    uint   TextDelay;
    uint   DamageHitDelay;
    int    ScreenWidth;
    int    ScreenHeight;
    int    MultiSampling;
    bool   MouseScroll;
    uint   DoubleClickTime;
    uchar  RoofAlpha;
    bool   HideCursor;
    bool   ShowMoveCursor;
    bool   DisableMouseEvents;
    bool   DisableKeyboardEvents;
    bool   HidePassword;
    string PlayerOffAppendix;
    uint   Animation3dSmoothTime;
    uint   Animation3dFPS;
    int    RunModMul;
    int    RunModDiv;
    int    RunModAdd;
    bool   MapZooming;
    float  SpritesZoom;
    float  SpritesZoomMax;
    float  SpritesZoomMin;
    float  EffectValues[ EFFECT_SCRIPT_VALUES ];
    string KeyboardRemap;
    uint   CritterFidgetTime;
    uint   Anim2CombatBegin;
    uint   Anim2CombatIdle;
    uint   Anim2CombatEnd;
    uint   RainTick;
    short  RainSpeedX;
    short  RainSpeedY;
    uint   ConsoleHistorySize;
    int    SoundVolume;
    int    MusicVolume;
    uint   ChosenLightColor;
    uchar  ChosenLightDistance;
    int    ChosenLightIntensity;
    uchar  ChosenLightFlags;

    // Mapper
    string ServerDir;
    bool   ShowCorners;
    bool   ShowSpriteCuts;
    bool   ShowDrawOrder;
    bool   SplitTilesCollection;
};

extern Settings GameOpt;
class IniFile;
extern IniFile* MainConfig;
extern StrVec   ProjectFiles;
