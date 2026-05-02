// Function : FUN_4017c9cc
// Address  : 0x4017c9cc
// Size     : 78 bytes


undefined4 FUN_4017c9cc(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = (int)param_2 >> 5;
  iVar3 = iVar1;
  if ((((iVar1 < iVar2) || (iVar3 = iVar2, iVar1 <= iVar2)) || ((param_2 & 0x1f) == 0)) ||
     (piVar5[iVar2] == ((uint)piVar5[iVar2] >> (param_2 & 0x1f)) << 0x20 - (0x20 - (param_2 & 0x1f))
     )) {
    piVar4 = piVar5 + iVar3;
    do {
      if (piVar4 <= piVar5) {
        return 0;
      }
      piVar4 = piVar4 + -1;
    } while (*piVar4 == 0);
  }
  return 1;
}

