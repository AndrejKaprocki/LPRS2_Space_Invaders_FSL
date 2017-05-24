#  Simulation Model Generator
#  Xilinx EDK 14.6 EDK_P.68d
#  Copyright (c) 1995-2012 Xilinx, Inc.  All rights reserved.
#
#  File     fsl_v20_0_wave.tcl (Wed May 24 11:35:51 2017)
#
#  Module   system_fsl_v20_0_wrapper
#  Instance fsl_v20_0
#  Because EDK did not create the testbench, the user
#  specifies the path to the device under test, $tbpath.
#
if { [info exists PathSeparator] } { set ps $PathSeparator } else { set ps "/" }
if { ![info exists tbpath] } { set tbpath "${ps}system" }

# wave add $tbpath${ps}fsl_v20_0${ps}FSL_Clk -into $id
# wave add $tbpath${ps}fsl_v20_0${ps}SYS_Rst -into $id
  wave add $tbpath${ps}fsl_v20_0${ps}FSL_Rst -into $id
# wave add $tbpath${ps}fsl_v20_0${ps}FSL_M_Clk -into $id
# wave add $tbpath${ps}fsl_v20_0${ps}FSL_M_Data -into $id
# wave add $tbpath${ps}fsl_v20_0${ps}FSL_M_Control -into $id
# wave add $tbpath${ps}fsl_v20_0${ps}FSL_M_Write -into $id
  wave add $tbpath${ps}fsl_v20_0${ps}FSL_M_Full -into $id
# wave add $tbpath${ps}fsl_v20_0${ps}FSL_S_Clk -into $id
  wave add $tbpath${ps}fsl_v20_0${ps}FSL_S_Data -into $id
  wave add $tbpath${ps}fsl_v20_0${ps}FSL_S_Control -into $id
# wave add $tbpath${ps}fsl_v20_0${ps}FSL_S_Read -into $id
  wave add $tbpath${ps}fsl_v20_0${ps}FSL_S_Exists -into $id
# wave add $tbpath${ps}fsl_v20_0${ps}FSL_Full -into $id
# wave add $tbpath${ps}fsl_v20_0${ps}FSL_Has_Data -into $id
# wave add $tbpath${ps}fsl_v20_0${ps}FSL_Control_IRQ -into $id

