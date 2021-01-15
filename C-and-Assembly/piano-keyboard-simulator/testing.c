//TESTING.C COMBINES ALL 3 .H FILES AND 2 .C FILES FOR TESTING ON CPULATOR


/* FPGA interrupts (there are 64 in total; only a few are defined below) */
#define	INTERVAL_TIMER_IRQ				    72
#define	KEYS_IRQ		 					73
#define	FPGA_IRQ2	 						74
#define	FPGA_IRQ3	 						75
#define	FPGA_IRQ4	 						76
#define	FPGA_IRQ5	 						77
#define	AUDIO_IRQ							78
#define	PS2_IRQ		 						79
#define	JTAG_IRQ		 					80
#define	IrDA_IRQ		 					81
#define	FPGA_IRQ10							82
#define	JP1_IRQ								83
#define	JP2_IRQ								84
#define	FPGA_IRQ13							85
#define	FPGA_IRQ14							86
#define	FPGA_IRQ15							87
#define	FPGA_IRQ16							88
#define	PS2_DUAL_IRQ						89
#define	FPGA_IRQ18							90
#define	FPGA_IRQ19							91

/* ARM A9 MPCORE devices (there are many; only a few are defined below) */
#define	MPCORE_GLOBAL_TIMER_IRQ			    27
#define	MPCORE_PRIV_TIMER_IRQ	    		29
#define	MPCORE_WATCHDOG_IRQ			    	30

/* HPS devices (there are many; only a few are defined below) */
#define	HPS_UART0_IRQ	   				    194
#define	HPS_UART1_IRQ	   				    195
#define	HPS_GPIO0_IRQ	        		  	196
#define	HPS_GPIO1_IRQ	        		  	197
#define	HPS_GPIO2_IRQ	        		  	198
#define	HPS_TIMER0_IRQ	        		 	199
#define	HPS_TIMER1_IRQ	        		 	200
#define	HPS_TIMER2_IRQ	        		 	201
#define	HPS_TIMER3_IRQ	        		 	202
#define	HPS_WATCHDOG0_IRQ	     			203
#define	HPS_WATCHDOG1_IRQ	     			204

#define		EDGE_TRIGGERED			0x1
#define		LEVEL_SENSITIVE		    0x0
#define		CPU0					0x01	// bit-mask; bit 0 represents cpu0
#define		ENABLE					0x1

#define		KEY0 						0
#define		KEY1 						1
#define		KEY2						2
#define		KEY3						3
#define		NONE						4

#define		RIGHT						1
#define		LEFT						2

#define		USER_MODE				0b10000
#define		FIQ_MODE				0b10001
#define		IRQ_MODE				0b10010
#define		SVC_MODE				0b10011
#define		ABORT_MODE				0b10111
#define		UNDEF_MODE				0b11011
#define		SYS_MODE				0b11111

#define		INT_ENABLE				0b01000000
#define		INT_DISABLE				0b11000000

/* This files provides address values that exist in the system */

#define BOARD                 "DE1-SoC"

/* Memory */
#define DDR_BASE              0x00000000
#define DDR_END               0x3FFFFFFF
#define A9_ONCHIP_BASE        0xFFFF0000
#define A9_ONCHIP_END         0xFFFFFFFF
#define SDRAM_BASE            0xC0000000
#define SDRAM_END             0xC3FFFFFF
#define FPGA_ONCHIP_BASE      0xC8000000
#define FPGA_ONCHIP_END       0xC803FFFF
#define FPGA_CHAR_BASE        0xC9000000
#define FPGA_CHAR_END         0xC9001FFF

/* Cyclone V FPGA devices */
#define LEDR_BASE             0xFF200000
#define HEX3_HEX0_BASE        0xFF200020
#define HEX5_HEX4_BASE        0xFF200030
#define SW_BASE               0xFF200040
#define KEY_BASE              0xFF200050
#define JP1_BASE              0xFF200060
#define JP2_BASE              0xFF200070
#define PS2_BASE              0xFF200100
#define PS2_DUAL_BASE         0xFF200108
#define JTAG_UART_BASE        0xFF201000
#define JTAG_UART_2_BASE      0xFF201008
#define IrDA_BASE             0xFF201020
#define TIMER_BASE            0xFF202000
#define TIMER_2_BASE          0xFF202020
#define AV_CONFIG_BASE        0xFF203000
#define PIXEL_BUF_CTRL_BASE   0xFF203020
#define CHAR_BUF_CTRL_BASE    0xFF203030
#define AUDIO_BASE            0xFF203040
#define VIDEO_IN_BASE         0xFF203060
#define ADC_BASE              0xFF204000

