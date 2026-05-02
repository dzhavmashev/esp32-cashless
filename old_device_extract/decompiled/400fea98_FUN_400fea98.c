// Function : FUN_400fea98
// Address  : 0x400fea98
// Size     : 36 bytes


undefined4 FUN_400fea98(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0x40) {
    uVar1 = FUN_400fea78((int)(char)(&DAT_3ffbdd4d)[param_1 * 3]);
  }
  return uVar1;
}

