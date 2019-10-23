/* SPDX-License-Identifier: GPL-2.0-only */
/**
 * @brief		OIS system calibration parameters
 *
 * @author		(C) 2019 ON Semiconductor.
 *
 * @file		Calibration_Eve.h
 * @date		svn:$Date:: 2019-09-19 14:22:48 +0900#$
 * @version 	svn:$Revision: 17 $
 * @attention
 **/
#ifndef CALIBRATION_EVE_H_
#define CALIBRATION_EVE_H_

#define	SEL_CLOSED_AF

//********************************************************************************
// defines
//********************************************************************************
#define	XY_BIAS			(0x60000000)
#define	X_OFSTO			(0x80000000)
#define	X_OFSTI			(0x80000000)
#define	Y_OFSTO			(0x80000000)
#define	Y_OFSTI			(0x80000000)
#ifdef SEL_CLOSED_AF
#define	AF_BIAS			(0x80000000)
#define	AF_OFSTO		(0x80000000)
#define	AF_OFSTI		(0x52000000)
#endif

#define	MARGIN			(0x0300)		// Margin

/************ for linearity measurement step ***********/
#define	SLT_OFFSET_X		(0x0FA0)
#define	SLT_OFFSET_Y		(0x0FA0)		// Xと異なる場合注意が必要。
#define	SLT_DIR_X			(-1)			// NVC move direction X
#define	SLT_DIR_Y			(+1)			// NVC move direction Y

/************ Target amplitude ***********/
#define BIAS_ADJ_RANGE_X		(0xCCCC)		//!< 80%
#define BIAS_ADJ_RANGE_Y		(0xCCCC)		//!< 80%
#ifdef	SEL_CLOSED_AF
#define BIAS_ADJ_RANGE_Z		(0x9999)		//!< 60%

#define	HIGH_MARGIN_Z			(0x0000)		//!< 20d in BIAS_ADJ_RANGE_Z(INF) from 0mA
#define	LOW_MARGIN_Z			(0x051E)		//!< 5% in BIAS_ADJ_RANGE_Z(MACRO) from mecha edge
#endif

/* for OIS calibration */
#define	SINE_OFFSET_OIS		0x001230B7		// Freq Setting = Freq * 80000000h / Fs(18k)	: 10Hz
#define	SINE_GAIN_OIS		0x7FFFFFFF		// Set Sine Wave Gain
#define	SINE_NUM_OIS		1801			// Fs / Freq

/* for AF calibration */
#ifdef	SEL_CLOSED_AF
#define	SINE_OFFSET_AF		0x000746AE		// Freq Setting = Freq * 80000000h / Fs(18k)	: 4Hz
// #define	SINE_GAINP_AF		0x66666666		// Set Sine Wave plus Gain about 120mA
// #define	SINE_GAINM_AF		0x26666666		// Set Sine Wave minus Gain about 45mA
#define	SINE_GAINP_AF		0x26666666		// Set Sine Wave plus Gain about 45mA
#define	SINE_GAINM_AF		0x66666666		// Set Sine Wave minus Gain about 120mA
#define	SINE_NUM_AF			4504			// Fs / Freq
#endif

#define DECRE_CAL			(0x0100)		// decrease value

/*********** Default loop gain ***********/
#define	SXGAIN_LOP			(0x30000000 )	// 0.375000
#define	SYGAIN_LOP			(0x30000000 )	// 0.375000
#ifdef SEL_CLOSED_AF
#define	SZGAIN_LOP			(0x30000000 )	// 0.375000
#endif

/* Loop gain adjustment frequency parameter (X) */
#define LOOP_NUM_HX			2402			// 18.014kHz/0.120kHz*16times
#define LOOP_FREQ_HX		0x00DA4897		// 120Hz  = Freq * 80000000h / Fs(18k)
#define LOOP_GAIN_HX		0x0337184F		// -32dB
#define	GAIN_GAP_HX			(1000)			// 20*log(1000/1000)=0dB

/* Loop gain adjustment frequency parameter (Y) */
#define LOOP_NUM_HY			2620			// 18.014kHz/0.110kHz*16times
#define LOOP_FREQ_HY		0x00C817B4		// 110Hz  = Freq * 80000000h / Fs(18k)

