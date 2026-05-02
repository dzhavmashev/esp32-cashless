// Function : FUN_4012c908
// Address  : 0x4012c908
// Size     : 54 bytes


undefined4 FUN_4012c908(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = 0;
  piVar3 = param_2;
  do {
    if (*piVar3 == 0) {
      *(int **)(param_1 + 0xdc) = param_2;
      uVar2 = 0;
LAB_4012c91b:
      memw();
      return uVar2;
    }
    iVar1 = (*(code *)&SUB_4008c01c)();
    uVar4 = uVar4 + iVar1;
    if ((0xfe < iVar1 - 1U) || (0xffff < uVar4)) {
      uVar2 = 0xffff8f00;
      goto LAB_4012c91b;
    }
    piVar3 = piVar3 + 1;
  } while( true );
}

