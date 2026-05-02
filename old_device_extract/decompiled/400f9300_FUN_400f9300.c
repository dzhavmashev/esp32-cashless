// Function : FUN_400f9300
// Address  : 0x400f9300
// Size     : 42 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f9300(void)

{
  _DAT_3ffc56c0 = (*(code *)&SUB_4008fcc8)(4);
  if (_DAT_3ffc56c0 == 0) {
    memw();
    (*(code *)&SUB_40094c54)("i_flash/cache_utils.c",0x5a,"her_cpu","k_yield");
  }
  return;
}

