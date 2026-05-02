// Function : FUN_40168748
// Address  : 0x40168748
// Size     : 158 bytes


void FUN_40168748(uint param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  memw();
  *(undefined4 *)(param_1 * 0x10 + 0x3ff03088) = 1;
  uVar2 = 8;
  if (param_1 != 1) {
    if (1 < (int)param_1) goto LAB_40168796;
    uVar2 = 0;
    if (param_1 == 0) {
      uVar2 = 5;
    }
  }
  do {
    param_1 = param_1 - 2;
    memw();
    FUN_401686c0();
    if (param_1 < 2) {
      uVar5 = rsil(5);
      param_1 = 0;
      piVar3 = param_2;
      while (param_1 < uVar2) {
        iVar4 = param_1 * 4;
        iVar1 = (*(code *)&SUB_400845ac)(iVar4 + 0x3ff03000);
        param_1 = param_1 + 2;
        piVar3[1] = iVar1;
        memw();
        iVar1 = (*(code *)&SUB_400845ac)(iVar4 + 0x3ff03004);
        *piVar3 = iVar1;
        piVar3 = piVar3 + 2;
        memw();
      }
      (*(code *)&SUB_4000bfdc)(uVar5);
    }
    else {
      (*(code *)&SUB_400845b8)(param_2,0x3ff03000,uVar2);
    }
    piVar3 = param_2 + uVar2;
    while (piVar3 != param_2) {
      iVar1 = *param_2;
      param_1 = 0;
      param_2 = param_2 + 1;
      if (iVar1 != 0) {
        return;
      }
    }
    (*(code *)&SUB_40094bc8)();
LAB_40168796:
    uVar2 = 0;
    if ((int)param_1 < 4) {
      uVar2 = 0x10;
    }
  } while( true );
}

