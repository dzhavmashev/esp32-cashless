// Function : FUN_400fe380
// Address  : 0x400fe380
// Size     : 90 bytes


void FUN_400fe380(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (param_2 == 0) {
    memw();
    uVar1 = *(uint *)(iVar2 + 0x20) & 0xfffffeff;
  }
  else {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0x40) = *(uint *)(iVar2 + 0x40) & 0xf00fffff | (param_2 & 0xff) << 0x14;
    memw();
    uVar1 = *(uint *)(iVar2 + 0x20) | 0x100;
  }
  memw();
  *(uint *)(iVar2 + 0x20) = uVar1;
  memw();
  return;
}

