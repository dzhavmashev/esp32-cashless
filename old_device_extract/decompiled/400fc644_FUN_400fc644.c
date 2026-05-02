// Function : FUN_400fc644
// Address  : 0x400fc644
// Size     : 84 bytes


undefined4 FUN_400fc644(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0x16;
  if ((param_1 != (int *)0x0) &&
     ((uVar3 = 0, param_2 == (int *)0x0 || ((*param_2 != 0 && (uVar3 = param_2[1], uVar3 < 3)))))) {
    piVar1 = (int *)(*(code *)&SUB_40094d60)(8);
    uVar4 = 0xc;
    if (piVar1 != (int *)0x0) {
      piVar1[1] = uVar3;
      uVar4 = 4;
      if (uVar3 != 1) {
        uVar4 = 1;
      }
      memw();
      iVar2 = (*(code *)&SUB_4008fcc8)(uVar4);
      *piVar1 = iVar2;
      if (*piVar1 == 0) {
        memw();
        (*(code *)&SUB_40094d80)(piVar1);
        uVar4 = 0xb;
      }
      else {
        *param_1 = (int)piVar1;
        uVar4 = 0;
        memw();
      }
    }
  }
  return uVar4;
}