/* Cyclone V HPS devices */
#define HPS_GPIO1_BASE        0xFF709000
#define I2C0_BASE             0xFFC04000
#define I2C1_BASE             0xFFC05000
#define I2C2_BASE             0xFFC06000
#define I2C3_BASE             0xFFC07000
#define HPS_TIMER0_BASE       0xFFC08000
#define HPS_TIMER1_BASE       0xFFC09000
#define HPS_TIMER2_BASE       0xFFD00000
#define HPS_TIMER3_BASE       0xFFD01000
#define FPGA_BRIDGE           0xFFD0501C

/* ARM A9 MPCORE devices */
#define   PERIPH_BASE         0xFFFEC000    // base address of peripheral devices
#define   MPCORE_PRIV_TIMER   0xFFFEC600    // PERIPH_BASE + 0x0600

/* Interrupt controller (GIC) CPU interface(s) */
#define MPCORE_GIC_CPUIF      0xFFFEC100    // PERIPH_BASE + 0x100
#define ICCICR                0x00          // offset to CPU interface control reg
#define ICCPMR                0x04          // offset to interrupt priority mask reg
#define ICCIAR                0x0C          // offset to interrupt acknowledge reg
#define ICCEOIR               0x10          // offset to end of interrupt reg
/* Interrupt controller (GIC) distributor interface(s) */
#define MPCORE_GIC_DIST       0xFFFED000    // PERIPH_BASE + 0x1000
#define ICDDCR                0x00          // offset to distributor control reg
#define ICDISER               0x100         // offset to interrupt set-enable regs
#define ICDICER               0x180         // offset to interrupt clear-enable regs
#define ICDIPTR               0x800         // offset to interrupt processor targets regs
#define ICDICFR               0xC00         // offset to interrupt configuration regs


void config_interrupt (int, int);
void hw_write_bits(volatile int *, volatile int, volatile int);
void enable_A9_interrupts(void);
void set_A9_IRQ_stack(void);
void config_interrupt (int, int);
void hw_write_bits(volatile int * , volatile int , volatile int );
//Set up functions in C code
void config_PS2(void);
void PS2_ISR(void);

// Define the IRQ exception handler
void __attribute__ ((interrupt)) __cs3_isr_irq (void)
{
	// Read the ICCIAR from the processor interface 
	int address = MPCORE_GIC_CPUIF + ICCIAR; 
	int int_ID = *((int *) address); 
   
	if (int_ID == PS2_IRQ)				// check if interrupt is from the PS/2
		PS2_ISR ();
	else
		while (1);									// if unexpected, then stay here

	// Write to the End of Interrupt Register (ICCEOIR)
	address = MPCORE_GIC_CPUIF + ICCEOIR;
	*((int *) address) = int_ID;

	return;
} 

// Define the remaining exception handlers
void __attribute__ ((interrupt)) __cs3_reset (void)
{
    while(1);
}

void __attribute__ ((interrupt)) __cs3_isr_undef (void)
{
    while(1);
}

void __attribute__ ((interrupt)) __cs3_isr_swi (void)
{
    while(1);
}

void __attribute__ ((interrupt)) __cs3_isr_pabort (void)
{
    while(1);
}

void __attribute__ ((interrupt)) __cs3_isr_dabort (void)
{
    while(1);
}

void __attribute__ ((interrupt)) __cs3_isr_fiq (void)
{
    while(1);
}

/* 
 * Initialize the banked stack pointer register for IRQ mode
*/
void set_A9_IRQ_stack(void)
{
	int stack, mode;
	stack = A9_ONCHIP_END - 7;		// top of A9 onchip memory, aligned to 8 bytes
	/* change processor to IRQ mode with interrupts disabled */
	mode = INT_DISABLE | IRQ_MODE;
	asm("msr cpsr, %[ps]" : : [ps] "r" (mode));
	/* set banked stack pointer */
	asm("mov sp, %[ps]" : : [ps] "r" (stack));

	/* go back to SVC mode before executing subroutine return! */
	mode = INT_DISABLE | SVC_MODE;
	asm("msr cpsr, %[ps]" : : [ps] "r" (mode));
}

