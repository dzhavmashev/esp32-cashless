// Function : FUN_40110a18
// Address  : 0x40110a18
// Size     : 187 bytes


undefined4 FUN_40110a18(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("lid pcb",0x663,"_commit","lid pcb");
  }
  piVar6 = *(int **)(param_1 + 0x9c);
  uVar7 = 0xfa;
  piVar4 = piVar6;
  if (piVar6 != (int *)0x0) {
    do {
      piVar5 = (int *)*piVar4;
      if (piVar5 == (int *)0x0) {
        iVar2 = FUN_401102b4(piVar4);
        uVar7 = 0xfa;
        if (iVar2 == 0) {
          *piVar4 = *(int *)(param_1 + 0x98);
          *(int **)(param_1 + 0x98) = piVar6;
          iVar2 = piVar4[3];
          *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 0x800;
          memw();
          *(undefined4 *)(param_1 + 0x9c) = 0;
          memw();
          iVar2 = FUN_40109eec(*(undefined4 *)(iVar2 + 4));
          uVar1 = *(ushort *)(piVar4 + 2);
          uVar3 = FUN_40185288(*(undefined2 *)(piVar4[3] + 0xc));
          *(uint *)(param_1 + 0x78) = (uint)((uVar3 & 3) != 0) + iVar2 + (uint)uVar1;
          *(undefined4 *)(param_1 + 0x60) = 0;
          uVar7 = 0;
        }
        goto LAB_40110abe;
      }
      iVar2 = FUN_401102b4(piVar4);
      piVar4 = piVar5;
    } while (iVar2 == 0);
    uVar7 = 0xfa;
  }
LAB_40110abe:
  memw();
  return uVar7;
}

