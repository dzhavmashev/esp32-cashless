// Function : FUN_401064a8
// Address  : 0x401064a8
// Size     : 116 bytes


void FUN_401064a8(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = (int *)*param_1;
  piVar2 = (int *)0x0;
LAB_401064af:
  do {
    piVar3 = piVar2;
    piVar2 = piVar4;
    if (piVar2 == (int *)0x0) {
      return;
    }
    piVar4 = (int *)*piVar2;
  } while ((piVar2[0x1b] != param_2) && (param_2 != 0));
  if (param_3 != 0) goto code_r0x401064d4;
  goto LAB_401064f1;
code_r0x401064d4:
  if (piVar2[0x15] == param_4) {
    memw();
    iVar1 = (*(code *)&SUB_4008b33c)(param_3,piVar2 + 5,param_4);
    if (iVar1 == 0) {
LAB_401064f1:
      if (piVar3 == (int *)0x0) {
        *param_1 = (int)piVar4;
        memw();
      }
      else {
        *piVar3 = (int)piVar4;
      }
      piVar4 = (int *)*piVar2;
      memw();
      FUN_401063cc(param_1,piVar2,0);
      piVar2 = piVar3;
    }
  }
  goto LAB_401064af;
}

