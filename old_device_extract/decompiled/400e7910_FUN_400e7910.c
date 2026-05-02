// Function : FUN_400e7910
// Address  : 0x400e7910
// Size     : 22 bytes


undefined4 FUN_400e7910(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 3) {
    uVar1 = *(undefined4 *)(&DAT_3ffc51ac + param_1 * 4);
  }
  return uVar1;
}

