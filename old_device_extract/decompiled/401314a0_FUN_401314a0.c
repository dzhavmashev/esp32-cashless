// Function : FUN_401314a0
// Address  : 0x401314a0
// Size     : 49 bytes


void FUN_401314a0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = param_1 + param_2 + -1;
  while (param_1 <= puVar3) {
    uVar1 = (*(code *)&SUB_40064ae0)(*param_1);
    uVar2 = (*(code *)&SUB_40064ae0)(*puVar3);
    *param_1 = uVar2;
    param_1 = param_1 + 1;
    *puVar3 = uVar1;
    memw();
    puVar3 = puVar3 + -1;
  }
  return;
}

