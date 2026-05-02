// Function : FUN_40129ce0
// Address  : 0x40129ce0
// Size     : 69 bytes


int FUN_40129ce0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 200) - *(int *)(param_1 + 0xc0);
  piVar2 = *(int **)(param_1 + 0x4c);
  if (piVar2 == (int *)0x0) {
    return iVar1;
  }
  iVar5 = piVar2[0x14];
  if (iVar5 == 0) {
    return -0x6c00;
  }
  uVar4 = *(uint *)(iVar5 + 4);
  if (uVar4 < 9) {
    if (uVar4 < 6) {
      if (uVar4 != 2) {
        return -0x6c00;
      }
      iVar3 = *(int *)(iVar5 + 0x18) + piVar2[3];
      if (1 < *(int *)(param_1 + 0x14)) {
        iVar3 = iVar3 + *(int *)(iVar5 + 0x18);
      }
      goto LAB_40129d12;
    }
  }
  else if (uVar4 != 10) {
    return -0x6c00;
  }
  iVar3 = *piVar2;
LAB_40129d12:
  return iVar1 + iVar3;
}

