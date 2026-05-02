// Function : FUN_4015549c
// Address  : 0x4015549c
// Size     : 118 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015549c(void)

{
  int iVar1;
  
  if ((*(byte *)(_DAT_3ffbfd50 + 0x46) & 1) != 0) {
    FUN_40147fe4(1,8,4,0x3f433a78,*(byte *)(_DAT_3ffbfd50 + 0x46),
                 *(undefined1 *)(_DAT_3ffbfd50 + 0x47));
    iVar1 = _DAT_3ffbfd50;
    *(undefined1 *)(_DAT_3ffbfd50 + 0x46) = 0;
    *(undefined1 *)(iVar1 + 0x47) = 0;
    memw();
    memw();
    FUN_4015b14c();
    (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffbfd50 + 0x18);
    (**(code **)(_DAT_3ffc1a34 + 0xec))(_DAT_3ffbfd50 + 4);
    if ((_DAT_3ffc8864 != 0) && (*(int *)(_DAT_3ffbfd50 + 0x3c) == 0)) {
      return 0;
    }
  }
  if ((_DAT_3ffc8864 != 0) && (*(int *)(_DAT_3ffbfd50 + 0x3c) == 0)) {
    return 0xffffffff;
  }
  return 0;
}

