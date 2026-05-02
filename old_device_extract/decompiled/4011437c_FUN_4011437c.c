// Function : FUN_4011437c
// Address  : 0x4011437c
// Size     : 61 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011437c(void)

{
  char cVar1;
  
  cVar1 = DAT_3ffc637c;
  if (DAT_3ffc637c == '\0') {
    (*(code *)&SUB_40094c54)("ONS_LEN",0x139,"efcount","ONS_LEN");
  }
  DAT_3ffc637c = cVar1 + -1;
  memw();
  if (DAT_3ffc637c == '\0') {
    memw();
    FUN_40113ef0(_DAT_3ffc6380);
    _DAT_3ffc6380 = 0;
  }
  memw();
  return;
}

