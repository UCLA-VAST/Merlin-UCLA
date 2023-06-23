#!/bin/bash

# Please change these paths
xilinx_path=/opt/xilinx
tools_path=/opt/tools
XILINX_VITIS=/opt/tools/xilinx/Vitis/2021.1
XILINX_XRT=/opt/xilinx/xrt
XILINX_VIVADO=/opt/tools/xilinx/Vivado/2021.1
LM_LICENSE_FILE=

########################

CURRENT_PATH=$(cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd)
imagename="ghcr.io/ucla-vast/merlin-ucla:latest"

docker run -v /home:/home -v $tools_path:$tools_path -v $xilinx_path:$xilinx_path -e XILINX_VITIS=$XILINX_VITIS -e XILINX_XRT=$XILINX_XRT -e XILINX_VIVADO=$XILINX_VIVADO -e LM_LICENSE_FILE=$LM_LICENSE_FILE -w="$CURRENT_PATH" -it "$imagename"
