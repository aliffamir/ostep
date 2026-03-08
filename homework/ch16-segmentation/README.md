# Segmentation

## Q1
```
segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 0

ARG seed 0
ARG address space size 128
ARG phys mem size 512

Segment register information:

  Segment 0 base  (grows positive) : 0x00000000 (decimal 0)
  Segment 0 limit                  : 20

  Segment 1 base  (grows negative) : 0x00000200 (decimal 512)
  Segment 1 limit                  : 20

Virtual Address Trace
  VA  0: 0x0000006c (decimal:  108) --> segmentation violation
  VA  1: 0x00000061 (decimal:   97) --> segmentation violation
  VA  2: 0x00000035 (decimal:   53) --> segmentation violation
  VA  3: 0x00000021 (decimal:   33) --> segmentation violation
  VA  4: 0x00000041 (decimal:   65) --> segmentation violation


segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512
-L 20 -s 1

segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512
-L 20 -s 2

```

