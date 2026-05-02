// Function : FUN_40147614
// Address  : 0x40147614
// Size     : 73 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_40147614(void)

{
  undefined1 *puVar1;
  undefined1 local_30 [48];
  
  local_30[0] = 0;
  memw();
  memw();
  puVar1 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0x4d;
    memw();
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    memw();
    *(undefined4 *)(puVar1 + 4) = 0x401503cc;
    *(undefined1 **)(puVar1 + 0xc) = local_30;
    *(undefined4 *)(puVar1 + 0x14) = 0;
    memw();
    FUN_40150444();
  }
  return local_30[0];
}

