zc706-ddr3-sodimm
=================

Example project that uses the 1GB DDR3 SODIMM memory on the ZC706 board

### Description

This XPS project provides the processor and peripherals access to the 1GB
DDR3 SODIMM memory via the Xilinx "AXI 7 Series Memory Controller" IP core.
The SDK project included is a simple application that writes to the memory
and reads it back in order to verify the memory space. Be aware that the
test can take some time to complete (maybe 30 seconds).

As the core is memory mapped, the memory can be used by the processor directly
or it can be used by other peripherals via DMA. Check my other examples on
DMA if you want to know how to do this.

### License

Feel free to modify the project or use it as a base for your application.

### Fork and share

If you port this project to another hardware platform, please send me the
code or push it onto GitHub and send me the link so I can post it on my
website. The more people that benefit, the better.

### About the author

I'm an FPGA consultant and I provide FPGA design services and training to
innovative companies around the world. I believe in sharing knowledge and
I regularly contribute to the open source community.

Jeff Johnson
http://www.fpgadeveloper.com