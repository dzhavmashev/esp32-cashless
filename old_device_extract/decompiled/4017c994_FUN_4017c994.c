// Function : FUN_4017c994
// Address  : 0x4017c994
// Size     : 53 bytes


void FUN_4017c994(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(param_3 + 0x14);
  puVar1 = param_1 + (param_2 + -1 >> 5) + 1;
  puVar3 = puVar2 + *(int *)(param_3 + 0x10);
  for (; puVar2 < puVar3; puVar2 = puVar2 + 1) {
    *param_1 = *puVar2;
    param_1 = param_1 + 1;
  }
  for (; param_1 < puVar1; param_1 = param_1 + 1) {
    *param_1 = 0;
  }
  return;
}

