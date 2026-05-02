// Function : FUN_40106520
// Address  : 0x40106520
// Size     : 488 bytes


int * FUN_40106520(int *param_1,undefined4 param_2,uint param_3,int param_4,int param_5,
                  undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9,uint param_10
                  )

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined8 uVar11;
  
  uVar11 = (*(code *)&SUB_40085bfc)();
  if ((0x40 < param_3) ||
     (((bVar1 = (param_10 & 0x30000) != 0, param_5 == 0 && (bVar1)) ||
      (piVar2 = (int *)(*(code *)&SUB_40094dd8)(1,0x74), piVar2 == (int *)0x0)))) {
    piVar2 = (int *)0x0;
    goto LAB_40106538;
  }
  (*(code *)&SUB_4008b3d0)(piVar2 + 5,param_2,param_3);
  piVar2[0x15] = param_3;
  if (param_4 == 0) {
    if ((param_10 != 0x20000) && (!bVar1)) {
      FUN_40106150(param_2,param_3,param_7,param_8,piVar2 + 1,(param_10 & 0x18580) != 0 || bVar1);
    }
  }
  else {
    memw();
    (*(code *)&SUB_4008b3d0)(piVar2 + 1,param_4,0x10);
  }
  uVar11 = (*(code *)&SUB_4000c988)((int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
  (*(code *)&SUB_40002954)((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,0x412e8480);
  iVar3 = (*(code *)&SUB_40002ac4)();
  piVar2[0x16] = iVar3 + 0x83d600;
  piVar2[0x1a] = iVar3 + 0x5c4900;
  piVar2[0x17] = param_10;
  memw();
  (*(code *)&SUB_4008b3d0)(piVar2 + 0x18,param_7,6);
  piVar2[0x1b] = param_9;
  piVar6 = (int *)0x0;
  for (piVar8 = (int *)*param_1; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
    memw();
    iVar3 = (*(code *)&SUB_4008b33c)(param_7,piVar8 + 0x18,6);
    if (iVar3 == 0) {
      uVar10 = piVar8[0x15];
      if (uVar10 == param_3) {
        memw();
        iVar3 = (*(code *)&SUB_4008b33c)(piVar8 + 5,param_2,param_3);
        if ((iVar3 == 0) &&
           (iVar3 = (*(code *)&SUB_4008b33c)(piVar8 + 1,piVar2 + 1,0x10,uVar10), iVar3 == 0)) {
          (*(code *)&SUB_40094d80)(piVar2);
          piVar2 = piVar8;
          goto LAB_40106538;
        }
      }
      if (piVar6 == (int *)0x0) {
        *param_1 = *piVar8;
      }
      else {
        *piVar6 = *piVar8;
        memw();
      }
      if (piVar8[0x1c] == 0) {
        memw();
        FUN_401064a8(param_1,param_9,piVar8 + 5,uVar10);
      }
      FUN_401063cc(param_1,piVar8,1);
      break;
    }
    piVar6 = piVar8;
  }
  if ((9 < param_1[1]) && (puVar4 = (undefined4 *)*param_1, puVar4 != (undefined4 *)0x0)) {
    puVar9 = (undefined4 *)*puVar4;
    if (*(undefined4 **)(param_1[2] + 0x1c0) == puVar4) {
      uVar7 = 0;
      if (puVar9 != (undefined4 *)0x0) {
        uVar7 = *puVar9;
      }
      *puVar4 = uVar7;
      puVar4 = puVar9;
      if (puVar9 == (undefined4 *)0x0) goto LAB_401066b1;
    }
    else {
      *param_1 = (int)puVar9;
      memw();
    }
    memw();
    FUN_401063cc(param_1,puVar4,0);
  }
LAB_401066b1:
  piVar6 = (int *)*param_1;
  piVar8 = (int *)0x0;
  while ((piVar5 = piVar6, piVar5 != (int *)0x0 && (piVar5[0x16] <= piVar2[0x16]))) {
    piVar8 = piVar5;
    piVar6 = (int *)*piVar5;
  }
  if (piVar8 == (int *)0x0) {
    *piVar2 = *param_1;
    *param_1 = (int)piVar2;
    memw();
    FUN_401063f0(param_1);
  }
  else {
    *piVar2 = *piVar8;
    *piVar8 = (int)piVar2;
    memw();
  }
  param_1[1] = param_1[1] + 1;
  memw();
LAB_40106538:
  memw();
  return piVar2;
}

