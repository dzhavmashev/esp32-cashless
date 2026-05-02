// Function : FUN_400f7cec
// Address  : 0x400f7cec
// Size     : 26 bytes


void FUN_400f7cec(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1 < 3) && (iVar1 = *(int *)(param_1 * 4 + 0x3ffc5588), iVar1 != 0)) {
    *(undefined4 *)(iVar1 + 0xd0) = param_2;
  }
  memw();
  return;
}

