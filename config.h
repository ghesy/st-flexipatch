/* See LICENSE file for copyright and license details. */

static char *font = "Fira Mono:pixelsize=16:antialias=true:autohint=true";
static char *font2[] = {
	"Hack Nerd Font Mono:pixelsize=16:antialias=true:autohint=true",
	"JoyPixels:pixelsize=12:antialias=true:autohint=true",
	"Braille:pixelsize=16:antialias=true:autohint=true",
};

static unsigned int cursorthickness = 1;
static int borderpx = 10;
float alpha = 0.85;

static float cwscale = 1.0;
static float chscale = 1.0;

static MouseShortcut mshortcuts[] = {
	/* mask                 button   function        argument       release */
	{ XK_ANY_MOD,           Button2, clippaste,      {.i = 0},      1 },
	{ ShiftMask,            Button4, ttysend,        {.s = "\033[5;2~"} },
	{ ShiftMask,            Button5, ttysend,        {.s = "\033[6;2~"} },
	{ XK_NO_MOD,            Button4, kscrollup,      {.i = 3} },
	{ XK_NO_MOD,            Button5, kscrolldown,    {.i = 3} },
};
static MouseShortcut maltshortcuts[] = {
	/* mask                 button   function        argument       release */
	{ XK_ANY_MOD,           Button2, clippaste,      {.i = 0},      1 },
	{ XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"} },
	{ XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"} },
};

#define MODKEY Mod1Mask
#define TERMMOD (Mod1Mask|ShiftMask)

static char *urls[] = { "/bin/sh", "-c",
    "xurls | ifne dmenu -l 10 -w $WINDOWID | xargs -r0 xdg-open", NULL };

static char *bufedit[] = { "/bin/sh", "-c",
    "st -e sh -c 'printf \"%s\\n\" \"$0\" | $EDITOR' \"$(cat)\"", NULL };

static Shortcut shortcuts[] = {
	/* mask                 keysym          function         argument */
	{ TERMMOD,              XK_K,           zoom,            {.f = +2} },
	{ TERMMOD,              XK_J,           zoom,            {.f = -2} },
	{ TERMMOD,              XK_N,           zoomreset,       {.f =  0} },
	{ MODKEY,               XK_c,           clipcopy,        {.i =  0} },
	{ MODKEY,               XK_v,           clippaste,       {.i =  0} },
	{ MODKEY,               XK_k,           kscrollup,       {.i =  3} },
	{ MODKEY,               XK_j,           kscrolldown,     {.i =  3} },
	{ MODKEY,               XK_u,           kscrollup,       {.i = 20} },
	{ MODKEY,               XK_d,           kscrolldown,     {.i = 20} },
	{ TERMMOD,              XK_U,           newterm,         {.i =  0} },
	{ MODKEY,               XK_l,           externalpipe,    { .v = urls } },
	{ MODKEY,               XK_o,           externalpipe,    { .v = bufedit } },
};

#include "config.ext.h"
