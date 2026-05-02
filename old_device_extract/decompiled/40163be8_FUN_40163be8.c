// Function : FUN_40163be8
// Address  : 0x40163be8
// Size     : 92 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163be8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = 0;
  do {
    while( true ) {
      iVar1 = _DAT_3ffc0034;
      iVar3 = _DAT_3ffc0034 + iVar2 * 8;
      iVar5 = *(int *)(iVar3 + 0x334);
      if (iVar5 == 0) break;
      iVar4 = *(int *)(iVar5 + 0x28);
      *(int *)(iVar3 + 0x334) = iVar4;
      if (iVar4 == 0) {
        *(int *)(iVar3 + 0x338) = iVar1 + (iVar2 + 0x66) * 8 + 4;
      }
      *(undefined4 *)(iVar5 + 0x28) = 0;
      memw();
      FUN_4018a7b8();
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 2);
  iVar2 = 0;
  do {
    iVar1 = iVar2 + 1;
    FUN_40163ba8(iVar2);
    iVar2 = iVar1;
  } while (iVar1 != 0x10);
  while (iVar2 = FUN_401630f8(), iVar2 != 0) {
    FUN_4018a7b8();
  }
  FUN_40162d48();
  return;
}

