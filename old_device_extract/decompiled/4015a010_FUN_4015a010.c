// Function : FUN_4015a010
// Address  : 0x4015a010
// Size     : 66 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015a010(void)

{
  char cVar1;
  
  cVar1 = *(char *)(_DAT_3ffbfc54 + 0x498);
  if (cVar1 == '\x01') {
    FUN_40147fe4(1,4,4,0x3f434248,_DAT_3ffbfc54 + 4);
    DAT_3ffc8a6a = cVar1;
    memw();
    memw();
    return;
  }
  FUN_40147fe4(1,4,4,0x3f434225);
  return;
}