#define LOOP_GAIN_HY		0x0337184F		// -32dB
#define	GAIN_GAP_HY			(1000)		// 20*log(1000/1000)=0dB

/* Loop gain adjustment frequency parameter (Z) */
#ifdef	SEL_CLOSED_AF
#define	LOOP_NUM_HZ			1601			// 18.014kHz/0.180kHz*16times	DVT
#define	LOOP_FREQ_HZ		0x01476CE2		// 180Hz  = Freq * 80000000h / Fs(18k)
#define	LOOP_GAIN_HZ		0x02492492		// -35dB
#define	GAIN_GAP_HZ			(1000)		// 20*log(1000/1000)=0dB
#endif

/* Loop gain pass max min range */
#define 	LOOP_MAX_X		(SXGAIN_LOP << 1)	// x2
#define 	LOOP_MIN_X		(SXGAIN_LOP >> 1)	// x0.5
#define 	LOOP_MAX_Y		(SYGAIN_LOP << 1)	// x2
#define 	LOOP_MIN_Y		(SYGAIN_LOP >> 1)	// x0.5
#ifdef	SEL_CLOSED_AF
#define 	LOOP_MAX_Z		(0x70000000)		// x2.5
#define 	LOOP_MIN_Z		(0x10000000)		// x0.35
#endif

//********************************************************************************
// temperature compensation parameters : W0213C
//********************************************************************************
#define	TEMP_RCODEX				0x00000000
#define	TEMP_RCODEY				0x00000000
#define	TEMP_RCODEZ				0x7FFFFFFF
#define	TEMP_SHAG				0x02C80000
#define	TEMP_SHBG				0x037A0000
#define	TEMP_SHCG				0x00000000
#define	TEMP_SHOUTAG			0x00000000
#define	TEMP_SHOUTBG			0x00000000
#define	TEMP_SHAB				0x00003A90
#define	TEMP_SHAC				0x7FFF8AE0
#define	TEMP_SHAA				0x00003A90
#define	TEMP_SHBB				0x0000012B
#define	TEMP_SHBC				0x7FFFFDAA
#define	TEMP_SHBA				0x0000012B
#define	TEMP_SHCB				0x00000000
#define	TEMP_SHCC				0x00000000
#define	TEMP_SHCA				0x00000000
#define	TEMP_TAB				0x00001223
#define	TEMP_TAC				0x7FFFDBB9
#define	TEMP_TAA				0x00001223
#define	TEMP_TBB				0x000147A7
#define	TEMP_TBC				0x7FFD70B3
#define	TEMP_TBA				0x000147A7
#define	TEMP_TEMPOFF			0x1B000000
#define	TEMP_TAG				0x49700000
#define	TEMP_TBG				0xE5700000
#define	TEMP_SHIFTG				0x3FFFFFFF
#define	TEMP_SHOUTAG1			0x00000000
#define	TEMP_SHOUTBG1			0x00000000
#define	TEMP_TCX				0x08
#define	TEMP_TBX				0x00
#define	TEMP_TAX				0x00

