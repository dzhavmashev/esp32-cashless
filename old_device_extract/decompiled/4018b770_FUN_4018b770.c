// Function : FUN_4018b770
// Address  : 0x4018b770
// Size     : 32 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018b770(int param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _DAT_3ffc06fc;
  _DAT_3ffc06fc = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 8) = 0;
  memw();
  FUN_4018c68c(uVar1,param_1,param_2);
  return;
}

