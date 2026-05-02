// Function : FUN_40147720
// Address  : 0x40147720
// Size     : 186 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40147720(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _DAT_3ffc8804;
  iVar1 = _DAT_3ffc8800;
  if (_DAT_3ffc8800 != 0) {
    *(undefined4 *)(_DAT_3ffc8800 + 0x158) = 0;
    memw();
    iVar3 = FUN_4015469c(iVar1,*(undefined1 *)(_DAT_3ffbfc54 + 0x9c));
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x158) = 0;
    memw();
    iVar3 = FUN_4015469c(iVar2,*(undefined1 *)(_DAT_3ffbfc54 + 0x3fa));
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  _DAT_3ffc8810 = 100;
  memw();
  memw();
  FUN_4018688c(&DAT_3ffc87f0);
  FUN_40154bf8(&DAT_3ffc87f0);
  if ((iVar1 != 0) && (*(char *)(_DAT_3ffbfc54 + 0x9c) == '\x03')) {
    FUN_4014a9bc(iVar1);
  }
  if ((iVar2 != 0) && (*(char *)(_DAT_3ffbfc54 + 0x3fa) == '\x03')) {
    FUN_4014a9bc(iVar2);
  }
  FUN_40147694();
  FUN_40155364(&DAT_3ffc87f0);
  FUN_4015ee60();
  _DAT_3ffc8864 = 0;
  _DAT_3ffc8874 = 0;
  memw();
  FUN_401476e8();
  FUN_401476b8();
  FUN_401550c4();
  return 0;
}

