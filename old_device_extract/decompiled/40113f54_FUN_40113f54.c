// Function : FUN_40113f54
// Address  : 0x40113f54
// Size     : 28 bytes


int FUN_40113f54(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_40113f2c();
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x14) = param_1;
    *(undefined1 *)(iVar1 + 0x2c) = param_1;
    memw();
  }
  memw();
  return iVar1;
}

