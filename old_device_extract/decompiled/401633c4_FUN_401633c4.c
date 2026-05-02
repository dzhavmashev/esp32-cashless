// Function : FUN_401633c4
// Address  : 0x401633c4
// Size     : 50 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401633c4(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (iVar2 + 200) * 4;
    if (*(int *)(_DAT_3ffc0034 + iVar1) != 0) {
      FUN_4018a7b8();
      *(undefined4 *)(_DAT_3ffc0034 + iVar1) = 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 4);
  memw();
  FUN_4015f7b4();
  return;
}

