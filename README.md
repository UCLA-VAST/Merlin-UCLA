# Merlin-UCLA


### Documentation

Please visit the website: [Merlin-UCLA](https://ucla-vast.github.io/Merlin-UCLA/)

### Use Merlin-UCLA with Docker

#### Download 
```sh
docker pull ghcr.io/ucla-vast/merlin-ucla:latest
```

#### Configuration

Please update the file `run_docker.sh` with you own paths.

#### Run in interactive mode

```sh
sh run_docker.sh
```

### Install Merlin-UCLA

Prequest dependency environment:
1. python >= 3.6.8
2. cmake >= 3.19.0
3. boost == 1.67.0
4. clang == 6.0.0
5. gcc == 4.9.4
6. llvm == 6.0.0


How to build:
1. In merlin_setting.sh, change MERLIN_COMPILER_HOME to your absolute path
2. Download gcc4.9.4 to $gcc_path specified in merlin_settings.sh and compile, add built library path to LD_LIBRARY_PATH in merlin_setting.sh
3. Download llvm6.0.0, clang 6.0.0, boost1.67.0 to the path specified in merlin_settings.sh, and compile all the packages with gcc4.9.4 built in step 2
4. source merlin_setting.sh
5. cd trunk/build;
6. cmake3 -DCMAKE_BUILD_TYPE=Release ..;
7. make -j;

### Run Merlin-UCLA

Please first source all the necessary paths e.g., `source /opt/tools/xilinx/Vitis_HLS/2021.1/settings64.sh`.

#### Run

```sh
merlincc
```

To print the help:

```sh
merlincc -h
```

#### Compilation Options

To select the platform please use the option:

```sh
--platform=<the platform>
#for example
--platform=vitis::/opt/xilinx/platforms/xilinx_u200_xdma_201830_2/xilinx_u200_xdma_201830_2.xpfm  
```

To change frequency please add the option:

```sh
--kernel_frequency <frequency in MHz>
# for example
--kernel_frequency 250
```

To automatically do tree reduction in logarithmic time please add the option:
```sh
-funsafe-math-optimizations
```

To change the burst single size threshold please add the option:

```sh
--attribute burst_single_size_threshold=<size>
# for example
--attribute burst_single_size_threshold=36700160
```

To change the burst total size threshold please add the option:

```sh
--attribute burst_total_size_threshold=<size>
# for example
--attribute burst_total_size_threshold=36700160
```

You can include the path of the include folder with the option `-I`. For example we use the options:

```sh
CFLAGS="-I $XILINX_HLS/include" merlincc --attribute burst_total_size_threshold=36700160 --attribute burst_single_size_threshold=36700160 --kernel_frequency 250  -funsafe-math-optimizations --platform=vitis::/opt/xilinx/platforms/xilinx_u200_xdma_201830_2/xilinx_u200_xdma_201830_2.xpfm  -I $XILINX_HLS/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/ -I $XILINX_HLS/include/ -I /opt/merlin/sources/merlin-compiler/trunk/source-opt/include/apint_include/ -c -o mykernel_merlincc_polyopt --report=estimate
```


#### Pragmas

All pragmas are applied above the loop contrary to Xilinx Vitis.

##### Mandatory Pragma
Please add `#pragma ACCEL kernel` above the main function. For example:

```C
#pragma ACCEL kernel
void kernel_bicg(int m,int n,float A[2100][1900],float s[1900],float q[2100],float p[1900],float r[2100])
{
  int i;
  int j;    
    for (i = 0; i < 1900; i++) {
      s[i] = 0;
    }
    for (i = 0; i < 2100; i++) {
      q[i] = 0.0;
      for (j = 0; j < 1900; j++) {
        s[j] = s[j] + r[i] * A[i][j];
        q[i] = q[i] + A[i][j] * p[j];
      }
    }
}
```

##### Hardware directives

###### Parallel / Unroll

`#pragma ACCEL parallel factor=<uf>`

If factor is not specify the loop is fully unrolled.

###### Pipeline

`#pragma ACCEL pipeline flatten`

The loop bellow the pragma will be pipeline and the innermost loop will be fully unrolled.

###### Tile 1D / Strip mining

`#pragma ACCEL tile factor=<tile size>`

The loop bellow the pragma will be strip mined and the innermost loop create will have a trip count equal to `tile size`.

###### Memory communication

`#pragma ACCEL cache variable=<name array>`

The transfer from off-chip to on-chip will be done at the position of the pragma cache.

###### Double buffer

`#pragma ACCEL pipeline`

The communication of the array will be done at the position of the pragma and transfer with double buffer.

Note: `#pragma ACCEL pipeline` can also be use as `#pragma ACCEL pipeline flatten` if all the innermost loop are fully unrolled.