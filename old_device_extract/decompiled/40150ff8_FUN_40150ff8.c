// Function : FUN_40150ff8
// Address  : 0x40150ff8
// Size     : 97 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40150ff8(void)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = FUN_40155040();
  iVar4 = FUN_40155000();
  iVar1 = _DAT_3ffbfc54;
  if (*(char *)(_DAT_3ffbfc54 + 0x3fc) == '\x01') {
    if (((int)(uint)*(byte *)(_DAT_3ffbfc54 + 0x3f3) < iVar4 + -3) &&
       (*(byte *)(_DAT_3ffbfc54 + 0x3f3) < 10)) goto LAB_4015103c;
    uVar2 = 2;
  }
  else {
    if ((*(char *)(_DAT_3ffbfc54 + 0x3fc) != '\x02') ||
       (iVar3 + 3 < (int)(uint)*(byte *)(_DAT_3ffbfc54 + 0x3f3))) goto LAB_4015103c;
    uVar2 = 1;
  }
  *(undefined1 *)(_DAT_3ffbfc54 + 0x3fc) = uVar2;
  memw();
LAB_4015103c:
  memw();
  FUN_40150e8c(0x21,*(undefined1 *)(iVar1 + 0x3fc),DAT_3ffc8a05 == '\0');
  return;
}

