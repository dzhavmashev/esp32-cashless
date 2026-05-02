// Function : FUN_400ff670
// Address  : 0x400ff670
// Size     : 78 bytes


void FUN_400ff670(int param_1,uint param_2)

{
  uint *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)**(undefined4 **)(&DAT_3f40e4e8 + param_1 * 4);
  do {
    memw();
    memw();
    memw();
  } while (0x80 - (*(uint *)(puVar2 + 0x1c) >> 0x10 & 0xff) < 2);
  puVar1 = (uint *)&DAT_60000000;
  if ((puVar2 != &DAT_3ff40000) && (puVar1 = (uint *)&DAT_60010000, puVar2 != &DAT_3ff50000)) {
    puVar1 = (uint *)&DAT_6002e000;
  }
  memw();
  *puVar1 = param_2 & 0xff;
  memw();
  return;
}

