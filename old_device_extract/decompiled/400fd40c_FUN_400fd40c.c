// Function : FUN_400fd40c
// Address  : 0x400fd40c
// Size     : 59 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fd40c(undefined1 param_1)

{
  undefined1 auStack_34 [12];
  undefined4 uStack_28;
  uint uStack_24;
  
  memw();
  uStack_28 = 0;
  do {
    memw();
    uStack_24 = *(uint *)(_DAT_3ffbdd38 + 0x1c);
    memw();
    memw();
  } while ((uStack_24 >> 0x10 & 0xff) == 0x80);
  memw();
  auStack_34[0] = param_1;
  FUN_400fe3dc(&DAT_3ffbdd38,auStack_34,1,&uStack_28);
  return;
}

