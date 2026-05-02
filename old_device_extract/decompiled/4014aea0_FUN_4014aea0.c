// Function : FUN_4014aea0
// Address  : 0x4014aea0
// Size     : 93 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014aea0(int param_1)

{
  byte bVar1;
  
  if (param_1 == 0) {
    FUN_40147fe4(1,0x800,1,"d param",&DAT_3f423a5e,0xf2);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined2 *)(param_1 + 0x15c) = 0;
  memw();
  if (param_1 == _DAT_3ffc8800) {
    if (DAT_3ffc8a38 == 0) {
      return;
    }
    bVar1 = 0xfe;
  }
  else {
    if (DAT_3ffc8a38 == 0) {
      return;
    }
    bVar1 = 0xfd;
  }
  DAT_3ffc8a38 = DAT_3ffc8a38 & bVar1;
  memw();
  if (DAT_3ffc8a38 != 0) {
    return;
  }
  memw();
  FUN_4014a6e8();
  return;
}

