// Function : FUN_4010e034
// Address  : 0x4010e034
// Size     : 40 bytes


void FUN_4010e034(void)

{
  FUN_4010daf0();
  DAT_3ffc6335 = DAT_3ffc6335 + 1;
  memw();
  if ((DAT_3ffc6335 & 1) != 0) {
    memw();
    FUN_4010dbf0();
  }
  return;
}

