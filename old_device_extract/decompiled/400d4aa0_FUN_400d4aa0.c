// Function : FUN_400d4aa0
// Address  : 0x400d4aa0
// Size     : 29 bytes


void FUN_400d4aa0(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_2 + param_3;
  for (; param_2 != puVar1; param_2 = param_2 + 1) {
    FUN_400d3f48(param_1,*param_2);
  }
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + param_3;
  return;
}

