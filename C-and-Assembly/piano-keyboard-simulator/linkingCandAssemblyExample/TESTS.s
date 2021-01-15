//Audio example that outputs a square wave
//example from piazza
.text
.global assembly
assembly:
	mov  r8, #0xF
	ldr  r6, =0xff203040
	ldr  r4, =0x60000000
	mov  r5, r8
    ldr r1, =0x6000
WaitForWriteSpace:
    subs r1, #1
    beq END
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
	b    WaitForWriteSpace
END: b END
