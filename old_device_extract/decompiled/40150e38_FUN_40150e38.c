// Function : FUN_40150e38
// Address  : 0x40150e38
// Size     : 56 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40150e38(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40165e64();
  uVar2 = 0;
  if ((iVar1 != 0) && (uVar2 = 0, DAT_3ffc8a05 == '\0')) {
    uVar2 = 0xffffffff;
    if ((_DAT_3ffbfc54 != 0) && (*(int *)(_DAT_3ffbfc54 + 0x494) != 0)) {
      uVar2 = (**(code **)(_DAT_3ffc1a34 + 0x134))(*(int *)(_DAT_3ffbfc54 + 0x494));
    }
  }
  return uVar2;
}

