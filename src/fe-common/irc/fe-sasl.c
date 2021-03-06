/*
    fe-sasl.c : irssi

    Copyright (C) 2015 The Lemon Man

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "module.h"
#include "module-formats.h"
#include "signals.h"
#include "levels.h"

#include "printtext.h"

static void sig_sasl_success(IRC_SERVER_REC *server)
{
	printformat(server, NULL, MSGLEVEL_CRAP, IRCTXT_SASL_SUCCESS);
}

static void sig_sasl_failure(IRC_SERVER_REC *server, const char *reason)
{
	printformat(server, NULL, MSGLEVEL_CRAP, IRCTXT_SASL_ERROR, reason);
}

void fe_sasl_init(void)
{
	signal_add("server sasl success", (SIGNAL_FUNC) sig_sasl_success);
	signal_add("server sasl failure", (SIGNAL_FUNC) sig_sasl_failure);
}

void fe_sasl_deinit(void)
{
	signal_remove("server sasl success", (SIGNAL_FUNC) sig_sasl_success);
	signal_remove("server sasl failure", (SIGNAL_FUNC) sig_sasl_failure);
}