//********************************************************************************
// structure for calibration
//********************************************************************************
#ifdef	__OISCMD__
const ADJ_HALL Eve_HallCalParameter[] = {
{
/****** P1 ACT=01 ******/
/* BiasInit */		XY_BIAS,
/* XOffsetInit */	X_OFSTO,
/* XOffsetInitIn */	X_OFSTI,
/* YOffsetInit */	Y_OFSTO,
/* YOffsetInitIn */	Y_OFSTI,
/* Margin */		MARGIN,
/* XTargetRange */	BIAS_ADJ_RANGE_X,
/* XTargetMax */	(BIAS_ADJ_RANGE_X + MARGIN),
/* XTargetMin */	(BIAS_ADJ_RANGE_X - MARGIN),
/* YTargetRange */	BIAS_ADJ_RANGE_Y,
/* YTargetMax */	(BIAS_ADJ_RANGE_Y + MARGIN),
/* YTargetMin */	(BIAS_ADJ_RANGE_Y - MARGIN),
/* OisSinNum */		SINE_NUM_OIS,
/* OisSinFreq */	SINE_OFFSET_OIS,
/* OisSinGain */	SINE_GAIN_OIS,
/* AfSinNum */		SINE_NUM_AF,
/* AfSinFreq */		SINE_OFFSET_AF,
/* AfSinGainP */	SINE_GAINP_AF,
/* AfSinGainM */	SINE_GAINM_AF,
/* DecrementStep */ DECRE_CAL,
#ifdef SEL_CLOSED_AF
/* ZBiasInit */		AF_BIAS,
/* ZOffsetInit */	AF_OFSTO,
/* ZOffsetInitIn */	AF_OFSTI,
/* ZTargetRange */	BIAS_ADJ_RANGE_Z,
/* ZTargetMax */	(BIAS_ADJ_RANGE_Z + MARGIN),
/* ZTargetMin */	(BIAS_ADJ_RANGE_Z - MARGIN),
/* ZHighMargin */	HIGH_MARGIN_Z,
/* ZLowMargin */	LOW_MARGIN_Z,
#endif
} };

const ADJ_LOPGAN Eve_LoopGainParameter[] = {
{
/****** P1 ACT=01 ******/
/* Hxgain */		SXGAIN_LOP,
/* Hygain */		SYGAIN_LOP,
/* XNoiseNum */		LOOP_NUM_HX,
/* XNoiseFreq */	LOOP_FREQ_HX,
/* XNoiseGain */	LOOP_GAIN_HX,
/* XGap  */			GAIN_GAP_HX,
/* YNoiseNum */		LOOP_NUM_HY,
/* YNoiseFreq */	LOOP_FREQ_HY,
/* YNoiseGain */	LOOP_GAIN_HY,
/* YGap  */			GAIN_GAP_HY,
/* XJudgeHigh */ 	LOOP_MAX_X,
/* XJudgeLow  */ 	LOOP_MIN_X,
/* YJudgeHigh */ 	LOOP_MAX_Y,
/* YJudgeLow  */ 	LOOP_MIN_Y,
#ifdef SEL_CLOSED_AF
/* Hzgain */		SZGAIN_LOP,
/* ZNoiseNum */		LOOP_NUM_HZ,
/* ZNoiseFreq */	LOOP_FREQ_HZ,
/* ZNoiseGain */	LOOP_GAIN_HZ,
/* ZGap  */			GAIN_GAP_HZ,
/* ZJudgeHigh */ 	LOOP_MAX_Z,
/* ZJudgeLow  */ 	LOOP_MIN_Z,
#endif
} };

const ADJ_LINEARITY_MIXING Eve_LinMixParameter[] = {
{
/****** P1 ACT=01 ******/
/* SltOffsetX */	SLT_OFFSET_X,
/* SltOffsetY */	SLT_OFFSET_Y,
/* SltDirX */		SLT_DIR_X,
/* SltDirY */		SLT_DIR_Y
} };

#else	// __OISCMD__
extern const ADJ_HALL Eve_HallCalParameter[];
extern const ADJ_LOPGAN Eve_LoopGainParameter[];
extern const ADJ_LINEARITY_MIXING Eve_LinMixParameter[];
#endif	// __OISCMD__

#ifdef	__OISFLSH__
const stAdj_Temp_Compensation Eve_TempCompParameter[] = {
{
/****** P1 ACT=01 ******/
/* rcodeX */	TEMP_RCODEX,
/* rcodeY */	TEMP_RCODEY,
/* rcodeZ */	TEMP_RCODEZ,
/* shag */		TEMP_SHAG,
/* shbg */		TEMP_SHBG,
/* shcg */		TEMP_SHCG,
/* shoutag */	TEMP_SHOUTAG,
/* shoutbg */	TEMP_SHOUTBG,
/* shab */		TEMP_SHAB,
/* shac */		TEMP_SHAC,
/* shaa */		TEMP_SHAA,
/* shbb */		TEMP_SHBB,
/* shbc */		TEMP_SHBC,
/* shba */		TEMP_SHBA,
/* shcb */		TEMP_SHCB,
/* shcc */		TEMP_SHCC,
/* shca */		TEMP_SHCA,
/* tab */		TEMP_TAB,
/* tac */		TEMP_TAC,
/* taa */		TEMP_TAA,
/* tbb */		TEMP_TBB,
/* tbc */		TEMP_TBC,
/* tba */		TEMP_TBA,
/* TEMPOFF */	TEMP_TEMPOFF,
/* tag */		TEMP_TAG,
/* tbg */		TEMP_TBG,
/* shiftg */	TEMP_SHIFTG,
/* shoutag1 */	TEMP_SHOUTAG1,
/* shoutbg1 */	TEMP_SHOUTBG1,
/* tcx */		TEMP_TCX,
/* tbx */		TEMP_TBX,
/* tax */		TEMP_TAX
} };
#else	// __OISFLSH__
extern const stAdj_Temp_Compensation Eve_TempCompParameter[];
#endif	// __OISFLSH__

