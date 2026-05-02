// Function : FUN_400fe144
// Address  : 0x400fe144
// Size     : 282 bytes


void FUN_400fe144(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | 0x8000000;
  memw();
  iVar2 = 80000000;
  if ((*(uint *)(iVar1 + 0x20) & 0x8000000) == 0) {
    iVar2 = 1000000;
  }
  memw();
  memw();
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xfff00000 | (uint)(iVar2 << 4) / 0x1c2000;
  memw();
  memw();
  *(uint *)(iVar1 + 0x14) =
       *(uint *)(iVar1 + 0x14) & 0xff0fffff | ((uint)(iVar2 << 4) / 0x1c200 & 0xf) << 0x14;
  memw();
  memw();
  *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) & 0xfffffffe;
  memw();
  memw();
  *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) & 0xfffffff7;
  memw();
  memw();
  *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) & 0xffffffef;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffeffff;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffffd;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | 0xc;
  memw();
  memw();
  *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) & 0xfffffffb;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xffffffcf | 0x10;
  memw();
  memw();
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfff003ff;
  memw();
  memw();
  *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & 0xff7fffff;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xffff7fff;
  memw();
  return;
}

