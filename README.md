# OIT-Robosub
Oregon Tech Robosub (Robonation) Software Team

	Introduction

Everything will be done mainly in Python for vision processing and machine learning. Proposed hardware control for the sub will be accomplished primarily using MplabX IDE using C code on a PIC32XX family microcontroller; a flight controller/PID tuner is another proposed addition. Basic goals for software is object tracking with cameras.

	Machine Learning Section

The following is a list of websites to get started on researching Machine Learning (ML) to use in training the sub to recognize different objects. Opencv can be used to pipe in camera video to tensorflow.

http://www.opennn.net/
https://www.tensorflow.org/

	Long Term Goals
Eventually, using an FPGA to either replace/complement the Microcontroller on the Sub Arduino would provide some unique implications in terms of computational speed and hardware control. If an FPGA were to be integrated, likely an Intel FPGA, or Xilinx Board, SystemVerilog would be the optimal choice for HDL usage.
