[TOC]

#ARM Instruction[^ref]#
##1. Instruction Set##
###1.1 Encoding###
* Bit 31-28: cond
* Bit 27-25: function selector
* Bit 24-21: opcode
* Bit 20: S/L

####1.1.1 Function Selector####
* 0 0 0
	* Bit7=x, Bit4=0
		* Bit24=1, Bit23=0, Bit20=0: Miscellanceous instructions
		* Others: Data processing immediate shift
	* Bit7=0, Bit4=1
		* Bit24=1, Bit23=0, Bit20=0: Miscellanceous instructions
		* Others: Data processing register shift
	* Bit7=1, Bit4=1: Multiplies or Extra load/store
* 0 0 1
	* Bit24=1, Bit23=0, Bit21=0: Undefined instruction
	* Bit24=1, Bit23=0, Bit21=1: Move immediate to status register
	* Others: Data processing immediate
* 0 1 0: Load/store immediate offset
* 0 1 1
	* Bit4=0: Load/store register offset
	* Bit4=1: Media instructions
* 1 0 0
	* Load/store multiple
* 1 0 1
	* Branch and branck with link
* 1 1 0
	* Coprocessor load/store and double register transfers
* 1 1 1
	* Bit24=0
		* Bit4=0: Coprocessor data processing
		* Bit4=1: Coprocessor register transfers
	* Bit24=1
		* Software interrupt (SWI)

####1.1.2 Shifter\_operand####
Bit 11~0 is the shifter\_operand. Bit 7 and 4 are shifter\_operand function selector.

| Bit7 | Bit4 | function  | encoding                              |
|------|------|-----------|---------------------------------------|
| x    | 0    | imm shift | shift amount (5) shift (2) 0(1) Rm(4) |
| 0    | 1    | reg shift | Rs(4) 0(1) shift(2) 1(1) Rm(4)        |
| 1    | 1    | other     |                                       |

###1.2 Data-processing instruction###
| Opcode | Mnemonic | Operation | Action |
|--------|----------|-----------|--------|
| 0000   | AND      |
| 0001   | EOR      |
| 0010   | SUB      |
| 0011   | RSB      |
| 0100   | ADD      |
| 0101   | ADC      |
| 0110   | SBC      |
| 0111   | RSC      |
| 1000   | TST      |
| 1001   | TEQ      |
| 1010   | CMP      |
| 1011   | CMN      |
| 1100   | ORR      |
| 1101   | MOV      |
| 1110   | BIC      |
| 1111   | MVN      |


[^ref]: Ref to "ARM Architecture Reference Manual" (ARM DDI 0100I)