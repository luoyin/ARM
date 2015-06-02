#ifndef __ARM_INS_H__
#define __ARM_INS_H__

enum _arm_ins_condition {
	_ARM_INS_COND_EQ=0,			// 0000
	_ARM_INS_COND_NE,				// 0001
	_ARM_INS_COND_CS_HS,			// 0010
	_ARM_INS_COND_CC_LO,			// 0011
	_ARM_INS_COND_MI,				// 0100
	_ARM_INS_COND_PL,				// 0101
	_ARM_INS_COND_VS,				// 0110
	_ARM_INS_COND_VC,				// 0111
	_ARM_INS_COND_HI,				// 1000
	_ARM_INS_COND_LS,				// 1001
	_ARM_INS_COND_GE,				// 1010
	_ARM_INS_COND_LT,				// 1011
	_ARM_INS_COND_GT,				// 1100
	_ARM_INS_COND_LE,				// 1101
	_ARM_INS_COND_AL,				// 1110
	_ARM_INS_COND_UP,				// 1111		(Unpredictable)
} _ARM_INS_CONDITION;

enum _arm_ins_opcode {
	_ARM_INS_OP_AND=0,			// 0000
	_ARM_INS_OP_EOR=1,			// 0001
	_ARM_INS_OP_SUB=2,			// 0010
	_ARM_INS_OP_RSB=3,			// 0011
	_ARM_INS_OP_ADD=4,			// 0100
	_ARM_INS_OP_ADC=5,			// 0101
	_ARM_INS_OP_SBC=6,			// 0110
	_ARM_INS_OP_RSC=7,			// 0111
	_ARM_INS_OP_TST=8,			// 1000
	_ARM_INS_OP_TEQ=9,			// 1001
	_ARM_INS_OP_CMP=10,			// 1010
	_ARM_INS_OP_CMN=11,			// 1011
	_ARM_INS_OP_ORR=12,			// 1100
	_ARM_INS_OP_MOV=13,			// 1101
	_ARM_INS_OP_BIC=14,			// 1110
	_ARM_INS_OP_MVN=15,			// 1111
} _ARM_INS_OPCODE;

/*
 * <opcode1>{<cond>}{S} <Rd>, <shifter_operand>
 * <opcode2>{<cond>} <Rn>, <shifter_operand>
 * <opcode1>{<cond>}{S} <Rd>, <Rn>, <shifter_operand>
*/
enum _arm_ins_opcode_class {
	_ARM_INS_OP_CLASS1,			// MOV, MVN
	_ARM_INS_OP_CLASS2,			// CMP, CMN, TST, TEQ
	_ARM_INS_OP_CLASS3,			// ADD, SUB, RSB, ADC, SBC, RSC, AND, BIC, EOR, ORR
} _ARM_INS_CLASS;

// 指令类型确定
//   (指令码 & TYPE_MASK1)^TYPE_MASK2
//     =0: 为该类型
//     !=0: 不为该类型

// selector
enum _arm_ins_type_mask1 {
	_ARM_INS_TM1_DPIS			=0x0E000010,			// 0000 1110 0000 0000 0000 0000 0001 0000
	_ARM_INS_TM1_MISC1		=0x0F900010,			// 0000 1111 1001 0000 0000 0000 0001 0000
	_ARM_INS_TM1_DPRS			=0x0E000090,			// 0000 1110 0000 0000 0000 0000 1001 0000
	_ARM_INS_TM1_MISC2		=0x0F900090,			// 0000 1111 1001 0000 0000 0000 1001 0000
	_ARM_INS_TM1_MUL_EXLS	=0x0E000090,			// 0000 1110 0000 0000 0000 0000 1001 0000
	_ARM_INS_TM1_DPI 			=0x0E000000,			// 0000 1110 0000 0000 0000 0000 0000 0000
	_ARM_INS_TM1_UNI			=0x0FB00000,			// 0000 1111 1011 0000 0000 0000 0000 0000
	_ARM_INS_TM1_MISR			=0x0FB00000,			// 0000 1111 1011 0000 0000 0000 0000 0000
	_ARM_INS_TM1_LSIO			=0x0E000000,			// 0000 1110 0000 0000 0000 0000 0000 0000
	_ARM_INS_TM1_LSRO			=0x0E000010,			// 0000 1110 0000 0000 0000 0000 0001 0000
	_ARM_INS_TM1_MEDIA		=0x0E000010,			// 0000 1110 0000 0000 0000 0000 0001 0000
	_ARM_INS_TM1_ARCH_U		=0x0FF000F0,			// 0000 1111 1111 0000 0000 0000 1111 0000
	_ARM_INS_TM1_LSM			=0x0E000000,			// 0000 1110 0000 0000 0000 0000 0000 0000
	_ARM_INS_TM1_BRANCH		=0x0E000000,			// 0000 1110 0000 0000 0000 0000 0000 0000
	_ARM_INS_TM1_CLST			=0x0E000000,			// 0000 1110 0000 0000 0000 0000 0000 0000
	_ARM_INS_TM1_CDP			=0x0F000010,			// 0000 1111 0000 0000 0000 0000 0001 0000
	_ARM_INS_TM1_CRT			=0x0F000010,			// 0000 1111 0000 0000 0000 0000 0001 0000
	_ARM_INS_TM1_SWI			=0x0F000000,			// 0000 1111 0000 0000 0000 0000 0001 0000
	_ARM_INS_TM1_UCI			=0xF0000000,			// 1111 0000 0000 0000 0000 0000 0000 0000
} _ARM_INS_TYPE_MASK1;

