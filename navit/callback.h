/**
 * Navit, a modular navigation system.
 * Copyright (C) 2005-2008 Navit Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 */

#ifndef NAVIT_CALLBACK_H
#define NAVIT_CALLBACK_H

#include "item.h"
#include "attr.h"

#ifdef __cplusplus
extern "C" {
#endif
/* prototypes */
enum attr_type;

struct callback
{
	void (*func)();
	char func_name[400]; // function name as string (function that will be called)
	char setup_func_name[400]; // function name as string (function that created the callback)
	int pcount;
	enum attr_type type;
	void *p[0];
};

struct callback_list
{
	char cb_name[400]; // callbacklist "function:name"
	GList *list;
};

void callback_dump_callbacks();
struct callback_list *callback_list_new(char *name);
struct callback *callback_new_attr(void (*func)(void), enum attr_type type, int pcount, void **p);
struct callback *callback_new_attr_args(const char *module, const int mlen,const char *function, void (*func)(void), enum attr_type type, int count, ...);
struct callback *callback_new(void (*func)(void), int pcount, void **p);
struct callback *callback_new_args(const char *module, const int mlen,const char *function, void (*func)(void), int count, ...);
void callback_destroy_real(const char *module, const int mlen,const char *function, struct callback *cb);
void callback_set_arg(struct callback *cb, int arg, void *p);
// void callback_list_add(struct callback_list *l, struct callback *cb);
void callback_list_add_2(const char *module, const int mlen,const char *function, struct callback_list *l, struct callback *cb);
struct callback *callback_list_add_new(struct callback_list *l, void (*func)(void), int pcount, void **p);
void callback_add_names(struct callback *cb, const char *parent_name, const char *func_name);
// void callback_list_remove(struct callback_list *l, struct callback *cb);
void callback_list_remove_2(const char *module, const int mlen,const char *function, struct callback_list *l, struct callback *cb);
void callback_list_remove_destroy(struct callback_list *l, struct callback *cb);
void callback_call(struct callback *cb, int pcount, void **p);
void callback_call_args_real(const char *module, const int mlen,const char *function, struct callback *cb, int count, ...);
void callback_list_call_attr(struct callback_list *l, enum attr_type type, int pcount, void **p);
void callback_list_call_attr_args(const char *module, const int mlen,const char *function, struct callback_list *cbl, enum attr_type type, int count, ...);
void callback_list_call(struct callback_list *l, int pcount, void **p);
void callback_list_call_args(const char *module, const int mlen,const char *function, struct callback_list *cbl, int count, ...);
void callback_list_destroy(struct callback_list *l);
/* end of prototypes */

#define callback_destroy(cb) callback_destroy_real(__FILE__,__LINE__,__PRETTY_FUNCTION__,cb)

#define callback_call_args(cb, count, ...) callback_call_args_real(__FILE__,__LINE__,__PRETTY_FUNCTION__,cb, count, __VA_ARGS__)

#define callback_list_add(l, cb) callback_list_add_2(__FILE__,__LINE__,__PRETTY_FUNCTION__,l,cb)
#define callback_list_remove(l, cb) callback_list_remove_2(__FILE__,__LINE__,__PRETTY_FUNCTION__,l,cb)


#define callback_new_0(func) callback_new_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,func, 0)
#define callback_new_1(func,p1) callback_new_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,func, 1, p1)
#define callback_new_2(func,p1,p2) callback_new_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,func, 2, p1, p2)
#define callback_new_3(func,p1,p2,p3) callback_new_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,func, 3, p1, p2, p3)
#define callback_new_4(func,p1,p2,p3,p4) callback_new_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,func, 4, p1, p2, p3, p4)

#define callback_new_attr_0(func,type) callback_new_attr_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,func, type, 0)
#define callback_new_attr_1(func,type,p1) callback_new_attr_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,func, type, 1, p1)
#define callback_new_attr_2(func,type,p1,p2) callback_new_attr_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,func, type, 2, p1, p2)
#define callback_new_attr_3(func,type,p1,p2,p3) callback_new_attr_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,func, type, 3, p1, p2, p3)
#define callback_new_attr_4(func,type,p1,p2,p3,p4) callback_new_attr_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,func, type, 4, p1, p2, p3, p4)

#define callback_call_0(cb) callback_call_args_real(__FILE__,__LINE__,__PRETTY_FUNCTION__,cb, 0)
#define callback_call_1(cb,p1) callback_call_args(cb, 1, p1)
#define callback_call_2(cb,p1,p2) callback_call_args(cb, 2, p1, p2)
#define callback_call_3(cb,p1,p2,p3) callback_call_args(cb, 3, p1, p2, p3)
#define callback_call_4(cb,p1,p2,p3,p4) callback_call_args(cb, 4, p1, p2, p3, p4)

#define callback_list_call_0(cbl) callback_list_call_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,cbl, 0)
#define callback_list_call_1(cbl,p1) callback_list_call_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,cbl, 1, p1)
#define callback_list_call_2(cbl,p1,p2) callback_list_call_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,cbl, 2, p1, p2)
#define callback_list_call_3(cbl,p1,p2,p3) callback_list_call_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,cbl, 3, p1, p2, p3)
#define callback_list_call_4(cbl,p1,p2,p3,p4) callback_list_call_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,cbl, 4, p1, p2, p3, p4)

#define callback_list_call_attr_0(cbl,type) callback_list_call_attr_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,cbl,type, 0)
#define callback_list_call_attr_1(cbl,type,p1) callback_list_call_attr_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,cbl, type, 1, p1)
#define callback_list_call_attr_2(cbl,type,p1,p2) callback_list_call_attr_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,cbl, type, 2, p1, p2)
#define callback_list_call_attr_3(cbl,type,p1,p2,p3) callback_list_call_attr_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,cbl, type, 3, p1, p2, p3)
#define callback_list_call_attr_4(cbl,type,p1,p2,p3,p4) callback_list_call_attr_args(__FILE__,__LINE__,__PRETTY_FUNCTION__,cbl, type, 4, p1, p2, p3, p4)

#define callback_cast(x) (void (*)(void))(x)
#ifdef __cplusplus
}
#endif

#endif

