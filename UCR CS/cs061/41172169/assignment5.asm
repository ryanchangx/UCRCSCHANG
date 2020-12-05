;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Ryan Chang
; Email: rchan123@ucr.edu
; 
; Assignment name: Assignment 5
; Lab section: B21
; TA: Jason Goulding
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================

.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------
;-------------------------------
;INSERT CODE STARTING FROM HERE
;-------------------------------
ALL_THE_WAY_UP
LD R6, MENU_4000	; Menu Subroutine. Outputs Menu and returns value 1-7. Keeps asking if invalid.
JSRR R6	
					
					; R3 is the throwaway register
ADD R3,R1,#-1
BRz SR1

ADD R3,R1,#-2
BRz SR2

ADD R3,R1,#-3
BRz SR3

ADD R3,R1,#-4
BRz SR4

ADD R3,R1,#-5
BRz SR5

ADD R3,R1,#-6
BRz SR6

ADD R3,R1,#-7		; if R1 is 7, then HALT
BRz SR7

TO_HALT
HALT

SR1
	LD R6, ALL_MACHINES_BUSY_4300
	JSRR R6
		ADD R2,R2,#-1
		BRnp SKIP_BUSY
			LEA R0, allbusy
			PUTS
		BR END_SR1
		SKIP_BUSY
			LEA R0, allnotbusy
			PUTS
		END_SR1
BR ALL_THE_WAY_UP

SR2
	LD R6, ALL_MACHINES_FREE_4500
	JSRR R6
		ADD R2,R2,#-1
		BRnp SKIP_FREE
			LEA R0, allfree
			PUTS
		BR END_SR2
		SKIP_FREE
			LEA R0, allnotfree
			PUTS
		END_SR2
BR ALL_THE_WAY_UP

SR3
	LD R6, NUM_BUSY_MACHINES_4700
	JSRR R6
	LEA R0, busymachine1
	PUTS
	LD R6, PRINT_NUM_5900
	JSRR R6
	LEA R0,	busymachine2
	PUTS
BR ALL_THE_WAY_UP

SR4
	LD R6, NUM_FREE_MACHINES_4900
	JSRR R6
	LEA R0, freemachine1
	PUTS
	LD R6, PRINT_NUM_5900
	JSRR R6
	LEA R0, freemachine2
	PUTS
BR ALL_THE_WAY_UP

SR5
	LD R6, GET_MACHINE_NUM_5500
	JSRR R6
	LD R6, MACHINE_STATUS_5100
	JSRR R6
	LEA R0, status1
	PUTS
	ADD R2,R2,#-1
	BRnp BUSY_MS
		LD R6, PRINT_NUM_5900
		JSRR R6
		LEA R0, status3
		PUTS
	BR SKIP_BUSY_MS
	BUSY_MS
		LD R6, PRINT_NUM_5900
		JSRR R6
		LEA R0, status2
		PUTS		
	SKIP_BUSY_MS
BR ALL_THE_WAY_UP

SR6
	LD R6, FIRST_FREE_5300
	JSRR R6
	ADD R0,R1,#1
	BRnp FOUND_MACHINE
		LEA R0, firstfree2
		PUTS
	BR SKIP_FOUND_MACHINE
	FOUND_MACHINE
		LEA R0, firstfree1
		PUTS
		LD R6, PRINT_NUM_5900
		JSRR R6
		LD R0, newline
		OUT
	SKIP_FOUND_MACHINE
BR ALL_THE_WAY_UP
	
SR7
	LEA R0, goodbye
	PUTS
BR TO_HALT

;---------------	
;Data
;---------------
;Subroutine pointers
MENU_4000				.FILL x4000
ALL_MACHINES_BUSY_4300	.FILL x4300
ALL_MACHINES_FREE_4500	.FILL x4500
NUM_BUSY_MACHINES_4700	.FILL x4700
NUM_FREE_MACHINES_4900	.FILL x4900
MACHINE_STATUS_5100		.FILL x5100
FIRST_FREE_5300 		.FILL x5300
GET_MACHINE_NUM_5500	.FILL x5500
PRINT_NUM_5900			.FILL x5900

