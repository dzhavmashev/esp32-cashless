// Function : FUN_401686f8
// Address  : 0x401686f8
// Size     : 79 bytes


void FUN_401686f8(int param_1,undefined4 *param_2,int param_3,char param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  FUN_401686c0();
  puVar1 = param_2 + param_3;
  iVar3 = 0x3ff03000 - (int)param_2;
  while (param_2 != puVar1) {
    uVar2 = (*(code *)&SUB_40064ae0)(*param_2);
    puVar4 = (undefined4 *)(iVar3 + (int)param_2);
    param_2 = param_2 + 1;
    *puVar4 = uVar2;
    memw();
  }
  if (param_4 == '\0') {
    puVar1 = (undefined4 *)(param_1 * 0x10 + 0x3ff03084);
  }
  else {
    puVar1 = (undefined4 *)((param_1 + 0x3ff0308) * 0x10);
  }
  memw();
  *puVar1 = 1;
  memw();
  return;
}

