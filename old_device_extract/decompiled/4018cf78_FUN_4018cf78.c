// Function : FUN_4018cf78
// Address  : 0x4018cf78
// Size     : 135 bytes


undefined4 FUN_4018cf78(int *param_1,int param_2,int param_3,int *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  
  piVar1 = (int *)(*(code *)&SUB_40094dd8)(1,8);
  uVar3 = 0x101;
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)(*(code *)&SUB_40094dd8)(1,8);
    if (piVar2 == (int *)0x0) {
      (*(code *)&SUB_40094d80)(piVar1);
      uVar3 = 0x101;
    }
    else {
      piVar4 = (int *)*param_1;
      *piVar2 = param_2;
      piVar2[1] = param_3;
      *piVar1 = (int)piVar2;
      if (piVar4 == (int *)0x0) {
        piVar1[1] = 0;
        *param_1 = (int)piVar1;
      }
      else {
        do {
          piVar5 = piVar4;
          if ((param_5 != 0) && (*(int *)*piVar5 == param_2)) {
            ((int *)*piVar5)[1] = param_3;
            memw();
            (*(code *)&SUB_40094d80)(piVar1);
            (*(code *)&SUB_40094d80)(piVar2);
            return 0;
          }
          piVar4 = (int *)piVar5[1];
        } while ((int *)piVar5[1] != (int *)0x0);
        piVar1[1] = 0;
        piVar5[1] = (int)piVar1;
        memw();
      }
      uVar3 = 0;
      if (param_4 != (int *)0x0) {
        *param_4 = (int)piVar2;
        memw();
      }
    }
  }
  return uVar3;
}

