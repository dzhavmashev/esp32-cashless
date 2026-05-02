// Function : FUN_40163b5c
// Address  : 0x40163b5c
// Size     : 73 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163b5c(int param_1)

{
  int iVar1;
  
  *(undefined4 *)
   (_DAT_3ffc0034 + ((*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x14 & 0xf) + 1) * 0x30 + 4) = 0
  ;
  memw();
  FUN_40188470();
  do {
    iVar1 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    **(uint **)(param_1 + 0x2c) = **(uint **)(param_1 + 0x2c) | 0x400000;
    memw();
    FUN_4018a7b8(param_1);
    param_1 = iVar1;
  } while (iVar1 != 0);
  return;
}

