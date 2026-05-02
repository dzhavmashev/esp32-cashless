// Function : FUN_4015b18c
// Address  : 0x4015b18c
// Size     : 53 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015b18c(byte param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(_DAT_3ffbfdf0 + 0x4c) != '\0') {
    uVar2 = 3;
    if (*(byte *)(_DAT_3ffbfdf0 + 0x4d) < param_1) goto LAB_4015b1bc;
    FUN_4015b14c();
  }
  iVar1 = _DAT_3ffbfdf0;
  *(undefined1 *)(_DAT_3ffbfdf0 + 0x4c) = 1;
  uVar2 = 0;
  *(byte *)(iVar1 + 0x4d) = param_1;
  memw();
  *(undefined4 *)(iVar1 + 0x1c) = param_2;
  *(undefined4 *)(iVar1 + 0x20) = param_3;
LAB_4015b1bc:
  memw();
  return uVar2;
}

