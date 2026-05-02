// Function : FUN_4015b24c
// Address  : 0x4015b24c
// Size     : 34 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4015b24c(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (param_1 & 0xff) - 1;
  iVar1 = 0;
  if ((uVar2 & 0xff) < 0xe) {
    iVar1 = uVar2 * 0xc + _DAT_3ffbfdf0 + 0x54;
  }
  return iVar1;
}

