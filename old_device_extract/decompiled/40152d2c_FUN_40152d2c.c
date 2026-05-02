// Function : FUN_40152d2c
// Address  : 0x40152d2c
// Size     : 131 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40152d2c(int *param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 *local_30 [12];
  
  iVar1 = 0;
  if (((*param_1 == _DAT_3ffc8800) && (_DAT_3ffc89f4 != 0)) && (DAT_3ffc89ee == '\x03')) {
    iVar1 = 0x10;
  }
  iVar1 = FUN_4015f5c0(local_30,0x18,iVar1 + 2);
  if (iVar1 != 0) {
    if ((*param_1 == _DAT_3ffc8800) && (_DAT_3ffc89f4 != 0)) {
      **(uint **)(iVar1 + 0x2c) = **(uint **)(iVar1 + 0x2c) | 1;
      memw();
    }
    *(undefined2 *)(iVar1 + 0x14) = 0x18;
    memw();
    *local_30[0] = param_2;
    *(undefined2 *)(iVar1 + 0x16) = 2;
    memw();
    memw();
    return;
  }
  FUN_40147fe4(1,0x40,2,0x3f436aac);
  return;
}

