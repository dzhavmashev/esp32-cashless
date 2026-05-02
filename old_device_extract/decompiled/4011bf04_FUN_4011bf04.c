// Function : FUN_4011bf04
// Address  : 0x4011bf04
// Size     : 80 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011bf04(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    FUN_40174130(" match.");
  }
  else {
    puVar1 = _DAT_3ffc6534;
    if (*(int *)(param_1 + 0xd4) != 0) {
      FUN_40113e64();
      FUN_40113ef0(*(undefined4 *)(param_1 + 0xd4));
      *(undefined4 *)(param_1 + 0xd4) = 0;
      puVar1 = _DAT_3ffc6534;
    }
    while (puVar1 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)puVar1[1];
      memw();
      FUN_40185520(&DAT_3ffc6534,puVar1);
      (*(code *)&SUB_40094d80)(*puVar1);
      (*(code *)&SUB_40094d80)(puVar1);
      puVar1 = puVar2;
    }
  }
  return;
}

