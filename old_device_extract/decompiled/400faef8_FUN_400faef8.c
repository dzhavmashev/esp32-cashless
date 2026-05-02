// Function : FUN_400faef8
// Address  : 0x400faef8
// Size     : 137 bytes


undefined4 FUN_400faef8(int *param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_400fc5a0(param_2);
  if (param_1[2] == 0) {
LAB_400faf39:
    piVar2 = (int *)(*(code *)&SUB_40094d60)(0x80);
    uVar5 = 0x101;
    if (piVar2 == (int *)0x0) goto LAB_400faf32;
    FUN_401849d0();
    iVar3 = param_1[1];
    if (iVar3 != 0) {
      *(int **)(iVar3 + 4) = piVar2;
    }
    *piVar2 = iVar3;
    piVar2[1] = 0;
    param_1[1] = (int)piVar2;
    if (*param_1 == 0) {
      *param_1 = (int)piVar2;
    }
    param_1[2] = param_1[2] + 1;
    piVar2[3] = (uint)param_3 | iVar1 << 8;
    piVar2[2] = piVar2[2] + 1;
    memw();
  }
  else {
    iVar3 = param_1[1];
    uVar4 = *(uint *)(iVar3 + 8);
    if (0x1c < uVar4) goto LAB_400faf39;
    *(uint *)(iVar3 + 8) = uVar4 + 1;
    *(byte *)(iVar3 + (uVar4 + 3) * 4) = param_3;
    memw();
    iVar3 = iVar3 + uVar4 * 4;
    *(uint *)(iVar3 + 0xc) = (uint)*(byte *)(iVar3 + 0xc) | iVar1 << 8;
  }
  uVar5 = 0;
LAB_400faf32:
  memw();
  return uVar5;
}

