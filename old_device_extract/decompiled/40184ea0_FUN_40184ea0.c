// Function : FUN_40184ea0
// Address  : 0x40184ea0
// Size     : 28 bytes


undefined4 FUN_40184ea0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x102;
  if (param_1 != 0) {
    uVar1 = 0x102;
    if ((*(uint *)(param_1 + 0x48) & 2) == 0) {
      *param_2 = *(undefined4 *)(param_1 + 0x34);
      uVar1 = 0;
    }
  }
  memw();
  return uVar1;
}

