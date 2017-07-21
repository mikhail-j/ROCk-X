/*
 * Copyright 2012-16 Advanced Micro Devices, Inc.
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


#ifndef _DCE_ABM_H_
#define _DCE_ABM_H_

#include "abm.h"

#define ABM_COMMON_REG_LIST_DCE_BASE() \
	SR(BL_PWM_PERIOD_CNTL), \
	SR(BL_PWM_CNTL), \
	SR(BL_PWM_CNTL2), \
	SR(BL_PWM_GRP1_REG_LOCK), \
	SR(LVTMA_PWRSEQ_REF_DIV), \
	SR(MASTER_COMM_CNTL_REG), \
	SR(MASTER_COMM_CMD_REG), \
	SR(MASTER_COMM_DATA_REG1), \
	SR(DMCU_STATUS)

#define ABM_DCE110_COMMON_REG_LIST() \
	ABM_COMMON_REG_LIST_DCE_BASE(), \
	SR(DC_ABM1_HG_SAMPLE_RATE), \
	SR(DC_ABM1_LS_SAMPLE_RATE), \
	SR(BL1_PWM_BL_UPDATE_SAMPLE_RATE), \
	SR(DC_ABM1_HG_MISC_CTRL), \
	SR(DC_ABM1_IPCSC_COEFF_SEL), \
	SR(BL1_PWM_CURRENT_ABM_LEVEL), \
	SR(BL1_PWM_TARGET_ABM_LEVEL), \
	SR(BL1_PWM_USER_LEVEL), \
	SR(DC_ABM1_LS_MIN_MAX_PIXEL_VALUE_THRES), \
	SR(DC_ABM1_HGLS_REG_READ_PROGRESS), \
	SR(BIOS_SCRATCH_2)

#define ABM_SF(reg_name, field_name, post_fix)\
	.field_name = reg_name ## __ ## field_name ## post_fix

#define ABM_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh) \
	ABM_SF(BL_PWM_PERIOD_CNTL, BL_PWM_PERIOD, mask_sh), \
	ABM_SF(BL_PWM_PERIOD_CNTL, BL_PWM_PERIOD_BITCNT, mask_sh), \
	ABM_SF(BL_PWM_CNTL, BL_ACTIVE_INT_FRAC_CNT, mask_sh), \
	ABM_SF(BL_PWM_CNTL, BL_PWM_FRACTIONAL_EN, mask_sh), \
	ABM_SF(BL_PWM_CNTL, BL_PWM_EN, mask_sh), \
	ABM_SF(BL_PWM_GRP1_REG_LOCK, BL_PWM_GRP1_IGNORE_MASTER_LOCK_EN, mask_sh), \
	ABM_SF(BL_PWM_GRP1_REG_LOCK, BL_PWM_GRP1_REG_LOCK, mask_sh), \
	ABM_SF(BL_PWM_GRP1_REG_LOCK, BL_PWM_GRP1_REG_UPDATE_PENDING, mask_sh), \
	ABM_SF(LVTMA_PWRSEQ_REF_DIV, BL_PWM_REF_DIV, mask_sh), \
	ABM_SF(MASTER_COMM_CNTL_REG, MASTER_COMM_INTERRUPT, mask_sh), \
	ABM_SF(MASTER_COMM_CMD_REG, MASTER_COMM_CMD_REG_BYTE0, mask_sh), \
	ABM_SF(MASTER_COMM_CMD_REG, MASTER_COMM_CMD_REG_BYTE1, mask_sh), \
	ABM_SF(MASTER_COMM_CMD_REG, MASTER_COMM_CMD_REG_BYTE2, mask_sh), \
	ABM_SF(DMCU_STATUS, UC_IN_RESET, mask_sh)

#define ABM_MASK_SH_LIST_DCE110(mask_sh) \
	ABM_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh), \
	ABM_SF(DC_ABM1_HG_MISC_CTRL, \
			ABM1_HG_NUM_OF_BINS_SEL, mask_sh), \
	ABM_SF(DC_ABM1_HG_MISC_CTRL, \
			ABM1_HG_VMAX_SEL, mask_sh), \
	ABM_SF(DC_ABM1_HG_MISC_CTRL, \
			ABM1_HG_BIN_BITWIDTH_SIZE_SEL, mask_sh), \
	ABM_SF(DC_ABM1_IPCSC_COEFF_SEL, \
			ABM1_IPCSC_COEFF_SEL_R, mask_sh), \
	ABM_SF(DC_ABM1_IPCSC_COEFF_SEL, \
			ABM1_IPCSC_COEFF_SEL_G, mask_sh), \
	ABM_SF(DC_ABM1_IPCSC_COEFF_SEL, \
			ABM1_IPCSC_COEFF_SEL_B, mask_sh), \
	ABM_SF(BL1_PWM_CURRENT_ABM_LEVEL, \
			BL1_PWM_CURRENT_ABM_LEVEL, mask_sh), \
	ABM_SF(BL1_PWM_TARGET_ABM_LEVEL, \
			BL1_PWM_TARGET_ABM_LEVEL, mask_sh), \
	ABM_SF(BL1_PWM_USER_LEVEL, \
			BL1_PWM_USER_LEVEL, mask_sh), \
	ABM_SF(DC_ABM1_LS_MIN_MAX_PIXEL_VALUE_THRES, \
			ABM1_LS_MIN_PIXEL_VALUE_THRES, mask_sh), \
	ABM_SF(DC_ABM1_LS_MIN_MAX_PIXEL_VALUE_THRES, \
			ABM1_LS_MAX_PIXEL_VALUE_THRES, mask_sh), \
	ABM_SF(DC_ABM1_HGLS_REG_READ_PROGRESS, \
			ABM1_HG_REG_READ_MISSED_FRAME_CLEAR, mask_sh), \
	ABM_SF(DC_ABM1_HGLS_REG_READ_PROGRESS, \
			ABM1_LS_REG_READ_MISSED_FRAME_CLEAR, mask_sh), \
	ABM_SF(DC_ABM1_HGLS_REG_READ_PROGRESS, \
			ABM1_BL_REG_READ_MISSED_FRAME_CLEAR, mask_sh)


#define ABM_REG_FIELD_LIST(type) \
	type ABM1_HG_NUM_OF_BINS_SEL; \
	type ABM1_HG_VMAX_SEL; \
	type ABM1_HG_BIN_BITWIDTH_SIZE_SEL; \
	type ABM1_IPCSC_COEFF_SEL_R; \
	type ABM1_IPCSC_COEFF_SEL_G; \
	type ABM1_IPCSC_COEFF_SEL_B; \
	type BL1_PWM_CURRENT_ABM_LEVEL; \
	type BL1_PWM_TARGET_ABM_LEVEL; \
	type BL1_PWM_USER_LEVEL; \
	type ABM1_LS_MIN_PIXEL_VALUE_THRES; \
	type ABM1_LS_MAX_PIXEL_VALUE_THRES; \
	type ABM1_HG_REG_READ_MISSED_FRAME_CLEAR; \
	type ABM1_LS_REG_READ_MISSED_FRAME_CLEAR; \
	type ABM1_BL_REG_READ_MISSED_FRAME_CLEAR; \
	type BL_PWM_PERIOD; \
	type BL_PWM_PERIOD_BITCNT; \
	type BL_ACTIVE_INT_FRAC_CNT; \
	type BL_PWM_FRACTIONAL_EN; \
	type MASTER_COMM_INTERRUPT; \
	type MASTER_COMM_CMD_REG_BYTE0; \
	type MASTER_COMM_CMD_REG_BYTE1; \
	type MASTER_COMM_CMD_REG_BYTE2; \
	type BL_PWM_REF_DIV; \
	type BL_PWM_EN; \
	type UC_IN_RESET; \
	type BL_PWM_GRP1_IGNORE_MASTER_LOCK_EN; \
	type BL_PWM_GRP1_REG_LOCK; \
	type BL_PWM_GRP1_REG_UPDATE_PENDING

struct dce_abm_shift {
	ABM_REG_FIELD_LIST(uint8_t);
};

struct dce_abm_mask {
	ABM_REG_FIELD_LIST(uint32_t);
};

struct dce_abm_registers {
	uint32_t BL_PWM_PERIOD_CNTL;
	uint32_t BL_PWM_CNTL;
	uint32_t BL_PWM_CNTL2;
	uint32_t LVTMA_PWRSEQ_REF_DIV;
	uint32_t DC_ABM1_HG_SAMPLE_RATE;
	uint32_t DC_ABM1_LS_SAMPLE_RATE;
	uint32_t BL1_PWM_BL_UPDATE_SAMPLE_RATE;
	uint32_t DC_ABM1_HG_MISC_CTRL;
	uint32_t DC_ABM1_IPCSC_COEFF_SEL;
	uint32_t BL1_PWM_CURRENT_ABM_LEVEL;
	uint32_t BL1_PWM_TARGET_ABM_LEVEL;
	uint32_t BL1_PWM_USER_LEVEL;
	uint32_t DC_ABM1_LS_MIN_MAX_PIXEL_VALUE_THRES;
	uint32_t DC_ABM1_HGLS_REG_READ_PROGRESS;
	uint32_t MASTER_COMM_CNTL_REG;
	uint32_t MASTER_COMM_CMD_REG;
	uint32_t MASTER_COMM_DATA_REG1;
	uint32_t BIOS_SCRATCH_2;
	uint32_t DMCU_STATUS;
	uint32_t BL_PWM_GRP1_REG_LOCK;
};

struct dce_abm {
	struct abm base;
	const struct dce_abm_registers *regs;
	const struct dce_abm_shift *abm_shift;
	const struct dce_abm_mask *abm_mask;
};

struct abm *dce_abm_create(
	struct dc_context *ctx,
	const struct dce_abm_registers *regs,
	const struct dce_abm_shift *abm_shift,
	const struct dce_abm_mask *abm_mask);

void dce_abm_destroy(struct abm **abm);

#endif /* _DCE_ABM_H_ */