;Other data 
newline 		.fill '\n'

; Strings for reports from menu subroutines:
goodbye         .stringz "Goodbye!\n"
allbusy         .stringz "All machines are busy\n"
allnotbusy      .stringz "Not all machines are busy\n"
allfree         .stringz "All machines are free\n"
allnotfree		.stringz "Not all machines are free\n"
busymachine1    .stringz "There are "
busymachine2    .stringz " busy machines\n"
freemachine1    .stringz "There are "
freemachine2    .stringz " free machines\n"
status1         .stringz "Machine "
status2		    .stringz " is busy\n"
status3		    .stringz " is free\n"
firstfree1      .stringz "The first available machine is number "
firstfree2      .stringz "No machines are free\n"


;-----------------------------------------------------------------------------------------------------------------
; Subroutine: MENU_4000
; Inputs: None
; Postcondition: The subroutine has printed out a menu with numerical options, invited the
;                user to select an option, and returned the selected option.
; Return Value (R1): The option selected:  #1, #2, #3, #4, #5, #6 or #7 (as a number, not a character)
;                    no other return value is possible
;-----------------------------------------------------------------------------------------------------------------
.ORIG x4000
;-------------------------------
;INSERT CODE For Subroutine MENU
;--------------------------------
;HINT back up		; DO NOT BACKUP R1 AS IT IS THE RETURN VALUE
ST R0, BACKUP_R0_0
ST R2, BACKUP_R2_0
ST R6, BACKUP_R6_0
ST R7, BACKUP_R7_0

;INSTRUCTIONS
TO_MENU
LD R0, Menu_string_addr
PUTS

GETC
OUT
;MAKE NUMBER
LD R6, ZERO_0
NOT R6,R6
ADD R6,R6,#1
ADD R0,R0,R6

; CHECK FOR LESS THAN 0
ADD R1,R0,#0
BRnz TO_ERROR
; CHECK FOR MORE THAN 7
ADD R6,R1,#-7
BRp TO_ERROR

LD R0, NEWLINE_0
OUT

;HINT Restore
LD R0, BACKUP_R0_0
LD R2, BACKUP_R2_0		; just in case others call and use R2.
LD R6, BACKUP_R6_0
LD R7, BACKUP_R7_0

;RETURN, value is in R1
RET

TO_ERROR
LD R0, NEWLINE_0
OUT
LEA R0, Error_msg_1
PUTS
BR TO_MENU

;--------------------------------
;Data for subroutine MENU
;--------------------------------
NEWLINE_0			.FILL 	'\n'
ZERO_0				.FILL	x30
SEVEN_0				.FILL	x37
TEMP_MENU			.BLKW	#1
BACKUP_R0_0			.BLKW	#1
BACKUP_R2_0			.BLKW	#1
BACKUP_R6_0			.BLKW 	#1
BACKUP_R7_0			.BLKW 	#1
Error_msg_1	      .STRINGZ "INVALID INPUT\n"
Menu_string_addr  .FILL x6400