/* 
 * Turn on interrupts in the ARM processor
*/
void enable_A9_interrupts(void)
{
	int status = SVC_MODE | INT_ENABLE;
	asm("msr cpsr, %[ps]" : : [ps]"r"(status));
}

/* 
 * Configure the Generic Interrupt Controller (GIC)
*/
void config_GIC(void)
{
	int address;	// used to calculate register addresses

 	/* configure the HPS timer interrupt */
	/**((int *) 0xFFFED8C4) = 0x01000000;
	*((int *) 0xFFFED118) = 0x00000080;*/

  	
  	config_interrupt (PS2_IRQ, CPU0);
    config_interrupt (HPS_TIMER0_IRQ, CPU0);
  	// Set Interrupt Priority Mask Register (ICCPMR). Enable interrupts for lowest priority 
	address = MPCORE_GIC_CPUIF + ICCPMR;
  	*((int *) address) = 0xFFFF;       

  	// Set CPU Interface Control Register (ICCICR). Enable signaling of interrupts
	address = MPCORE_GIC_CPUIF + ICCICR;
	*((int *) address) = ENABLE;

	// Configure the Distributor Control Register (ICDDCR) to send pending interrupts to CPUs 
	address = MPCORE_GIC_DIST + ICDDCR;
	*((int *) address) = ENABLE;   
}


/* 
 * Configure registers in the GIC for individual interrupt IDs.
*/
void config_interrupt (int int_ID, int CPU_target)
{
	int n, addr_offset, value, address;
	/* Set Interrupt Processor Targets Register (ICDIPTRn) to cpu0. 
	 * n = integer_div(int_ID / 4) * 4
	 * addr_offet = #ICDIPTR + n
	 * value = CPU_target << ((int_ID & 0x3) * 8)
	 */
	n = (int_ID >> 2) << 2;
	addr_offset = ICDIPTR + n;
	value = CPU_target << ((int_ID & 0x3) << 3);
	
	/* Now that we know the register address and value, we need to set the correct bits in 
	 * the GIC register, without changing the other bits */
	address = MPCORE_GIC_DIST + addr_offset;
	hw_write_bits((int *) address, 0xff << ((int_ID & 0x3) << 3), value);  
    
	/* Set Interrupt Set-Enable Registers (ICDISERn). 
	 * n = (integer_div(in_ID / 32) * 4
	 * addr_offset = 0x100 + n
	 * value = enable << (int_ID & 0x1F) */
	n = (int_ID >> 5) << 2; 
	addr_offset = ICDISER + n;
	value = 0x1 << (int_ID & 0x1f);
	/* Now that we know the register address and value, we need to set the correct bits in 
	 * the GIC register, without changing the other bits */
	address = MPCORE_GIC_DIST + addr_offset;
	hw_write_bits((int *) address, 0x1 << (int_ID & 0x1f), value);    
}

void hw_write_bits(volatile int * addr, volatile int unmask, volatile int value)
{     
    *addr = ((~unmask) & *addr) | value;
}


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


volatile int pixel_buffer_start; // global variable
volatile int * pixel_ctrl_ptr = (int *)0xFF203020;

//Draw functions on VGA
void plot_pixel(int x, int y, short int line_color);
void clear_screen();
void draw_line(int x0, int x1, int y0, int y1, short int colour);
void wait_for_vsync();
void draw_frame();
void setup_buffer();
void draw_rectangles(); 
void draw(int xBoundStart, int xBoundEnd, int yBoundStart, int yBoundEnd);
void clear_rectangles(int xBoundStart, int xBoundEnd, int yBoundStart, int yBoundEnd);
void fill_rectangle(int x0, int x1, int y0, int y1);
void fill_C();
void fill_D();
void fill_E();
void fill_F();
void fill_G();
void fill_A();
void fill_B();
void fill_C2();
void fill_note();
//Print text on screen
void print_text(int x, int y, char* ptr);

