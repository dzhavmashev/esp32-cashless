// Function : FUN_4012c394
// Address  : 0x4012c394
// Size     : 286 bytes


undefined4 FUN_4012c394(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = param_1[0x11];
  uVar3 = *(uint *)(*(int *)(iVar2 + 0x14) + 0x10);
  if (uVar3 != 7) {
    if (uVar3 < 8) {
      if (3 < uVar3 - 1) goto LAB_4012c439;
    }
    else if (1 < uVar3 - 9) {
LAB_4012c439:
      uVar5 = 0;
      param_1[1] = param_1[1] + 1;
      goto LAB_4012c441;
    }
  }
  iVar4 = *param_1;
  if (*(char *)(iVar4 + 4) == '\0') {
    if (param_1[0x3a] == 0) {
      param_1[1] = param_1[1] + 1;
      memw();
      uVar5 = 0;
      goto LAB_4012c441;
    }
  }
  else if (*(char *)(iVar4 + 4) == '\x01') {
    piVar1 = *(int **)(iVar2 + 0x1e4);
    if (piVar1 == (int *)0x0) {
      piVar1 = *(int **)(iVar4 + 0xa0);
      uVar5 = 0xffff8a80;
      if (piVar1 == (int *)0x0) goto LAB_4012c441;
    }
    uVar5 = 0xffff8a80;
    if (*piVar1 == 0) goto LAB_4012c441;
  }
  piVar1 = *(int **)(iVar2 + 0x1e4);
  if ((piVar1 == (int *)0x0) && (piVar1 = *(int **)(iVar4 + 0xa0), piVar1 == (int *)0x0)) {
    iVar4 = 7;
  }
  else {
    iVar4 = 7;
    for (iVar2 = *piVar1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x154)) {
      uVar3 = *(uint *)(iVar2 + 8);
      if (0x3ffdU - iVar4 < uVar3) {
        uVar5 = 0xffff8b00;
        goto LAB_4012c441;
      }
      *(char *)(param_1[0x33] + iVar4) = (char)(uVar3 >> 0x10);
      memw();
      *(char *)(param_1[0x33] + iVar4 + 1) = (char)(uVar3 >> 8);
      memw();
      *(char *)(param_1[0x33] + iVar4 + 2) = (char)uVar3;
      memw();
      memw();
      (*(code *)&SUB_4008b3d0)(param_1[0x33] + iVar4 + 3,*(undefined4 *)(iVar2 + 0xc),uVar3);
      iVar4 = uVar3 + iVar4 + 3;
    }
  }
  iVar2 = iVar4 + -7;
  *(char *)(param_1[0x33] + 4) = (char)((uint)iVar2 >> 0x10);
  memw();
  *(char *)(param_1[0x33] + 5) = (char)((uint)iVar2 >> 8);
  memw();
  *(char *)(param_1[0x33] + 6) = (char)iVar2;
  memw();
  param_1[0x34] = 0x16;
  param_1[0x35] = iVar4;
  *(undefined1 *)param_1[0x33] = 0xb;
  memw();
  param_1[1] = param_1[1] + 1;
  memw();
  uVar5 = FUN_4012a534(param_1);
LAB_4012c441:
  memw();
  return uVar5;
}

