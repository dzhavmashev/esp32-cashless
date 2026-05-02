// Function : FUN_40160384
// Address  : 0x40160384
// Size     : 106 bytes


void FUN_40160384(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x12) = 0;
  memw();
  memw();
  iVar1 = FUN_40189c90(*(undefined4 *)(param_2 + 0x24));
  if (iVar1 == 0) {
    FUN_40163cb0(param_2,1);
  }
  else {
    iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);
    if ((**(uint **)(param_2 + 0x2c) & 0x40000) != 0) {
      iVar1 = iVar1 + 4;
    }
    FUN_40163050((*(uint **)(param_2 + 0x2c))[4] >> 0x14 & 0xf,1);
    FUN_40162dac(*(uint *)(*(int *)(param_2 + 0x2c) + 4) & 0xf,iVar1 + 4,iVar1 + 10,
                 *(ushort *)(iVar1 + 0x16) >> 4);
    FUN_40162f2c(*(uint *)(*(int *)(param_2 + 0x2c) + 4) & 0xf,
                 *(uint *)(*(int *)(param_2 + 0x2c) + 0x10) >> 0x14 & 0xf);
  }
  *(undefined1 *)(param_1 + 0x13) = 8;
  memw();
  memw();
  return;
}

