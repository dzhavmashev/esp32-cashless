// Function : FUN_4015b570
// Address  : 0x4015b570
// Size     : 69 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015b570(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_3ffbfdf0;
  iVar2 = _DAT_3ffbfdf0 + 0x50;
  memw();
  FUN_40147fe4(1,8,5,0x3f436236,*(undefined1 *)(_DAT_3ffbfdf0 + 0x50),
               *(undefined1 *)(_DAT_3ffbfdf0 + 0x51),*(undefined1 *)(_DAT_3ffbfdf0 + 0x52),
               *(undefined1 *)(_DAT_3ffbfdf0 + 0x53));
  if ((*(char *)(iVar1 + 0x50) != *(char *)(iVar1 + 0x52)) ||
     (*(char *)(iVar1 + 0x51) != *(char *)(iVar1 + 0x53))) {
    FUN_4015b284(iVar2);
  }
  return;
}

