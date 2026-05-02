// Function : FUN_4015a178
// Address  : 0x4015a178
// Size     : 24 bytes


undefined4 FUN_4015a178(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0xff) < 0x19) {
    uVar1 = *(undefined4 *)(&DAT_3ffc8930 + (param_1 & 0xff) * 4);
  }
  return uVar1;
}

