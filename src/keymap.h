/* Copyright (c) 1992-2010 John E. Davis
 * This file is part of JED editor library source.
 *
 * You may distribute this file under the terms the GNU General Public
 * License.  See the file COPYING for more information.
 */
#ifndef _JED_KEYMAP_H_
#define _JED_KEYMAP_H_
/*Jed Keymap routines.
 *
 *  The main problem here is how to associate a sequence of characters to a
 *  given function in as fast a way as possible.  In addition, I require that
 *  the procedure be memory efficient as well as allowing the user the
 *  flexability to redefine the keys and add new keymaps.
 *
 *  To do this, I define a key map to be an array of keys.  There may be many
 *  keymaps (global, local, etc...).    A key structure is defined.
 */
#ifdef HAS_MOUSE
typedef struct
{
   int x, y;			       /* row column of mouse event */

#define JMOUSE_UP		1
#define JMOUSE_DOWN		2
#define JMOUSE_DRAG		3
#define JMOUSE_DOUBLE_CLICK	4
#define JMOUSE_TRIPLE_CLICK	5
#define JMOUSE_IGNORE_EVENT	6      /* generated by button up on multiclick. */

   unsigned char type;
   /* Note: The specific values for JMOUSE_BUTTON_? are exploited by the
    * mouse mapping code in mouse.c
    */
#define JMOUSE_BUTTON_1		0x01
#define JMOUSE_BUTTON_2		0x02
#define JMOUSE_BUTTON_3		0x04
#define JMOUSE_BUTTON_4		0x08
#define JMOUSE_BUTTON_5		0x10
#define JMOUSE_BUTTON_6		0x20
#define JMOUSE_SHIFT		0x40
#define JMOUSE_CTRL		0x80
   unsigned char button;	       /* button that triggered event */
   unsigned char state;		       /* button info BEFORE event */
} JMouse_Type;

extern int jed_mouse_cmd (void);
extern void jed_set_default_mouse_hook (char *, char *);
extern void jed_set_current_mouse_window (void);
extern int jed_mouse_add_event (JMouse_Type *);
extern void jed_flush_mouse_queue (void);
extern void jed_mouse_get_event_info (void);
extern void jed_map_mouse_buttons (int *, int *);
#endif

extern SLKeyMap_List_Type *Global_Map;
extern SLKeyMap_List_Type *Jed_Current_Keymap;

extern void init_keymaps(void);
extern int digit_arg(void);
extern void do_jed(void);
extern void jed(void);
extern int jed_do_key (void);
extern int kbd_quit(void);
extern FVOID_STAR Last_Key_Function;
extern FVOID_STAR Jed_This_Key_Function;
extern int *Repeat_Factor;
extern void jed_call_cmd (char *);

extern void jed_set_abort_char(int *);
extern int next_function_list(char *);
extern int open_function_list(char *);

extern char *Read_This_Character;      /* alternate keyboard buffer */
extern int add_to_completion(char *);
extern int is_internal(char *);

extern void create_keymap (char *);
extern char Key_Buffer[SLANG_MAX_KEYMAP_KEY_SEQ + 1];
extern char Jed_Key_Buffer[SLANG_MAX_KEYMAP_KEY_SEQ + 1];
extern char *Key_Bufferp;
extern int jed_beep (void);
extern void set_current_kbd_command (char *);
extern char Current_Kbd_Command_String[32];
extern char Last_Kbd_Command_String[32];

extern unsigned char Jed_Abort_Char;
extern int Jed_Max_Hits;

extern int jed_init_keymap_intrinsics (void);

#endif

