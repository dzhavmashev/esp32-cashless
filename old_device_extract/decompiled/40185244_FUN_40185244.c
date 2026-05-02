// Function : FUN_40185244
// Address  : 0x40185244
// Size     : 9 bytes


undefined4 FUN_40185244(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x1c0);
  }
  return uVar1;
}

