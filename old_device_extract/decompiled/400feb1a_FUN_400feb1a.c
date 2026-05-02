// Function : FUN_400feb1a
// Address  : 0x400feb1a
// Size     : 98 bytes


void FUN_400feb1a(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 int *param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *unaff_a8;
  int unaff_a9;
  int in_a13;
  int in_a14;
  uint in_a15;
  int in_stack_0000001c;
  
  if (in_stack_0000001c != param_3) {
    piVar2 = (int *)(param_3 * 4 + 0x3ffc5808);
    iVar3 = *piVar2;
    if ((iVar3 != 0) && (piVar2 = *(int **)(iVar3 + 0xb4), piVar2 <= unaff_a8)) {
      if (piVar2 == (int *)0xffffffff) {
        unaff_a9 = in_a13;
      }
      if (unaff_a9 == 0) {
        memw();
        iVar1 = (*(code *)&SUB_4008b33c)(param_5,iVar3 + in_a14,piVar2);
        if ((iVar1 == 0) &&
           ((piVar4 = param_6, param_1 == 0 && piVar2 == (int *)0x0 ||
            (((unaff_a8 <= piVar2 || (*(byte *)(param_5 + (int)piVar2) == in_a15)) &&
             (piVar4 = piVar2, (int)param_6 < (int)piVar2)))))) {
          param_1 = iVar3;
          param_6 = piVar4;
        }
      }
    }
    FUN_400feb1a(param_1,piVar2,param_3 + 1,iVar3,param_5,param_6);
    return;
  }
  memw();
  return;
}

