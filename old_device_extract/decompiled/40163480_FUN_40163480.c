// Function : FUN_40163480
// Address  : 0x40163480
// Size     : 94 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163480(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = _DAT_3ffc0034;
  puVar2 = _DAT_3ffc0034 + 8;
  *puVar2 = 0;
  puVar1[9] = puVar2;
  *(undefined1 *)(puVar1 + 0xc) = 0;
  *(undefined1 *)(puVar1 + 0xc) = 1;
  *(undefined1 *)(puVar1 + 0x18) = 1;
  *(undefined1 *)(puVar1 + 0x24) = 1;
  *(undefined1 *)(puVar1 + 6) = 3;
  *(undefined1 *)((int)puVar1 + 0x19) = 6;
  *(undefined1 *)((int)puVar1 + 0x1a) = 9;
  *(undefined1 *)((int)puVar1 + 0x1b) = 0xc;
  *(undefined1 *)(puVar1 + 0xb) = 7;
  *(undefined1 *)(puVar1 + 0x17) = 7;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  *(undefined1 *)(puVar1 + 0x23) = 8;
  memw();
  puVar1[5] = 0;
  memw();
  return;
}

