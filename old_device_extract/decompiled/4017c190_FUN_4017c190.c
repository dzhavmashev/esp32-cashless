// Function : FUN_4017c190
// Address  : 0x4017c190
// Size     : 66 bytes


void FUN_4017c190(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar1 = (undefined4 *)(*(code *)&SUB_40094d60)(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)(*(code *)&SUB_40094c54)(&DAT_3f4260d0,0x8a,0,"ity");
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x24) + 0xc) + param_2[1] * 4);
    *param_2 = *puVar1;
    *puVar1 = param_2;
  }
  return;
}

