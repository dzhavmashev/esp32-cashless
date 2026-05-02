// Function : FUN_40163728
// Address  : 0x40163728
// Size     : 47 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163728(uint param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = _DAT_3ffc0034;
  uVar1 = (uint)(0xfffffffefffffffe >> 0x20 - (param_1 & 0x1f));
  _DAT_3ffc0034[(param_2 & 0xff) + 1] = _DAT_3ffc0034[(param_2 & 0xff) + 1] & uVar1;
  *puVar2 = *puVar2 & uVar1;
  memw();
  FUN_401636d0();
  return;
}

