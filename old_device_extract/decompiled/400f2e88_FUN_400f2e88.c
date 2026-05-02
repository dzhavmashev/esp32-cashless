// Function : FUN_400f2e88
// Address  : 0x400f2e88
// Size     : 54 bytes


void FUN_400f2e88(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 != 0) {
    puVar1 = &DAT_3ff40000;
    if ((*(char *)(param_1 + 4) != '\0') &&
       (puVar1 = &DAT_3ff50000, *(char *)(param_1 + 4) != '\x01')) {
      puVar1 = &DAT_3ff6e000;
    }
    memw();
    memw();
    *(uint *)(puVar1 + 0x18) = *(uint *)(puVar1 + 0x18) & 0xfffffffe;
    memw();
    memw();
    *(uint *)(puVar1 + 0x18) = *(uint *)(puVar1 + 0x18) | 1;
  }
  return;
}