int main(void)
{   
    ///////////////////////Set up GIC for interrupts//////////////////////////////////////
    
    set_A9_IRQ_stack ();			// initialize the stack pointer for IRQ mode
	config_GIC ();					// configure the general interrupt controller
	config_PS2();
	enable_A9_interrupts ();	// enable interrupts
	setup_buffer(); 

    
        //print text title on screen
        char text_welcome[27] = "Experience Music Creation \0";
        print_text(28,  10, text_welcome);


    while(1){

    //////////////Drawing animated 8 line box////////////////////////////////////////////

        //draw animated 8line-segments
        draw_rectangles();

        //draw frame for piano key board
        //rectangular dimension:240 by 120
        //corners from (40, 60) to (280, 180)
        draw_frame();
        wait_for_vsync(); // swap front and back buffers on VGA vertical sync
        pixel_buffer_start = *(pixel_ctrl_ptr + 1); // new back buffer
 
    }//end of while loop

}//end of main

void setup_buffer(){
         ////////////////////variables for buffer and drawing//////////////////////////////////
    *(pixel_ctrl_ptr + 1) = 0xC8000000; // first store the address in the
    // back buffer
    /* now, swap the front/back buffers, to set the front buffer location */
    wait_for_vsync();
    /* initialize a pointer to the pixel buffer, used by drawing functions */
    pixel_buffer_start = *pixel_ctrl_ptr;
    clear_screen(); // pixel_buffer_start points to the pixel buffer
    /* set back pixel buffer to start of SDRAM memory */
    *(pixel_ctrl_ptr + 1) = 0xC8000000;   //changing this to 0xC0000000 would make pink
    pixel_buffer_start = *(pixel_ctrl_ptr + 1); // we draw on the back buffer
	clear_screen(); 
}


//draw four moving rectangles
void draw_rectangles(){
    draw(1, 59, 1, 59);
    draw(258, 316, 1, 59);
    draw(1, 59, 182, 238);
    draw (258, 316, 182, 238);

    return;
}

//draw 8 moving lines
void draw(int xBoundStart, int xBoundEnd, int yBoundStart, int yBoundEnd){
    int x[8];
    int y[8];
    int d_x[8];
    int d_y[8];
    int color[8];
    int i;

    for( i=0; i<8; i++){
        //generate random locations and directions
        x[i]=rand()% (xBoundEnd - xBoundStart) + xBoundStart;
        y[i]=rand()% (yBoundEnd - yBoundStart) + yBoundStart;
        d_x[i]= ((rand()%2)*2) -1; //directions can be between -1 to 1
        d_y[i]= ((rand()%2)*2) -1; //directions can be between -1 to 1
        color[i]=rand()%0xFFFF-1; //random colour in array
    }
    clear_rectangles(xBoundStart, xBoundEnd, yBoundStart, yBoundEnd);
    //draw lines while linking each point
    for( i=0; i<8; i++){
        draw_line(x[i], x[(i+1)%8], y[i], y[(i+1)%8], color[i]);
    }

    for( i=0; i<8; i++){
        x[i]+= d_x[i]; //move coordinates
        y[i]+= d_y[i]; //move coorinates
        //check boundary of screen reached
        if(x[i] ==xBoundStart || x[i] ==xBoundEnd - 1){
            d_x[i]= -d_x[i];
        }
        if(y[i] == yBoundStart || y[i] == yBoundEnd - 1){
            d_y[i]= -d_y[i];
        }
    }

}

//plot pixel
void plot_pixel(int x, int y, short int line_color){
    *(short int *)(pixel_buffer_start + (y << 10) + (x << 1)) = line_color;
}


