# Read all from Stdin

```
sudo apt install build-essential g++ golang rustc ghc time
make run
```

## Results

```
## Machine

Intel(R) Pentium(R) Gold G5420 CPU @ 3.80GHz
8 GB DDR4-2400 (single module)
Samsung Pm961 512gb PCIe NVMe

## Command        Time [s]  Mem [kB]

# 1 GB rand.data (default)
./readall_c 128000  0.22  1050184
./readall_c         0.34  1050016
./readall_cpp       0.92  2100140
./readall_go        0.80  3286640
./readall_hs        0.65  2128868
./readall_rs        0.22  1050508

# 2 GB rand.data
./readall_c 128000  0.44  2099140
./readall_c         0.67  2098652
./readall_cpp       2.11  4197544
./readall_go        2.05  6566216
./readall_hs        1.47  4253876
./readall_rs        0.44  2099080
```
