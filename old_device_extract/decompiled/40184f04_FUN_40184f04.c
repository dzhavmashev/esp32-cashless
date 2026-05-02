// Function : FUN_40184f04
// Address  : 0x40184f04
// Size     : 19 bytes


undefined4 FUN_40184f04(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    uVar1 = *(undefined4 *)(param_1 + 0x40);
  }
  else if (param_2 == 2) {
    uVar1 = *(undefined4 *)(param_1 + 0x44);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