;-----------------------------------------------------------------------------------------------------------------
; Subroutine: ALL_MACHINES_BUSY_4300 (#1)
; Inputs: None
; Postcondition: The subroutine has returned a value indicating whether all machines are busy
; Return value (R2): 1 if all machines are busy, 0 otherwise
;-----------------------------------------------------------------------------------------------------------------
.ORIG x4300
;-------------------------------
;INSERT CODE For Subroutine ALL_MACHINES_BUSY
;--------------------------------
;BACKUP
ST R7, BACKUP_R7_ALL_MACHINES_BUSY
;INSTRUCTIONS
	;ALGORITHM
		;CHECK IF IT IS NEGATIVE (1)
			; IF TRUE, IMPLIES A MACHINE IS FREE, IMMEDIATELY RETURN 0.
		;ELSE LEFT SHIFT
LDI R2, BUSYNESS_ADDR_ALL_MACHINES_BUSY	;DO NOT Restore the value of R2 back into the vector.

WHILE_AMB
ADD R2,R2,#0
BRn IS_FREE_AMB
ADD R2,R2,R2
BRnp WHILE_AMB	; if 0, that means that all MACHINES are busy.
AND R2,R2,x0
ADD R2,R2,#1
TO_RET_AMB
;RESTORE
LD R7, BACKUP_R7_ALL_MACHINES_BUSY
;RETURN
RET
IS_FREE_AMB
	AND R2,R2,x0
BR TO_RET_AMB

;--------------------------------
;Data for subroutine ALL_MACHINES_BUSY
;--------------------------------
BACKUP_R7_ALL_MACHINES_BUSY		.BLKW	#1
BUSYNESS_ADDR_ALL_MACHINES_BUSY .Fill xB200

;-----------------------------------------------------------------------------------------------------------------
; Subroutine: ALL_MACHINES_FREE_4500 (#2)
; Inputs: None
; Postcondition: The subroutine has returned a value indicating whether all machines are free
; Return value (R2): 1 if all machines are free, 0 otherwise
;-----------------------------------------------------------------------------------------------------------------
.ORIG x4500
;-------------------------------
;INSERT CODE For Subroutine ALL_MACHINES_FREE
;--------------------------------
;BACKUP
ST R3, BACKUP_R3_ALL_MACHINES_FREE
ST R7, BACKUP_R7_ALL_MACHINES_FREE
;INSTRUCTIONS
	;ALGORITHM
		;CHECK IF IT IS POSITIVE (0)
			; IF TRUE, IMPLIES A MACHINE IS FREE, IMMEDIATELY RETURN 0.
		;ELSE LEFT SHIFT
LDI R2, BUSYNESS_ADDR_ALL_MACHINES_FREE
LD R3, COUNTER_AMF
WHILE_AMF
ADD R2,R2,#0
BRzp IS_BUSY
ADD R2,R2,R2
ADD R3,R3,#-1
BRp WHILE_AMF
AND R2,R2,x0
ADD R2,R2,#1
TO_RET_AMF
;RESTORE
LD R3, BACKUP_R3_ALL_MACHINES_FREE
LD R7, BACKUP_R7_ALL_MACHINES_FREE
;RETURN
RET

IS_BUSY
	AND R2,R2,x0
BR TO_RET_AMF
;--------------------------------
;Data for subroutine ALL_MACHINES_FREE
;--------------------------------
COUNTER_AMF						.FILL #16
BACKUP_R3_ALL_MACHINES_FREE		.BLKW #1
BACKUP_R7_ALL_MACHINES_FREE		.BLKW #1
BUSYNESS_ADDR_ALL_MACHINES_FREE .Fill xB200

;-----------------------------------------------------------------------------------------------------------------
; Subroutine: NUM_BUSY_MACHINES_4700 (#3)
; Inputs: None
; Postcondition: The subroutine has returned the number of busy machines.
; Return Value (R1): The number of machines that are busy (0)
;-----------------------------------------------------------------------------------------------------------------
.ORIG x4700				; WHY IS THIS ALWAYS RETURNING 16???
;-------------------------------
;INSERT CODE For Subroutine NUM_BUSY_MACHINES
;--------------------------------
;BACKUP
ST R2, BACKUP_R2_NUM_BUSY_MACHINES
ST R3, BACKUP_R3_NUM_BUSY_MACHINES
ST R7, BACKUP_R7_NUM_BUSY_MACHINES
;INSTRUCTIONS
LDI R2, BUSYNESS_ADDR_NUM_BUSY_MACHINES
LD R3, COUNTER_NBM
AND R1,R1,x0
WHILE_NBM
ADD R2,R2,#0
BRzp COUNT_BUSY
RET_COUNT_BUSY
ADD R2,R2,R2
ADD R3,R3,#-1
BRp WHILE_NBM
;RESTORE
LD R2, BACKUP_R2_NUM_BUSY_MACHINES
LD R3, BACKUP_R3_NUM_BUSY_MACHINES
LD R7, BACKUP_R7_NUM_BUSY_MACHINES
;RETURN
RET
COUNT_BUSY
	ADD R1,R1,#1
BR RET_COUNT_BUSY

;--------------------------------
;Data for subroutine NUM_BUSY_MACHINES
;--------------------------------
COUNTER_NBM						.FILL #16
BACKUP_R2_NUM_BUSY_MACHINES		.BLKW #1
BACKUP_R3_NUM_BUSY_MACHINES		.BLKW #1
BACKUP_R7_NUM_BUSY_MACHINES		.BLKW #1
BUSYNESS_ADDR_NUM_BUSY_MACHINES .Fill xB200

;-----------------------------------------------------------------------------------------------------------------
; Subroutine: NUM_FREE_MACHINES_4900 (#4)
; Inputs: None
; Postcondition: The subroutine has returned the number of free machines
; Return Value (R1): The number of machines that are free (1)
;-----------------------------------------------------------------------------------------------------------------
.ORIG x4900
;-------------------------------
;INSERT CODE For Subroutine NUM_FREE_MACHINES
;--------------------------------
;BACKUP
ST R2, BACKUP_R2_NUM_FREE_MACHINES
ST R3, BACKUP_R3_NUM_FREE_MACHINES
ST R7, BACKUP_R7_NUM_FREE_MACHINES
;INSTRUCTIONS
LDI R2, BUSYNESS_ADDR_NUM_FREE_MACHINES
LD R3, COUNTER_NFM
AND R1,R1,x0
WHILE_NFM
ADD R2,R2,#0
BRn COUNT_FREE
RET_COUNT_FREE
ADD R2,R2,R2
ADD R3,R3,#-1
BRp WHILE_NFM
;RESTORE
LD R2, BACKUP_R2_NUM_FREE_MACHINES
LD R3, BACKUP_R3_NUM_FREE_MACHINES
LD R7, BACKUP_R7_NUM_FREE_MACHINES
;RETURN
RET

COUNT_FREE
	ADD R1,R1,#1
BR RET_COUNT_FREE
;--------------------------------
;Data for subroutine NUM_FREE_MACHINES 
;--------------------------------
COUNTER_NFM						.FILL #16
BACKUP_R2_NUM_FREE_MACHINES		.BLKW	#1
BACKUP_R3_NUM_FREE_MACHINES		.BLKW	#1
BACKUP_R7_NUM_FREE_MACHINES		.BLKW	#1
BUSYNESS_ADDR_NUM_FREE_MACHINES .Fill xB200


;-----------------------------------------------------------------------------------------------------------------
; Subroutine: MACHINE_STATUS_5100 (#5)
; Input (R1): Which machine to check, guaranteed in range {0,15}
; Postcondition: The subroutine has returned a value indicating whether
;                the selected machine (R1) is busy or not.
; Return Value (R2): 0 if machine (R1) is busy, 1 if it is free
;              (R1) unchanged
;-----------------------------------------------------------------------------------------------------------------
.ORIG x5100
;-------------------------------
;INSERT CODE For Subroutine MACHINE_STATUS
;--------------------------------
;BACKUP
ST R1, BACKUP_R1_MACHINE_STATUS
ST R3, BACKUP_R3_MACHINE_STATUS
ST R7, BACKUP_R7_MACHINE_STATUS
;INSTRUCTIONS
	; Figure out which machine to check
		; left shift 15-N amount of times, then check if it is n or zp
		; if n, then return 1. If zp then return 0.
LDI R2, BUSYNESS_ADDR_MACHINE_STATUS
NOT R1,R1
ADD R1,R1,#1
ADD R1,R1,#15	; R1 is now the counter.
WHILE_MS
ADD R1,R1,#-1
BRn OUT_WHILE_MS
ADD R2,R2,R2
BR WHILE_MS
OUT_WHILE_MS
ADD R2,R2,#0
BRn FREE_MS
AND R2,R2,x0
TO_RET_MS
;RESTORE
LD R1, BACKUP_R1_MACHINE_STATUS
LD R3, BACKUP_R3_MACHINE_STATUS
LD R7, BACKUP_R7_MACHINE_STATUS
;RETURN
RET

FREE_MS
	AND R2,R2,x0
	ADD R2,R2,#1
BR TO_RET_MS

;--------------------------------
;Data for subroutine MACHINE_STATUS
;--------------------------------
BACKUP_R1_MACHINE_STATUS		.BLKW #1
BACKUP_R3_MACHINE_STATUS		.BLKW #1
BACKUP_R7_MACHINE_STATUS		.BLKW #1
BUSYNESS_ADDR_MACHINE_STATUS	.Fill xB200

;-----------------------------------------------------------------------------------------------------------------
; Subroutine: FIRST_FREE_5300 (#6)
; Inputs: None
; Postcondition: The subroutine has returned a value indicating the lowest numbered free machine
; Return Value (R1): the number of the free machine
;-----------------------------------------------------------------------------------------------------------------
.ORIG x5300
;-------------------------------
;INSERT CODE For Subroutine FIRST_FREE
;--------------------------------
;BACKUP
ST R2, BACKUP_R2_FIRST_FREE
ST R4, BACKUP_R4_FIRST_FREE
ST R3, BACKUP_R3_FIRST_FREE
ST R7, BACKUP_R7_FIRST_FREE
;INSTRUCTIONS
	; check MSB
		; if MSB is a 1, then save that number?
	; left shift
	; decrement counter
LDI R2, BUSYNESS_ADDR_FIRST_FREE
LD R3, COUNTER_FF
AND R1,R1,x0
ADD R1,R1,#-1
WHILE_FF
ADD R2,R2,#0
BRn FIRST_FREE_CHECK
RET_FIRST_FREE_CHECK
ADD R2,R2,R2
ADD R3,R3,#-1
BRp WHILE_FF

;RESTORE
LD R2, BACKUP_R2_FIRST_FREE
LD R3, BACKUP_R3_FIRST_FREE
LD R4, BACKUP_R4_FIRST_FREE
LD R7, BACKUP_R7_FIRST_FREE
;RETURN
RET

FIRST_FREE_CHECK
	ADD R1,R3,#-1
	AND R4,R4,x0
	ADD R4,R4,#1
BR RET_FIRST_FREE_CHECK

;--------------------------------
;Data for subroutine FIRST_FREE
;--------------------------------
COUNTER_FF				.FILL	#16
BACKUP_R2_FIRST_FREE	.BLKW	#1
BACKUP_R3_FIRST_FREE	.BLKW	#1
BACKUP_R4_FIRST_FREE	.BLKW	#1
BACKUP_R7_FIRST_FREE	.BLKW	#1
BUSYNESS_ADDR_FIRST_FREE .Fill xB200

;-----------------------------------------------------------------------------------------------------------------
; Subroutine: GET_MACHINE_NUM_5500
; Inputs: None
; Postcondition: The number entered by the user at the keyboard has been converted into binary,
;                and stored in R1. The number has been validated to be in the range {0,15}
; Return Value (R1): The binary equivalent of the numeric keyboard entry
; NOTE: You can use your code from assignment 4 for this subroutine, changing the prompt, 
;       and with the addition of validation to restrict acceptable values to the range {0,15}
;-----------------------------------------------------------------------------------------------------------------
.ORIG x5500
;-------------------------------
;INSERT CODE For Subroutine 
;-------------------------------
;BACKUP, all registers except r1.
ST R0, BACKUP_R0_GET_MACHINE_NUM
ST R2, BACKUP_R2_GET_MACHINE_NUM
ST R3, BACKUP_R3_GET_MACHINE_NUM
ST R4, BACKUP_R4_GET_MACHINE_NUM
ST R5, BACKUP_R5_GET_MACHINE_NUM
ST R6, BACKUP_R6_GET_MACHINE_NUM
ST R7, BACKUP_R7_GET_MACHINE_NUM
;INSTRUCTIONS
TO_INTRO_GMN
LEA R0, prompt
PUTS

AND R1,R1,x0
AND R2,R2,x0		
AND R3,R3,x0		
AND R4,R4,x0		
AND R5,R5,x0
AND R6,R6,x0	
ST R6, is_neg
ST R6, has_sign
LD R5,counter

GETC
OUT

LD R2,newline_GMN				; if the first thing is a newline, then it is an error.
NOT R2,R2					; two's complement
ADD R2,R2,x1
ADD R2,R0,R2
BRz ERROR

TO_CHECK
							; is very first character = '\n'? if so, just quit (no message)!
LD R2,newline_GMN		; R2 is the newline character. Not and add 1 to get 2's complement
NOT R2,R2					; two's complement
ADD R2,R2,x1
ADD R2,R0,R2
BRz TO_HALT_GMN			; if zero then branch to the very end, indicates that the character is a newline

							; is it = '+'? if so, ignore it, go get digits
LD R2,positive_GMN		; R2 is the positive character. The previous value in R2 is overwritten
NOT R2,R2					; two's complement
ADD R2,R2,x1
ADD R2,R0,R2
BRz TO_DIGIT_POS			; if positive symbol, then dont check the rest and go straight to digit input

							; is it = '-'? if so, set neg flag, go get digits
LD R2,negative_GMN		; R2 is the negative character. Previous value in R2 is overwritten
NOT R2,R2					; two's complement
ADD R2,R2,x1
ADD R2,R0,R2
BRz ERROR					; if negative symbol, then dont check the rest and go straight to digit input
							; how to make the whole thing negative???

							; is it < '0'? if so, it is not a digit	- o/p error message, start over
LD R2,zero_GMN			; load ascii value for 0
NOT R2,R2					; two's complement
ADD R2,R2,x1
ADD R2,R0,R2
BRn ERROR					; if negative branch to ERROR
							; is it > '9'? if so, it is not a digit	- o/p error message, start over
LD R2,nine_GMN			; load ascii value for 9
NOT R2,R2					; two's complement
ADD R2,R2,x1
ADD R2,R0,R2
BRp ERROR
BR END_ERROR
ERROR
	LD R0,newline_GMN	; how can we replace this?
	OUT
	LEA R0,Error_msg_2
	PUTS
	BR TO_INTRO_GMN
END_ERROR

LD R3,ten			; multiply R4 by 10
ST R4,temp			; R4 gets store in memory, 
LD R6,temp			; loads the value from temp into R6
AND R4,R4,x0
MULTIPLY
ADD R4,R4,R6
ADD R3,R3,#-1
BRp MULTIPLY					

LD R2,zero_GMN
NOT R2,R2
ADD R2,R2,x1
ADD R2,R0,R2		; converts to number, stores in R2
ADD R4,R4,R2		; adds to R4

ADD R5,R5,#-1
BRnz TO_ENDL		; if it gets to 0, then add a manual space.
; Now get remaining digits from user in a loop (max 5), testing each to see if it is a digit, and build up number in accumulator
TO_DIGIT
GETC				; use addition to store numbers in register
OUT					; remember to end with a newline!
BR TO_CHECK

TO_HALT_GMN
LD R1,is_neg
ADD R1,R1,#-1
BRz MAKE_NEG
RETURN_HALT
BR TO_RET_GMN

TO_ENDL
LD R0,newline_GMN
OUT
BR TO_HALT_GMN

TO_DIGIT_POS
LD R1,has_sign
ADD R1,R1,#-1
BRz ERROR
LD R1,has_sign
ADD R1,R1,#1
ST R1,has_sign
BR TO_DIGIT

MAKE_NEG
NOT R4,R4
ADD R4,R4,#1
BR RETURN_HALT

TO_RET_GMN
ADD R1,R4,#0

LD R4, fifteen_GMN
NOT R4,R4
ADD R4,R4,#1
ADD R4,R1,R4					; check if less than or equal to 15
BRp ERROR 
;RESTORE
LD R0, BACKUP_R0_GET_MACHINE_NUM
LD R2, BACKUP_R2_GET_MACHINE_NUM
LD R3, BACKUP_R3_GET_MACHINE_NUM
LD R4, BACKUP_R4_GET_MACHINE_NUM
LD R5, BACKUP_R5_GET_MACHINE_NUM
LD R6, BACKUP_R6_GET_MACHINE_NUM
LD R7, BACKUP_R7_GET_MACHINE_NUM
;RETURN, VALUE IN R1
RET
;--------------------------------
;Data for subroutine Get input
;--------------------------------
is_neg						.BLKW	#1
has_sign					.BLKW	#1
temp						.BLKW	#1
newline_GMN				.FILL x0A
positive_GMN				.FILL x2B
negative_GMN				.FILL x2D
zero_GMN					.FILL x30
nine_GMN					.FILL x39
ten							.FILL #10
one							.FILL #1
fifteen_GMN				.FILL #15
counter						.FILL #5
BACKUP_R0_GET_MACHINE_NUM	.BLKW	#1
BACKUP_R2_GET_MACHINE_NUM	.BLKW	#1
BACKUP_R3_GET_MACHINE_NUM	.BLKW	#1
BACKUP_R4_GET_MACHINE_NUM	.BLKW	#1
BACKUP_R5_GET_MACHINE_NUM	.BLKW	#1
BACKUP_R6_GET_MACHINE_NUM	.BLKW	#1
BACKUP_R7_GET_MACHINE_NUM	.BLKW	#1
prompt .STRINGZ "Enter which machine you want the status of (0 - 15), followed by ENTER: "
Error_msg_2 .STRINGZ "ERROR INVALID INPUT\n"

	
;-----------------------------------------------------------------------------------------------------------------
; Subroutine: PRINT_NUM_5900
; Inputs: R1, which is guaranteed to be in range {0,16}
; Postcondition: The subroutine has output the number in R1 as a decimal ascii string, 
;                WITHOUT leading 0's, a leading sign, or a trailing newline.
; Return Value: None; the value in R1 is unchanged
;-----------------------------------------------------------------------------------------------------------------
.ORIG x5900		; check if a newline should be accepted or not accepted.
;-------------------------------
;INSERT CODE For Subroutine 
;-------------------------------
;BACKUP
ST R0, BACKUP_R0_PRINT_NUM
ST R1, BACKUP_R1_PRINT_NUM
ST R2, BACKUP_R2_PRINT_NUM
ST R7, BACKUP_R7_PRINT_NUM
;INSTRUCTIONS
ADD R2,R1,#-10	; R2 is throwaway register
BRn SINGLE		; if not single, must be double
ADD R1,R2,#0	; R2 already has the number we need.
AND R2,R2,x0
ADD R0,R2,#1
LD R2,ASCII_PRINT
ADD R0,R0,R2
OUT
ADD R0,R1,#0	; Transfer R1 int R0.
ADD R0,R0,R2	; turn into ascii character
OUT

TO_RET_PRINT	; need to restore before return
;RESTORE
LD R0, BACKUP_R0_PRINT_NUM
LD R1, BACKUP_R1_PRINT_NUM
LD R2, BACKUP_R2_PRINT_NUM
LD R7, BACKUP_R7_PRINT_NUM

;RETURN
RET

SINGLE
LD R2, ASCII_PRINT
ADD R0,R1,R2
OUT
BR TO_RET_PRINT
;--------------------------------
;Data for subroutine print number
;--------------------------------
ASCII_PRINT			.FILL 	x30
BACKUP_R0_PRINT_NUM	.BLKW	#1
BACKUP_R1_PRINT_NUM	.BLKW	#1
BACKUP_R2_PRINT_NUM	.BLKW	#1
BACKUP_R7_PRINT_NUM	.BLKW	#1


.ORIG x6400
MENUSTRING .STRINGZ "**********************\n* The Busyness Server *\n**********************\n1. Check to see whether all machines are busy\n2. Check to see whether all machines are free\n3. Report the number of busy machines\n4. Report the number of free machines\n5. Report the status of machine n\n6. Report the number of the first available machine\n7. Quit\n"

.ORIG xB200					; Remote data
BUSYNESS .FILL x8000		; <----!!!BUSYNESS VECTOR!!! Change this value to test your program.

;---------------	
;END of PROGRAM
;---------------	
.END
