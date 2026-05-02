// Function : FUN_40107e34
// Address  : 0x40107e34
// Size     : 100 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40107e34(int *param_1)

{
  int *extraout_a3;
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  int in_t0;
  
  FUN_4011b020();
  iVar1 = *param_1;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 4) = param_1[1];
  }
  piVar3 = (int *)&DAT_3ffc58c0;
  piVar2 = (int *)param_1[1];
  if (_DAT_3ffc58c0 == param_1) {
    if (piVar2 != (int *)0x0) {
      pcVar5 = " option";
      uVar4 = 0x749;
      goto LAB_40107e5a;
    }
  }
  else {
    if (piVar2 != (int *)0x0) {
      *piVar2 = iVar1;
      memw();
      goto LAB_40107e69;
    }
    pcVar5 = "== NULL";
    uVar4 = 0x74c;
LAB_40107e5a:
    memw();
    iVar1 = in_t0;
    (*(code *)&SUB_40094c54)("!= NULL",uVar4,"allback",pcVar5);
    piVar3 = extraout_a3;
  }
  *piVar3 = iVar1;
LAB_40107e69:
  memw();
  _DAT_3ffc58c4 = _DAT_3ffc58c4 + 1;
  memw();
  memw();
  FUN_4011b040();
  return;
}

