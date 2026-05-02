// Function : FUN_4018d1e0
// Address  : 0x4018d1e0
// Size     : 106 bytes


undefined4 FUN_4018d1e0(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar2 = (int *)*param_1;
  piVar4 = piVar2;
  do {
    while( true ) {
      piVar1 = piVar4;
      if (piVar1 == (int *)0x0) {
        return 0x105;
      }
      piVar4 = (int *)piVar1[1];
      piVar5 = (int *)*piVar1;
      if (param_3 == 0) break;
      if (*piVar5 == *param_2) {
        if (piVar1 == piVar2) {
          *param_1 = (int)piVar4;
        }
        else {
          do {
            piVar3 = piVar2;
            piVar2 = (int *)piVar3[1];
          } while (piVar2 != piVar1);
          piVar3[1] = (int)piVar4;
          memw();
        }
LAB_4018d20c:
        memw();
        (*(code *)&SUB_40094d80)(piVar5);
        (*(code *)&SUB_40094d80)(piVar1);
        return 0;
      }
    }
  } while (piVar5 != param_2);
  if (piVar1 == piVar2) {
    *param_1 = (int)piVar4;
  }
  else {
    do {
      piVar5 = piVar2;
      piVar2 = (int *)piVar5[1];
    } while (piVar2 != piVar1);
    piVar5[1] = (int)piVar4;
    memw();
  }
  memw();
  piVar5 = param_2;
  goto LAB_4018d20c;
}

