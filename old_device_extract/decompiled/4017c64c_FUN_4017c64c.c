// Function : FUN_4017c64c
// Address  : 0x4017c64c
// Size     : 55 bytes


int FUN_4017c64c(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  iVar3 = *(int *)(param_2 + 0x10);
  iVar2 = *(int *)(param_1 + 0x10) - iVar3;
  if (iVar2 == 0) {
    puVar4 = (uint *)(param_1 + 0x14U) + iVar3;
    puVar1 = (uint *)(param_2 + 0x14 + iVar3 * 4);
    do {
      puVar4 = puVar4 + -1;
      puVar1 = puVar1 + -1;
      if (*puVar4 != *puVar1) {
        if (*puVar4 < *puVar1) {
          return -1;
        }
        return 1;
      }
    } while ((uint *)(param_1 + 0x14U) < puVar4);
  }
  return iVar2;
}