void draw_frame(){

    //rectangular frame
    draw_line(40, 280, 60, 60, 0x001F);   // this line is blue
    draw_line(40, 280, 180, 180, 0x001F);   // this line is blue
    draw_line(40, 40, 60, 180, 0x001F);   // this line is blue
    draw_line(280, 280, 60, 180, 0x001F);   // this line is blue
    //5 white key separators underneath black keys
    draw_line(70, 70, 120, 180, 0x001F);   // this line is blue
    draw_line(100, 100, 120, 180, 0x001F);   // this line is blue
    draw_line(160, 160, 120, 180, 0x001F);   // this line is blue
    draw_line(190, 190, 120, 180, 0x001F);   // this line is blue
    draw_line(220, 220, 120, 180, 0x001F);   // this line is blue
    //2 white full key separators
    draw_line(130, 130, 60, 180, 0x001F);   // this line is blue
    draw_line(250, 250, 60, 180, 0x001F);   // this line is blue
    //draw 10 black key outlines
    draw_line(60, 60, 60, 120, 0x001F);   // this line is blue
    draw_line(80, 80, 60, 120, 0x001F);   // this line is blue
    draw_line(90, 90, 60, 120, 0x001F);   // this line is blue
    draw_line(110, 110, 60, 120, 0x001F);   // this line is blue
    draw_line(150, 150, 60, 120, 0x001F);   // this line is blue
    draw_line(170, 170, 60, 120, 0x001F);   // this line is blue
    draw_line(180, 180, 60, 120, 0x001F);   // this line is blue
    draw_line(200, 200, 60, 120, 0x001F);   // this line is blue
    draw_line(210, 210, 60, 120, 0x001F);   // this line is blue
    draw_line(230, 230, 60, 120, 0x001F);   // this line is blue
    //draw 5 horizontal black key lines
    draw_line(60, 80, 120, 120, 0x001F);   // this line is blue
    draw_line(90, 110, 120, 120, 0x001F);   // this line is blue
    draw_line(150, 170, 120, 120, 0x001F);   // this line is blue
    draw_line(180, 200, 120, 120, 0x001F);   // this line is blue
    draw_line(210, 230, 120, 120, 0x001F);   // this line is blue

}


//clear screen
void clear_screen(){
    int x, y;
    //set entire screen black
    for(x=0; x<320; x++){
        for(y=0; y<240; y++){
            plot_pixel(x, y, 0);
        }
    }
}

void clear_rectangles(int xBoundStart, int xBoundEnd, int yBoundStart, int yBoundEnd){
    int x, y;
    //set bounded portion of screen black
    for(x=xBoundStart; x<=xBoundEnd; x++){
        for(y=yBoundStart; y<=yBoundEnd; y++){
            plot_pixel(x, y, 0);
        }
    }
}

//drawing a line
void draw_line(int x0, int x1, int y0, int y1, short int colour){
    int temp;
    bool isSteep;
    if(abs(y1-y0) > abs(x1-x0)){
        isSteep=true;
    }else{
        isSteep=false;
    }

    if(isSteep){
        //swap x0 y0
        temp = x0;
        x0 = y0;
        y0 = temp;

        //swap x1 y1
        temp = x1;
        x1 = y1;
        y1 = temp;

    }

    if(x0>x1){
        //swap x0 x1
        temp = x0;
        x0 = x1;
        x1 = temp;

        //swap y0 y1
        temp = y0;
        y0 = y1;
        y1 = temp;
    }

    int deltax= x1-x0;
    int deltay= abs(y1-y0);
    int error = -(deltax/2);
    int y=y0;
    int y_step;

    if(y0<y1){
        y_step=1;
    }else{
        y_step=-1;
    }

    int x;
    for(x = x0; x <= x1; x++){
        if(isSteep==true){
            plot_pixel(y, x, colour);
        }else {
            plot_pixel(x, y, colour);
        }
        error = error + deltay;

        if(error>=0){
            y = y + y_step;
            error = error - deltax;
        }
    }

}

//wait for swap to happen
void wait_for_vsync() {
    volatile int * pixel_ctrl_ptr = (int *) 0xFF203020; //pixel controller
    register int status;

    *pixel_ctrl_ptr = 1; //start sychronization process

    status = *( pixel_ctrl_ptr +3);
    while ((status & 0x01) != 0) {
        status = * (pixel_ctrl_ptr +3);
    }

    return;
}

//Fill a rectangle with colour
//R0, R1, R2, R3 are parameters passed from sound.s
void fill_rectangle(int x0, int x1, int y0, int y1){
    int i;
    for(i=y0; i<y1; i++){
        draw_line(x0, x1, i, i, 0xFFFF);
    } 
    //fill an entire rectangle white

}

void fill_C(){
    fill_rectangle(40, 60, 60, 120);
    fill_rectangle(40, 70, 120, 180);
}

void fill_D(){
    fill_rectangle(80, 90, 60, 120);
    fill_rectangle(70, 100, 120, 180);
}

void fill_E(){
    fill_rectangle(110, 130, 60, 120);
    fill_rectangle(100, 130, 120, 180);
}


void fill_F(){
    fill_rectangle(130, 150, 60, 120);
    fill_rectangle(130, 160, 120, 180);
}

