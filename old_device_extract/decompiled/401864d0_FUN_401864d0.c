// Function : FUN_401864d0
// Address  : 0x401864d0
// Size     : 9 bytes


undefined4 FUN_401864d0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 4);
  }
  return uVar1;
}

