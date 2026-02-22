# Homework (simulation) relocation.py

## Q1
### Seed 1
Base-and-Bounds register information:

  Base   : 0x0000363c (decimal 13884)
  Limit  : 290

Virtual Address Trace
  VA  0: 0x0000030e (decimal:  782) --> segmentation violation
  VA  1: 0x00000105 (decimal:  261) --> PA = 0x00003741
  VA  2: 0x000001fb (decimal:  507) --> segmentation violation
  VA  3: 0x000001cc (decimal:  460) --> segmentation violation
  VA  4: 0x0000029b (decimal:  667) --> segmentation violation

### Seed 2
Base-and-Bounds register information:

  Base   : 0x00003ca9 (decimal 15529)
  Limit  : 500

Virtual Address Trace
  VA  0: 0x00000039 (decimal:   57) --> PA = 0x00003ce2
  VA  1: 0x00000056 (decimal:   86) --> PA = 0x00003cff
  VA  2: 0x00000357 (decimal:  855) --> segmentation violation
  VA  3: 0x000002f1 (decimal:  753) --> segmentation violation
  VA  4: 0x000002ad (decimal:  685) --> segmentation violation

### Seed 3
Base-and-Bounds register information:

  Base   : 0x000022d4 (decimal 8916)
  Limit  : 316

Virtual Address Trace
  VA  0: 0x0000017a (decimal:  378) --> segmentation violation
  VA  1: 0x0000026a (decimal:  618) --> segmentation violation
  VA  2: 0x00000280 (decimal:  640) --> segmentation violation
  VA  3: 0x00000043 (decimal:   67) --> PA = 0x00002317
  VA  4: 0x0000000d (decimal:   13) --> PA = 0x000022e1

## Q2
-l (limit size) has to be set to the maximum virtual address + 1 = 930

## Q3
-s 1 -n 10 -l 100

16 KB = 16 x 1024 = 16384 bytes

max base address = 16384 - 100 = 16284
