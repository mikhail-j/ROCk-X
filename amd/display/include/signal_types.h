/*
 * Copyright 2012-15 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DC_SIGNAL_TYPES_H__
#define __DC_SIGNAL_TYPES_H__

enum signal_type {
	SIGNAL_TYPE_NONE		= 0L,		/* no signal */
	SIGNAL_TYPE_DVI_SINGLE_LINK	= (1 << 0),
	SIGNAL_TYPE_DVI_DUAL_LINK	= (1 << 1),
	SIGNAL_TYPE_HDMI_TYPE_A		= (1 << 2),
	SIGNAL_TYPE_LVDS		= (1 << 3),
	SIGNAL_TYPE_RGB			= (1 << 4),
	SIGNAL_TYPE_DISPLAY_PORT	= (1 << 5),
	SIGNAL_TYPE_DISPLAY_PORT_MST	= (1 << 6),
	SIGNAL_TYPE_EDP			= (1 << 7),
	SIGNAL_TYPE_VIRTUAL		= (1 << 9),	/* Virtual Display */
};

/* help functions for signal types manipulation */
bool dc_is_hdmi_signal(enum signal_type signal);
bool dc_is_dp_sst_signal(enum signal_type signal);
bool dc_is_dp_signal(enum signal_type signal);
bool dc_is_embedded_signal(enum signal_type signal);
bool dc_is_dvi_signal(enum signal_type signal);
bool dc_is_dvi_single_link_signal(enum signal_type signal);
bool dc_is_dual_link_signal(enum signal_type signal);
bool dc_is_audio_capable_signal(enum signal_type signal);

#endif
