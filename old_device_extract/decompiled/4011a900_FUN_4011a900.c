// Function : FUN_4011a900
// Address  : 0x4011a900
// Size     : 91 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011a900(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  
  if (_DAT_3ffc84a4 == param_1) {
    _DAT_3ffc84a4 = 0;
  }
  iVar1 = 0;
  puVar2 = &DAT_3ffc851c;
  do {
    if (*(int *)(puVar2 + 0x14) == param_1) {
      puVar3 = (undefined4 *)&DAT_3ffc846c;
      do {
        if ((undefined1 *)*puVar3 == puVar2) {
          *puVar3 = 0;
          *(undefined1 *)(puVar3 + 2) = 0;
          memw();
        }
        puVar3 = puVar3 + 3;
      } while (puVar3 != (undefined4 *)&DAT_3ffc8490);
      puVar2[0x25] = 0;
      memw();
      memw();
      FUN_40119080(iVar1);
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0x2c;
  } while (iVar1 != 5);
  FUN_4011a348();
  return;
}

