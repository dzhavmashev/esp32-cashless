// Function : FUN_400fc864
// Address  : 0x400fc864
// Size     : 179 bytes


undefined4 FUN_400fc864(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  
  iVar1 = FUN_400fc730(param_1);
  if (iVar1 == 0) {
    return 2;
  }
  piVar2 = (int *)(*(code *)&SUB_400916b4)(0);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)(*(code *)&SUB_40094dd8)(1,4);
    if (piVar2 != (int *)0x0) {
      (*(code *)&SUB_40091684)(0,0,piVar2,0x400fc758);
      goto LAB_400fc8a1;
    }
LAB_400fc88c:
    uVar6 = 0xc;
  }
  else {
LAB_400fc8a1:
    piVar8 = (int *)*piVar2;
    for (piVar3 = piVar8; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
      if (param_1 == *piVar3) {
        if (param_2 == 0) {
          if (piVar8 == piVar3) {
            *piVar2 = piVar3[2];
          }
          else {
            do {
              piVar2 = piVar8;
              piVar8 = (int *)piVar2[2];
            } while (piVar8 != piVar3);
            piVar2[2] = piVar3[2];
            memw();
          }
          memw();
          (*(code *)&SUB_40094d80)(piVar3);
        }
        else {
          piVar3[1] = param_2;
        }
        goto LAB_400fc8d6;
      }
    }
    if (param_2 != 0) {
      piVar3 = (int *)(*(code *)&SUB_40094d60)(0xc);
      if (piVar3 == (int *)0x0) goto LAB_400fc88c;
      piVar3[1] = param_2;
      iVar5 = *piVar2;
      *piVar3 = param_1;
      iVar1 = iVar5;
      iVar7 = 0;
      while (iVar4 = iVar1, iVar4 != 0) {
        iVar7 = iVar4;
        iVar1 = *(int *)(iVar4 + 8);
      }
      if (iVar7 == 0) {
        piVar3[2] = iVar5;
        *piVar2 = (int)piVar3;
        memw();
        return 0;
      }
      piVar3[2] = *(int *)(iVar7 + 8);
      *(int **)(iVar7 + 8) = piVar3;
      memw();
    }
LAB_400fc8d6:
    uVar6 = 0;
    memw();
  }
  return uVar6;
}

