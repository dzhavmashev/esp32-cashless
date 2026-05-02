// Function : FUN_4010c96c
// Address  : 0x4010c96c
// Size     : 235 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010c96c(char *param_1)

{
  int iVar1;
  int iVar2;
  
  (*(code *)&SUB_4008b530)(param_1,0,8);
  iVar2 = _DAT_3ffc8418;
  while (iVar1 = _DAT_3ffc840c, iVar2 != 0) {
    param_1[7] = param_1[7] + '\x01';
    memw();
    *param_1 = *param_1 + '\x01';
    memw();
    iVar2 = *(int *)(iVar2 + 0x34);
    memw();
  }
  while (iVar2 = _DAT_3ffc841c, iVar1 != 0) {
    param_1[7] = param_1[7] + '\x01';
    memw();
    iVar2 = *(int *)(iVar1 + 0x3c);
    if (iVar2 == 6) {
      param_1[2] = param_1[2] + '\x01';
      memw();
    }
    else if (iVar2 == 9) {
      param_1[3] = param_1[3] + '\x01';
      memw();
      memw();
    }
    else if (iVar2 == 8) {
      param_1[1] = param_1[1] + '\x01';
      memw();
      memw();
    }
    else if (iVar2 == 5) {
      param_1[4] = param_1[4] + '\x01';
      memw();
      memw();
    }
    memw();
    iVar1 = *(int *)(iVar1 + 0x34);
  }
  while (iVar1 = _DAT_3ffc8410, iVar2 != 0) {
    param_1[7] = param_1[7] + '\x01';
    memw();
    param_1[5] = param_1[5] + '\x01';
    memw();
    memw();
    iVar2 = *(int *)(iVar2 + 0x34);
  }
  while (iVar1 != 0) {
    param_1[7] = param_1[7] + '\x01';
    memw();
    param_1[6] = param_1[6] + '\x01';
    memw();
    memw();
    iVar1 = *(int *)(iVar1 + 0x34);
  }
  return;
}

