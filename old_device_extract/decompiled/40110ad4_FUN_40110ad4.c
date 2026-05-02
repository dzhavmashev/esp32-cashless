// Function : FUN_40110ad4
// Address  : 0x40110ad4
// Size     : 185 bytes


undefined4 FUN_40110ad4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("lid pcb",0x6c1,"it_fast","lid pcb");
  }
  piVar5 = *(int **)(param_1 + 0x9c);
  uVar1 = 0xfa;
  if (piVar5 != (int *)0x0) {
    iVar2 = FUN_401102b4(piVar5);
    uVar1 = 0xfa;
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x9c) = *piVar5;
      for (piVar3 = (int *)(param_1 + 0x98); *piVar3 != 0; piVar3 = (int *)*piVar3) {
        iVar2 = FUN_40109eec(*(undefined4 *)(*(int *)(*piVar3 + 0xc) + 4));
        iVar4 = FUN_40109eec(*(undefined4 *)(piVar5[3] + 4));
        if (-1 < iVar2 - iVar4) break;
      }
      *piVar5 = *piVar3;
      *piVar3 = (int)piVar5;
      if (*piVar5 == 0) {
        *(undefined2 *)(param_1 + 0x94) = 0;
        memw();
      }
      if (*(char *)(param_1 + 0x6e) != -1) {
        *(char *)(param_1 + 0x6e) = *(char *)(param_1 + 0x6e) + '\x01';
        memw();
      }
      uVar1 = 0;
      *(undefined4 *)(param_1 + 0x60) = 0;
    }
  }
  memw();
  return uVar1;
}

