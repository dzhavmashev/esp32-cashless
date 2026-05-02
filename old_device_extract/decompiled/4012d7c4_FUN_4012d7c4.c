// Function : FUN_4012d7c4
// Address  : 0x4012d7c4
// Size     : 77 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4012d7c4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)&DAT_3ffc76a4;
  if (_DAT_3ffc76a0 == 0) {
    for (piVar4 = &DAT_3f41cf90; (iVar3 = *piVar4, piVar1 < (int *)0x3ffc7884 && (iVar3 != 0));
        piVar4 = piVar4 + 1) {
      iVar2 = FUN_4012d7a8(iVar3);
      if ((iVar2 != 0) && ((*(int *)(iVar2 + 8) != 0x2a && (1 < *(int *)(iVar2 + 8) - 0x24U)))) {
        *piVar1 = iVar3;
        piVar1 = piVar1 + 1;
      }
    }
    *piVar1 = 0;
    _DAT_3ffc76a0 = 1;
    memw();
  }
  return;
}

