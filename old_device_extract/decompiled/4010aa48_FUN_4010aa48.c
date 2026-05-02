// Function : FUN_4010aa48
// Address  : 0x4010aa48
// Size     : 82 bytes


void FUN_4010aa48(void)

{
  char cVar1;
  
  FUN_4010a2c4(0);
  FUN_4010a2c4(1);
  FUN_4010a2c4(2);
  FUN_4010a2c4(3);
  cVar1 = DAT_3ffc5d6e;
  if (DAT_3ffc5d6e == '\0') {
    FUN_40113304(0x4010aa94,0);
    DAT_3ffc6204 = cVar1;
    memw();
    memw();
  }
  else {
    FUN_40113258(1000,0x4010aa94,0);
  }
  return;
}

