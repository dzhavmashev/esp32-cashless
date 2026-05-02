// Function : FUN_400e7928
// Address  : 0x400e7928
// Size     : 32 bytes


undefined4 FUN_400e7928(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 3) {
    uVar1 = FUN_40101600(*(undefined4 *)(&DAT_3ffc51ac + param_1 * 4),param_2);
  }
  return uVar1;
}

