// Function : FUN_40116720
// Address  : 0x40116720
// Size     : 39 bytes


void FUN_40116720(int *param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    puVar1 = (undefined4 *)&DAT_3ffc83fc;
    do {
      puVar1 = (undefined4 *)*puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        return;
      }
    } while (((((*(byte *)((int)puVar1 + 0xeb) & 1) == 0) ||
              ((*(byte *)((int)puVar1 + 0xeb) & 4) == 0)) || (puVar1[1] == 0)) ||
            (*param_1 != puVar1[1]));
  }
  return;
}

