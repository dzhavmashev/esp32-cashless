// Function : FUN_40163f8c
// Address  : 0x40163f8c
// Size     : 27 bytes


undefined2 FUN_40163f8c(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = param_1 - 0x11U & 0xff;
  uVar1 = 0;
  if (uVar2 < 0xf) {
    uVar1 = *(undefined2 *)(&DAT_3f4247fc + uVar2 * 2);
  }
  return uVar1;
}

