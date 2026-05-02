// Function : FUN_4014ac84
// Address  : 0x4014ac84
// Size     : 102 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4014ac84(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0xd7);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_1 == _DAT_3ffc8800) {
    iVar2 = 2;
    iVar1 = 0;
  }
  else {
    if (param_1 != _DAT_3ffc8804) {
      return -1;
    }
    iVar2 = 8;
    iVar1 = 2;
  }
  while( true ) {
    if (iVar2 == iVar1) {
      return -1;
    }
    if (*(char *)(iVar1 + 0x3ffc89c6) == '\0') break;
    iVar1 = iVar1 + 1;
  }
  *(undefined1 *)(iVar1 + 0x3ffc89c6) = 1;
  memw();
  memw();
  return iVar1;
}

