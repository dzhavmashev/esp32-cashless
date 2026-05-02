// Function : FUN_401630f8
// Address  : 0x401630f8
// Size     : 37 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401630f8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _DAT_3ffc0034;
  iVar2 = *(int *)(_DAT_3ffc0034 + 0x344);
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + 0x28);
    *(int *)(_DAT_3ffc0034 + 0x344) = iVar3;
    if (iVar3 == 0) {
      *(int *)(iVar1 + 0x348) = iVar1 + 0x344;
    }
    *(undefined4 *)(iVar2 + 0x28) = 0;
  }
  memw();
  return;
}

