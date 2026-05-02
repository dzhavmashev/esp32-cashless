// Function : FUN_40110988
// Address  : 0x40110988
// Size     : 139 bytes


undefined1 FUN_40110988(int param_1)

{
  ushort uVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("lid pcb",0x3eb,"e_flags"," length");
  }
  piVar2 = *(int **)(param_1 + 0x98);
  if (*(int **)(param_1 + 0x98) != (int *)0x0) {
    do {
      piVar5 = piVar2;
      piVar2 = (int *)*piVar5;
    } while ((int *)*piVar5 != (int *)0x0);
    uVar4 = FUN_40185288(*(undefined2 *)(piVar5[3] + 0xc));
    if ((uVar4 & 7) == 0) {
      uVar1 = *(ushort *)(piVar5[3] + 0xc);
      uVar4 = FUN_40185288(1);
      iVar6 = piVar5[3];
      uVar4 = (uint)uVar1 | uVar4 & 0xffff;
      *(char *)(iVar6 + 0xc) = (char)uVar4;
      memw();
      uVar1 = *(ushort *)(param_1 + 0x46);
      *(char *)(iVar6 + 0xd) = (char)(uVar4 >> 8);
      *(ushort *)(param_1 + 0x46) = uVar1 | 0x20;
      memw();
      uVar3 = 0;
      goto LAB_40110a11;
    }
  }
  uVar3 = FUN_40110868(param_1,1);
LAB_40110a11:
  memw();
  return uVar3;
}

