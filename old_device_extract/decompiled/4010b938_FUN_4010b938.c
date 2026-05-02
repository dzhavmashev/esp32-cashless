// Function : FUN_4010b938
// Address  : 0x4010b938
// Size     : 31 bytes


void FUN_4010b938(char param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != '\0') {
    puVar1 = (undefined4 *)&DAT_3ffc83fc;
    do {
      puVar1 = (undefined4 *)*puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        return;
      }
    } while ((char)(*(char *)((int)puVar1 + 0xee) + '\x01') != param_1);
  }
  return;
}

