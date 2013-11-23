/*
 * ZC706 DDR3 SODIMM memory test
 *
 * This application tests the DDR3 SODIMM memory by writing
 * a sequence of numbers and then reading them back.
 *
 * Jeff Johnson
 * fpgadeveloper.com
 */

#include <stdio.h>
#include <xil_io.h>
#include "xparameters.h"

#define SODIMM_WORDS (XPAR_AXI_7SERIES_DDRX_0_S_AXI_HIGHADDR - \
	XPAR_AXI_7SERIES_DDRX_0_S_AXI_BASEADDR) / 4

int main()
{
	unsigned int *sodimm;
	unsigned int i;
	unsigned int value;
	unsigned int failed;

	//sodimm = (unsigned int *)XPAR_AXI_7SERIES_DDRX_0_S_AXI_BASEADDR;
	sodimm = (unsigned int *)0x80000000;

    xil_printf("-------------------------\n\r");
    xil_printf("ZC706 DDR3 SODIMM example\n\r");
    xil_printf("-------------------------\n\r");

    xil_printf("Initial read at base address: 0x%X\n\r",sodimm[0]);

    sodimm[0] = 0xDEADBEEF;
    xil_printf("Read after writing DEADBEEF : 0x%X\n\r",sodimm[0]);

    // Write incrementing values to the SODIMM
    for(i = 0;i < SODIMM_WORDS;i++){
    	sodimm[i] = i;
    }

    // Read and check the written values
    failed = 0;
    for(i = 0;i < SODIMM_WORDS;i++){
    	value = sodimm[i];
    	if(value != i){
    		xil_printf("SODIMM failed at address 0x%X\n\r",sodimm+i);
    		failed = 1;
    		break;
    	}
    }
    if(failed == 0)
    	xil_printf("SODIMM test passed\n\r");

    return 0;
}

