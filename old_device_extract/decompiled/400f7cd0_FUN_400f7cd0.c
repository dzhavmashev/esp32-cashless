// Function : FUN_400f7cd0
// Address  : 0x400f7cd0
// Size     : 27 bytes


undefined4 FUN_400f7cd0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 < 3) && (*(int *)(param_1 * 4 + 0x3ffc5588) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

