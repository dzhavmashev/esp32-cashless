// Function : FUN_40163c48
// Address  : 0x40163c48
// Size     : 104 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163c48(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 0x2c) + 0x10);
  uVar1 = FUN_40187ce0(*(uint *)(*(int *)(param_1 + 0x2c) + 4) >> 4 & 0xf);
  uVar2 = uVar2 >> 0x14 & 0xf;
  *(undefined4 *)(_DAT_3ffc0034 + (uVar2 + 1) * 0x30 + 4) = 0;
  memw();
  FUN_40188470(uVar2);
  while( true ) {
    iVar3 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    **(uint **)(param_1 + 0x2c) = **(uint **)(param_1 + 0x2c) | 0x400000;
    if (iVar3 == 0) break;
    memw();
    FUN_401604bc(uVar1,param_1,0);
    param_1 = iVar3;
  }
  FUN_401604bc(uVar1,param_1,param_2);
  return;
}

