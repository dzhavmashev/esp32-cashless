// Function : FUN_40184e80
// Address  : 0x40184e80
// Size     : 24 bytes


undefined4 FUN_40184e80(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x102;
  if ((param_1 != 0) && ((*(uint *)(param_1 + 0x48) & 1) == 0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x38);
    uVar1 = 0;
  }
  memw();
  return uVar1;
}

