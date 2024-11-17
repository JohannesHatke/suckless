/* See LICENSE file for copyright and license details. */

/* custom commands */


#define	TIMER_FILE "/home/johannes/Programs/GCAL-logger/src/control.sh"
#define	SCRIPT_FOLDER "/home/johannes/Programs/scripts"
static const char *screenshot[] = {SCRIPT_FOLDER"/takeSCandCopy",NULL};


#ifdef TIMER_FILE
static const char *timer_control[] = {TIMER_FILE, NULL};
#else
static const char *timer_control[] = {"echo","timer not found", NULL};
#endif



static const char *increase_volume[] = {SCRIPT_FOLDER"/audio/increase_current",NULL};
static const char *decrease_volume[] = {SCRIPT_FOLDER"/audio/decrease_current",NULL};
static const char *choose_audio_output[] = {SCRIPT_FOLDER"/audio/choose_output",NULL};
static const char *mute_audio_output[] = {SCRIPT_FOLDER"/audio/mute_current",NULL};
static const char *vpn_toggle[] = {SCRIPT_FOLDER"/vpn/mullvad_connect", NULL};
static const char *docking_display[] = {SCRIPT_FOLDER"/docking_display", NULL};
static const char *launch_ranger[] = {"st","-e","ranger",NULL };
static const char *power_script[] = {SCRIPT_FOLDER"/power", NULL};

/* appearance */
static unsigned int borderpx  = 2;        /* border pixel of windows */
static unsigned int snap      = 32;       /* snap pixel */
static int showbar            = 1;        /* 0 means no bar */ 
static int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int gappx     = 2;        /* gap pixel between windows */
static const char *fonts[]          = { "Hack:size=10", "Hack Nerd Font Mono:size=18:antialias=true:autohint=true" };
static const char dmenufont[]       = "Ubuntu mono:size=10"; /* Ubuntu mono */
static char normbgcolor[]       = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]       = "#bbbbbb";
static char selfgcolor[]       = "#eeeeee";
static char selbordercolor[]        = "#ee3c3a";
static char selbgcolor[]        = "#ee3c3a";
static char col00[]       = "#000000";
static char col01[]       = "#ff0000";
static char col02[]       = "#08c74b";
static char col03[]       = "#ffff00";
static char col04[]       = "#08c74b";
static char col05[]       = "#08c74b";
static char col06[]       = "#08c74b";
static char col07[]       = "#ffffff";
static char col08[]       = "#08c74b";
static char col09[]       = "#08c74b";
static char col10[]       = "#08c74b";
static char col11[]       = "#08c74b";
static char col12[]       = "#08c74b";
static char col13[]       = "#08c74b";
static char col14[]       = "#08c74b";
static char col15[]       = "#08c74b";



static const char *colors[][3]      = {
		/*		fg         bg          border   */
	[SchemeNorm] =	 { normfgcolor,	normbgcolor,	normbordercolor },
	[SchemeSel]  =	 { selfgcolor,	selbgcolor,	selbordercolor },
	[SchemeWarn] =	 { col03,	normbgcolor,	col01 },
	[SchemeUrgent]=	 { col01,	normbgcolor,	normbordercolor },
	[SchemeOk]=	 { col02,	normbgcolor,	normbordercolor },
 };

/* tagging */
static const char *tags[] = { "1", "2", "󱗖", "4", "5", "", "7", "8", "󰈹" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "thunderbird",  NULL,	  NULL,       1 << 5,       0,           -1 },
	{ "Zathura",  NULL,	  NULL,       1 << 2,       0,           -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", normbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "background",        STRING,  &normbgcolor },
		{ "normbordercolor",    STRING,  &normbordercolor },  //color around unselected window
		{ "foreground",        STRING,  &normfgcolor },
		{ "selbgcolor",         STRING,  &selbgcolor }, // selection middle of bar and tab
		{ "selbordercolor",     STRING,  &selbordercolor }, // selection border color
		{ "selfgcolor",         STRING,  &selfgcolor },
		{ "borderpx",          	INTEGER, &borderpx },
		{ "snap",          		INTEGER, &snap },
		{ "showbar",          	INTEGER, &showbar },
		{ "topbar",          	INTEGER, &topbar },
		{ "nmaster",          	INTEGER, &nmaster },
		{ "resizehints",       	INTEGER, &resizehints },
		{ "mfact",      	 	FLOAT,   &mfact },

		{ "color0",      	 	STRING,   &col00 },
		{ "color1",      	 	STRING,   &col01 },
		{ "color2",      	 	STRING,   &col02 },
		{ "color3",      	 	STRING,   &col03 },
		{ "color4",      	 	STRING,   &col04 },
		{ "color5",      	 	STRING,   &col05 },
		{ "color6",      	 	STRING,   &col06 },
		{ "color7",      	 	STRING,   &col07 },
		{ "color8",      	 	STRING,   &col08 },
		{ "color9",      	 	STRING,   &col09 },
		{ "color10",      	 	STRING,   &col10 },
		{ "color11",      	 	STRING,   &col11 },
		{ "color12",      	 	STRING,   &col12 },
		{ "color13",      	 	STRING,   &col13 },
		{ "color14",      	 	STRING,   &col14 },
		{ "color15",      	 	STRING,   &col15 },
};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,			XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	/* custom commands */
	{ MODKEY|ShiftMask,             XK_s,      spawn,            {.v = power_script } },
	{ MODKEY|ShiftMask,             XK_t,      spawn,            {.v = timer_control } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,            {.v = docking_display } },
	{ 0, XF86XK_AudioRaiseVolume, spawn, {.v = increase_volume} }, 
	{ 0, XF86XK_AudioLowerVolume, spawn, {.v = decrease_volume} }, 
	{ 0, XF86XK_AudioMute, spawn, {.v = mute_audio_output} }, 
	{ 0, XK_Print, spawn, {.v = screenshot} }, 
	{ MODKEY , XK_o, spawn, {.v = choose_audio_output} }, 
	{ MODKEY,	             XK_v, spawn,         {.v = vpn_toggle } },
	{ Mod1Mask,	             XK_F4, killclient,     {0} }, //alt f4
	{ MODKEY,	             XK_n, spawn,     {.v = launch_ranger} }, 
};
/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


