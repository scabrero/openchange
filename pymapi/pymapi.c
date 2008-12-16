/*
   OpenChange MAPI implementation.

   Copyright (C) Jelmer Vernooij <jelmer@openchange.org> 2008.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "pymapi/pymapi.h"

void initmapi(void);

static PyMethodDef mapi_methods[] = {
	{ NULL }
};

void initmapi(void)
{
	PyObject *m;

	if (PyType_Ready(&PyMapiSessionType) < 0)
		return;

	if (PyType_Ready(&PyMapiObjectType) < 0)
		return;

	if (PyType_Ready(&PyMapiMsgStoreType) < 0)
		return;

	m = Py_InitModule3("mapi", mapi_methods, "MAPI/RPC Python bindings");
	if (m == NULL)
		return;

	Py_INCREF((PyObject *)&PyMapiSessionType);
	PyModule_AddObject(m, "Session", (PyObject *)&PyMapiSessionType);

	Py_INCREF((PyObject *)&PyMapiObjectType);
	PyModule_AddObject(m, "Object", (PyObject *)&PyMapiObjectType);

	Py_INCREF((PyObject *)&PyMapiMsgStoreType);
	PyModule_AddObject(m, "MessageStore", (PyObject *)&PyMapiMsgStoreType);
}