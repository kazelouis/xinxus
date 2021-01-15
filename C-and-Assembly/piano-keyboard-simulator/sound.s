//On SW input, pitched sound is outputed 
//VGA colours the note pressed
//sw7 - C, sw6 - D, sw5 - E, sw4 - F, sw3 - G, sw2 - A, sw1 - B, sw0 - C2

.text

/*
.global start_assembly
start_assembly:
	  //ldr  r8, =0x5
	  ldr  r6, =0xff203040  //audio
    ldr  r7, =0xff200040 //switches
    ldr  r1, [r7] //r1 stores value of switches
	  ldr  r4, =0xBB800000
	  //mov  r5, r8 //r5 = 48
    //ldr r1, =0x6000 //running time

CHECK_SWITCH: //AND R1, #0x80
			        ldr r1, [r7]
			        CMP r1, #0x80
			        beq C_note
              CMP r1, #0x40
              beq D_note
              CMP r1, #0x20
              beq E_note
              CMP r1, #0x10
              beq F_note
              CMP r1, #0x8
              beq G_note
              CMP r1, #0x4
              beq A_note
              CMP r1, #0x2
              beq B_note
              CMP r1, #0x1
              beq C2_note
              CMP r1, #0
              beq PLAY_NOTHING
*/

.global C_note
C_note: push {R0-R12, LR}
        ldr r5, =0xF
        mov  r8, r5          //let r8 be a temporary holder of r5
        LDR R9, =400      //subtract counter to determine duration of sound
        
        ldr  r6, =0xff203040  //audio
        ldr  r4, =0xBB800000        
        B WaitForWriteSpace

.global D_note
D_note: push {R0-R12, LR}
        ldr r5, =0xD
        mov  r8, r5          //let r8 be a temporary holder of r5
        LDR R9, =400      //subtract counter to determine duration of sound
        
        ldr  r6, =0xff203040  //audio
        ldr  r4, =0xBB800000       
        B WaitForWriteSpace

.global E_note
E_note: push {R0-R12, LR} 
        ldr r5, =0xC
        mov  r8, r5          //let r8 be a temporary holder of r5
        LDR R9, =400      //subtract counter to determine duration of sound
         
        ldr  r6, =0xff203040  //audio        
        ldr  r4, =0xBB800000       
        B WaitForWriteSpace

.global F_note
F_note:  push {R0-R12, LR}
         ldr r5, =0xB
         mov  r8, r5          //let r8 be a temporary holder of r5
         LDR R9, =400      //subtract counter to determine duration of sound
         
        ldr  r6, =0xff203040  //audio
        ldr  r4, =0xBB800000 
        B WaitForWriteSpace

.global G_note
G_note:  push {R0-R12, LR}
         ldr r5, =0xA
         mov  r8, r5          //let r8 be a temporary holder of r5
         LDR R9, =400      //subtract counter to determine duration of sound
          
        ldr  r6, =0xff203040  //audio
        ldr  r4, =0xBB800000        
        B WaitForWriteSpace

.global A_note
A_note:   push {R0-R12, LR}
          ldr r5, =0x9
          mov  r8, r5          //let r8 be a temporary holder of r5
          LDR R9, =400      //subtract counter to determine duration of sound
        
        ldr  r6, =0xff203040  //audio
        ldr  r4, =0xBB800000
        B WaitForWriteSpace

.global B_note
B_note:  push {R0-R12, LR}
          ldr r5, =0x8
          mov  r8, r5          //let r8 be a temporary holder of r5
          LDR R9, =400      //subtract counter to determine duration of sound

        ldr  r6, =0xff203040  //audio
        ldr  r4, =0xBB800000
        B WaitForWriteSpace

.global C2_note
C2_note: push {R0-R12, LR}
         ldr r5, =0x7
         mov  r8, r5          //let r8 be a temporary holder of r5
         LDR R9, =400      //subtract counter to determine duration of sound

        ldr  r6, =0xff203040  //audio
        ldr  r4, =0xBB800000           
        B WaitForWriteSpace

PLAY_NOTHING: POP {R0-R12, LR}
			        mov PC, LR       //return to C program

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
            mov  r5, r8             //r8 = 48
            neg  r4, r4             //multiplies r4 by -1 and places it into r4
            SUBS R9, #1             //SUBTRACT COUNTER TO STOP SOUND
            BEQ    PLAY_NOTHING
            bne    WaitForWriteSpace

	

