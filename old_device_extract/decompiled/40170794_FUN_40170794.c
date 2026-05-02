// Function : FUN_40170794
// Address  : 0x40170794
// Size     : 113 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40170794(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 local_30 [12];
  
  piVar1 = (int *)(param_1 + -0x10);
  local_30[0] = 0x3ffc7eac;
  FUN_40170734(0x3ffc7eac);
  iVar3 = 0x3ffc7eac;
  if (_DAT_3ffc7eb0 == (int *)0x0) {
LAB_401707b0:
    *(int **)(param_1 + -0xc) = _DAT_3ffc7eb0;
  }
  else {
    iVar6 = *piVar1;
    piVar7 = (int *)((int)piVar1 + iVar6);
    if (piVar7 < _DAT_3ffc7eb0) goto LAB_401707b0;
    piVar8 = (int *)&DAT_3ffc7eb0;
    piVar5 = _DAT_3ffc7eb0;
    if (_DAT_3ffc7eb0 == piVar7) {
      iVar4 = *_DAT_3ffc7eb0;
      *(int *)(param_1 + -0xc) = _DAT_3ffc7eb0[1];
      *piVar1 = iVar4 + iVar6;
    }
    else {
      while ((piVar2 = (int *)piVar5[1], piVar2 != (int *)0x0 && (piVar7 < piVar2))) {
        piVar8 = piVar5 + 1;
        piVar5 = piVar2;
      }
      if (piVar7 == piVar2) {
        iVar6 = iVar6 + *piVar7;
        piVar5[1] = piVar7[1];
      }
      piVar7 = (int *)*piVar8;
      if (piVar1 == (int *)((int)piVar7 + *piVar7)) {
        *piVar7 = *piVar7 + iVar6;
        goto LAB_401707ff;
      }
      iVar3 = piVar7[1];
      *piVar1 = iVar6;
      *(int *)(param_1 + -0xc) = iVar3;
      iVar3 = *piVar8;
    }
  }
  *(int **)(iVar3 + 4) = piVar1;
LAB_401707ff:
  FUN_40170758(local_30);
  return;
}

