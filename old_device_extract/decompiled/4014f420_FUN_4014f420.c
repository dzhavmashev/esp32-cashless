// Function : FUN_4014f420
// Address  : 0x4014f420
// Size     : 105 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4014f420(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (1 < DAT_3ffc89d9) {
    return 0;
  }
  iVar2 = FUN_40186968();
  if (iVar2 != 0) {
    return iVar2;
  }
  FUN_4015182c();
  uVar3 = 3;
  cVar1 = *_DAT_3ffbfc54;
  if ((cVar1 != '\0') && (uVar3 = 0, cVar1 != '\x01')) {
    if (cVar1 != '\x02') {
      if (cVar1 != '\x03') goto LAB_4014f468;
      FUN_4014ebe0(0);
    }
    uVar3 = 1;
  }
  FUN_4014ebe0(uVar3);
LAB_4014f468:
  iVar2 = FUN_40147a54(cVar1);
  if ((iVar2 == 0) && (iVar2 = FUN_4014dda8(cVar1), iVar2 == 0)) {
    DAT_3ffc89d9 = 2;
    memw();
    memw();
    FUN_40154e0c();
  }
  return iVar2;
}

