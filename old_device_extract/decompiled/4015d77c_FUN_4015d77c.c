// Function : FUN_4015d77c
// Address  : 0x4015d77c
// Size     : 141 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_4015d77c(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = _DAT_3ffc8804;
  uVar4 = 1;
  while( true ) {
    if (*(byte *)(_DAT_3ffbfc54 + 0x3f6) < uVar4) {
      return (int *)0x0;
    }
    if (*(int *)(uVar4 * 4 + _DAT_3ffc8804 + 0xec) == 0) break;
    uVar4 = uVar4 + 1 & 0xff;
  }
  piVar2 = (int *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x3a8);
  iVar5 = uVar4 * 4 + iVar1;
  *(int **)(iVar5 + 0xec) = piVar2;
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  memw();
  FUN_4015c3d8(piVar2,iVar1);
  *(char *)(piVar2 + 0x4d) = (char)uVar4 + '\a';
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(*(int *)(iVar5 + 0xec) + 4,param_1,6);
  uVar3 = *(uint *)(iVar1 + 300);
  *piVar2 = iVar1;
  *(uint *)(iVar1 + 300) = uVar3 | 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
  memw();
  return piVar2;
}

