// Function : FUN_400fe884
// Address  : 0x400fe884
// Size     : 157 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_400fe884(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  memw();
  iVar1 = (*(code *)&SUB_40094d60)(0xc0);
  uVar3 = 0x101;
  if (iVar1 != 0) {
    for (iVar2 = 0; iVar2 != _DAT_3ffc5804; iVar2 = iVar2 + 1) {
      if (*(int *)(iVar2 * 4 + 0x3ffc5808) == 0) goto LAB_400fe8d6;
    }
    if (iVar2 == 8) {
      (*(code *)&SUB_40094d80)(iVar1);
      uVar3 = 0x101;
    }
    else {
      _DAT_3ffc5804 = iVar2 + 1;
LAB_400fe8d6:
      *(int *)(iVar2 * 4 + 0x3ffc5808) = iVar1;
      if (param_2 == -1) {
        (*(code *)&SUB_4008b530)(iVar1 + 0xa4,0,0xf);
      }
      else {
        memw();
        (*(code *)&SUB_4008bf10)(iVar1 + 0xa4,param_1);
      }
      (*(code *)&SUB_4008b3d0)(iVar1,param_3,0xa4);
      uVar3 = 0;
      *(int *)(iVar1 + 0xb4) = param_2;
      *(undefined4 *)(iVar1 + 0xb8) = param_4;
      *(int *)(iVar1 + 0xbc) = iVar2;
      if (param_5 != (int *)0x0) {
        *param_5 = iVar2;
        memw();
      }
    }
  }
  return uVar3;
}

