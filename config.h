/* See LICENSE file for copyright and license details. */

static char *font = "Fira Mono:pixelsize=16:antialias=true:autohint=true";
static char *font2[] = {
	"Hack Nerd Font Mono:pixelsize=16:antialias=true:autohint=true",
	"DejaVu Sans Mono:pixelsize=16:antialias=true:autohint=true",
	"JoyPixels:pixelsize=12:antialias=true:autohint=true",
	"Braille:pixelsize=16:antialias=true:autohint=true",
	"Vazir:pixelsize=16:antialias=true:autohint=true",
};

static unsigned int cursorthickness = 1;
static int borderpx = 10;
float alpha = 0.90;

static float cwscale = 1.0;
static float chscale = 1.0;

static MouseShortcut mshortcuts[] = {
	/* mask                 button   function        argument       release */
	{ ShiftMask,            Button4, ttysend,        {.s = "\033[5;2~"} },
	{ ShiftMask,            Button5, ttysend,        {.s = "\033[6;2~"} },
};

#define MODKEY Mod1Mask
#define TERMMOD (Mod1Mask|ShiftMask)

static Shortcut shortcuts[] = {
	/* mask                 keysym          function         argument */
	{ TERMMOD,              XK_K,           zoom,            {.f = +2} },
	{ TERMMOD,              XK_J,           zoom,            {.f = -2} },
	{ TERMMOD,              XK_N,           zoomreset,       {.f =  0} },
	{ MODKEY,               XK_c,           clipcopy,        {.i =  0} },
	{ MODKEY,               XK_v,           clippaste,       {.i =  0} },
	{ TERMMOD,              XK_U,           newterm,         {.i =  0} },
};

#include "config.ext.h"
