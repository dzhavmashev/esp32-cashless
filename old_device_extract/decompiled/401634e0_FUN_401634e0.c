// Function : FUN_401634e0
// Address  : 0x401634e0
// Size     : 79 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401634e0(uint param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,uint param_5
                 )

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = _DAT_3ffc0034;
  uVar2 = param_1 & 0xff;
  *(undefined1 *)(_DAT_3ffc0034 + uVar2 * 0xc + 0xb) = param_4;
  *(undefined1 *)((int)puVar1 + uVar2 * 0x30 + 0x2d) = param_3;
  *(undefined1 *)((int)puVar1 + uVar2 * 0x30 + 0x2e) = param_2;
  *(undefined1 *)((int)puVar1 + (uVar2 + 1) * 0x30 + 1) = 0;
  memw();
  uVar2 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
  puVar1[(param_5 & 0xff) + 1] = puVar1[(param_5 & 0xff) + 1] | uVar2;
  *puVar1 = *puVar1 | uVar2;
  memw();
  return;
}

