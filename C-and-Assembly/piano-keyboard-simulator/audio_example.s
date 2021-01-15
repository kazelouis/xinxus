//Audio example that outputs a square wave
//example from piazza

.global _start
_start:
	mov  r8, #48 				//controls pitch of sound
	ldr  r6, =0xff203040
	ldr  r4, =0x60000000		//controls loudness/amplitude of sound
	mov  r5, r8
	ldr  r1, =100000    		//counter controls duration of sound
WaitForWriteSpace:
	ldr  r2, [r6, #4]
	tst  r2, #0xff000000
	beq  WaitForWriteSpace
	tst  r2, #0x00ff0000
	beq  WaitForWriteSpace
WriteTwoSamples:
	str  r4, [r6, #8]
	str  r4, [r6, #12]
	subs r5, #1
	bne  WaitForWriteSpace
HalfPeriodInvertWaveform:
	mov  r5, r8
	neg  r4, r4
	subs r1, #1					//subtract counter to determine duration of sound
	bne    WaitForWriteSpace
END: b 		END
