// Function : FUN_400fad94
// Address  : 0x400fad94
// Size     : 193 bytes


int FUN_400fad94(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  uVar1 = (**(code **)(*param_2 + 8))(param_2);
  piVar2 = (int *)FUN_400facd8(param_1,uVar1);
  if (piVar2 == (int *)0x0) {
    piVar3 = (int *)(*(code *)&SUB_40094d60)(0x68);
    iVar6 = 0x101;
    if (piVar3 == (int *)0x0) goto LAB_400fae0e;
    *piVar3 = 0;
    piVar3[1] = 0;
    piVar3[4] = 0;
    piVar3[5] = 0;
    piVar3[6] = 0;
    piVar3[7] = 0;
    piVar3[8] = 0;
    piVar3[9] = 0;
    piVar3[10] = 0;
    piVar3[0xe] = 0;
    piVar3[0xf] = 0;
    piVar3[0x10] = 0;
    piVar3[0x19] = 0;
    piVar3[2] = (int)param_2;
    piVar2 = piVar3;
  }
  else {
    for (piVar5 = *(int **)(param_1 + 0x1c); piVar3 = (int *)0x0, piVar5 != (int *)0x0;
        piVar5 = (int *)piVar5[2]) {
      if (piVar5 == param_2) {
        FUN_40184968(param_1 + 0x1c,piVar5);
        (**(code **)(*piVar5 + 4))(piVar5);
        piVar3 = (int *)0x0;
        break;
      }
    }
  }
  memw();
  iVar6 = FUN_400fa890(piVar2,param_3,param_4);
  if (piVar3 != (int *)0x0) {
    if (iVar6 == 0) {
      iVar4 = *(int *)(param_1 + 0x14);
      if (iVar4 != 0) {
        *(int **)(iVar4 + 4) = piVar3;
      }
      *piVar3 = iVar4;
      piVar3[1] = 0;
      *(int **)(param_1 + 0x14) = piVar3;
      if (*(int *)(param_1 + 0x10) == 0) {
        *(int **)(param_1 + 0x10) = piVar3;
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    }
    else {
      memw();
      FUN_400fa720(piVar3);
      (*(code *)&SUB_40094d80)(piVar3);
    }
  }
LAB_400fae0e:
  memw();
  return iVar6;
}

