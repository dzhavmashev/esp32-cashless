// Function : FUN_4015168c
// Address  : 0x4015168c
// Size     : 114 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4015168c(void)

{
  int iVar1;
  
  iVar1 = (uint)*(byte *)(_DAT_3ffbfc54 + 0x9f) * 0x8c;
  (*(code *)&SUB_4008b530)(_DAT_3ffbfc54 + iVar1 + 0xa0,0,0x8c);
  (*(code *)&SUB_4008b530)(_DAT_3ffbfc54 + iVar1 + 0x10b,0xff,0x20);
  DAT_3ffc89f2 = 1;
  memw();
  memw();
  iVar1 = FUN_40150e8c(0xd,_DAT_3ffbfc54 + 0xa0,DAT_3ffc8a05 == '\0');
  if (iVar1 == 0) {
    iVar1 = FUN_40150e38();
  }
  return iVar1;
}