#undef	SLT_OFFSET_X
#undef	SLT_OFFSET_Y
#undef	SLT_DIR_X
#undef	SLT_DIR_Y

#undef	XY_BIAS
#undef	X_OFSTO
#undef	X_OFSTI
#undef	Y_OFSTO
#undef	Y_OFSTI
#undef 	MARGIN
#undef 	BIAS_ADJ_RANGE_X
#undef 	BIAS_ADJ_RANGE_Y
#undef	SINE_OFFSET
#undef	SINE_GAIN
#undef	SINE_NUM
#undef	SINE_OFFSET_OIS
#undef	SINE_GAIN_OIS
#undef	SINE_NUM_OIS
#undef 	DECRE_CAL
#undef	SXGAIN_LOP
#undef	SYGAIN_LOP
#undef 	LOOP_NUM_HX
#undef 	LOOP_FREQ_HX
#undef 	LOOP_GAIN_HX
#undef	GAIN_GAP_HX
#undef 	LOOP_NUM_HY
#undef 	LOOP_FREQ_HY
#undef 	LOOP_GAIN_HY
#undef	GAIN_GAP_HY
#undef 	LOOP_MAX_X
#undef 	LOOP_MIN_X
#undef 	LOOP_MAX_Y
#undef 	LOOP_MIN_Y

#ifdef	SEL_CLOSED_AF
 #undef	AF_BIAS
 #undef	AF_OFSTO
 #undef	AF_OFSTI
 #undef	BIAS_ADJ_RANGE_Z
 #undef	SZGAIN_LOP
 #undef	SINE_OFFSET_AF
 #undef	SINE_GAINP_AF
 #undef	SINE_GAINM_AF
 #undef	SINE_NUM_AF
 #undef	LOOP_NUM_HZ
 #undef	LOOP_FREQ_HZ
 #undef	LOOP_GAIN_HZ
 #undef	GAIN_GAP_HZ
 #undef	LOOP_MAX_Z
 #undef	LOOP_MIN_Z
 #undef	SEL_CLOSED_AF
 #undef	HIGH_MARGIN_Z
 #undef	LOW_MARGIN_Z
#endif

#undef	TEMP_RCODEX
#undef	TEMP_RCODEY
#undef	TEMP_RCODEZ
#undef	TEMP_SHAG
#undef	TEMP_SHBG
#undef	TEMP_SHCG
#undef	TEMP_SHOUTAG
#undef	TEMP_SHOUTBG
#undef	TEMP_SHAB
#undef	TEMP_SHAC
#undef	TEMP_SHAA
#undef	TEMP_SHBB
#undef	TEMP_SHBC
#undef	TEMP_SHBA
#undef	TEMP_SHCB
#undef	TEMP_SHCC
#undef	TEMP_SHCA
#undef	TEMP_TAB
#undef	TEMP_TAC
#undef	TEMP_TAA
#undef	TEMP_TBB
#undef	TEMP_TBC
#undef	TEMP_TBA
#undef	TEMP_TEMPOFF
#undef	TEMP_TAG
#undef	TEMP_TBG
#undef	TEMP_SHIFTG
#undef	TEMP_TCX
#undef	TEMP_TBX
#undef	TEMP_TAX

#endif	// CALIBRATION_EVE_H_