// comparator
enum _arm_ins_type_mask2 {
	_ARM_INS_TM2_DPIS			=0x00000000,			// 0000 000x xxxx xxxx xxxx xxxx xxx0 xxxx
	_ARM_INS_TM2_MISC1		=0x01000000,			// 0000 0001 0xx0 xxxx xxxx xxxx xxx0 xxxx
	_ARM_INS_TM2_DPRS			=0x00000010,			// 0000 000x xxxx xxxx xxxx xxxx 0xx1 xxxx
	_ARM_INS_TM2_MISC2		=0x01000010,			// 0000 0001 0xx0 xxxx xxxx xxxx 0xx1 xxxx
	_ARM_INS_TM2_MUL_EXLS 	=0x00000090,			// 0000 000x xxxx xxxx xxxx xxxx 1xx1 xxxx
	_ARM_INS_TM2_DPI 			=0x02000000,			// 0000 001x xxxx xxxx xxxx xxxx xxxx xxxx
	_ARM_INS_TM2_UNI     		=0x03000000,			// 0000 0011 0x00 xxxx xxxx xxxx xxxx xxxx
	_ARM_INS_TM2_MISR			=0x03200000,			// 0000 0011 0x10 xxxx xxxx xxxx xxxx xxxx
	_ARM_INS_TM2_LSIO			=0x04000000,			// 0000 010x xxxx xxxx xxxx xxxx xxxx xxxx
	_ARM_INS_TM2_LSRO			=0x06000000,			// 0000 011x xxxx xxxx xxxx xxxx xxx0 xxxx
	_ARM_INS_TM2_MEDIA		=0x06000010,			// 0000 011x xxxx xxxx xxxx xxxx xxx1 xxxx
	_ARM_INS_TM2_ARCH_U		=0x07F000F0,			// 0000 0111 1111 xxxx xxxx xxxx 1111 xxxx
	_ARM_INS_TM2_LSM			=0x08000000,			// 0000 100x xxxx xxxx xxxx xxxx xxxx xxxx
	_ARM_INS_TM2_BRANCH		=0x0A000000,			// 0000 101x xxxx xxxx xxxx xxxx xxxx xxxx
	_ARM_INS_TM2_CLST			=0x0C000000,			// 0000 110x xxxx xxxx xxxx xxxx xxxx xxxx
	_ARM_INS_TM2_CDP			=0x0E000000,			// 0000 1110 xxxx xxxx xxxx xxxx xxx0 xxxx
	_ARM_INS_TM2_CRT			=0x0E000010,			// 0000 1110 xxxx xxxx xxxx xxxx xxx1 xxxx
	_ARM_INS_TM2_SWI			=0x0F000000,			// 0000 1111 xxxx xxxx xxxx xxxx xxxx xxxx
	_ARM_INS_TM2_UCI			=0xF0000000,			// 1111 xxxx xxxx xxxx xxxx xxxx xxxx xxxx
} _ARM_INS_TYPE_MASK2;

#endif
