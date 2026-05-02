// Function : FUN_400e78f4
// Address  : 0x400e78f4
// Size     : 28 bytes


int FUN_400e78f4(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)&DAT_3ffc51ac;
  iVar1 = 0;
  while ((*piVar2 != param_1 || (*piVar2 == 0))) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
    if (iVar1 == 3) {
      return 3;
    }
  }
  return iVar1;
}

