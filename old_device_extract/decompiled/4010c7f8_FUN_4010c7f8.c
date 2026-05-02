// Function : FUN_4010c7f8
// Address  : 0x4010c7f8
// Size     : 33 bytes


int FUN_4010c7f8(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_4010c7bc(param_2);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x14) = param_1;
    *(undefined1 *)(iVar1 + 0x2c) = param_1;
    memw();
  }
  memw();
  return iVar1;
}