void fill_G(){
    fill_rectangle(170, 180, 60, 120);
    fill_rectangle(160, 190, 120, 180);
}

void fill_A(){
    fill_rectangle(200, 210, 60, 120);
    fill_rectangle(190, 220, 120, 180);
}

void fill_B(){
    fill_rectangle(230, 250, 60, 120);
    fill_rectangle(220, 250, 120, 180);
}

void fill_C2(){
    fill_rectangle(250, 280, 60, 180);
}

/* setup the PS/2 interrupts */
void config_PS2()
{
	volatile int * PS2_ptr = (int *) PS2_BASE;	// PS/2 port address

	*(PS2_ptr) = 0xFF;				/* reset */
	*(PS2_ptr + 1) = 0x1; 			/* write to the PS/2 Control register to enable interrupts */

}

bool note_A=false;
bool note_B=false;
bool note_C=false;
bool note_D=false;
bool note_E=false;
bool note_F=false;
bool note_G=false;
bool note_C2=false;

void fill_note(){

        clear_rectangles(40, 280, 60, 180);
        draw_frame();
        wait_for_vsync(); // swap front and back buffers on VGA vertical sync
        pixel_buffer_start = *(pixel_ctrl_ptr + 1); // new back buffer

        if(note_A==true){
            note_A=false; //reset boolean
            fill_A();
            A_note();
        }else if(note_B==true){
            note_B=false; //reset boolean
            fill_B();
            B_note();
        }else if(note_C==true){
            note_C=false; //reset boolean
            fill_C();
            C_note();
        }else if(note_D==true){
            note_D=false; //reset boolean
            fill_D();
            D_note();
        }else if(note_E==true){
            note_E=false; //reset boolean
            fill_E();
            E_note();
        }else if(note_F==true){
            note_F=false; //reset boolean
            fill_F();
            F_note();
        }else if(note_G==true){
            note_G=false; //reset boolean
            fill_G();
            G_note();
        }else if(note_C2==true){
            note_C2=false; //reset boolean
            fill_C2();
            C2_note();
        }else{
            //FILL NOTHING
        }
                
        //delay loop
        int delay=100000; //delay loop counter
		for(delay>=0; delay--;){
            //wait and do nothing
        }


}

//DISPLAYS KEYBOARD INPUT BYTE3 ONTO THE LED LIGHTS
#define RLEDs ((volatile long *) 0xFF200000)

///////////Read character from Keyboard and display on LEDR//////////////////////     
void PS2_ISR()
{   

    unsigned char byte1 = 0;
	unsigned char byte2 = 0;
	unsigned char byte3 = 0;
	
  	volatile int * PS2_ptr = (int *) 0xFF200100;  // PS/2 port address

	int PS2_data, RVALID;

		PS2_data = *(PS2_ptr);	// read the Data register in the PS/2 port
		RVALID = (PS2_data & 0x8000);	// extract the RVALID field
		if (RVALID != 0)
		{
			/* always save the last three bytes received */
			byte1 = byte2;
			byte2 = byte3;
			byte3 = PS2_data & 0xFF;

            // Display last byte on Red LEDs
		    *RLEDs = byte3;

            if(byte3 == (char) 0x1C){
                note_A= true;
                fill_note();
                return;
            }else if(byte3 == (char) 0x32){
                    note_B= true;
                    fill_note();
                    return;
            }else if(byte3 == (char) 0x21){
                    note_C= true;
                    fill_note();
                    return;
            }else if(byte3 == (char) 0x23){
                    note_D= true;
                    fill_note();
                    return;
            }else if(byte3 == (char) 0x24){
                    note_E= true;
                    fill_note();
                    return;
            }else if(byte3 == (char) 0x2B ){
                    note_F= true;
                    fill_note();
                    return;
            }else if(byte3 == (char) 0x34){
                    note_G= true;
                    fill_note();
                    return;
            }else if(byte3 == (char) 0x33){
                    note_C2= true;
                    fill_note();
                    return;
            }else {
                //display nothing
                return;
            }

		}

    return;
}

void print_text(int x, int y, char* ptr) {
    int offset;
    volatile char* char_buffer = (char*)FPGA_CHAR_BASE;

    offset = (y << 7) + x;
    while(*ptr) {
        *(char_buffer + offset) = *ptr;
        ++ ptr;
        ++ offset;
    }

    return;
}