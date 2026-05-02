// Function : FUN_40189a7c
// Address  : 0x40189a7c
// Size     : 43 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40189a7c(void)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar3 = _DAT_3ffc06fc;
  puVar2 = (uint *)FUN_4018ce90();
  while( true ) {
    if (puVar3 == (uint *)0x0) {
      return 0;
    }
    memw();
    if ((*puVar3 >> 0x1e & 1) == 1) break;
    bVar1 = puVar3 == puVar2;
    puVar3 = (uint *)puVar3[2];
    if (bVar1) {
      return 0;
    }
  }
  return 1;
}

